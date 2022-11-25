#pragma once

#include "Unit.hpp"

class Villager : public Unit
{
public:
  Villager(const Hero::Sid& NewId);

  virtual void Start() override;
  virtual void Update() override;
  virtual void End() override;
};