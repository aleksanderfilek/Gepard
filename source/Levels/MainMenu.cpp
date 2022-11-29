#include "MainMenu.hpp"

#include "../Hero/Core/Core.hpp"
#include "../Hero/Systems/Resources.hpp"
#include "../Hero/Graphics/Shader.hpp"

#include "../Defaults.hpp"
#include "../Widgets/MainMenu/UI_MainMenu.hpp"
#include "../Actors/StaticCamera.hpp"

void MainMenu::Load()
{
    Hero::Resources* resources = Hero::Core::getSystem<Hero::Resources>(SID("Resources"));
    resources->Add(SID("RendererShader"), PATH(assets/rendererShader.he));
    resources->Add(SID("S_Spritebatch"), PATH(assets/S_Spritebatch.he));
    resources->Add(SID("S_Basic"), PATH(assets/S_Basic.he));
    resources->Add(SID("T_ColorPalette"), PATH(assets/T_ColorPalette.he));
    resources->Add(SID("S_Billboard"), PATH(assets/S_Billboard.he));

    window = Hero::Core::getSystem<Hero::System::Window>(SID("Window"));
    window->setBackgroundColor({0xFE,0xF1,0xCF,0xFF});

    ui = Hero::Core::getSystem<Hero::System::UserInterface>(SID("Ui"));
    ui->setShader((Hero::Shader*)resources->Get(SID("S_Spritebatch")));
}

void MainMenu::Start()
{
    Scene::Start();

    widgets[0] = new UI_MainMenu();
    ui->add("MainMenu", widgets[0]);

    AddActor(new StaticCamera(SID("Camera")));
}

void MainMenu::Update()
{
    Hero::System::Window::clear();

    Scene::Update();
}


void MainMenu::ChangeWidget(int Index)
{
    widgets[currentWidgetIndex]->setVisibility(false);
    currentWidgetIndex = Index;
    widgets[currentWidgetIndex]->setVisibility(true);
}