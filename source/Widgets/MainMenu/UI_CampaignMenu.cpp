#include "UI_CampaignMenu.hpp"

#include "../../Hero/Core/Core.hpp"
#include "../../Hero/Systems/Resources.hpp"
#include "../../Defaults.hpp"
#include "../../Hero/UserInterface/Image.hpp"
#include "../../Hero/UserInterface/Label.hpp"
#include "../../Hero/Graphics/Font.hpp"
#include "../../Hero/ThirdParty/GL/Gl.hpp"
#include "../../Hero/UserInterface/VerticalStack.hpp"
#include "../../Hero/Systems/ActorScene/SceneSystem.hpp"
#include "../../Hero/Systems/ActorScene/Scene.hpp"
#include "../../Hero/Core/Events.hpp"

#include "../Button.hpp"
#include "../../Levels/MainMenu.hpp"

static event(BackBtn_Click)
{
    Hero::SceneSystem* sceneSystem = Hero::Core::getSystem<Hero::SceneSystem>(SID("Scene"));
    MainMenu* scene = (MainMenu*)sceneSystem->GetCurrentScene();
    scene->ChangeMenu(0);
}

UI_CampaignMenu::UI_CampaignMenu() : Hero::UI::Widget()
{
    glEnable(GL_BLEND);
    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);

    Hero::Resources* resources = Hero::Core::getSystem<Hero::Resources>(SID("Resources"));
    resources->Add(SID("UI_MainMenu_Panel"), PATH(assets/ui/UI_MainMenu_Panel.he));
    resources->Add(SID("Arial48"), PATH(assets/ui/arial.he));

    Hero::UI::IElement* backBtn = CreateButton("Back", 
        (Hero::Font*)resources->Get(SID("Arial48")), (Hero::Texture*)resources->Get(SID("UI_MainMenu_Panel")));
    backBtn->SetRelativeTransform(Hero::Int4(0, 0, 200, 50));
    backBtn->addEvent(Hero::UI::Event::OnLeftClick, BackBtn_Click, this);

    Hero::UI::VerticalStack* verticalPanel = new Hero::UI::VerticalStack();
    verticalPanel->setSpacing(10);
    verticalPanel->SetRelativeTransform(Hero::Int4(500, 100, 200, 400));
    verticalPanel->add("backBtn", backBtn);

    add("verticalPanel", verticalPanel);
}