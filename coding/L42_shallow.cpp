#include<iostream>
#include<cstring>
using namespace std;

class Hero {
    int health;
    public:
    char level;
    char *name;
    static int timeToComplete;

    Hero() { // Simple constructor
        cout<<"Simple Constructor called"<<endl;
        name = new char[100];
    }

    Hero(int health, int level) { // parametrized constructor
        this->health = health;
        this->level = level;
        // cout<<this<<endl;
    }

    Hero(Hero &temp) { // copy constructor
        char *ch = new char[strlen(temp.name) + 2];
        strcpy(ch, temp.name);
        this->name= ch;
        this->health = temp.health;
        this->level = temp.level;
    } 

    void print() {
        cout<<this->health<<", ";
        cout<<this->level<<", ";
        cout<<this->name<<endl;
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
    void setName(char name[]){
        strcpy(this->name, name);
    }
    string getName(){
        return name;
    }

    static int random() {
        // cout<<timeToComplete<<endl;
        return timeToComplete;
    }
    ~Hero() {
        cout<<"Destructor called"<<endl;
    }
};

int Hero::timeToComplete = 5;

int main()
{

    cout<<Hero::random()<<endl;

    // cout<<Hero::timeToComplete<<endl;
    // Hero a, b;
    // cout<<a.timeToComplete<<endl;
    // b.timeToComplete = 10;

    // cout<<a.timeToComplete<<endl;
    // cout<<b.timeToComplete<<endl;
    
    // Hero a;
    // Hero *b = new Hero;
    // delete b;   

    // Hero hero1;
    // hero1.setHealth(12);
    // hero1.setLevel('D');
    // char name[7] = "Babbar";
    // hero1.setName(name);
    // hero1.getName();
    // hero1.print();

    // Hero hero2(hero1);
    // hero2.print();

    // hero1.name[0] = 'G';
    // hero1.print();
    // hero2.print();

    // hero1 = hero2;
    // hero1.print();
    // hero2.print();

    // Hero suresh(70, 'C');
    // Hero ritesh(suresh);
    // cout<<ritesh.getHealth()<<endl;
    // cout<<ritesh.getLevel()<<endl;
    // Hero ramesh;
    // Hero *h = new Hero(70, 'a');
    // cout<<h->getHealth()<<endl;
    // cout<<h->getLevel()<<endl;
    return 0;
}