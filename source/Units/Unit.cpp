#include "Unit.hpp"
#include "../Hero/Systems/ActorScene/Scene.hpp"
#include "../World/Components/Pathfinding.hpp"
#include "../Hero/Core/Time.hpp"

Unit::Unit(const Hero::Sid& NewId) : Hero::Actor(NewId)
{

}

void Unit::Start()
{
  Hero::Actor::Start();

  pathfinding = (Pathfinding*)GetScene()->GetActor(SID("World"))->GetComponent<Pathfinding>();

  camera = GetScene()->GetActor(SID("Camera"));
}

void Unit::Update()
{
  Hero::Actor::Update();

  Hero::Float3 cameraForwardVector = camera->GetTransformRef()->GetWorldRotation().GetForwardVector();
  cameraForwardVector.y = 0.0f;
  cameraForwardVector.normalize();

  Hero::Float3 forwardVector = GetTransformRef()->GetWorldRotation().GetForwardVector();

  float angle = acosf(Hero::dotProduct(cameraForwardVector, Hero::Float3::forward()));

  if(cameraForwardVector.x < 0.0f)
   angle *= -1.0f;

  Hero::Quaternion rotation(angle - 90.0f, Hero::Float3::up());
  GetTransformRef()->SetLocalRotation(rotation);

  MoveAlongPath();
}

void Unit::End()
{
  Hero::Actor::End();
}

Hero::Actor* Unit::Clone()
{
  Hero::Actor* actor = new Unit(GetName());
  //actor->SetTransform(actor->GetTransform());
  return actor;
}

void Unit::MoveAlongPath()
{
  if(path == nullptr) 
    return;

  double deltaTime = Hero::Time::getDeltaTime();

  Hero::Float3 startPoint = GetTransform().GetLocalPosition();
  Hero::Float3 destPoint = Hero::Float3(path[currentPathPoint].x, 0.0f, path[currentPathPoint].y);
  Hero::Float3 direction = destPoint - startPoint;
  direction.normalize();

  GetTransformRef()->SetLocalPosition(startPoint  + direction * moveSpeed * deltaTime);

  if(distance(GetTransform().GetLocalPosition(), destPoint) < 0.05f)
  {
    currentPathPoint++;
    if(currentPathPoint == pathLength)
    {
      delete[] path;
      path = nullptr;
    }
  }
}

void Unit::MoveTo(const Hero::Float2& Position)
{
  Hero::Float3 position = GetTransform().GetLocalPosition();
  pathfinding->GetPathToPoint(Hero::Float2(position.x, position.z), Position, path, pathLength);
  currentPathPoint = 1;
}