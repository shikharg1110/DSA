#include<iostream>
using namespace std;

class Hero {
    int health;
    public:
    char level;

    Hero() { // Simple constructor
        cout<<"Simple Constructor called"<<endl;
    }

    Hero(int health, int level) { // parametrized constructor
        this->health = health;
        this->level = level;
        // cout<<this<<endl;
    }

    Hero(Hero &temp) { // copy constructor
        this->health = temp.health;
        this->level = temp.level;
    }

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

    Hero suresh(70, 'C');
    Hero ritesh(suresh);
    cout<<ritesh.getHealth()<<endl;
    cout<<ritesh.getLevel()<<endl;
    // Hero ramesh;
    // Hero *h = new Hero(70, 'a');
    // cout<<h->getHealth()<<endl;
    // cout<<h->getLevel()<<endl;
    return 0;
}