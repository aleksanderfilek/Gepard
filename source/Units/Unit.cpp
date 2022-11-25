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

  GetTransformRef()->SetLocalPosition(Hero::Float3(0.5f, 0.0f, 0.5f));
}

void Unit::Update()
{
  Hero::Actor::Update();

  if(path == nullptr) return;

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
      path = nullptr;
    }
  }
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

void Unit::MoveTo(const Hero::Float2& Position)
{
  Hero::Float3 position = GetTransform().GetLocalPosition();
  pathfinding->GetPathToPoint(Hero::Float2(position.x, position.z), Position, path, pathLength);
  currentPathPoint = 1;
  for(int i = 0; i < pathLength; i++)
    std::cout<<path[i]<<std::endl;
}