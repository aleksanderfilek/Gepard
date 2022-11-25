#include "WoodcutterHut.hpp"
#include "../Hero/Core/Core.hpp"
#include "../Hero/Systems/Resources.hpp"
#include "../Hero/Graphics/Mesh.hpp"
#include "../Hero/Graphics/Material.hpp"
#include "../Defaults.hpp"

void WoodcutterHut::Start()
{
  Hero::Resources* resources = Hero::Core::getSystem<Hero::Resources>(SID("Resources"));
  resources->Add(SID("Mat_WoodcutterHut"), PATH(assets/buildings/woodcutterhut/Mat_WoodcutterHut.he));
  resources->Add(SID("M_WoodcutterHut"), PATH(assets/buildings/woodcutterhut/M_WoodcutterHut.he));

  staticMesh = new Hero::StaticMesh();
  staticMesh->SetMesh((Hero::Mesh*)resources->Get(SID("M_WoodcutterHut")));
  staticMesh->SetMaterial((Hero::Material*)resources->Get(SID("Mat_WoodcutterHut")));
  AddComponent(staticMesh);

  GetTransformRef()->SetLocalPosition(Hero::Float3(4.0f, 0.0f, 4.0f));

  size = Hero::Int2(2, 2);

  Building::Start();
}

void WoodcutterHut::Update()
{
  Building::Update();

}

void WoodcutterHut::End()
{
  Building::End();

}