#pragma once 

#include "../Hero/Systems/ActorScene/Actor.hpp"
#include "../Hero/Core/Sid.hpp"
#include "../Hero/Systems/Input.hpp"
#include "../Hero/Components/Camera.hpp"

class Player : public Hero::Actor
{
private:
  Hero::System::Input* input;
  
  float rotY = 0.0f;
  Hero::Camera* camera;
  Actor* cameraActor;
  Hero::Matrix4x4 invProjectionMat;

  class GroundSelection* selection = nullptr;

public:
  Player(const Hero::Sid& NewId);

  virtual void Start() override;
  virtual void Update() override;
  virtual void End() override;

  void LookAndMove();
  Hero::Float3 GetPointUnderCursor();

  Hero::Actor* Clone() override;
};