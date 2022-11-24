#pragma once

#include "../Hero/Systems/ActorScene/Actor.hpp"

class World : public Hero::Actor
{
private:
  class Pathfinding* pathfinding = nullptr;

public:
  World(const Hero::Sid& NewId);

  virtual void Start() override;
  virtual void Update() override;
  virtual void End() override;

  Hero::Actor* Clone() override;
};