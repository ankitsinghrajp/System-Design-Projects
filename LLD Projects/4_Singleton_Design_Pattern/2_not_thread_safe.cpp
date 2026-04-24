#include<iostream>
using namespace std;

class Singleton{
   private:
   static Singleton* instance;

    Singleton(){
        cout<<"Singleton constructor called. New object created!"<<endl;
    }

    public:
    static Singleton* getinstance(){
       if(instance == nullptr){
           instance =  new Singleton();
       }
       return instance;
    }
};

Singleton* Singleton::instance = nullptr;

int main(){
    Singleton* s1 = Singleton::getinstance();
    Singleton* s2 = Singleton::getinstance();

    cout<<(s1 == s2)<<endl;


    return 0;
}