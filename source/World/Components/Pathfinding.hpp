#pragma once

#include "../../Hero/Systems/ActorScene/ActorComponent.hpp"
#include "../../Hero/Core/Math.hpp"

struct NavNode
{
  Hero::Int2 position;
  float hCost = 0.0f;
  float gCost = 0.0f;
  NavNode* parent = nullptr;
  float GetFCost() { return gCost + hCost; }
};

class Pathfinding/* : public Hero::ActorComponent*/
{
private:
  bool* walkableArea;
  uint32_t height;
  uint32_t width;

  int CoordToIndex(const Hero::Int2& Point);
  float CalculatehCost(const Hero::Int2 A, Hero::Int2 B);
  bool IsValidCoord(const Hero::Int2& Point);
  Hero::Int2 WorldToArea(const Hero::Float2& Point);
  
public:
  Pathfinding(uint32_t Height, uint32_t Width);
  ~Pathfinding();

  SetWalkableState(Hero::Float2 Position, Hero::Float2 Size, bool Walkable);
  bool GetPathToPoint(Hero::Float2 StartPoint, Hero::Float2 DestinationPoint, Hero::Float2*& Path, uint32_t& PathLenght);
};