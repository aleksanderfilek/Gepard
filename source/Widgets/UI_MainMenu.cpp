#include "UI_MainMenu.hpp"

#include "../Hero/Core/Core.hpp"
#include "../Hero/Systems/Resources.hpp"
#include "../Defaults.hpp"
#include "../Hero/UserInterface/Image.hpp"
#include "../Hero/UserInterface/Label.hpp"
#include "../Hero/Graphics/Font.hpp"
#include "../Hero/ThirdParty/GL/Gl.hpp"

UI_MainMenu::UI_MainMenu() : Hero::UI::Widget()
{
    glEnable(GL_BLEND);
    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);

    Hero::Resources* resources = Hero::Core::getSystem<Hero::Resources>(SID("Resources"));
    resources->Add(SID("UI_MainMenu_Panel"), PATH(assets/ui/UI_MainMenu_Panel.he));
    resources->Add(SID("Arial48"), PATH(assets/ui/arial.he));

    Hero::UI::Image* panel = new Hero::UI::Image();
    panel->setTexture((Hero::Texture*)resources->Get(SID("UI_MainMenu_Panel")));
    panel->SetRelativeTransform(Hero::Int4(0, 0, 0, 50), 
    Hero::UI::HorizontalAnchor::STRETCH, Hero::UI::VerticalAnchor::TOP);
    add("panel", panel);
    
    // Hero::UI::Label* title = new Hero::UI::Label();
    // title->setAlligment(Hero::UI::Alligment::CENTER);
    // title->SetRelativeTransform(Hero::Int4(0, 0, 0, 50), 
    //     Hero::UI::HorizontalAnchor::STRETCH, Hero::UI::VerticalAnchor::TOP);
    // title->setFont((Hero::Font*)resources->Get(SID("Arial48")));
    // title->setText("Gepard");
    // title->apply();
    // add("Title", title);
}