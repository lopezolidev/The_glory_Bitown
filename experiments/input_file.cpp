#include <iostream>

using namespace std;

// class Obs: public Entity {
//     public:
//         Obs(int t, bool advType){
//             if(t == 1){ // ' * '
//                 trans = false;
//             } else if(t == 2){ // ' PA ' 
//                 if(!advType){ // type: ' LU '
//                     trans = true;
//                 } else {
//                     trans = false;
//                 }
//             } else if(t == 3){ // ' AR '
//                 if(advType){ // type: ' AR '
//                     trans = true;
//                 } else {
//                     trans = false;
//                 }
//             }
//         }
// }; // obstacle creator

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
        bool type = false;
        int attack[2][4] = {{0, 0, 0, 0}, {0, 0, 0, 0}};
        player(int v, bool t){
            vit = v;
            if(!type){     // 0 → LUCHADOR
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

int dungeonsQuant(){
    int q = 0;

    cout << "Insert dungeons quantiity" << endl;

    cin >> q;

    if(q < 1){
        cout << "Invalid quantity." << endl;
        cin >> q;
    }

    cout << "dungeons quantity: " << q << endl;

    return q;

} //dungeons quantity entry

void dungeonCreator(){
    int rows, columns = 0;

    cout << "Insert rows and columns" << endl;
    cin >> rows >> columns; 

    cout << "rows: " << rows << endl;
    cout << "columns: " << columns << endl;

    char c;
    char row[c];

    int i = 0;

    while(i < rows){
        int j = 0;
        while(j < columns){
            cin >> c;
            if(c != ' '){
                row[j] = c;
                j++;
                // if(c == 'P'){
//  WORK IN PROGRESS...
                // }

            }

        }
        cout << row << endl;
        i++;
    }


}


void dataEntry(){
    player p(0, false);

    p.vit = vitalityEntry();

    p.type = characterType();

    // int q = dungeonsQuant();

    // int k = 0;
    // while(k < q){

    //     dungeonCreator();
    //     k++;
    // }

}

void whatIfP(char ***matrix, int i, int j, int& k){
    char c_2;
    cin >> c_2;
    if(c_2 == 'A'){
        matrix[i][j][k++] = c_2;
    }else if(c_2 == 'E'){
        matrix[i][j][k++] = c_2;
    } else if(c_2 == 'S'){
        matrix[i][j][k++] = c_2;
    }
    k++;
}

void whatIfS(char ***matrix, int i, int j, int& k){
    char c_2;
    int n = 0;
    while(n < 1){
        cin >> c_2;
        if(c_2 != ' '){
            matrix[i][j][k] = c_2;
            k++;
            n++;
        }
    }
    k++;
}

void whatIfOorG(char ***matrix, int i, int j, int& k){
    char c_2;
    int n = 0;
    while(n < 2){
        cin >> c_2;
        if(c_2 != ' '){
            matrix[i][j][k] = c_2;
            k++;
            n++;
        }
    }
}

void askData(char***& matrix, int a, int b){
    // a = rows, b = columns

    matrix = new char**[a];
    for(int i = 0; i < a; i++){
        matrix[i] = new char*[b]; 
        for(int j = 0; j < b; j++){
            matrix[i][j] = new char[3];
            for(int k = 0; k < 3; k++){
                matrix[i][j][k] = ' ';
            }
        }
    }

      int i = 0;
        while(i < a){
            int j = 0;
            while(j < b){
                int k = 0;
                while(k < 3){
                    char c;
                    cin >> c;
                    if(c == '*' || c == '.'){
                        matrix[i][j][k] = c;
                        k = 3;
                    } else if(c == 'P' || c == 'S' || c == 'O' || c == 'G'){
                        matrix[i][j][k] = c;
                        k++;
                        // Based on the type, call the respective function
                        if(c == 'P'){
                            whatIfP(matrix, i, j, k);
                        } else if(c == 'S'){
                            whatIfS(matrix, i, j, k);
                        } else if(c == 'O' || c == 'G'){
                            whatIfOorG(matrix, i, j, k);
                        }

                    }
                }
                j++;
            }
            i++;
        }
          //matrix fill → Aquí se llena la matrix con el caracter correspondiente
}

void printData(char ***matriz, int rows, int columns){
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < columns; j++) {
            for (int k = 0; k < 3; k++) {
                cout << matriz[i][j][k];
            }
            cout << "  ";
        }
        cout << endl;
    }
}

int main(){

    dataEntry();

    // char*** matriz = nullptr;

    //     cout << "insert number of rows and columns:  ";
    //     int a, b = 0;
    //     cin >> a >> b;

    //     askData(matriz, a, b);
        
    //     printData(matriz, a, b);

    //    for (int i = 0; i < a; i++) {
    //         for (int j = 0; j < b; j++) {
    //             delete[] matriz[i][j];
    //         }
    //         delete[] matriz[i];
    //     }
    //     delete[] matriz;

    return 0;
}

// And that's it...