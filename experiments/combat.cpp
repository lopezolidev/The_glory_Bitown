#include <iostream>

using namespace std;

class PJ {
    public:
        bool trans = false;
        int vit = 0;
        bool isDead(){
            bool b = false;
            if(vit <= 0){
                b = true;
            }
            return b;
        }
};  // por defecto todos los personajes tienen vitalidad en 0, no son transitables por el jugador y tenemos un metodo que verifica si el personaje esta muerto

class player : public PJ{
    public: 
        bool type = 0;
        int attack[4][4] = {{0, 0, 0, 0}, {0, 0, 0, 0}, {0, 0, 0, 0}, {0, 0, 0, 0}};
        player(int v, bool t){
            vit = v;
            if(!type){     // 0 → LUCHADOR
                type = t;
            } else {    // 1 → ARQUERO
                type = t;
            }
        }
}; // el jugador es un personaje más pere que solo tiene 2 tipos: 0 - guerrero, 1 - arquero

class enemy : public PJ{
    public:
        char type;
        int attack[4][2]; // Ajustar el tamaño de la matriz para el caso más grande
         enemy(int v, char t) {
        vit = v;
        if (t == 0) {
            type = 'S';
            attack[0][0] = 1; // daño - embestida
            attack[1][0] = 0; // cooldown - embestida
            attack[2][0] = 1; // cooldown2 - embestida
            attack[3][0] = 0; // Enfriamiento - embestida
        } else if (t == 1) {
            type = 'O';
            attack[0][0] = 2; // daño - golpe simple
            attack[1][0] = 0; // cooldown - golpe simple
            attack[2][0] = 2; // cooldown2 - golpe simple
            attack[3][0] = 0; // enfriamiento - golpe simple
            attack[0][1] = 4; // daño - patada giratoria
            attack[1][1] = 0; // cooldown - patada giratoria
            attack[2][1] = 3; // cooldown2 - patada giratoria
            attack[3][1] = 0; // Enfriamiento - patada giratoria
        } else if (t == 2) {
            type = 'G';
            attack[0][0] = 5; // daño - pisoteada
            attack[1][0] = 0; // cooldown - pisoteada
            attack[2][0] = 2; // cooldown2 - pisoteada
            attack[3][0] = 0; // Enfriamiento - pisoteada
        }
    }
};

void initializeAttacks(player& p){
    if(!p.type){ // si aventurero es luchador
        // ataques del luchador
        p.attack[0][0] = 12;   
        p.attack[0][1] = 7;
        p.attack[0][2] = 4;
        p.attack[0][3] = 2;
        // cooldowns respectivos del Luchador por ataque
        p.attack[1][0] = 0;
        p.attack[1][1] = 0;
        p.attack[1][2] = 0;
        p.attack[1][3] = 0;
        //cooldowns2 del Luchador 
        p.attack[2][0] = 4;
        p.attack[2][1] = 3;
        p.attack[2][2] = 2;
        p.attack[2][3] = 1;
        //Enfriamiento de cada ataque 
        p.attack[3][0] = 0;
        p.attack[3][1] = 0;
        p.attack[3][2] = 0;
        p.attack[3][3] = 0;
    } else { // si aventurero es arquero
        // ataques del Arquero
        p.attack[0][0] = 2;   
        p.attack[0][1] = 2;
        p.attack[0][2] = 2;
        p.attack[0][3] = 1;
        // cooldowns respectivos del Arquero por ataque
        p.attack[1][0] = 0;
        p.attack[1][1] = 0;
        p.attack[1][2] = 0;
        p.attack[1][3] = 0;
        //cooldowns2 del Arquero
        p.attack[2][0] = 3;
        p.attack[2][1] = 2;
        p.attack[2][2] = 1;
        p.attack[2][3] = 1;
        //Enfriamiento de cada ataque 
        p.attack[3][0] = 0;
        p.attack[3][1] = 0;
        p.attack[3][2] = 0;
        p.attack[3][3] = 0;
    }
} //esta funcion inicializa los ataques del luchador o aquero , para cada vez que inicie una partida o logre matar a un enemigo 

// funcion de pelea
 void fight(player& p,int v, char t){
  //reiniciar ataques
   initializeAttacks(p);
   //crear enemigo 
   
   
   enemy monstruo(v, t);// ← llamas al constructor con el nombre directamente de la variable
   
   //ciclos de  pelea 
     while(p.vit>0 && monstruo.vit>0 ){
       //ciclo del player
       for(int i = 0; i < 4; i++){
         if(p.attack[1][i] == 0){
           monstruo.vit-= p.attack[0][i];
           p.attack[1][i] = p.attack[1][i] + p.attack[2][i] + 1;
           p.attack[3][i] = 1;
           break;
         }
     }
       //ciclo del enemy
        for(int j = 0; j < 4; j++){
         if(monstruo.attack[1][j] == 0){
           p.vit-= monstruo.attack[0][j];
           monstruo.attack[1][j] = monstruo.attack[1][j] + monstruo.attack[2][j] + 1;
           monstruo.attack[3][j] = 1;
           break; 
         }
       }
       //ciclo para restar cooldowns
       for (int k = 0; k < 4; k++){
        if (p.attack[3][k]== 1){
            p.attack[1][k]= p.attack[1][k]-1;
            if(p.attack[1][k]==0){
                p.attack[3][k]== 0;
            }
          }
        if (monstruo.attack[3][k]== 1){
            monstruo.attack[1][k]= monstruo.attack[1][k]-1;
            if(monstruo.attack[1][k]==0){
                monstruo.attack[3][k]== 0;
          }
        }
      }
    }

    cout << "Player ";

    if(p.isDead()){
        cout << "not ";
    }

    cout << "survived";
  }

int main(){

    bool b = false;
    player p(20, b);
    fight(p, 12, 'O');


    return 0;
}