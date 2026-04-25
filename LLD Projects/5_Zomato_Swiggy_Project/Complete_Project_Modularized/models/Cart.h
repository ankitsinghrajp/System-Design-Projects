#ifndef CART_H
#define CART_H

#include<iostream>
#include<vector>
#include<Restaurent.h>
#include<MenuItem.h>

using namespace std;

class Cart{
    private:
      Restaurent* restaurent;
      vector<MenuItem> items;
      
    public:
     Cart(){
        restaurent = nullptr;
     }

     void addItem(const MenuItem & item){
        if(!restaurent){
            // cerr is used for error printing like cout
            // cout is used for normal output

            cerr<<"Cart: Set a restaurent before adding items."<<endl;
            return;
        }

        items.push_back(item);
     }

     double getTotalCost() const{
        double sum = 0;
        for(const auto & it: items){
            sum += it.getPrice();
        }
        return sum;
     }

     bool isEmpty(){
        return (!restaurent || items.empty());
     }

     void clear(){
        items.clear();
        restaurent = nullptr;
     }

     // Getters & setters
     
     void setRestaurent(Restaurent * r){
        restaurent = r;
     }

     Restaurent* getRestaurent() const{
        return restaurent;
     }

     const vector<MenuItem> &getItem() const{
        return items;
     }

     
};

#endif // !CART_H