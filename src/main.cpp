#include <iostream>

using namespace std;

//clases
class PJ {
    public:
        bool trans = false;
        int vit = 0;
        bool isDead(){
            if(vit <= 0){
                return true;
            }
        }
};  // por defecto todos los personajes tienen vitalidad en 0, no son transitables por el jugador y tenemos un metodo que verifica si el personaje esta muerto

class player : public PJ{
    public: 
        bool type = 0;
        int attack[2][4] = {{0, 0, 0, 0}, {0, 0, 0, 0}};
        player(int v, bool t){
            vit = v;
            if(!t){     // 0 → LUCHADOR
                type = t;
            } else {    // 1 → ARQUERO
                type = t;
            }
        }
}; // el jugador es un personaje más pero que solo tiene 2 tipos: 0 - guerrero, 1 - arquero

class enemy : public PJ{
    public:
        char type;
        enemy(int v, char t){
            vit = v;
            if(t == 0){ // Slimes → 0
                type = 'S';
                int attack[2][1]; // arreglo de daños - cooldowns
                attack[0][0] = 1; // daño - embestida
                attack[1][0] = 1; // cooldown - embestida
            } else if(t == 1){ // Orcos → 1
                type = 'O';
                int attack[2][2]; // arreglo de daños - cooldowns
                attack[0][0] = 2; // daño - golpe simple
                attack[0][1] = 4; // daño - patada giratoria
                attack[1][0] = 2; // cooldown - golpe simple
                attack[1][1] = 3; // cooldown - patada giratoria
            } else if(t == 2){ // Gigantes → 2
                type = 'G'; 
                int attack[2][1]; // arreglo daños - cooldowns
                attack[0][0] = 5;   // daño - pisoteada
                attack[1][0] = 2;   // cooldown - pisoteada
            }
        }
};

//clases 

void initializeAttacks(player& p){
    if(!p.type){ // si aventurero es luchador
        // ataques del luchador
        p.attack[0][0] = 2;   
        p.attack[0][1] = 4;
        p.attack[0][2] = 7;
        p.attack[0][3] = 12;
        // cooldowns respectivos del Luchador por ataque
        p.attack[1][0] = 1;
        p.attack[1][1] = 2;
        p.attack[1][2] = 3;
        p.attack[1][3] = 4;
    } else { // si aventurero es arquero
        // ataques del luchador
        p.attack[0][0] = 1;   
        p.attack[0][1] = 2;
        p.attack[0][2] = 2;
        p.attack[0][3] = 2;
        // cooldowns respectivos del Arquero por ataque
        p.attack[1][0] = 1;
        p.attack[1][1] = 1;
        p.attack[1][2] = 2;
        p.attack[1][3] = 3;
    }
} // esta funcion inicializa los ataques del arquero, para cada vez que inicie una partida o logre matar a un enemigo

int vitalityEntry(){
    cout << "Insert vitality" << endl;
    int v = 0;
    cin >> v;
    while(v < 1){
        cout << "invalid vitality: " << endl;
        cin >> v;
    }
    // cout << "vitality: " << v << endl;
    return v;
} // Ingresamos la vitalidad del aventurero, esta función recibe al parametro de player por referencia, para poder alterar su vitalidad

bool characterType(){
    char c; //solo un caracter será nuestro elemento de lectura
    bool b; // el booleano de tipo para asignarlo al aventurero

    cout << "insert type: " << endl;

    int i = 0;
    while(i < 1){
        cin >> c;
        if(c != ' '){
            if(c == 'L'){
                b = false;
                i++;
            } else if(c == 'A'){
                b = true;
                i++;
            }
        }
    } // este ciclo da el tipo del guerrero con base al caracter leido. Si c == 'L' (luchador) → el tipo del aventurero es luchador, caso de que sea 'A' entonces será arquero
    return b;
}   // character type entry

int main(){

    return 0;
}