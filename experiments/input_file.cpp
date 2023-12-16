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
         enemy(int v, char t) { // se ajusta el constructor según el tipo de enemigo a los parámetros que recibe
        vit = v;
        if (t == 'S') {   // si es un Slime
            type = t;
            attack[0][0] = 1; // daño - embestida
            attack[1][0] = 0; // cooldown - embestida
            attack[2][0] = 1; // cooldown2 - embestida
            attack[3][0] = 0; // Enfriamiento - embestida
        } else if (t == 'O') {    // si es un Orco
            type = t;
            attack[0][0] = 2; // daño - golpe simple
            attack[1][0] = 0; // cooldown - golpe simple
            attack[2][0] = 2; // cooldown2 - golpe simple
            attack[3][0] = 0; // enfriamiento - golpe simple
            attack[0][1] = 4; // daño - patada giratoria
            attack[1][1] = 0; // cooldown - patada giratoria
            attack[2][1] = 3; // cooldown2 - patada giratoria
            attack[3][1] = 0; // Enfriamiento - patada giratoria
        } else if (t == 'G') {    // si es un Gigante
            type = t;
            attack[0][0] = 5; // daño - pisoteada
            attack[1][0] = 0; // cooldown - pisoteada
            attack[2][0] = 2; // cooldown2 - pisoteada
            attack[3][0] = 0; // Enfriamiento - pisoteada
        }
    }
}; // clase de creación de enemigo
//clases 

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
/*


FRANYER!  esto de initializeAttacks implementalo si quieres, eliminalo si te estorba visualmente


*/ 

int vitalityEntry(){
    int v = 0;
    cin >> v;
    while(v < 1){
        cin >> v;
    }
    // cout << "vitality: " << v << endl;
    return v;
} // Ingresamos la vitalidad del aventurero, esta función recibe al parametro de player por referencia, para poder alterar su vitalidad

bool characterType(){
    char c, d; //solo un caracter será nuestro elemento de lectura, el segundo evitará errores para la proxima entrada
    bool b; // el booleano de tipo para asignarlo al aventurero

    int i = 0;
    while(i < 1){
        cin >> c >> d;
        if(c != ' '){
            if(c == 'L'){   // si el caracter de entrada es 'L' es un luchador, que equivale a bool 'FALSE'
                b = false;
                i++;
            } else if(c == 'A'){    // si el caracter de entrada es 'A' es un arquero, que equivale a bool 'TRUE'
                b = true;
                i++;
            }
        }
    } // este ciclo da el tipo del guerrero con base al caracter leido.
    return b;
}   // character type entry

int dungeonsQuant(){
    int q = 0;

    cout << "Insert dungeons quantity" << endl;

    cin >> q;

    if(q < 1){
        cout << "Invalid quantity." << endl;
        cin >> q;
    }

    cout << "dungeons quantity: " << q << endl;

    return q;

} //dungeons quantity entry

void whatIfP(char ***matrix, int i, int j, int& k){
    char c_2;
    cin >> c_2;
    if(c_2 == 'A'){
        matrix[i][j][k] = c_2;
    }else if(c_2 == 'E'){
        matrix[i][j][k] = c_2;
    } else if(c_2 == 'S'){
        matrix[i][j][k] = c_2;
    }
    k++;
}   // función que introduce los caracteres correspondientes a la celda que empiece por 'P', sea PA: pantano, PS: portal de salida, PE: Portal de entrada

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
}   // detecta si es un Slime, que ingrese su caracter en la primera posición del arreglo de 3 posiciones, y luego ingrese la vida del monstruo

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
}   // Si es un orco o un gigante se ingresa su respectivo caracter y luego su vida, se hace un ciclo que mientras no sea vacío el caracter se ingresa la vida del enemigo

char*** createMatrix(char***& matrix, int a, int b){
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
    }   // creamos una matriz dinámica de 3 dimensiones, las filas y columnas son desconocidas, pero los elementos de la matriz de caracteres más interna son conocidos y son vacíos

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
                          // Based on the type call the respective function depending on the character of the cell
                        if(c == 'P'){ // what if the character is a 'P'
                            whatIfP(matrix, i, j, k);
                            k++;   
                        } else if(c == 'S'){    // what if the character is an 'S'
                            whatIfS(matrix, i, j, k);   
                        } else if(c == 'O' || c == 'G'){    // what if the character is a 'G'
                            whatIfOorG(matrix, i, j, k);
                        }                       
                    } else if(c == 'A'){
                        matrix[i][j][k] = c;
                        k++;
                        char c_2;
                        cin >> c_2;
                        if(c_2 != ' '){
                            matrix[i][j][k] = c_2;
                            k = 3;
                        }   // caso particular para los árboles
                    }
                }
                j++;
            }
            i++;
        }
          return matrix;
          //matrix fill → Aquí se llena la matrix con el caracter correspondiente
}
// función para crear la matriz dinámica e ingresar los datos caracter por caracter

void printData(char*** matriz, int rows, int columns){
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
// funcion para imprimir las celdas de la matriz

bool deleteMatrix(char***& matrix, int rows, int cols){
    bool b =false;    
       for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                delete[] matrix[i][j];
                b = true;
            }
            delete[] matrix[i];
        }
        delete[] matrix;
    return b;
};
// función para liberar la memoria de la matriz 

bool backtracking_Escape(){
 // ...   
}

bool backtracking_KillAll(){
 // ...   
}

void partida(char***& M, player p){
    bool b_1 = false, b_2 = false;

    b_1 = backtracking_Escape();
    b_2 = backtracking_KillAll();

    if(b_1 && b_2){
        cout << "YOU GET THE GLORY";
    } else if(b_1){
        cout << "YOU SURVIVE";
    } else {
        cout << "YOU DIE";
    }

    cout << endl;

}

void worldCreator(){
    int rows = 0, cols = 0;

    cin >> rows >> cols;

    cout << "rows: " << rows << ", cols: " << cols << endl;

    char*** myMatrix = nullptr; // declaramos la matriz como un puntero nulo, es decir que no apunta a ninguna dirección de memoria
    myMatrix = createMatrix(myMatrix, rows, cols);

    //jugamos → partida();  // en esta función enviamos la matriz y el jugador por referencia

    printData(myMatrix, rows, cols);  // imprimimos la matriz

    // if(deleteMatrix(myMatrix, rows, cols)) cout << endl << "deleted matrix" << endl;   // eliminamos la matriz

    //  cout << "rows: " << rows << ", cols: " << cols << endl;

}   // esta función crea la matriz, la cual es enviada a una función de Game la cual es central para imprimir los resultados por pantalla que se solicitan en el documento del proyecto


void dataEntry(){
    player p(0, false);

    p.vit = vitalityEntry();

    p.type = characterType();

    cout << "Vitality of character: " << p.vit << endl;
    cout << "Type of character: ";
    if(p.type){
        cout << "Arquero";
    } else {
        cout << "Luchador";
    }
    cout << endl;   // LIMPIAR
}
// función para ingresar los datos del jugador

int main(){

    dataEntry();
    int q = dungeonsQuant();
    int k = 0;
    while(k < q){
        cout << "dungeon N°: " << k + 1 << endl;
        worldCreator();
        k++;
    }

    return 0;
}

// And that's it...