#include "Game.hpp"
#include "../Hero/Systems/Window.hpp"

void Game::Load()
{

}

void Game::Start()
{
  Hero::Scene::Start();

}

void Game::Update()
{
  Hero::System::Window::clear();
  Hero::Scene::Update();
}

void Game::End()
{
  Hero::Scene::End();

}