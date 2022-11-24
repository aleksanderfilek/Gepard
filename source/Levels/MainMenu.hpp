#pragma once

#include "../Hero/Systems/ActorScene/Scene.hpp"
#include "../Hero/Systems/Window.hpp"

class MainMenu : public Hero::Scene
{
private:
    class UI_MainMenu* mainMenu;
    Hero::System::Window* window;
public:
    void Load() override;
    void Start() override;
    void Update() override;
    void End() override;
};