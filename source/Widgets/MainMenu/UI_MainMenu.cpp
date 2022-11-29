#include "UI_MainMenu.hpp"

#include "../../Hero/Core/Core.hpp"
#include "../../Hero/Systems/Resources.hpp"
#include "../../Defaults.hpp"
#include "../../Hero/UserInterface/Image.hpp"
#include "../../Hero/UserInterface/Label.hpp"
#include "../../Hero/Graphics/Font.hpp"
#include "../../Hero/ThirdParty/GL/Gl.hpp"
#include "../../Hero/UserInterface/VerticalStack.hpp"

#include "../../Hero/Core/Events.hpp"

#include "../Button.hpp"

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

    Hero::UI::IElement* playBtn = CreateButton("Play", 
        (Hero::Font*)resources->Get(SID("Arial48")), (Hero::Texture*)resources->Get(SID("UI_MainMenu_Panel")));
    playBtn->SetRelativeTransform(Hero::Int4(0, 0, 200, 50));

    Hero::UI::IElement* settingsBtn = CreateButton("Settings", 
        (Hero::Font*)resources->Get(SID("Arial48")), (Hero::Texture*)resources->Get(SID("UI_MainMenu_Panel")));
    settingsBtn->SetRelativeTransform(Hero::Int4(0, 0, 200, 50));

    Hero::UI::IElement* quitBtn = CreateButton("Quit", 
        (Hero::Font*)resources->Get(SID("Arial48")), (Hero::Texture*)resources->Get(SID("UI_MainMenu_Panel")));
    quitBtn->SetRelativeTransform(Hero::Int4(0, 0, 200, 50));

    Hero::UI::VerticalStack* verticalPanel = new Hero::UI::VerticalStack();
    verticalPanel->setSpacing(10);
    verticalPanel->SetRelativeTransform(Hero::Int4(100, 100, 200, 400));
    verticalPanel->add("playBtn", playBtn);
    verticalPanel->add("settingsBtn", settingsBtn);
    verticalPanel->add("quitBtn", quitBtn);

    add("verticalPanel", verticalPanel);
}