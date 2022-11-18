#pragma once

#include "../Hero/Systems/ActorScene/Actor.hpp"
#include "../Hero/Core/Sid.hpp"
#include "../Hero/Components/StaticMesh.hpp"

class Character : public Hero::Actor
{
private:
  Hero::StaticMesh* staticMesh = nullptr;
  Hero::Actor* camera = nullptr;

public:
  Character(const Hero::Sid& NewId);

  virtual void Start() override;
  virtual void Update() override;
  virtual void End() override;

  void SetVisibility(bool Visibile);

  Hero::Actor* Clone() override;
};