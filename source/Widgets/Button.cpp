#include "Button.hpp"

#include "../Hero/UserInterface/Canvas.hpp"
#include "../Hero/UserInterface/Image.hpp"
#include "../Hero/UserInterface/Label.hpp"

Hero::UI::IElement* CreateButton(const char* Text, Hero::Font* Font, Hero::Texture* BackgroundTexture)
{
  Hero::UI::Canvas* panel = new Hero::UI::Canvas();

  Hero::UI::Image* bckg = new Hero::UI::Image();
  bckg->SetRelativeTransform(Hero::Int4(0.0f, 0.0f, 0.0f, 0.0f), 
    Hero::UI::HorizontalAnchor::STRETCH, Hero::UI::VerticalAnchor::STRETCH);
  bckg->setTexture(BackgroundTexture);

  Hero::UI::Label* label = new Hero::UI::Label();
  label->SetRelativeTransform(Hero::Int4::zero(), 
    Hero::UI::HorizontalAnchor::CENTER, Hero::UI::VerticalAnchor::CENTER);
  label->setAlligment(Hero::UI::Alligment::CENTER);
  label->SetRelativeTransform(Hero::Int4::zero(), 
      Hero::UI::HorizontalAnchor::STRETCH, Hero::UI::VerticalAnchor::STRETCH);
  label->setFont(Font);
  label->setText(Text);
  label->apply();

  panel->add("bckg", bckg);
  panel->add("label", label);

  return panel;
} 