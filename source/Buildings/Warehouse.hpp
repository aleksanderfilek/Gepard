#pragma once

#include "Building.hpp"

class Warehouse : public Building
{
public:
  Warehouse(const Hero::Sid& NewId):Building(NewId){};

  virtual void Start() override;
  virtual void Update() override;
  virtual void End() override;
};