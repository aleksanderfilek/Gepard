#pragma once

#include "../Hero/Systems/ActorScene/Actor.hpp"


class Unit : public Hero::Actor
{
private:
  class Pathfinding* pathfinding;

public:
  Unit(const Hero::Sid& NewId);

  virtual void Start() override;
  virtual void Update() override;
  virtual void End() override;

  Hero::Actor* Clone() override;
};