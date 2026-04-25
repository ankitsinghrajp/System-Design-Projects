#ifndef ORDER_H
#define ORDER_H

#include<iostream>
#include<string>
#include<vector>
#include<User.h>
#include<Restaurent.h>
#include<MenuItem.h>
#include "../strategies/PaymentStrategy.h";
#include "../utils/TimeUtils.h";
using namespace std;

class Order{
    protected: 
      static int nextOrderId;
      int orderId;
      User* user;
      Restaurent* restaurent;
      vector<MenuItem> items;
      PaymentStrategy* paymentStrategy;
      double total;
      string scheduled;

    public: 
    Order(){
        user = nullptr;
        restaurent = nullptr;
        paymentStrategy = nullptr;
        total = 0.0;
        scheduled = "";
        orderId = ++nextOrderId;
    }

    virtual ~Order(){
        delete paymentStrategy;
    }

    bool processPayment(){
        if(paymentStrategy){
            paymentStrategy->pay(total);
            return true;
        }
        else{
            cout<<"Please choose a payment mode first"<<endl;
            return false;
        }
    }

    virtual string getType() const = 0;

    // Getters and Setters

    int getOrderId() const{
        return orderId;
    }

    void setUser(User* u){
        user = u;
    }

    User* getUser() const{
        return user;
    }

    void setRestaurent(Restaurent* r){
        restaurent = r;
    }

    Restaurent* getRestaurent() const{
        return restaurent;
    }

    void setItems(const vector<MenuItem> &its){
        items = its;
        total = 0;
        for(auto &i: items){
            total += i.getPrice();
        }
    }
    
    const vector<MenuItem> getItems() const{
        return items;
    }

    void setPaymentStrategy(const PaymentStrategy* ps){
         paymentStrategy = ps;
    }
};



#endif // !ORDER_H