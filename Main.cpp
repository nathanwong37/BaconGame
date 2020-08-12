//Author: Nathan Wong
//Student Id:1151284
//Date: 2/4/2020
// Driver for Main, takes in a file with movies and actors. Then the actors are stored in a graph.
//The graph then does a breadth first search to locate the bacon number
//If bacon number is found prints out actor and bacon number
//Else prints out actor and infinity.
#include"Graph.h"
//#include"Movie.h"
#include"Actor.h"
#include<iostream>
#include<fstream>
#include<sstream>
#include<map>
#include<iterator>
using namespace std;
//Methods
bool isActor(const string line);
string parseTitle(string line);
//Main driver
//Parameters: Takes in arguments from command line
//Pre: Text file is in valid format
//Post: Prints out all actors bacon number
//Methods used: isActor, isIn, parseTitle,Infile.open,getline(), add actors, dispalyList.
//Return val: 0 if succesful
int main(int argc, char* argv[])
{
   //Gets file name
   string fileName = string(argv[1]);
   ifstream inFile;
   inFile.open(fileName);
   string line;
   Actor actor;
   map<string, set<Actor>> movieMap;
   //Opens file
   if (inFile.is_open())
   {
      while (!inFile.eof())
      {
         getline(inFile, line);
         //Line is empty
         if (line.length() == 0)
         {
            continue;
         }
         if (!line.empty())
         {
            //Checks if line contains an actor
            if (isActor(line))
            {
               //parses actor
               stringstream ss(line);
               string name;
               getline(ss, name, '\t');
               line = line.substr(name.size(), line.size());
               actor.setName(name);
            }
            //Gets title from line
            string title = parseTitle(line);
            //cout << title << endl;
            if (movieMap.count(title) != 1)
            {
               set<Actor> actorSet;
               actorSet.insert(actor);
               movieMap.insert({ title, actorSet });
            }
            else
            {
               set <Actor> actorSet = movieMap[title];
               actorSet.insert(actor);
               movieMap.at(title) = actorSet;
            }
         }
      }
   }
   else {
      cerr << "Error File not opened" << endl;
   }
   Graph graph1;
   map<string,set<Actor>>::iterator it = movieMap.begin();
   while (it != movieMap.end())
   {
      graph1.addActors(it->second);
      it++;
   }
   graph1.displayList();

   return 0;
}
//checks if a line is an actor line
//Parameter: string line
//pre: line is valid
//Post: line is either deemd good or not good
//REt Val: True or false depending on its validity
bool isActor(const string line)
{
   if (line[0] == 9)
   {
      return false;
   }
   return true;
}
//Parses a line to get title
//Parameter: line
//Pre: line is valid
//Post: returns a line that has the title
//Ret Val: string
string parseTitle(string line)
{
   while (line[0] == 9)
   {
      line = line.substr(1, line.size());
   }
   stringstream s3(line);
   string title;
   char c;
   bool paranth = false;
   //Read char by char
   while (s3.get(c))
   {
      //If its in a paranth and there are numbers after
      if ((c < 57 && c>48) && paranth)
      {
         paranth = false;
      }
      //If C is not valid delete and break
      if (c == '{' || c == '<' || c == '[' || (paranth && (c > 57 || c < 48)))
      {
         title = title.substr(0, title.size() - 1);
         break;
      }
      //Indicates paranth
      if (c == '(')
      {
         //Adds characters
         paranth = true;
      }
      title = title + c;
   }
   //Needs to delete one more if paranthesis
   if (paranth)
   {
      title = title.substr(0, title.size() - 1);
   }
   //returns the title.
   return title;
}
