#pragma once 

#include "../Hero/Systems/ActorScene/Actor.hpp"
#include "../Hero/Core/Sid.hpp"
#include "../Hero/Components/StaticMesh.hpp"

class Selector : public Hero::Actor
{
private:
    Hero::StaticMesh* staticMesh = nullptr;

public:
    Selector(const Hero::Sid& NewId);

    virtual void Start() override;
    virtual void Update() override;
    virtual void End() override;

    void SetVisibility(bool Visibile);

    Hero::Actor* Clone() override;
};