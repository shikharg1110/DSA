#include<iostream>
using namespace std;

class Hero {
    int health;
    public:
    char level;

    void print() {
        cout<<level<<endl;
    }

    int getHealth() {
        return health;
    }
    char getLevel() {
        return level;
    }

    void setHealth(int h){
        health = h;
    }
    void setLevel(char ch){
        level = ch;
    }
};

int main()
{
    Hero ramesh; // static allocatino

    // dynamic allocation
    Hero *r = new Hero();
    cout<<"r level:" <<(*r).level<<endl;
    cout<<"r health:" <<(*r).getHealth()<<endl;
    cout<<"r health:" <<r->getHealth()<<endl;

    // ramesh.health = 50;
    // ramesh.level = 'b';
    ramesh.setHealth(40);
    ramesh.setLevel('a');
    cout<<"Heath: "<<ramesh.getHealth()<<endl;  
    cout<<"Level: "<<ramesh.level<<endl;  
    ramesh.print();
    return 0;
}