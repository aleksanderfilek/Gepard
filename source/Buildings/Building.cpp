#include "Building.hpp"
#include "../Hero/Systems/ActorScene/Scene.hpp"
#include "../World/World.hpp"
#include "../World/Components/Pathfinding.hpp"

Building::Building(const Hero::Sid& NewId) : WorldObject(NewId)
{

}

void Building::Start()
{
  WorldObject::Start();
}

void Building::End()
{
  WorldObject::End();
}

Hero::Actor* Building::Clone()
{
  Hero::Actor* actor = new Building(GetName());
  //actor->SetTransform(actor->GetTransform());
  return actor;
}