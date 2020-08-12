//Author: Nathan Wong
//Student Id:1151284
//Date: 2/4/2020
// Actor.h contains all files and methods for Actor Obj
#pragma once
#include<string>
using namespace std;
class Actor
{
   //public methods
public:
   //cstrs and dcstrs
   Actor();
   ~Actor();
   //setter and getter
   bool setName(string name);
   string getName() const;
   //operator overload
   bool operator == (const Actor& other) const;
   bool operator < (const Actor& a1) const;

private:
   //private variable
   string Name;
};
#include "Actor.cpp"

