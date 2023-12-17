#include <iostream>

using namespace std;

int posYE(char M[][10][3]){
    int i= 0;
    while(i < 10){
        int j = 0;
        while(j < 10){
                if(M[i][j][0] == 'P' && M[i][j][1] == 'E'){
                    return i;
                }
            j++;
        }
        i++;
    }
    return -1;
}


int posXE(char M[][10][3]){
    int i= 0;
    while(i < 10){
        int j = 0;
        while(j < 10){
                if(M[i][j][0] == 'P' && M[i][j][1] == 'E'){
                    return j;
                }
            j++;
        }
        i++;
    }
    return -1;
}

int mov[4][2] = {{-1, 0},{0, 1},{1, 0},{0, -1}};

/*
mov[4][2] = 
{
    {-1, 0},    UP
    {0 , 1},    RIGHT
    {1,  0},    DOWN
    {0, -1}     LEFT
}
*/

bool valido(int* fila, int posY, int posX, char M[][10][3], int& enemy_counter){
    // cout << "enemy counter" << enemy_counter << endl;

    int movY = fila[0];
    int movX = fila[1];

    bool b = false;

    // if((posY + movY) == 7 && (posX + movX) == 8){
    //     if(M[posY + movY][posX + movX][0] == 'G'){
            
    //         cout << "giant " << endl;
    //         enemy_counter++;
    //         cout << "enemy_counter " << enemy_counter << endl;
    //     }
    //     cout << "M[7][8][0] " << M[7][8][0] << endl;
    // }

    // Corregir las condiciones para validar la celda
    if (!(posY + movY < 0 || posY + movY >= 10 || posX + movX < 0 || posX + movX >= 10 ||
            M[posY + movY][posX + movX][0] == '*' ||
            M[posY + movY][posX + movX][0] == 'U' ||
            M[posY + movY][posX + movX][0] == 'R' ||
            M[posY + movY][posX + movX][0] == 'D' ||
            M[posY + movY][posX + movX][0] == 'L' )) {  
                // casos normales, donde no son enemigos y solo se compara si se está dentro de la matriz o las direcciones tomadas
                
                b = true;

    }
    if(M[posY + movY][posX + movX][0] == 'O' || M[posY + movY][posX + movX][0] == 'M'){
            // caso cuando es un enemigo transitable
        
        enemy_counter++;
        M[posY + movY][posX + movX][0] = '.';   // marcamos la matriz para no contar dos veces ese enemigo
        b = true;       
        cout << "enemy_counter " << enemy_counter << endl;

    }
    if( M[posY + movY][posX + movX][0] == 'G'){
        enemy_counter++;
        M[posY + movY][posX + movX][0] = '*';   // lo mismo para el caso del gigante
        b = false;
        cout << "enemy_counter " << enemy_counter << endl;
    }
    return b;

} // funcion validar → asegurando que la celda es valida para cruzar → más adelante implementarse con combate

void marcar(char M[][10][3], char m, int posX, int posY){

    M[posY][posX][0] = m;
    // Asegurarse de limpiar las posiciones [1] y [2]
    M[posY][posX][1] = ' ';
    M[posY][posX][2] = ' ';
}   // marcando la celda con el caracter del movimiento que hicimos o deshicimos

void printMatriz(char M[][10][3]){
    int i = 0;
    while(i < 10){
        int j = 0;
        while(j < 10){
            cout << M[i][j][0] << " " << M[i][j][1] << " ";
            j++;
        }
        cout << endl;
        i++;
    }
}

void backtracking(char M[][10][3], int posY, int posX, bool& b, int& enemy_counter){
    if(M[posY][posX][0] == 'P' && M[posY][posX][1] == 'S'){
        b = true;
        cout << "Salida!" << endl;
        printMatriz(M);
        return;
    }   // si las coordenadas actuales encajan con la celda de salida es que llegamos a la salida

    int i = 0;
    while(i < 4){
        if(valido(mov[i], posY, posX, M, enemy_counter)){      // si es válido el movimiento nos movemos en la matriz en esa direccion
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
            int movF = mov[i][0];   // guardamos el valor de la coordenada en Y
            int movC = mov[i][1];   // guardamos el valor de la coordenada en X

            marcar(M, marca, posX, posY);   // marcamos esa celda de la matriz, la celda donde estamos indicamos la direccion que tomamos

            cout << endl;
            printMatriz(M);
            cout << endl;   // imprimimos antes de los pasos recursivos

            if(M[posY + movF][posX + movC][0] == 'M' || M[posY + movF][posX + movC][0] == 'O' || M[posY + movF][posX + movC][0] == 'G'){
                // enemy_counter++;
                // cout << "killed enemy!"<<endl; 
            }   // si llega a conseguirse a algún enemigo aumenta el contador de enemigos encontrados, que sería lo mismo a enemigos peleados

            // if(posY == 3 && posX == 6) cout << "CORNER " << endl;

            backtracking(M, posY + movF, posX + movC, b, enemy_counter);  // ejecutamos llamada recursiva de backtracking
            if(b == true){
                break;
            }   // cuando lleguemos a la solución detenemos todos los ciclos para finalizar las llamadas recursivas

            marcar(M, elemento, posX, posY);    // regresamos el movimiento anterior
            
            // Comenta estas líneas si no necesitas ver los pasos intermedios
        }
        i++;
    }
 // si ninguna opción fue correcta y tuvimos que regresarnos
}

