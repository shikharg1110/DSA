#include<iostream>
using namespace std;

class Human {
    public:
    int height;
    int weigth;
    int age;

    int getAge() {
        return this->age;
    }
    void setWeight(int w) {
        this->weigth = w;
    }
};

class Male: public Human {
    public:
    string color;

    void sleep() {
        cout<<"Male sleep"<<endl;
    }
};

int main()
{
    Male obj1;
    cout<<obj1.age<<endl;
    cout<<obj1.weigth<<endl;
    cout<<obj1.height<<endl;
    cout<<obj1.color<<endl;
    obj1.setWeight(50);
     cout<<obj1.weigth<<endl;
    
    obj1.sleep();
    return 0;
}