//Author: Nathan Wong
//Student Id:1151284
//Date: 2/4/2020
// Implementation of Actor.h
#include "Actor.h"
//Cstr, takes no param and returns nothing
//Pre:Nothing
//Post: name is set to "";
Actor::Actor()
{
   Name = "";
}
//Dstr, takes no params and returns nothing
//Pre: Nothing
//Post: deconstructs actor obj
Actor::~Actor()
{
}

//Sets name of actor
//Param: String with name
//Pre: name is not empty or null
//Post: name is set
//return val: True if name is set, false if it is not
bool Actor::setName(string name)
{
   if (name != "")
   {
      this->Name = name;
      return true;
   }
   return false;
}

//Gets name of actor
//Pre: Name is not null
//Post: name is returned
//return val: string with name.
string Actor::getName() const
{
   return Name;
}
//Overlaods equal operator
//Param: Actor&
//Pre: Actor obj exists
//Post: compares the two names
//Return val: True if they same, false if diff
bool Actor::operator==(const Actor& other) const
{
   if (this->Name == other.getName())
   {
      return true;
   }
   return false;
}

//Operator < operator
//Param: Actor&
//Pre: Actor obj exists
//Post: compares if its less then
//Return val: true if <
bool Actor::operator<(const Actor& a1) const
{
   if (this->Name < a1.Name)
   {
      return true;
   }
   return false;
}
