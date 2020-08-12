//Author: Nathan Wong
//Student Id:1151284
//Date: 2/4/2020
//Graph.h file contains all methods and headers
//Functions include add actors, dispaly Lists
//get bacon number and find actor

#pragma once
#include"Actor.h"
#include<list>
#include<set>
#include<queue>
#include<algorithm>
using namespace std;
//Node Struct
struct ActorNode
{
   Actor actor;
   set<ActorNode*> coActor;
};
class Graph
{
   //public methods
public:
   //constructors
   Graph();
   ~Graph();
   //action verbs
   bool addActors(set<Actor>co_Stars);
   void displayList();
   //private methods
private:
   //Helper functions
   ActorNode* findActor(const Actor actor)const;
   int findBaconNumber(ActorNode* actor) const;
   bool Delete();
   // data member
   list<ActorNode*> adjLists;
};
#include "Graph.cpp"
