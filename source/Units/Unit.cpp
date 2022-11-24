#include "Unit.hpp"

Unit::Unit(const Hero::Sid& NewId) : Hero::Actor(NewId)
{

}

void Unit::Start()
{
  Hero::Actor::Start();
}

void Unit::Update()
{
  Hero::Actor::Update();
}

void Unit::End()
{
  Hero::Actor::End();
}

Hero::Actor* Unit::Clone()
{
  Hero::Actor* actor = new Unit(GetName());
  //actor->SetTransform(actor->GetTransform());
  return actor;
}