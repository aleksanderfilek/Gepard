#include "Warehouse.hpp"
#include "../Hero/Core/Core.hpp"
#include "../Hero/Systems/Resources.hpp"
#include "../Hero/Graphics/Mesh.hpp"
#include "../Hero/Graphics/Material.hpp"
#include "../Defaults.hpp"

void Warehouse::Start()
{
  Hero::Resources* resources = Hero::Core::getSystem<Hero::Resources>(SID("Resources"));
  resources->Add(SID("Mat_WoodcutterHut"), PATH(assets/buildings/Warehouse/Mat_WoodcutterHut.he));
  resources->Add(SID("M_Warehouse"), PATH(assets/buildings/Warehouse/M_Warehouse.he));

  staticMesh = new Hero::StaticMesh();
  staticMesh->SetMesh((Hero::Mesh*)resources->Get(SID("M_Warehouse")));
  staticMesh->SetMaterial((Hero::Material*)resources->Get(SID("Mat_WoodcutterHut")));
  AddComponent(staticMesh);

  GetTransformRef()->SetLocalPosition(Hero::Float3(2.0f, 0.0f, 4.0f));

  size = Hero::Int2(2, 2);

  Building::Start();
}

void Warehouse::Update()
{
  Building::Update();

}

void Warehouse::End()
{
  Building::End();

}