#pragma once

#include "Building.hpp"

class WoodcutterHut : public Building
{
public:
  WoodcutterHut(const Hero::Sid& NewId):Building(NewId){};

  virtual void Start() override;
  virtual void Update() override;
  virtual void End() override;
};