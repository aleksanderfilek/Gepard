#include "GroundSelection.hpp"
#include "../Hero/Systems/Resources.hpp"
#include "../Hero/Core/Core.hpp"
#include "../Hero/Graphics/Mesh.hpp"
#include "../Hero/Graphics/Material.hpp"
#include "../Defaults.hpp"

GroundSelection::GroundSelection(const Hero::Sid& NewId)
 : Hero::Actor(NewId)
{

}

void GroundSelection::Start()
{
    Hero::Actor::Start();
    Hero::Resources* resources = Hero::Core::getSystem<Hero::Resources>(SID("Resources"));
    resources->Add(SID("S_GroundSelection"), PATH(assets/groundSelection/S_GroundSelection.he));
    resources->Add(SID("T_GroundSelection"), PATH(assets/groundSelection/T_GroundSelection.he));
    resources->Add(SID("M_GroundSelection"), PATH(assets/groundSelection/M_GroundSelection.he));
    resources->Add(SID("Plane1x1"), PATH(assets/basic/Plane1x1.he));

    staticMesh = new Hero::StaticMesh();
    staticMesh->SetMesh((Hero::Mesh*)resources->Get(SID("Plane1x1")));
    Hero::Material* material = (Hero::Material*)resources->Get(SID("M_GroundSelection"));
    staticMesh->SetMaterial(material);
    AddComponent(staticMesh);

}

void GroundSelection::Update()
{
    Hero::Actor::Update();
}

void GroundSelection::End()
{
    Hero::Actor::End();
}

Hero::Actor* GroundSelection::Clone()
{
  Hero::Actor* actor = new GroundSelection(GetName());
  //actor->SetTransform(actor->GetTransform());
  return actor;
}

void GroundSelection::SetVisibility(bool Visibile)
{
    staticMesh->SetVisibility(Visibile);
}