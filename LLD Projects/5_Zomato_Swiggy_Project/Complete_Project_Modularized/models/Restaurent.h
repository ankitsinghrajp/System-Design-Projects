#ifndef RESTAURENT_H
#define RESTAURENT_H

#include<iostream>
#include<string>
#include<vector>
#include "MenuItem.h"
using namespace std;


class Restaurent {
    private: 
      static int nextRestaurentId;
      int restaurentId;
      string name;
      string location;
      vector<MenuItem> menu;

      Restaurent(string name, string location){
            this->name = name;
            this->location = location;
            this->restaurentId = ++nextRestaurentId;
      }

      public: 
       ~Restaurent(){
        cout<<"Destroying restaurent..."<<name<<" and clearing its menu."<<endl;
        menu.clear();
       }

       string getName() const{
        return name;
       }

       void setName(const string &n) {
            name = n;
       }

       string getLocation() const{
            return location;
       }

       void setLocation(const string &loc){
            location = loc;
       }

       void addMenuItem(const MenuItem & item){
            menu.push_back(item);
       }

       const vector<MenuItem> & getMenu() const{
            return menu;
       }
};

int Restaurent::nextRestaurentId = 0;

#endif // RESTAURENT.H