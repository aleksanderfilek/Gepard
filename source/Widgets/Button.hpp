#pragma once

#include "../Hero/UserInterface/IElement.hpp"
#include "../Hero/Graphics/Texture.hpp"
#include "../Hero/Graphics/Font.hpp"

Hero::UI::IElement* CreateButton(const char* Text, Hero::Font* Font, Hero::Texture* BackgroundTexture);