#include "UI_MainMenu.hpp"

#include "../Hero/Core/Core.hpp"
#include "../Hero/Systems/Resources.hpp"
#include "../Defaults.hpp"
#include "../Hero/UserInterface/Image.hpp"
#include "../Hero/UserInterface/Label.hpp"
#include "../Hero/Graphics/Font.hpp"
#include "../Hero/ThirdParty/GL/Gl.hpp"

#include "../Hero/Core/Events.hpp"

#include <iostream>

event(BuildingBtn_Click)
{
    Hero::UI::Image* buildingPanel = (Hero::UI::Image*)args;
    buildingPanel->setVisibility(!buildingPanel->isVisible());
}

UI_MainMenu::UI_MainMenu() : Hero::UI::Widget()
{
    glEnable(GL_BLEND);
    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);

    Hero::Resources* resources = Hero::Core::getSystem<Hero::Resources>(SID("Resources"));
    resources->Add(SID("UI_MainMenu_Panel"), PATH(assets/ui/UI_MainMenu_Panel.he));
    resources->Add(SID("Arial48"), PATH(assets/ui/arial.he));
    resources->Add(SID("T_IconBuilding"), PATH(assets/ui/icons/T_IconBuilding.he));

    Hero::UI::Image* panel = new Hero::UI::Image();
    panel->setTexture((Hero::Texture*)resources->Get(SID("UI_MainMenu_Panel")));
    panel->SetRelativeTransform(Hero::Int4(0, 0, 0, 50), 
        Hero::UI::HorizontalAnchor::STRETCH, Hero::UI::VerticalAnchor::TOP);
    add("panel", panel);

    Hero::UI::Label* title = new Hero::UI::Label();
    title->setAlligment(Hero::UI::Alligment::CENTER);
    title->SetRelativeTransform(Hero::Int4(0, 0, 0, 50), 
        Hero::UI::HorizontalAnchor::STRETCH, Hero::UI::VerticalAnchor::TOP);
    title->setFont((Hero::Font*)resources->Get(SID("Arial48")));
    title->setText("Gepard");
    title->apply();
    add("Title", title);

    Hero::UI::Image* buildingPanel = new Hero::UI::Image();
    buildingPanel->setTexture((Hero::Texture*)resources->Get(SID("UI_MainMenu_Panel")));
    buildingPanel->SetRelativeTransform(Hero::Int4(-200, 50, 200, 400), 
        Hero::UI::HorizontalAnchor::RIGHT, Hero::UI::VerticalAnchor::TOP);
    buildingPanel->setVisibility(false);
    add("buildingPanel", buildingPanel);

    Hero::UI::Image* buildingBtn = new Hero::UI::Image();
    buildingBtn->setTexture((Hero::Texture*)resources->Get(SID("T_IconBuilding")));
    buildingBtn->SetRelativeTransform(Hero::Int4(-40, 10, 30, 30), 
        Hero::UI::HorizontalAnchor::RIGHT, Hero::UI::VerticalAnchor::TOP);
    buildingBtn->addEvent(Hero::UI::Event::OnLeftClick, BuildingBtn_Click, buildingPanel);
    add("buildingBtn", buildingBtn);
}