int enemies(char M[][10][3], int f, int c){
    int count = 0;
    int i = 0;
    while(i < f){
        int j = 0;
        while(j < c){
            if(M[i][j][0] == 'O' || M[i][j][0] == 'G' || M[i][j][0] == 'M'){
                count++;
            }
            j++;
        }
        i++;
    }

    return count;
}

int main(){
    char M[10][10][3];

    char pared[3] = {'*', ' ',' '};
    char camino[3] = {'.', ' ', ' '};
    char entrada[3] = {'E', ' ', ' '};
    char salida[3] = {'S', ' ', ' '};

    for(int i = 0; i < 10; i++){
        for(int j = 0; j < 10; j++){
            for(int k = 0; k < 3; k++){
                M[i][j][k] = ' ';
            }
        }
    }   // llenado de matriz

    for(int i = 0; i < 10; i++){
        M[0][i][0] = '*';
    }
    for(int i = 0; i < 10; i++){
        M[i][0][0] = '*';
    }
    for(int i = 0; i < 10; i++){
        M[i][9][0] = '*';
    }
    for(int i = 0; i < 10; i++){
        M[9][i][0] = '*';
    }

    for(int i = 1; i < 5; i++){
        M[1][i][0] = '.';
    }

    M[1][5][0] = '*';
    
    for(int i = 6; i < 9; i++){
        M[1][i][0] = '.';
    }

    for(int i = 0; i < 9; i+=2){
        M[2][i][0] = '*';
        M[2][i+1][0] = '.';
    }

    M[2][9][0] = '*';

    for(int i = 0; i < 9; i+=2){
        M[3][i][0] = '*';
        M[3][i+1][0] = '.';
    }

    M[3][6][0] = '.';
    M[3][9][0] = '*';

    for(int i = 0; i < 9; i+=2){
        M[4][i][0] = '*';
        M[4][i+1][0] = '.';
    }

    M[4][4][0] = '.';
    M[4][5][0] = '*';
    M[4][9][0] = '*';

    for(int i = 0; i < 9; i+=2){
        M[5][i][0] = '*';
        M[5][i+1][0] = '.';
    }


    M[5][3][0] = '*';
    M[5][6][0] = '.';
    M[5][8][0] = '.';
    M[5][9][0] = '*';

    for(int i = 0; i < 9; i+=2){
        M[6][i][0] = '*';
        M[6][i+1][0] = '.';
    }

    M[6][4][0] = '.';
    M[6][6][0] = '.';
    M[6][7][0] = '*';
    M[6][9][0] = '*';

    for(int i = 0; i < 9; i+=2){
        M[7][i][0] = '*';
        M[7][i+1][0] = '.';
    }

    M[7][2][0] = '.';
    M[7][4][0] = '.';
    M[7][5][0] = '*';
    M[7][6][0] = '.';
    M[7][7][0] = '*';
    M[7][9][0] = '*';
    
    for(int i = 0; i < 9; i+=2){
        M[8][i][0] = '*';
        M[8][i+1][0] = '.';
    }

    M[8][4][0] = '.';
    M[8][4][0] = '.';
    M[8][3][0] = '*';
    M[8][5][0] = '*';
    M[8][6][0] = '.';
    M[8][7][0] = '.';
    M[8][8][0] = '.';

    M[5][0][0] = '*';

    M[0][3][0] = 'P';
    M[0][3][1] = 'E';

    M[8][9][0] = '*';
    M[7][9][0] = 'P';    
    M[7][9][1] = 'S';
    M[7][8][0] = '.';

    // Hasta aquí la matriz

    //Introducimos un enemigo
    M[2][3][0] = 'O';
    M[7][2][0] = 'M';
    M[2][5][0] = 'G';
  
    M[0][9][0] = 'G';       

    /*    
        ATENCIÓN

    
     M[0][9][0] = 'G';   // cambiamos la posición del gigante

     ahora tapamos la salida
     M[8][8][0] = '*';


        ATENCIÓN 
    */  

    //tapando la salida con un gigante
    M[7][8][0] = 'G';


    
    //preguntamos cuantos enemigos hay:
    int e = enemies(M, 10, 10);
    cout << "enemies? " << e << endl;

    for(int i = 0; i < 10; i++){
        for(int j = 0; j < 10; j++){
            cout << M[i][j][0] << ' ' << M[i][j][1] << ' ';
        }
        cout << endl;
    } 


    // Ahora aplicar el backtracking
    int posxE = posXE(M);
    int posyE = posYE(M);

    bool b = false;
    int eCounter = 0;

    backtracking(M, posyE, posxE, b, eCounter);

    cout << "dead enemies: " << eCounter << endl;

    cout << "there's ";

    
    if(b && (e == eCounter)){
        cout << "YOU GOT THE GLORY" << endl;
    }else if(b){
        cout << "YOU SURVIVE";
    } else {
        cout << "YOU DIE";
    }


    // cout << "Position in (x,y) of the Entrance: " << "( "<< posXE(M) << " , " << posYE(M) << " )" << endl;
    // cout << "Position in (x,y) of the Exit: " << "( "<< posXS(M) << " , " << posYS(M) << " )" << endl; 

    // cout << endl << endl;



    // cout << "Is valid the movement UP? ";
    // if(valido(mov[2], posXE(M), posYE(M), M)){
    //     cout << "Yes";
    // }else{
    //     cout << "No";
    // }

    return 0;
}