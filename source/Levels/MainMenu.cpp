#include "MainMenu.hpp"

#include "../Hero/Core/Core.hpp"
#include "../Hero/Systems/UserInterface.hpp"
#include "../Widgets/UI_MainMenu.hpp"
#include "../Hero/Systems/Resources.hpp"
#include "../Defaults.hpp"
#include "../Hero/Graphics/Shader.hpp"
#include "../Hero/Graphics/Material.hpp"
#include "../Hero/Graphics/Mesh.hpp"
#include "../Actors/Player.hpp"
#include "../Hero/Actors/Systems/ForwardRenderer.hpp"

#include<iostream>

void MainMenu::Load()
{
    Hero::Resources* resources = Hero::Core::getSystem<Hero::Resources>(SID("Resources"));
    resources->Add(SID("RendererShader"), PATH(assets/rendererShader.he));
    resources->Add(SID("S_Spritebatch"), PATH(assets/S_Spritebatch.he));
}

void MainMenu::Start()
{
    Scene::Start();

    window = Hero::Core::getSystem<Hero::System::Window>(SID("Window"));
    window->setBackgroundColor({215,227,224,0xFF});
    window->setDepthTest(true);
    
    Hero::Resources* resources = Hero::Core::getSystem<Hero::Resources>(SID("Resources"));

    Hero::System::UserInterface* ui = Hero::Core::getSystem<Hero::System::UserInterface>(SID("Ui"));
    ui->setShader((Hero::Shader*)resources->Get(SID("S_Spritebatch")));

    mainMenu = new UI_MainMenu();
    ui->add("MainMenu", mainMenu);

    AddActor(new Hero::ForwardRenderer(SID("Renderer")));
    AddActor(new Player(SID("Player")));
}

void MainMenu::Update()
{
    Hero::System::Window::clear();

    Scene::Update();

    window->render();
}

void MainMenu::End()
{
    Scene::End();

}