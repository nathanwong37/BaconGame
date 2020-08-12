//Author: Nathan Wong
//Student Id:1151284
//Date: 2/4/2020
// Implementation of Movie.h
#include "Movie.h"

//cstr for Movie, no param or return value
//Pre: None
//Post: title is set, actors is initialized.
Movie::Movie()
{
   string title = "";
   actors;
}
//Destructor for movie, no param or return value
//Pre: None
//Post: Movie is destructed
Movie::~Movie()
{
}

//Sets title Name
//Parameters: string title
//Pre: title is not null or empty
//Post: title is set to string
//Ret Val: True if set 
bool Movie::setTitleName(string title)
{
   this->title = title;
   return true;
}
//Adds actor to vector
//Parameters: Actor obj
//Pre: Actor obj is created
//Post: IF not duplicated actor obj added to vector
//ret val: True if added
bool Movie::addActor(Actor actor)
{
   //Checks if duplicated
   for (auto const& i : actors)
   {
      if (i.getName() == actor.getName())
      {
         return false;
      }
   }
   actors.push_back(actor);
   return true;
}
//gets title of movie
//Parameter: none
//Pre: title is not null
//Post: title is returned
//ret value: string of title
string Movie::getTitle() const
{
   return title;
}
//gets actors
//Parameters: none
//pre: vector is not empty
//post: vector is returned
//ret value: vector
vector<Actor> Movie::getActors() const
{
   return actors;
}
