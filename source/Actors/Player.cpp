#include "Player.hpp"

#include"../Hero/Core/Core.hpp"
#include"../Hero/ThirdParty/SDL2/SDL.h"
#include"../Hero/Core/Time.hpp"
#include "Selector.hpp"
#include "../Hero/Systems/ActorScene/SceneSystem.hpp"
#include "../Hero/Systems/ActorScene/Scene.hpp"
#include<iostream>
#include<cmath>

#define SPEED 40.0f
#define TURNSPEED 40.0f

static event(CameraOnResize)
{
  Hero::SceneSystem* sceneSystem = Hero::Core::getSystem<Hero::SceneSystem>(SID("Scene"));
  Hero::Scene* scene = sceneSystem->GetCurrentScene();
  Hero::Camera* camera = (Hero::Camera*)((Player*)scene->GetActor(SID("Player")))->cameraActor->GetComponent<Hero::Camera>();
  camera->SetSize(*(Hero::Int2*)args);
}

Player::Player(const Hero::Sid& NewId)
 : Hero::Actor(NewId)
{
  input = Hero::Core::getSystem<Hero::System::Input>(SID("Input"));
}

void Player::Start()
{
  Hero::Actor::Start();

  window = Hero::Core::getSystem<Hero::System::Window>(SID("Window"));
  window->setEvent(Hero::System::WindowEventType::RESIZED, CameraOnResize);

  cameraActor = new Hero::Actor(SID("Camera"));
  camera = new Hero::Camera();
  camera->SetSize(window->getSize());
  camera->SetFov(70.0f);
  camera->SetNearFarPlane(0.1f, 1000.0f);
  cameraActor->AddComponent(camera);
  cameraActor->GetTransformRef()->SetLocalRotation(Hero::Quaternion(0.0f, Hero::deg2rad(30.0f), 0.0f));
  cameraActor->GetTransformRef()->SetLocalPosition(Hero::Float3(0.0f, 10.0f, -10.0f));
  AddChild(cameraActor);

  invProjectionMat = camera->GetProjectionMatrix().inverted();

  selector = new Selector(SID("Selector"));
  GetScene()->AddActor(selector);
  selector->SetVisibility(false);
}

void Player::Update()
{
  Hero::Actor::Update();

  LookAndMove();

  Hero::Float3 point = GetPointUnderCursor();
  point = {floorf(point.x) + 0.5f,floorf(point.y),floorf(point.z) + 0.5f};
  selector->GetTransformRef()->SetLocalPosition(point);
}

void Player::End()
{
  Hero::Actor::End();
}

void Player::LookAndMove()
{
  if(input->keyPressed(Hero::System::Input::KeyCode::Q))
  {
    rotY += TURNSPEED * Hero::Time::getDeltaTime();
  }
  else if(input->keyPressed(Hero::System::Input::KeyCode::E))
  {
    rotY -= TURNSPEED * Hero::Time::getDeltaTime();
  }

  GetTransformRef()->SetLocalRotation(Hero::Quaternion(Hero::deg2rad(rotY), 0.0f, 0.0f));

  Hero::Float3 forward = GetTransformRef()->GetLocalRotation().GetForwardVector();
  forward.y = 0.0f;
  forward.normalize();
  Hero::Float3 right = GetTransformRef()->GetLocalRotation().GetRightVector();
  Hero::Float3 up = GetTransformRef()->GetLocalRotation().GetUpVector();

  Hero::Float3 newPosition = GetTransformRef()->GetLocalPosition();

  if(input->keyPressed(Hero::System::Input::KeyCode::W))
  {
    newPosition += forward * SPEED * Hero::Time::getDeltaTime();
  }
  else if(input->keyPressed(Hero::System::Input::KeyCode::S))
  {
    newPosition -= forward * SPEED * Hero::Time::getDeltaTime();
  }

  if(input->keyPressed(Hero::System::Input::KeyCode::A))
  {
    newPosition -= right * SPEED * Hero::Time::getDeltaTime();
  }
  else if(input->keyPressed(Hero::System::Input::KeyCode::D))
  {
    newPosition += right * SPEED * Hero::Time::getDeltaTime();    
  }

  GetTransformRef()->SetLocalPosition(newPosition);
}

Hero::Float3 Player::GetPointUnderCursor()
{
  Hero::Matrix4x4 invViewMat = camera->GetViewMatrix().inverted();

  Hero::Int2 mousePosition = input->getMousePosition();

  Hero::Int2 windowSize = window->getSize();

  Hero::Float4 screenCoord(
    (2.0f * (float)mousePosition.x / windowSize.x) - 1.0f, 
    1.0f - (2.0f * (float)mousePosition.y / windowSize.y), 
    1.0f, 1.0f);

  Hero::Float4 worldPos = invViewMat * invProjectionMat * screenCoord;

  Hero::Float3 cameraPosition = cameraActor->GetTransformRef()->GetWorldPosition();
  Hero::Float3 dir = Hero::Float3(worldPos);
  dir.normalize();

  float x = cameraPosition.x - ((cameraPosition.y * dir.x)/dir.y);
  float z = cameraPosition.z - ((cameraPosition.y * dir.z)/dir.y);
  Hero::Float3 groundPoint(x, 0.0f, z);

  return groundPoint;
}

Hero::Actor* Player::Clone()
{
  Hero::Actor* actor = new Player(GetName());
  //actor->SetTransform(actor->GetTransform());
  return actor;
}