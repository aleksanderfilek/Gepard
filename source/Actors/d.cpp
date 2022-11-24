// #include "Building.hpp"

// #include "../Hero/Systems/Resources.hpp"
// #include "../Hero/Core/Core.hpp"
// #include "../Hero/Graphics/Mesh.hpp"
// #include "../Hero/Graphics/Material.hpp"
// #include "../Defaults.hpp"
// #include"../Hero/Core/Time.hpp"
// #include "../Hero/Systems/ActorScene/Scene.hpp"

// Building::Building(const Hero::Sid& NewId)
//  : Hero::Actor(NewId)
// {

// }

// void Building::Start()
// {
//   Hero::Actor::Start();
//   Hero::Resources* resources = Hero::Core::getSystem<Hero::Resources>(SID("Resources"));
//   resources->Add(SID("S_SimpleTexture"), PATH(assets/S_SimpleTexture.he));
//   resources->Add(SID("T_ColorPalette"), PATH(assets/buildings/T_ColorPalette.he));
//   resources->Add(SID("M_Building"), PATH(assets/buildings/M_Building.he));
//   resources->Add(SID("Building"), PATH(assets/buildings/Building.he));

//   staticMesh = new Hero::StaticMesh();
//   staticMesh->SetMesh((Hero::Mesh*)resources->Get(SID("Building")));
//   staticMesh->SetMaterial((Hero::Material*)resources->Get(SID("M_Building")));
//   AddComponent(staticMesh);

//   GetTransformRef()->SetLocalPosition(Hero::Float3(4.0f, 0.0f, 4.0f));
//   GetTransformRef()->SetLocalScale(Hero::Float3(0.5f, 0.5f, 0.5f));
// }

// void Building::Update()
// {
//   Hero::Actor::Update();
// }

// void Building::End()
// {
//   Hero::Actor::End();
// }

// Hero::Actor* Building::Clone()
// {
//   Hero::Actor* actor = new Building(GetName());
//   //actor->SetTransform(actor->GetTransform());
//   return actor;
// }

// void Building::SetVisibility(bool Visibile)
// {
//   staticMesh->SetVisibility(Visibile);
// }