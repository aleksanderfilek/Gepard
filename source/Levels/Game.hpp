#pragma once

#include "../Hero/Systems/ActorScene/Scene.hpp"

class Game : public Hero::Scene
{
private:

public:
    void Start() override;
    void Update() override;
    void End() override;
};