#pragma once

#include "../Hero/Systems/ActorScene/Actor.hpp"
#include "../Utilities/QuadTree.hpp"
#include "WorldObject.hpp"

class World : public Hero::Actor
{
private:
  class Pathfinding* pathfinding = nullptr;

  QuadTree<WorldObject>* worldObjects;

public:
  World(const Hero::Sid& NewId);

  virtual void Start() override;
  virtual void Update() override;
  virtual void End() override;

  Hero::Actor* Clone() override;
};