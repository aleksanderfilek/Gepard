#include "StaticCamera.hpp"

#include"../Hero/Core/Core.hpp"
#include "../Hero/Systems/ActorScene/SceneSystem.hpp"
#include "../Hero/Systems/ActorScene/Scene.hpp"
#include "../Hero/Components/Camera.hpp"
#include "../Hero/Systems/Window.hpp"
#include "../Hero/Core/Events.hpp"

static event(CameraOnResize)
{
  Hero::SceneSystem* sceneSystem = Hero::Core::getSystem<Hero::SceneSystem>(SID("Scene"));
  Hero::Scene* scene = sceneSystem->GetCurrentScene();
  Hero::Camera* camera = (Hero::Camera*)((StaticCamera*)scene->GetActor(SID("Camera")))->GetComponent<Hero::Camera>();
  camera->SetSize(*(Hero::Int2*)args);
}

StaticCamera::StaticCamera(const Hero::Sid& NewId)
 : Hero::Actor(NewId)
{
  
}

void StaticCamera::Start()
{
  Hero::Actor::Start();
  Hero::System::Window* window = Hero::Core::getSystem<Hero::System::Window>(SID("Window"));
  window->setEvent(Hero::System::WindowEventType::RESIZED, CameraOnResize);

  Hero::Camera* camera = new Hero::Camera();
  camera->SetSize(window->getSize());
  camera->SetFov(70.0f);
  camera->SetNearFarPlane(0.1f, 1000.0f);
  AddComponent(camera);
}

Hero::Actor* StaticCamera::Clone()
{
  Hero::Actor* actor = new StaticCamera(GetName());
  //actor->SetTransform(actor->GetTransform());
  return actor;
}