#pragma once

#include "../Hero/Systems/ActorScene/Actor.hpp"
#include "../Hero/Components/StaticMesh.hpp"

class Unit : public Hero::Actor
{
protected:
  Hero::StaticMesh* staticMesh = nullptr;
  Hero::Actor* camera = nullptr;
  
  class Pathfinding* pathfinding;

  Hero::Float2* path = nullptr;
  uint32_t pathLength = 0;
  uint32_t currentPathPoint = 1;

  float moveSpeed = 1.0f;

public:
  Unit(const Hero::Sid& NewId);

  virtual void Start() override;
  virtual void Update() override;
  virtual void End() override;

  Hero::Actor* Clone() override;

  void MoveTo(const Hero::Float2& Position);
};