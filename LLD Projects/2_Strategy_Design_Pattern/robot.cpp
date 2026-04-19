#include<iostream>
#include<vector>
using namespace std;
class Talkable{
    public:
    virtual void talk() = 0;
    virtual ~Talkable(){}; // virtual destructor
};

class NormalTalk: public Talkable{
    public:
    void talk() override{
        cout<<"The robot is talking normally..."<<endl;
    }
};

class NoTalk: public Talkable{
    public:
     void talk() override{
        cout<<"The robot cannot talk..."<<endl;
     }
};

class Walkable{
    public:
      virtual void walk() = 0;
      virtual ~Walkable(){};
};

class NormalWalk: public Walkable{
    public:
    void walk() override{
        cout<<"The robot walks normally..."<<endl;
    }
};

class NoWalk: public Walkable{
    public:
      void walk() override{
        cout<<"The robot cannot walk..."<<endl;
      }
};

class Flyable{
    public:
    virtual void fly() = 0;
    virtual ~Flyable() {};
};

class NormalFly: public Flyable{
    public:
     void fly() override{
         cout<<"The robot can fly normally..."<<endl;
     }
};

class NoFly: public Flyable{
    public:
    void fly() override{
        cout<<"The robot cannot fly..."<<endl;
    }
};

class Robot{
    protected:
      Walkable * walkBehavior;
      Talkable* talkBehavior;
      Flyable* flyBehavior;

    public:
    Robot(Walkable* w, Talkable* t, Flyable* f){
        this->walkBehavior = w;
        this->talkBehavior = t;
        this->flyBehavior = f;
    }
    virtual ~Robot() {};
    
    void walk(){
        walkBehavior->walk();
    }

    void talk(){
        talkBehavior->talk();
    }

    void fly(){
        flyBehavior->fly();
    }
   
    virtual void projection() = 0;
};

class CompanionRobot: public Robot{
     public: 
     CompanionRobot(Walkable* w, Talkable* t, Flyable* f): Robot(w,t,f){}
     void projection() override{
        cout<<"Displaying friendly companion feature..."<<endl;
     }
};

class WorkerRobot: public Robot{
    public:
     WorkerRobot(Walkable* w, Talkable* t, Flyable* f): Robot(w,t,f){};

     void projection() override{
        cout<<"Displaying worker efficiency stats..."<<endl;
     }
};

int main(){
    Robot * robot1 = new CompanionRobot(new NormalWalk(), new NoTalk(), new NormalFly());
    robot1->walk();
    robot1->talk();
    robot1->fly();
    robot1->projection();
    return 0;
}