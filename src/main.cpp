#include <iostream>
using namespace std;

class PJ
{
public:
    bool trans = false;
    int vit = 0;
    bool isDead()
    {
        bool b = false;
        if (vit <= 0)
        {
            b = true;
        }
        return b;
    }
}; 
// por defecto todos los personajes tienen vitalidad en 0, no son transitables por el jugador y tenemos un metodo que verifica si el personaje esta muerto

class player : public PJ
{
public:
    bool type = 0;
    int attack[4][4] = {{0, 0, 0, 0}, {0, 0, 0, 0}, {0, 0, 0, 0}, {0, 0, 0, 0}};
    player(int v, bool t)
    {
        vit = v;
        if (!type)
        { // 0 LUCHADOR
            type = t;
        }
        else
        { // 1  ARQUERO
            type = t;
        }
    }
}; 
/*
el jugador es un personaje mas pero que solo tiene 2 tipos: 0 - guerrero, 1 - arquero

Además cuenta con una matriz de ataques y cooldowns
*/ 

class enemy : public PJ
{
public:
    char type;
    int attack[4][2]; // Ajustar el tamanio de la matriz para el caso mas grande
    enemy(int v, char t)
    {
        vit = v;
        if (t == 'S')   // caso de enemigo tipo Slime
        {
            type = 'S';
            attack[0][0] = 1; // damage - embestida
            attack[1][0] = 0; // cooldown - embestida
            attack[2][0] = 1; // cooldown2 - embestida
            attack[3][0] = 0; // Enfriamiento - embestida
        }
        else if (t == 'O') // caso de enemigo tipo Orco
        {
            type = 'O';
            attack[0][0] = 4; // damage - golpe simple
            attack[1][0] = 0; // cooldown - golpe simple
            attack[2][0] = 3; // cooldown2 - golpe simple
            attack[3][0] = 0; // enfriamiento - golpe simple
            attack[0][1] = 2; // daÃ±o - patada giratoria
            attack[1][1] = 0; // cooldown - patada giratoria
            attack[2][1] = 2; // cooldown2 - patada giratoria
            attack[3][1] = 0; // Enfriamiento - patada giratoria
        }
        else if (t == 'G')  // caso de enemigo tipo Gigante
        {
            type = 'G';
            attack[0][0] = 5; // damage - pisoteada
            attack[1][0] = 0; // cooldown - pisoteada
            attack[2][0] = 2; // cooldown2 - pisoteada
            attack[3][0] = 0; // Enfriamiento - pisoteada
        }
    }
};  
//clase del enemigo. El constructor recibe un caracter que define el tipo de enemigo junto a su vida, además cada tipo cuenta con su matriz de cooldowns y ataques

void initializeAttacks(player &p)
{
    if (!p.type)
    { // si aventurero es luchador
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
        // cooldowns2 del Luchador
        p.attack[2][0] = 4;
        p.attack[2][1] = 3;
        p.attack[2][2] = 2;
        p.attack[2][3] = 1;
        // Enfriamiento de cada ataque
        p.attack[3][0] = 0;
        p.attack[3][1] = 0;
        p.attack[3][2] = 0;
        p.attack[3][3] = 0;
    }
    else
    { // si aventurero es arquero
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
        // cooldowns2 del Arquero
        p.attack[2][0] = 3;
        p.attack[2][1] = 2;
        p.attack[2][2] = 1;
        p.attack[2][3] = 1;
        // Enfriamiento de cada ataque
        p.attack[3][0] = 0;
        p.attack[3][1] = 0;
        p.attack[3][2] = 0;
        p.attack[3][3] = 0;
    }
} // esta funcion inicializa los ataques del luchador o aquero , para cada vez que inicie una partida o logre matar a un enemigo
// esta función resetea los parámetros de la matriz de ataques y cooldowns

int vitalityEntry(){

    int v = 0;
    cin >> v;
    while(v < 1){
        cin >> v;
    }
    // cout << "vitality: " << v << endl;
    return v;
} 
// Ingresamos la vitalidad del aventurero, esta función recibe al parametro de player por referencia, para poder alterar su vitalidad

bool characterType(){
    char c, d; //solo 2 caracteres serán nuestro elementos de lectura
    bool b; // el booleano de tipo para asignarlo al aventurero

    int i = 0;
    while(i < 1){
        cin >> c >> d;
        if(c != ' '){
            if(c == 'L' && d == 'U'){
                b = false;      // 'L' → 0 → LUCHADOR
                i++;
            } else if(c == 'A' && d == 'R'){
                b = true;       // 'A' → 1 → ARQUERO
                i++;
            }
        }
    }
    return b;
}
// esta función da el tipo del guerrero con base al caracter leido. Si c == 'L' (luchador) → el tipo del aventurero es luchador, caso de que sea 'A' entonces será arquero

