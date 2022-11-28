#pragma once

#include "../Hero/Core/Sid.hpp"

#include <string>
#include <unordered_map>
#include <vector>
#include <sstream>
#include <fstream>
#include <iostream>

struct TableRow
{
  virtual void Serialize(std::vector<std::string>& Out) = 0;
  virtual void Deserialize(const std::vector<std::string>& In) = 0;
};

template<typename T>
class DataTable
{
private:
  std::unordered_map<Hero::Sid, T, Hero::SidHashFunction> data;         

public:
  DataTable(const std::string& Path);
  ~DataTable();

  int GetRowNames(std::vector<Hero::Sid>& Names);
  T* GetRow(const Hero::Sid& Id);
};

template<typename T>
DataTable<T>::DataTable(const std::string& Path)
{
  std::stringstream content;

  std::ifstream input(Path);

  if(!input.is_open())
  {
    std::cout<<"Could not load data table file, path: "<<Path<<std::endl;
    return;
  }

  content << input.rdbuf();
  input.close();

  while(!content.eof())
  {
    std::string line;
    getline(content, line, '\n');

    std::stringstream lineStream(line);
    int argNum = 0;

    Hero::Sid rowName;
    std::vector<std::string> args;
    T rowData;

    while(!lineStream.eof())
    {
      std::string arg;
      getline(lineStream, arg, ',');

      if(argNum == 0)
      {
        rowName = SID(arg.c_str());
        argNum++;
        continue;
      }

      args.push_back(arg);
      argNum++;
    }

    rowData.Deserialize(args);
    data.insert({rowName, rowData});
  }
}

template<typename T>
DataTable<T>::~DataTable()
{

}

template<typename T>
int DataTable<T>::GetRowNames(std::vector<Hero::Sid>& Names)
{
  int num = 0;

  std::vector<Hero::Sid> names;
  for(auto row: data)
  {
    std::cout<<row.first.id<<std::endl;
    names.push_back(row.first);
    num++;
  }

  Names = names;
  return num;
}

template<typename T>
T* DataTable<T>::GetRow(const Hero::Sid& Id)
{
  auto result = data.find(Id);
  if(result == data.end())
  {
    return nullptr;
  }

  return &result->second;
}