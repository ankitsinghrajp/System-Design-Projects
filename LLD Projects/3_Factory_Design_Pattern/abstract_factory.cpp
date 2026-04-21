#include<iostream>
#include<vector>
using namespace std;
class Burger{
  public:
   virtual void prepare() = 0;
   virtual ~Burger() {};
};

class BasicBurger: public Burger{
    public:
    void prepare() override{
        cout<<"The basic burger is prepared..."<<endl;
    }

};

class StandardBurger: public Burger{
    public:
    void prepare() override{
        cout<<"The standard burger is prepared..."<<endl;
    }
};

class PremiumBurger: public Burger{
    public:
    void prepare() override{
        cout<<"The premium burger is prepared..."<<endl;
    }
};

class BasicWheatBurger: public Burger{
    public:
    void prepare() override{
        cout<<"The basic wheat burger is prepared..."<<endl;
    }
};

class StandardWheatBurger: public Burger{
    public:
    void prepare() override{
        cout<<"The standard wheat burger is prepared..."<<endl;
    }
};

class PremiumWheatBurger: public Burger{
    public:
    void prepare() override{
        cout<<"The Premium wheat burger is prepared.."<<endl;
    }
};

class GarlicBread{
    public:
    virtual void prepare() = 0;
    virtual ~GarlicBread() {};
};

class BasicGarlicBread: public GarlicBread{
    public:
    void prepare() override{
        cout<<"The basic garlic bread is prepared..."<<endl;
    }
};

class StandardGarlicBread: public GarlicBread{
    public:
    void prepare() override{
        cout<<"The standard garlic bread is prepared..."<<endl;
    }
};

class PremiumGarlicBread: public GarlicBread{
    public:
    void prepare() override{
        cout<<"The premium garlic bread is prepared..."<<endl;
    }
};

class BasicWheatGarlicBread: public GarlicBread{
    public:
    void prepare() override{
        cout<<"The basic wheat garlic bread is prepared..."<<endl;
    }
};

class StandardWheatGarlicBread: public GarlicBread{
    public:
    void prepare() override{
        cout<<"The standard wheat garlic bread is prepared..."<<endl;
    }
};

class PremiumWheatGarlicBread: public GarlicBread{
    public:
    void prepare() override{
        cout<<"the premium wheat garlic bread is prepared..."<<endl;
    }
};

class Factory{
    public:
    virtual Burger* createBurger(string type) = 0;
    virtual GarlicBread* createGarlicBread(string type) = 0;
    virtual ~Factory(){};
};

class SingBakery: public Factory{
    public:
    Burger* createBurger(string type) override{
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
            cout<<"INVALID Burger Type!"<<endl;
            return nullptr;
        }
    }

    GarlicBread* createGarlicBread(string type) override{
          if(type == "basic"){
            return new BasicGarlicBread();
          }
          else if(type == "standard"){
            return new StandardGarlicBread();
          }
          else if(type == "premium"){
            return new PremiumGarlicBread();
          }
          else{
            cout<<"Invalid Bread typee!"<<endl;
            return nullptr;
          }
    }
};

class KingBakery: public Factory{
    public:
     Burger* createBurger(string type) override{
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
            cout<<"INVALID Burger Type!"<<endl;
            return nullptr;
        }
    }

    GarlicBread* createGarlicBread(string type) override{
          if(type == "basic"){
            return new BasicWheatGarlicBread();
          }
          else if(type == "standard"){
            return new StandardWheatGarlicBread();
          }
          else if(type == "premium"){
            return new PremiumWheatGarlicBread();
          }
          else{
            cout<<"Invalid Bread typee!"<<endl;
            return nullptr;
          }
    }
    
};

int main(){

    string type = "standard";
    cout<<"Meals taken from the sing bakery..."<<endl;
    Factory* mealFactory1 = new SingBakery();
    Burger* burger1 = mealFactory1->createBurger(type);
    GarlicBread* bread1 = mealFactory1->createGarlicBread(type);

    burger1->prepare();
    bread1->prepare();

    cout<<"Meals taken from the king bakery..."<<endl;
    Factory* mealFactory2 = new KingBakery();

    Burger* burger2 = mealFactory2->createBurger(type);
    GarlicBread* bread2 = mealFactory2->createGarlicBread(type);

    burger2->prepare();
    bread2->prepare();
    return 0;
}