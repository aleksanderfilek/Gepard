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

    Hero::UI::Widget* widgets[1];
    int currentWidgetIndex = 0;

    void ChangeWidget(int Index);

public:
    void Load() override;
    void Start() override;
    void Update() override;
};