#pragma once 

#include "../Hero/Systems/ActorScene/Actor.hpp"
#include "../Hero/Core/Sid.hpp"
#include "../Hero/Systems/Input.hpp"
#include "../Hero/Components/Camera.hpp"
#include "../Hero/Systems/Window.hpp"
#include "../Hero/Core/Events.hpp"

event(CameraOnResize);

class Player : public Hero::Actor
{
private:
  Hero::System::Input* input;
  Hero::System::Window* window;

  float rotY = 0.0f;
  Hero::Camera* camera;
  Hero::Matrix4x4 invProjectionMat;

  class Selector* selector = nullptr;

public:
  Player(const Hero::Sid& NewId);

  virtual void Start() override;
  virtual void Update() override;
  virtual void End() override;

  void LookAndMove();
  Hero::Float3 GetPointUnderCursor();

  Hero::Actor* Clone() override;

  Hero::Actor* cameraActor;
};