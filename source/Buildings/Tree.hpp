#pragma once

#include "WorldObject.hpp"

class Tree : public WorldObject
{
public:
  Tree(const Hero::Sid& NewId);

  virtual void Start() override;

  Hero::Actor* Clone() override;
};