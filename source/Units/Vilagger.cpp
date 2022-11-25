#include "Villager.hpp"
#include "../Hero/Core/Core.hpp"
#include "../Hero/Systems/Resources.hpp"
#include "../Hero/Graphics/Mesh.hpp"
#include "../Hero/Graphics/Material.hpp"
#include "../Defaults.hpp"

Villager::Villager(const Hero::Sid& NewId) : Unit(NewId)
{
  
}

void Villager::Start()
{
  Hero::Resources* resources = Hero::Core::getSystem<Hero::Resources>(SID("Resources"));
  resources->Add(SID("T_Villager"), PATH(assets/units/villager/T_Villager.he));
  resources->Add(SID("Mat_Villager"), PATH(assets/units/villager/Mat_Villager.he));
  resources->Add(SID("M_Villager"), PATH(assets/units/villager/M_Villager.he));

  staticMesh = new Hero::StaticMesh();
  staticMesh->SetMesh((Hero::Mesh*)resources->Get(SID("M_Villager")));
  staticMesh->SetMaterial((Hero::Material*)resources->Get(SID("Mat_Villager")));
  AddComponent(staticMesh);

  Unit::Start();

  // MoveTo(Hero::Float2(0.5f, 0.5f));
}

void Villager::Update()
{
  Unit::Update();
}

void Villager::End()
{
  Unit::End();
}