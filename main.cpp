#include <iostream>
#include <vector>
using namespace std;

int spam = 0;
int damage = 0;
int turn = 0;

class movesets{
public:
    int energy,health;
    movesets() : energy{100},health{100}{}; //constructor initializes everything to default

    ~movesets(){ //upon destruction of the instance
        cout<<"Game Over!"<<endl;
    }

    int Fireball(){
        if(spam%2 != 0){
            cout<<"Cannot spam the same moveset";
            return 1;
        }
        health = health - damage;
        damage = 20 + rand()%7; //Can give extra Burn damage
        energy = energy - 30 + 15; //energy = energy - energy consumed + regained 
        return 0;
    }

    void Claw_Attack(){
        health = health - damage;
        damage = 15;
        energy = energy - 10 + 20;
    }

    void Frozen_Breath(){
        health = health - damage;
        damage = 20;
        energy = energy - 25 + 10;
    }

    void heal(){
        health = health + 30;
        damage = 0;
        energy = energy - 20 + 15;
    }

    friend ostream& operator<<(ostream& field , movesets& m){
        field<<"Energy Left:- "<<m.energy<<"\nHealth Left:- "<<m.health<<"\nDamage Dealt:- "<<damage<<endl;
        return field;
    }
};

int main(){
    srand(time(0));
    movesets p1;
    movesets p2;
    if(turn%2==0){}
    else{}
    cin.get(); //Avoids the closing of terminal
}