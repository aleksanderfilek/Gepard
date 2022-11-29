#pragma once

#include "../Hero/Systems/ActorScene/Actor.hpp"
#include "../Hero/Core/Sid.hpp"

class StaticCamera : public Hero::Actor
{
public:
  StaticCamera(const Hero::Sid& NewId);

  virtual void Start() override;

  Hero::Actor* Clone() override;
};