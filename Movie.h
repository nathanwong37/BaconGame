#pragma once
#include<string>
#include<vector>
//Author: Nathan Wong
//Student Id:1151284
//Date: 2/4/2020
// Dates and Methods for Movie class
#include"Actor.h"
using namespace std;
class Movie
{
   //public method
public:
   //cstrs and dstrs
   Movie();
   ~Movie();
   //setter getter and verb methods
   bool setTitleName(string title);
   bool addActor(Actor actor);
   string getTitle()const;
   vector<Actor> getActors() const;
private:
   //private data
   string title;
   vector<Actor> actors;
};
//#include "Movie.cpp"

