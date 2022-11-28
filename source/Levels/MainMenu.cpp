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
#include "../World/World.hpp"
#include "../Buildings/WoodcutterHut.hpp"
#include "../Units/Villager.hpp"
#include "../Hero/Core/Random.hpp"
#include <sstream>
#include<iostream>
#include "../Buildings/Tree.hpp"
#include "../Buildings/Warehouse.hpp"

#include "../Utilities/DataTable.hpp"

struct tests : public TableRow
{
    std::string x;
    int a;
    void Serialize(std::vector<std::string>& Out);
    void Deserialize(const std::vector<std::string>& In);
};

void tests::Serialize(std::vector<std::string>& Out)
{

}

void tests::Deserialize(const std::vector<std::string>& In)
{
    x = In[0];
    a = std::stoi(In[1]);
}

void MainMenu::Load()
{
    Hero::Resources* resources = Hero::Core::getSystem<Hero::Resources>(SID("Resources"));
    resources->Add(SID("RendererShader"), PATH(assets/rendererShader.he));
    resources->Add(SID("S_Spritebatch"), PATH(assets/S_Spritebatch.he));
    resources->Add(SID("S_Basic"), PATH(assets/S_Basic.he));
    resources->Add(SID("T_ColorPalette"), PATH(assets/T_ColorPalette.he));
    resources->Add(SID("S_Billboard"), PATH(assets/S_Billboard.he));
}

void MainMenu::Start()
{
    DataTable<tests> testDT("bin/assets/dt.csv");
    tests* element = testDT.GetRow(SID("name1"));
    std::cout<<element->x<<", "<<element->a<<std::endl;

    Scene::Start();

    window = Hero::Core::getSystem<Hero::System::Window>(SID("Window"));
    window->setBackgroundColor({0xFE,0xF1,0xCF,0xFF});
    window->setDepthTest(true);
    
    Hero::Resources* resources = Hero::Core::getSystem<Hero::Resources>(SID("Resources"));

    Hero::System::UserInterface* ui = Hero::Core::getSystem<Hero::System::UserInterface>(SID("Ui"));
    ui->setShader((Hero::Shader*)resources->Get(SID("S_Spritebatch")));

    mainMenu = new UI_MainMenu();
    ui->add("MainMenu", mainMenu);

    AddActor(new Hero::ForwardRenderer(SID("Renderer")));
    AddActor(new World(SID("World")));
    AddActor(new Player(SID("Player")));
    AddActor(new WoodcutterHut(SID("Woodcutter")));
    AddActor(new Villager(SID("Villager")));
    AddActor(new Tree(SID("Tree")));
    AddActor(new Warehouse(SID("Warehouse")));
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