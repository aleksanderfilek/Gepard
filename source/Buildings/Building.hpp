#pragma once

#include "../Hero/Systems/ActorScene/Actor.hpp"
#include "../Hero/Components/StaticMesh.hpp"

class Building : public Hero::Actor
{
protected:
  Hero::StaticMesh* staticMesh = nullptr;

  Hero::Int2 size = Hero::Int2::one();

public:
  Building(const Hero::Sid& NewId);

  virtual void Start() override;
  virtual void End() override;

  Hero::Actor* Clone() override;
};