#include"Tree.hpp"
#include "../Hero/Core/Core.hpp"
#include "../Hero/Systems/Resources.hpp"
#include "../Hero/Graphics/Mesh.hpp"
#include "../Hero/Graphics/Material.hpp"
#include "../Defaults.hpp"

Tree::Tree(const Hero::Sid& NewId) : WorldObject(NewId)
{
  
}

void Tree::Start()
{
  Hero::Resources* resources = Hero::Core::getSystem<Hero::Resources>(SID("Resources"));
  resources->Add(SID("Mat_WoodcutterHut"), PATH(assets/buildings/woodcutterhut/Mat_WoodcutterHut.he));
  resources->Add(SID("M_Tree"), PATH(assets/worldobjects/M_Tree01.he));

  staticMesh = new Hero::StaticMesh();
  staticMesh->SetMesh((Hero::Mesh*)resources->Get(SID("M_Tree")));
  staticMesh->SetMaterial((Hero::Material*)resources->Get(SID("Mat_WoodcutterHut")));
  AddComponent(staticMesh);

  GetTransformRef()->SetLocalPosition(Hero::Float3(1.0f, 0.0f, 0.0f));

  WorldObject::Start();
}

Hero::Actor* Tree::Clone()
{
  Hero::Actor* actor = new Tree(GetName());
  //actor->SetTransform(actor->GetTransform());
  return actor;
}