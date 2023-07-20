#include<iostream>
using namespace std;
class player{
private:
int score;
int health;

/********** getter and setters are used to access private data outside the class by encapsulating inside a function; Thus providing security as data can't be changed directly by the variable now and when changed by using function of getter and setter, it can be easily traced and detected *********/
// In C++, we use this->health instead of this.health //

//setter
public:
void setScore(int s){
    // cout<<"score is changing!"<<" ";
    score = s;
}
void setHealth(int health){
    this->health = health;
}
// getter
int getScore(){
    return score;
}
int getHealth(){
    return health;
}
char name;
};
player maxScore(player a, player b){
    if(a.getScore()>b.getScore()) return a;
    else return b;
}
int main(){
    player shubh;  //compile time, static memory allocation//
    shubh.name='S';
    cout<<shubh.name<<endl;
    shubh.setScore(50);
    cout<<shubh.getScore()<<endl;
    shubh.setHealth(500);
    cout<<shubh.getHealth()<<endl;
    player ravi;
    ravi.setScore(80);
    player ashish = maxScore(shubh, ravi);
    cout<<ashish.getScore()<<endl;
    player *sakshiObject = new player;  //runtime, dynamic memory allocaction by pointer to object method//
    player sakshi = *sakshiObject;

    sakshi.setHealth(100);
    (*sakshiObject).setScore(400);
    //Another way of executing the above line//
    sakshiObject->setScore(900);
    cout<<sakshiObject->getScore()<<endl<<endl;

    cout<<(*sakshiObject).getScore()<<endl;
    cout<<sakshi.getHealth();
}