player dataEntry(){
    player p(0, false);

    p.vit = vitalityEntry();

    p.type = characterType();

    // cout << "Vitality of character: " << p.vit << endl;
    // cout << "Type of character: ";
    // if(p.type){
    //     cout << "Arquero";
    // } else {
    //     cout << "Luchador";
    // }
    // cout << endl;   // LIMPIAR

    return p;
}
// función para ingresar los datos del jugador y regresando al player

int dungeonsQuant(){
    int q = 0;

    cin >> q;

    if(q < 1){

        cin >> q;
    }

    // cout << "dungeons quantity: " << q << endl;

    return q;

} 
//Esta función almacena la cantidad de mazmorras que se emplearán en la partida

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
}   
// función que introduce los caracteres correspondientes a la celda que empiece por 'P', sea PA: pantano, PS: portal de salida, PE: Portal de entrada

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
// detecta si es un Slime, que ingrese su caracter en la primera posición del arreglo de 3 posiciones, y luego ingrese la vida del monstruo

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
// Si es un orco o un gigante se ingresa su respectivo caracter y luego su vida, se hace un ciclo que mientras no sea vacío el caracter se ingresa la vida del enemigo

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
                         //Aquí se llena la matrix con el caracter correspondiente
                    }
                }
                j++;
            }
            i++;
        }
          return matrix;
}
// función para crear la matriz dinámica e ingresar los datos caracter por caracter

int posYE_XE(char*** M, int filas, int columnas, char L){
    int i= 0;
    while(i < filas){
        int j = 0;
        while(j < columnas){
            if(M[i][j][0] == 'P' && M[i][j][1] == 'E'){
                    if(L == 'F'){
                        return i;
                    } else if(L == 'C'){
                        return j;
                    }
                }
            j++;
        }
        i++;
    }
    return -1;
}
// retorna la posición en filas o columnas del Portal de Entrada

int howManyEnemies(char*** M, int rows, int columns){
    int count = 0;
    int i = 0;
    while(i < rows){
        int j = 0;
        while(j < columns){
            if(M[i][j][0] == 'O' || M[i][j][0] == 'G' || M[i][j][0] == 'S'){
                count++;
            }
            j++;
        }
        i++;
    }

    return count;
}
// esta función nos retorna el número total de enemigos en la matriz

// funcion de pelea
bool fight(player &p, int v, char t)
    {
        // reiniciar ataques
        initializeAttacks(p);
        
        // crear enemigo
        enemy monstruo(v, t); 

        bool b = false;

        // ciclos de  pelea
        int turno =1;
        while (p.vit > 0 && monstruo.vit > 0)
        {
            // ciclo del player
    //cout<<"turno - "<<turno<<endl;
            for (int i = 0; i < 4; i++)
            {
                if (p.attack[1][i] == 0)
                {
    //  cout<<"vida del monstruo ant: "<<monstruo.vit<<endl;
                    monstruo.vit -= p.attack[0][i];
                    p.attack[1][i] = p.attack[1][i] + p.attack[2][i]+1;
                    p.attack[3][i] = 1;
        // cout<<"vida del monstruo des: "<<monstruo.vit<<endl;

                    break;
                }
            }
            if (monstruo.vit > 0)
            {
                // ciclo del enemy
                for (int j = 0; j < 2; j++)
                {
                
                    if (monstruo.attack[1][j] == 0)
                    {
                        p.vit -= monstruo.attack[0][j];
                        monstruo.attack[1][j] = monstruo.attack[1][j] + monstruo.attack[2][j]+1;
                        monstruo.attack[3][j] = 1;
                        break;
                    }
                }
            }
            // ciclo para restar cooldowns
            for (int k = 0; k < 4; k++)
            {
                if (p.attack[3][k] == 1)
                {   
                    p.attack[1][k]--; // p.attack[1][k]-1;
                    if (p.attack[1][k] == 0)
                    {
                        p.attack[3][k] == 0;
                    }
                }
                if (monstruo.attack[3][k] == 1)
                {
                    monstruo.attack[1][k]--; // monstruo.attack[1][k]-1;
                    if (monstruo.attack[1][k] == 0)
                    {
                        monstruo.attack[3][k] == 0;
                    }
                }
            }turno++;
        }


        if (p.vit > 0){
                b = true;
        }   // solo podemos cruzar una celda si nuestra vida es > 0

        return b;
}
// solo si el jugador sobrevive, la pelea es exitosa es decir retornas verdadero

