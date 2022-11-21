#include "Pathfinding.hpp"
#include <string.h>
#include <unordered_set>
#include <vector>
#include <iostream>

Pathfinding::Pathfinding(uint32_t Height, uint32_t Width)
{
  height = Height;
  width = Width;
  walkableArea = new bool[height * width];
  memset(walkableArea, true, height * width);
}

Pathfinding::~Pathfinding()
{
  delete[] walkableArea;
}

Pathfinding::SetWalkableState(Hero::Float2 Position, Hero::Float2 Size, bool Walkable)
{
  Hero::Int2 position = WorldToArea(Position);
  for(int y = position.y; y < position.y + (int)Size.y; y++)
  {
    for(int x = position.x; x < position.x + (int)Size.x; x++)
    {
      walkableArea[CoordToIndex({x, y})] = Walkable;
    }
  }
}

int Pathfinding::CoordToIndex(const Hero::Int2& Point)
{
  return Point.x + Point.y * width;
}

float Pathfinding::CalculatehCost(const Hero::Int2 A, Hero::Int2 B)
{
  return sqrtf(powf(A.x - B.x, 2) + powf(A.y - B.y, 2));
}

bool Pathfinding::IsValidCoord(const Hero::Int2& Point)
{
  return Point.x >= 0 && Point.y >= 0 && Point.x < width && Point.y < height;
}

Hero::Int2 Pathfinding::WorldToArea(const Hero::Float2& Point)
{
  return { (int)floor(Point.x), (int)floor(Point.y) };
}

bool Pathfinding::GetPathToPoint(Hero::Float2 StartPoint, Hero::Float2 DestinationPoint, Hero::Float2*& Path, uint32_t& PathLenght)
{
  NavNode startNode = { WorldToArea(StartPoint), CalculatehCost(WorldToArea(StartPoint), WorldToArea(DestinationPoint)) };
  NavNode destinationNode = { WorldToArea(DestinationPoint) };

  std::vector<NavNode*> openList;
  std::vector<NavNode*> closeList;
  std::vector<NavNode> nodes;

  nodes.push_back(startNode);
  openList.push_back(&nodes[0]);

  while(openList.size() > 0)
  {
    int nodeWithLowestFCostIndex = 0;
    for(int i = 1; i < openList.size(); i++)
    {
      if(openList[nodeWithLowestFCostIndex]->GetFCost() > openList[i]->GetFCost())
      {
        nodeWithLowestFCostIndex = i;
      }
    }

    NavNode* currentNode = openList[nodeWithLowestFCostIndex];
        closeList.push_back(openList[nodeWithLowestFCostIndex]);
    openList.erase(openList.begin() + nodeWithLowestFCostIndex);
    if(currentNode->position == destinationNode.position)
    {
      break;
    }

    for(int y = -1; y <= 1; y++)
    {
      for(int x = -1; x <= 1; x++)
      {
        if(y == 0 && x == 0)
        {
          continue;
        }

        Hero::Int2 coord = currentNode->position + (Hero::Int2){ x, y };

        if(!IsValidCoord(coord) || !walkableArea[CoordToIndex(coord)])
        {
          continue;
        }

        float cost = currentNode->gCost + CalculatehCost(currentNode->position, coord);
        NavNode neighbourNode = {coord, CalculatehCost(coord, destinationNode.position), cost, currentNode};

        bool skip = false;
        bool closeContains = false;
        for(int i = 0; i < closeList.size(); i++)
        {
          if(closeList[i]->position == coord)
          {
            closeContains = true;

            if(closeList[i]->GetFCost() <= neighbourNode.GetFCost())
            {
              skip = true;
              break;
            }

            closeList.erase(closeList.begin() + i);
            break;
          }
        }

        if(skip)
        {
          continue;
        }

        if(!closeContains)
        {
          bool openContains = false;
          for(int i = 0; i < openList.size(); i++)
          {
            if(openList[i]->position == coord)
            {
              openContains = true;

              if(openList[i]->GetFCost() <= neighbourNode.GetFCost())
              {
                skip = true;
                break;
              }

              openList.erase(openList.begin() + i);
              break;
            }

            if(skip)
            {
              continue;
            }
          }
        }
        
        bool openContains = false;
        for(int i = 0; i < openList.size(); i++)
        {
          if(openList[i]->position == coord)
          {
            openContains = true;
            break;
          }
        }
        if(!openContains)
        {
          nodes.push_back(neighbourNode);
          openList.push_back(&nodes[nodes.size()-1]);
        }
      }
    }
  }

  if(closeList[closeList.size()-1]->position != destinationNode.position)
  {
    return false;
  }

  for(auto point: closeList)
  {
    std::cout<<point->position;
    if(point->parent)
    std::cout<<" -> "<<point->parent->position<<std::endl;
    else
    std::cout<<std::endl;
  }

  std::vector<Hero::Int2> reversedPath;

  NavNode* currentNode = closeList[closeList.size()-1];
  while(currentNode->parent)
  {
    reversedPath.push_back(currentNode->position);
    currentNode = currentNode->parent;
  }
  reversedPath.push_back(closeList[0]->position);

  Path = new Hero::Float2[reversedPath.size()];
  PathLenght = reversedPath.size();

  int i = 0;
  for(auto point: reversedPath)
  {
    Path[PathLenght - i - 1] = { (float)point.x + 0.5f, (float)point.y + 0.5f};
    i++;
  }

  return true;
}