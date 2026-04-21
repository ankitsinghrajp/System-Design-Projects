#include<iostream>
using namespace std;
class Burger{
    public:
      virtual void prepare() = 0;
      virtual ~Burger() {};
};

class BasicBurger: public Burger{
    public:
    void prepare() override{
        cout<<"The basic burger is preparing..."<<endl;
    }
};

class StandardBurger: public Burger{
    public:
     void prepare() override{
        cout<<"The standard burger is preparing..."<<endl;
     }
};

class PremiumBurger: public Burger{
    public:
     void prepare() override{
        cout<<"The premium burger is preparing..."<<endl;
     }
};

class BurgerFactory{
    public:
    Burger* createBurger(string & type){
        if(type == "basic"){
            return new BasicBurger();
        }
        else if(type == "standard"){
            return new StandardBurger();
        }
        else if(type == "premium"){
           return new PremiumBurger();
        }
        else{
            cout<<"Invalid burger type!"<<endl;
            return nullptr;
        }
    }
};

int main(){
    string type = "standard";
    BurgerFactory* myBFactory = new BurgerFactory();
    Burger* burger = myBFactory->createBurger(type);

    burger->prepare();
    return 0;
}