void marcar(char***& M, char m_1, char m_2, char m_3, int posX, int posY){

    M[posY][posX][0] = m_1;
    // Asegurarse de limpiar las posiciones [1] y [2]
    M[posY][posX][1] = m_2;
    M[posY][posX][2] = m_3;
}   
// marcando la celda con el caracter del movimiento que hicimos o deshicimos


// WORK IN PROGRESS


int mov[4][2] = {{-1, 0},{0, 1},{1, 0},{0, -1}};

/*
mov[4][2] = 
{
    {-1, 0},    UP
    {0 , 1},    RIGHT
    {1,  0},    DOWN
    {0, -1}     LEFT
}

Matriz de movimientos
*/
bool validar(int* fila_mov, int posY, int posX, char***& M, int& enemy_counter, player& p, int vit, int rows, int cols){
    bool b_1 = false;
    bool b_2 = false;

    int movY = fila_mov[0]; // movmiento que haremos en filas
    int movX = fila_mov[1]; // movmiento que haremos en columnas
    
    char enemy = ' ';   // caracter enemigo
    int vit_e = 0; // vitalidad por defecto del enemigo

    if(     posY + movY >= 0 && posY + movY < rows  && 
            posX + movX >= 0 && posX + movX < cols) 
            {
            
                if(M[posY + movY][posX + movX][0] == '.' || 
                M[posY + movY][posX + movX][0] == 'P' && M[posY + movY][posX + movX][1] == 'S'  ||
                p.type && (M[posY + movY][posX + movX][0] == 'A' && M[posY + movY][posX + movX][1] == 'R')  ||
                !p.type && (M[posY + movY][posX + movX][0] == 'P' && M[posY + movY][posX + movX][1] == 'A')){
                    b_1 = true;
                    b_2 = true;
                } else if(M[posY + movY][posX + movX][0] == 'S' || M[posY + movY][posX + movX][0] == 'O' || M[posY + movY][posX + movX][0] == 'G'){
                    char enemy = M[posY + movY][posX + movX][0];
                    int vit_e = 0;
                    int vit_e_1 = 0;
                    int vit_e_2 = 0;
                    if(enemy == 'S'){   // if it's a slime
                        vit_e = M[posY + movY][posX + movX][1] - '0';
                    } else {    // Si se trata de un orco o un gigante
                        vit_e_1 = M[posY + movY][posX + movX][1] - '0';
                        vit_e_2 = M[posY + movY][posX + movX][2] - '0';
                        vit_e = vit_e_1 *10 + vit_e_2; 
                    }
                    b_1 = true;

                    bool f = fight(p, vit_e, enemy);    // guardamos en un booleano la victoria de combate


                    if(f){  // si el combate resulta exitoso aumentamos el contador de enemigos derrotados
                        enemy_counter++;
                        if(enemy != 'G') {      // si el enemigo derrotado no fue un gigante ubicamos un punto en el lugar para no combatir más de 1 vez contra el mismo enemigo
                            b_2 = true;
                            M[posY + movY][posX + movX][0] = '.';
                            M[posY + movY][posX + movX][1] = ' ';
                            M[posY + movY][posX + movX][2] = ' ';
                        } else {
                            b_2 = false;
                            M[posY + movY][posX + movX][0] = '*';
                            M[posY + movY][posX + movX][1] = ' ';
                            M[posY + movY][posX + movX][2] = ' ';
                        }   // al ser el enemigo derrotado un gigante colocamos un asterisco, simbolizando una pared
                    } else {
                        p.vit = vit;
                    } 
                }

            }

    return b_1 && b_2 ;
} 
// veificador de celda, incluye el combate para garantizar que la celda es válida. Además altera la celda del combate exitoso para garantizar no pelear con el mismo enemigo más de una vez

