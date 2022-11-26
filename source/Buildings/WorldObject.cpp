#include "WorldObject.hpp"

#include "../Hero/Systems/ActorScene/Scene.hpp"
#include "../World/World.hpp"
#include "../World/Components/Pathfinding.hpp"

WorldObject::WorldObject(const Hero::Sid& NewId) : Hero::Actor(NewId)
{

}

void WorldObject::Start()
{
  Pathfinding* pathfinding = (Pathfinding*)GetScene()->GetActor(SID("World"))->GetComponent<Pathfinding>();
  Hero::Float3 absolutPosition = GetTransform().GetWorldPosition();
  Hero::Int2 position((int)floorf(absolutPosition.x), (int)floorf(absolutPosition.z));
  pathfinding->SetWalkableState(position, size, false);
  
  Hero::Actor::Start();
}

void WorldObject::End()
{
  Pathfinding* pathfinding = (Pathfinding*)GetScene()->GetActor(SID("World"))->GetComponent<Pathfinding>();
  Hero::Float3 absolutPosition = GetTransform().GetWorldPosition();
  Hero::Int2 position((int)floorf(absolutPosition.x),(int)floorf(absolutPosition.z));
  pathfinding->SetWalkableState(position, size, true);

  Hero::Actor::End();
}

Hero::Actor* WorldObject::Clone()
{
  Hero::Actor* actor = new WorldObject(GetName());
  //actor->SetTransform(actor->GetTransform());
  return actor;
}