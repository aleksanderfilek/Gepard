#pragma once

#include "../World/WorldObject.hpp"

class Building : public WorldObject
{
public:
  Building(const Hero::Sid& NewId);

  virtual void Start() override;
  virtual void End() override;

  Hero::Actor* Clone() override;
};