void backtracking(char***& M, player& p, int vit, int posY, int posX, bool& escape, int& enemy_counter, int totalEnemies, int rows, int columns){
    if(M[posY][posX][0] == 'P' && M[posY][posX][1] == 'S'){
            escape = true;
            // cout << "Salida!" << endl;
            // printData(M, rows, columns);
            return;
        }   // si las coordenadas actuales encajan con la celda de salida es que llegamos a la salida

    int i = 0;
    while(i < 4){
        if(escape == true && enemy_counter == totalEnemies){
            break;
        }   // cuando logramos matar a todos los enemigos en caso de y que hayamos llegado a la salida
        if(validar(mov[i], posY, posX, M, enemy_counter, p, vit, rows, columns)){      // si es válido el movimiento nos movemos en la matriz en esa direccion

            char marca;
            if(mov[i][0] == -1 && mov[i][1] == 0){
                marca = 'U';    // si el movimiento en ese momento es arriba
            } else if(mov[i][0] == 0 && mov[i][1] == 1){
                marca = 'R';    // si el movimiento en ese momento es derecha
            } else if(mov[i][0] == 1 && mov[i][1] == 0){
                marca = 'D';    // si el movimiento en ese momento es abajo
            }  else {
                marca = 'L';    // si el movimiento es a la izquierda
            }   // según la dirección, el caracter marca guardará la Letra del movimiento que hicimos

            char elemento = M[posY][posX][0];   // guardamos caracter de elemento previo por si el movimiento siguiente es inválido
            char elemento_2 = M[posY][posX][1];
            char elemento_3 = M[posY][posX][2]; // además de cualquier otra cosa que hubiera en dicha celda
            
            int movF = mov[i][0];   // guardamos el valor de la coordenada en Y
            int movC = mov[i][1];   // guardamos el valor de la coordenada en X

            marcar(M, marca, ' ', ' ', posX, posY);   // marcamos esa celda de la matriz, la celda donde estamos indicamos la direccion que tomamos

            // cout << endl;
            // printData(M, rows, columns);
            // cout << endl;   // imprimimos antes de los pasos recursivos

            backtracking(M, p, vit, posY + movF, posX + movC, escape, enemy_counter, totalEnemies, rows, columns);  // ejecutamos llamada recursiva de backtracking

            marcar(M, elemento, elemento_2, elemento_3, posX, posY);    // regresamos el movimiento anterior

            // Comenta estas líneas si no necesitas ver los pasos intermedios
        }
        i++;
    }
}
// función de backtracking. Elemento principal para toda la partida, donde se realizarán los pasos recursivos y se validan las celdas donde se busca transitar. Altera los parámetros por referencia del jugador, la matriz y el contador de enemigos.


void partida(char***& M, player& p, int vit, int rows, int cols){
    int fila_E = posYE_XE(M, rows, cols, 'F');
    int columna_E = posYE_XE(M, rows, cols, 'C');

    bool escape = false;
    int total_enemies = 0;
 
    total_enemies = howManyEnemies(M, rows, cols);

    int enemies_counter = 0;

    backtracking(M, p, vit, fila_E, columna_E, escape, enemies_counter, total_enemies, rows, cols);

    if(escape && (total_enemies == enemies_counter)){
        cout << "YOU GET THE GLORY";
    } else if(escape){
        cout << "YOU SURVIVE";
    } else {
        cout << "YOU DIE";
    }

    cout << endl;

}   // en esta función se hace una comparación del booleano que arroja el backtracking y la comparación entre los enemigos muertos y los totales, así se podrá implementar el mensaje final por pantalla de la mejor solución posible

void deleteMatrix(char***& M, int rows, int cols){
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            delete[] M[i][j];
        }
        delete[] M[i];
    }
    delete[] M;
}

void worldCreator(player p, int vit){
    int rows = 0, cols = 0;

    cin >> rows >> cols;

    char*** myMatrix = nullptr; // declaramos la matriz como un puntero nulo, es decir que no apunta a ninguna dirección de memoria
    myMatrix = createMatrix(myMatrix, rows, cols);  // creamos la matriz dinámica retornando un puntero de punteros 

    partida(myMatrix, p, vit, rows, cols);  // en esta función enviamos la matriz y el jugador por referencia además de filas y columnas
    //jugamos 

    // printData(myMatrix, rows, cols);  // imprimimos la matriz
    deleteMatrix(myMatrix, rows, cols);
}   
// esta función crea la matriz, la cual es utilizada función de 'partida' la cual es central para hacer el recorrido del laberinto, la peleas e imprimir los resultados por pantalla que se solicitan en el documento del proyecto

void game(){
    player p = dataEntry();
    int q = dungeonsQuant();
    int k = 0;
    int vit = p.vit; // variable auxiliar que guarda la vitalidad con la que el jugador entró por primera vez al conjunto de mazmorras
    while(k < q){

        // p.vit = vit; // haciendo "reset" de la vida del jugador

        worldCreator(p, vit);
        k++;
    }
};

int main(){

    game();

    return 0;
}