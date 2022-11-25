#include "Selector.hpp"
#include "../Hero/Systems/Resources.hpp"
#include "../Hero/Core/Core.hpp"
#include "../Hero/Graphics/Mesh.hpp"
#include "../Hero/Graphics/Material.hpp"
#include "../Defaults.hpp"

Selector::Selector(const Hero::Sid& NewId)
 : Hero::Actor(NewId)
{

}

void Selector::Start()
{
    Hero::Actor::Start();
    
    Hero::Resources* resources = Hero::Core::getSystem<Hero::Resources>(SID("Resources"));
    resources->Add(SID("T_Selector"), PATH(assets/selector/T_Selector.he));
    resources->Add(SID("Mat_Selector"), PATH(assets/selector/Mat_Selector.he));
    resources->Add(SID("Plane1x1"), PATH(assets/basic/Plane1x1.he));

    staticMesh = new Hero::StaticMesh();
    staticMesh->SetMesh((Hero::Mesh*)resources->Get(SID("Plane1x1")));
    staticMesh->SetMaterial((Hero::Material*)resources->Get(SID("Mat_Selector")));
    AddComponent(staticMesh);
}

void Selector::Update()
{
    Hero::Actor::Update();
}

void Selector::End()
{
    Hero::Actor::End();
}

Hero::Actor* Selector::Clone()
{
  Hero::Actor* actor = new Selector(GetName());
  //actor->SetTransform(actor->GetTransform());
  return actor;
}

void Selector::SetVisibility(bool Visibile)
{
    staticMesh->SetVisibility(Visibile);
}