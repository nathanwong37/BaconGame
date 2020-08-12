//Author: Nathan Wong
//Student Id:1151284
//Date: 2/4/2020
// Implementation of Graph.cpp
#include "Graph.h"
#include<iostream>
using namespace std;
//Constructor, takes no paremeters return nothing
//Pre: Nothing
//Post: Adj list is established
Graph::Graph()
{
   adjLists;
}
//Deconstructor, takes no paremeters return nothing
//Pre: Wordtree has been created
//Post: All dynamic memory is deleted.
Graph::~Graph()
{
   Delete();
}
//Adds actors from movie to adjlist
//Param: A movie that is set to add
//Pre: Movie is a valid obj with Actors
//Post: actors are created to nodes and added to adj list
//Return val: True once actors are added
//Function called: Find actor to help Node
bool Graph::addActors(set<Actor> co_Stars)
{
   //Finds where an actor is located
   for (auto const& i: co_Stars)
   {
      ActorNode* ptr = findActor(i);
      //actor could not be found
      if (ptr == nullptr)
      {
         ActorNode* actor = new ActorNode;
         actor->actor = i;
         adjLists.push_back(actor);
         ptr = actor;
      }
      //Connects the actors together
      for (auto const& j: co_Stars)
      {
         if (j == i)
         {
            continue;
         }
         ActorNode* tmp = findActor(j);
         //Actor could not be found
         if (tmp == nullptr)
         {
            ActorNode* act1 = new ActorNode;
            act1->actor = j;
            adjLists.push_back(act1);
            tmp = act1;
         }
         //puts the costar actor in the actors connected list
         ptr->coActor.insert(tmp);
      }
   }

   return true;
}
//Displays the list
//Parameter None
//PreConditions: adj list is filled
//Return Val: void
//Function called: Get Bacon Number to get Bacon number
void Graph::displayList()
{
   for (auto& i : adjLists)
   {
      cout << i->actor.getName();
      int baconNumber = this->findBaconNumber(i);
      if (baconNumber == -1)
      {
         cout << "\tInfinity";
      }
      else {
         cout << "\t" << baconNumber;
      }
      cout << endl;
   }
}
//Finds an actor
//Parameter: Actor obj
//Preconditions: Actor is not null
//Postcondition: Actor is found
//Return val: ActorNode*
//Function called: None
ActorNode* Graph::findActor(const Actor actor)const
{
   for (auto const& i : adjLists)
   {
      if (i->actor == actor)
      {
         return i;
      }
   }
   return nullptr;
}
//Gets the bacon number
//Parameter: ActorNode* 
//Precondition: ActorNode* is not nullptr;
//Postcondition: returns an int
//Return val: -1 if not found otherwise amount it is done
//Function called: Actor getName()
int Graph::findBaconNumber(ActorNode* actor) const
{
   //What to find
   string goal = "Bacon, Kevin (I)";
   int count = 0;
   queue<ActorNode*> toVisit;
   list<ActorNode*> visited;
   ActorNode dev;
   dev.actor.setName("");
   ActorNode* Devil = &dev;
   Devil->coActor;
   bool beenThere = false;
   toVisit.push(actor);
   toVisit.push(Devil);
   //While queue is not empty visit nodes connection
   while (!toVisit.empty())
   {
      ActorNode* tmp = toVisit.front();
      //Check if tmp has already been there
      for (auto& k : visited)
      {
         if (tmp->actor.getName() == k->actor.getName())
         {
            beenThere = true;
         }
      }
      //Just pop the visit
      if (beenThere)
      {
         beenThere = false;
         toVisit.pop();
         continue;
      }
      //Checks if name is kevin bacon
      if (tmp->actor.getName() == goal)
      {
         return count;
      }
      //Reached end of level
      if (tmp->actor.getName() == "")
      {
         count++;
         toVisit.pop();
         toVisit.push(tmp);
         if (toVisit.front()->actor.getName() == "")
         {
            break;
         }
         continue;
      }
      else
      {
         //Pushes the connections to the queue
         for (auto const& j : tmp->coActor)
         {
            toVisit.push(j);
         }
      }
      visited.push_back(tmp);
      toVisit.pop();
   }
   //Not found
   return -1;
}
//Deletes bacon list;
//Parameters: None
//Pre: None
//Post: AdjList is deleted
//ret val: True if deleted
bool Graph::Delete()
{
   for (auto& i : adjLists)
   {
      delete i;
      i = nullptr;
   }
   adjLists.resize(0);
   return true;
}
