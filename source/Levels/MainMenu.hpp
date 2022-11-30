#pragma once

#include "../Hero/Systems/ActorScene/Scene.hpp"
#include "../Hero/Systems/Window.hpp"
#include "../Hero/Systems/UserInterface.hpp"
#include "../Hero/UserInterface/Widget.hpp"

class MainMenu : public Hero::Scene
{
private:
    Hero::System::Window* window;
    Hero::System::UserInterface* ui;

    Hero::UI::Widget* widgets[3];
    int currentWidgetIndex = 0;

public:
    void Load() override;
    void Start() override;
    void Update() override;

    void ChangeMenu(int Index);
};