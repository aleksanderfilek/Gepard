#include "MainMenu.hpp"

#include "../Hero/Core/Core.hpp"
#include "../Hero/Systems/Resources.hpp"
#include "../Hero/Graphics/Shader.hpp"

#include "../Defaults.hpp"
#include "../Actors/StaticCamera.hpp"
#include "../Widgets/MainMenu/UI_MainMenu.hpp"
#include "../Widgets/MainMenu/UI_CampaignMenu.hpp"
#include "../Widgets/MainMenu/UI_SettingsMenu.hpp"

void MainMenu::Load()
{
    Hero::Resources* resources = Hero::Core::getSystem<Hero::Resources>(SID("Resources"));
    resources->Add(SID("S_Spritebatch"), PATH(assets/S_Spritebatch.he));
    resources->Add(SID("S_Basic"), PATH(assets/S_Basic.he));

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

    widgets[1] = new UI_CampaignMenu();
    ui->add("CampaignMenu", widgets[1]);
    widgets[1]->setVisibility(false);

    widgets[2] = new UI_SettingsMenu();
    ui->add("SettingsMenu", widgets[2]);
    widgets[2]->setVisibility(false);

    AddActor(new StaticCamera(SID("Camera")));
}

void MainMenu::Update()
{
    Hero::System::Window::clear();

    Scene::Update();
}

void MainMenu::ChangeMenu(int Index)
{
    widgets[currentWidgetIndex]->setVisibility(false);
    currentWidgetIndex = Index;
    widgets[currentWidgetIndex]->setVisibility(true);
}