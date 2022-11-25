#include "Building.hpp"
#include "../Hero/Systems/ActorScene/Scene.hpp"
#include "../World/World.hpp"
#include "../World/Components/Pathfinding.hpp"

Building::Building(const Hero::Sid& NewId) : Hero::Actor(NewId)
{

}

void Building::Start()
{
  Pathfinding* pathfinding = (Pathfinding*)GetScene()->GetActor(SID("World"))->GetComponent<Pathfinding>();
  Hero::Float3 absolutPosition = GetTransform().GetWorldPosition();
  Hero::Int2 position((int)floorf(absolutPosition.x), (int)floorf(absolutPosition.z));
  pathfinding->SetWalkableState(position, size, false);
  
  Hero::Actor::Start();
}

void Building::End()
{
  Pathfinding* pathfinding = (Pathfinding*)GetScene()->GetActor(SID("World"))->GetComponent<Pathfinding>();
  Hero::Float3 absolutPosition = GetTransform().GetWorldPosition();
  Hero::Int2 position((int)floorf(absolutPosition.x),(int)floorf(absolutPosition.z));
  pathfinding->SetWalkableState(position, size, true);

  Hero::Actor::End();
}

Hero::Actor* Building::Clone()
{
  Hero::Actor* actor = new Building(GetName());
  //actor->SetTransform(actor->GetTransform());
  return actor;
}