#include "World.hpp"
#include "Components/Pathfinding.hpp"

World::World(const Hero::Sid& NewId) : Hero::Actor(NewId)
{
}

void World::Start()
{
  Hero::Actor::Start();
  pathfinding = new Pathfinding(50, 50);
  AddComponent(pathfinding);

  worldObjects = new QuadTree<class WorldObject>(Hero::Float4(0.0f, 0.0f, 50.0f, 50.0f));
}

void World::Update()
{
  Hero::Actor::Update();
}

void World::End()
{
  Hero::Actor::End();

  delete worldObjects;
}

Hero::Actor* World::Clone()
{
  Hero::Actor* actor = new World(GetName());
  //actor->SetTransform(actor->GetTransform());
  return actor;
}