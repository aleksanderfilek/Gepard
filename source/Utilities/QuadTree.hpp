#pragma once

#include "../Hero/Core/Math.hpp"

#include <vector>

template<typename T>
class QuadTree
{
private:
Hero::Float4 rect;

std::vector<std::pair<Hero::Float4, QuadTree<T>*>> subTree;
std::vector<T*> children;

public:
  QuadTree(const Hero::Float4& Rect, float MinCellSize = 1.0f);
  ~QuadTree();

  void Add(T* Child, const Hero::Float4& Rect);
  void Remove(T* Child, const Hero::Float4& Rect);
  void Clear();

  void Get(const Hero::Float4& Rect, std::vector<T*>& OutChildren);
};

template<typename T>
QuadTree<T>::QuadTree(const Hero::Float4& Rect, float MinCellSize)
{
  rect = Rect;

  if(Rect.z <= MinCellSize || Rect.w <= MinCellSize)
  {
    return;
  }

  subTree.push_back({Hero::Float4(Rect.x, Rect.y, Rect.z / 2.0f, Rect.w / 2.0f) , nullptr});
  subTree.push_back({Hero::Float4(Rect.x + Rect.z / 2.0f, Rect.y, Rect.z / 2.0f, Rect.w / 2.0f) , nullptr});
  subTree.push_back({Hero::Float4(Rect.x, Rect.y + Rect.w / 2.0f, Rect.z / 2.0f, Rect.w / 2.0f) , nullptr});
  subTree.push_back({Hero::Float4(Rect.x + Rect.z / 2.0f, Rect.y + Rect.w / 2.0f, Rect.z / 2.0f, Rect.w / 2.0f) , nullptr});
}

template<typename T>
QuadTree<T>::~QuadTree()
{
  Clear();
}

template<typename T>
void QuadTree<T>::Add(T* Child, const Hero::Float4& Rect)
{
  for(auto& sub: subTree)
  {
    if(sub.first.Contains(Rect))
    {
      if(!sub.second)
      {
        sub.second = new QuadTree<T>(sub.first);
      }

      sub.second->Add(Child, Rect);
      return;
    }
  }

  children.push_back(Child);
}

template<typename T>
void QuadTree<T>::Remove(T* Child, const Hero::Float4& Rect)
{
}

template<typename T>
void QuadTree<T>::Clear()
{
  for(auto& sub: subTree)
  {
    if(sub.second)
    {
      delete sub.second;
    }
  }

  children.clear();
}

template<typename T>
void QuadTree<T>::Get(const Hero::Float4& Rect, std::vector<T*>& OutChildren)
{

}