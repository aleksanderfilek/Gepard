#include<iostream>

#include"Hero/Core/Core.hpp"
#include"Hero/Systems/Window.hpp"
#include"Hero/Systems/Event.hpp"
#include"Hero/Systems/Input.hpp"
#include"Hero/Systems/ActorScene/SceneSystem.hpp"
#include"Hero/Systems/UserInterface.hpp"
#include"Hero/Systems/Resources.hpp"
#include"Hero/Systems/Profiler.hpp"

#include"Levels/MainMenu.hpp"

Hero::Core* core;

event(close)
{
  Hero::Core::close();
}

int WinMain(int argc, char* argv[])
{
  core = new Hero::Core();

  core->addSystem(new Hero::System::Window(SID("Window"), "Gepard", 1280, 720, SDL_WINDOW_RESIZABLE));
  core->addSystem(new Hero::System::Event(SID("Event")));
  core->addSystem(new Hero::System::Input(SID("Input")));
  core->addSystem(new Hero::SceneSystem(SID("Scene"), new MainMenu()));
  core->addSystem(new Hero::System::UserInterface(SID("Ui"),SID("Window"),SID("Input")));
  core->addSystem(new Hero::Resources(SID("Resources")));
  core->addSystem(new Hero::System::Profiler(SID("Profiler")));

  Hero::System::Event* event = core->getSystem<Hero::System::Event>(SID("Event"));
  Hero::System::Window* window = core->getSystem<Hero::System::Window>(SID("Window"));
  window->setEvent(Hero::System::WindowEventType::CLOSE, close);
  event->addWindow(window);

  Hero::System::UserInterface* ui = core->getSystem<Hero::System::UserInterface>(SID("Ui"));
  window->setEvent(Hero::System::WindowEventType::RESIZED, Hero::System::OnResize);

  core->start();

  delete core;

  return 0;
}