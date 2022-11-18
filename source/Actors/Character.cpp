#include "Character.hpp"

#include "../Hero/Systems/Resources.hpp"
#include "../Hero/Core/Core.hpp"
#include "../Hero/Graphics/Mesh.hpp"
#include "../Hero/Graphics/Material.hpp"
#include "../Defaults.hpp"
#include"../Hero/Core/Time.hpp"
#include "../Hero/Systems/ActorScene/Scene.hpp"

Character::Character(const Hero::Sid& NewId)
 : Hero::Actor(NewId)
{

}

void Character::Start()
{
  Hero::Actor::Start();
  Hero::Resources* resources = Hero::Core::getSystem<Hero::Resources>(SID("Resources"));
  resources->Add(SID("S_Billboard"), PATH(assets/S_Billboard.he));
  resources->Add(SID("T_Man01"), PATH(assets/characters/T_Man01.he));
  resources->Add(SID("M_Man01"), PATH(assets/characters/M_Man01.he));
  resources->Add(SID("Character"), PATH(assets/characters/Character.he));

  staticMesh = new Hero::StaticMesh();
  staticMesh->SetMesh((Hero::Mesh*)resources->Get(SID("Character")));
  staticMesh->SetMaterial((Hero::Material*)resources->Get(SID("M_Man01")));
  AddComponent(staticMesh);

  camera = GetScene()->GetActor(SID("Camera"));

  GetTransformRef()->SetLocalPosition(Hero::Float3(0.5f, 0.0f, 0.5f));
  GetTransformRef()->SetLocalRotation(Hero::Quaternion(Hero::deg2rad(90.0f), Hero::deg2rad(0.0f), Hero::deg2rad(0.0f)));
}

void Character::Update()
{
  Hero::Actor::Update();
/*
  Hero::Float3 cameraProjection = camera->GetTransformRef()->GetWorldPosition();
  cameraProjection.y = 0.0f;

  Hero::Float3 currentPosition = GetTransformRef()->GetWorldPosition();

  Hero::Float3 dir = cameraProjection - currentPosition;
  dir.normalize();

  float angle = acosf(Hero::dotProduct(Hero::Float3::forward(), dir));

  if(cameraProjection.x < 0.0f)
   angle *= -1.0f;

  Hero::Quaternion rotation(angle - 90.0f, Hero::Float3::up());
  GetTransformRef()->SetLocalRotation(rotation);
*/
}

void Character::End()
{
  Hero::Actor::End();
}

Hero::Actor* Character::Clone()
{
  Hero::Actor* actor = new Character(GetName());
  //actor->SetTransform(actor->GetTransform());
  return actor;
}

void Character::SetVisibility(bool Visibile)
{
  staticMesh->SetVisibility(Visibile);
}