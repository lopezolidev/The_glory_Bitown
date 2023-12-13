#include <iostream>

using namespace std;

int posYE(char M[][10][3]){
    int i= 0;
    while(i < 10){
        int j = 0;
        while(j < 10){
                if(M[i][j][0] == 'E'){
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
                if(M[i][j][0] == 'E'){
                    return j;
                }
            j++;
        }
        i++;
    }
    return -1;
}

int posYS(char M[][10][3]){
    int i= 0;
    while(i < 19){
        int j = 0;
        while(j < 10){
                if(M[i][j][0] == 'S'){
                    return i;
                }
            j++;
        }
        i++;
    }
    return -1;
}


int posXS(char M[][10][3]){
    int i= 0;
    while(i < 10){
        int j = 0;
        while(j < 10){
                if(M[i][j][0] == 'S'){
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

bool valido(int* fila, int posX, int posY, char M[][10][3]){
    int movX = fila[1];
    int movY = fila[0];

    bool b = false;

    if(!((movX + posX < 0 || movX + posX > 9) || (movY + posY < 0 || movY + posY > 9) || M[movY + posY][movX + posX][0] == '*')){
        b = true;
    }

    return b;
} // funcion validar → asegurando que la celda es valida para cruzar

void backtracking(char M[][10][3], int posX, int posY, int sX, int sY){
    if(M[posX][posY][0] == 'S'){
        cout << "Salida!" << endl;
        return;
    }
    int i = 0;
    while(i < 4){
        if(valido(mov[i], posX, posY, M)){

        }
        i++;
    }
}

int main(){
    char M[10][10][3];

    char pared[3] = {'*', ' ',' '};
    char camino[3] = {'.', ' ', ' '};
    char entrada[3] = {'E', ' ', ' '};
    char salida[3] = {'S', ' ', ' '};

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

    M[5][0][0] = 'E';
    M[7][9][0] = 'S';

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

    M[5][0][0] = 'E';
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
    M[8][9][0] = 'S';

    // Hasta aquí la matriz

    for(int i = 0; i < 10; i++){
        for(int j = 0; j < 10; j++){
            cout << M[i][j][0] << ' ';
        }
        cout << endl;
    } 


    // Ahora aplicar el backtracking

    // backtracking(M);

    cout << "Position in (x,y) of the Entrance: " << "( "<< posXE(M) << " , " << posYE(M) << " )" << endl;
    cout << "Position in (x,y) of the Exit: " << "( "<< posXS(M) << " , " << posYS(M) << " )" << endl; 

    cout << endl << endl;



    cout << "Is valid the movement UP? ";
    if(valido(mov[2], posXE(M), posYE(M), M)){
        cout << "Yes";
    }else{
        cout << "No";
    }

    return 0;
}