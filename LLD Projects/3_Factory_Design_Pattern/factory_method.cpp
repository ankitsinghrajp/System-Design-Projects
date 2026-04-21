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

class BasicWheatBurger: public Burger{
    public:
      void prepare() override{
        cout<<"The basic wheat burger is preparing..."<<endl;
      }
};

class StandardWheatBurger: public Burger{
    public:
      void prepare() override{
        cout<<"The standard wheat burger is preparing..."<<endl;
      }
};

class PremiumWheatBurger: public Burger{
    public:
      void prepare() override{
        cout<<"The premium wheat burger is preparing..."<<endl;
      }
};

class BurgerFactory{
    public:
     virtual Burger* createBurger(string & type) = 0;
};

class SingBurger: public BurgerFactory{
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

class KingBurger: public BurgerFactory{
    public:
    Burger* createBurger(string & type){
         if(type == "basic"){
            return new BasicWheatBurger();
         }
         else if(type == "standard"){
            return new StandardWheatBurger();
         }
         else if(type == "premium"){
            return new PremiumWheatBurger();
         }
         else{
            cout<<"Invalid burger type!"<<endl;
             return nullptr;
         }
    }
};
int main(){
    string type = "premium";
    BurgerFactory* singFactory = new SingBurger();
    BurgerFactory* kingFactory = new KingBurger();

    Burger* burger1 = singFactory->createBurger(type);
    Burger* burger2 = kingFactory->createBurger(type);
    burger1->prepare();
    burger2->prepare();

    return 0;
}