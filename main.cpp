#include <iostream>
#include <vector>
using namespace std;

int damage = 0;
int turn = 0;

class movesets{
public:
    int energy,health,spam;
    movesets() : energy{100},health{100},spam{0}{}; //constructor initializes everything to default

    /*~movesets(){ //upon destruction of the instance
        cout<<"Game Over!"<<endl;
    }*/

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
    cout<<"\nWelcome to the game\n"<<"(1) Player vs Player\n"<<"(2) Player vs AI\n----------------------\n"<<"(1) Fireball(Damage / Energy Consumption / Energy Regained) = 25,30,15\n"<<"(2) Claw Attack(Damage / Energy Consumption / Energy Regained) = 15,10,20\n"<<"(3) Frozen Breath(Damage / Energy Consumption / Energy Regained) = 20,25,10\n"<<"(4) Heal(Health Increase / Energy Consumption / Energy Regained) = 30,20,15";
    int mode,ab;
    cout<<"\nPlease enter the game mode:- ";
    cin>>mode;
    int choice;
    int temp = 0;
    while((p1.health>0 && p2.health>0)&&(p1.energy>0&&p2.energy>0)){
    if(turn%2==0){
        cout<<"\nPlease enter your choice Player 1:- ";
        cin>>choice;
        if(choice == 1){
            temp = p1.Fireball();
            if(temp==1){continue;}
            else p1.spam++;
        }
        else if(choice == 2){p1.Claw_Attack();}
        else if(choice == 3){p1.Frozen_Breath();}
        else{p1.heal();}
        if(choice!=1)p1.spam = 0;
        cout<<"Player 1 and Player 2 stats\n-----------------------------\n";
        cout<<p1;
        cout<<"Player 2 Health = "<<p2.health - damage;
    }
    if(mode == 1){
    if(turn%2!=0){
        cout<<"\nPlease enter your choice Player 2:- ";
        cin>>choice;
        if(choice == 1){
            temp = p2.Fireball();
            if(temp==1) continue;
            else p2.spam++;
        }
        else if(choice == 2){p2.Claw_Attack();}
        else if(choice == 3){p2.Frozen_Breath();}
        else{p2.heal();}
        p2.spam = 0;
        cout<<"Player 1 and Player 2 stats\n-----------------------------\n";
        cout<<p2;
        cout<<"Player 1 Health = "<<p2.health - damage;
        if(choice!=1)p2.spam = 0;
        }
    }
    else{
        if(turn%2!=0){
            ab = rand()%3;
            if(p2.health<30) p2.heal();
            else if(ab == 0) p2.Claw_Attack();
            else if(ab == 1) p2.Frozen_Breath();
            else{
                temp = p1.Fireball();
                if(temp==1){continue;}
                else p1.spam++;
            }
            cout<<"Player 2 and Player 1 stats\n-----------------------------\n";
            cout<<p2;
            cout<<"Player 1 Health = "<<p1.health - damage;
            if(choice!=1)p2.spam = 0;
        }
    }
    turn++;
    if((turn-1)%2 == 0) cout<<"Player 1 Won!!\n";
    else cout<<"Player 2 Won!!\n";
}
    cin.get(); //Avoids the closing of terminal
}