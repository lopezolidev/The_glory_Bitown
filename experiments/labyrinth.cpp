#include <iostream>

using namespace std;

bool validar(char x, char y){
    bool b = false;
    if(!((x < 0 || x > 9) || (y < 0 || y > 9))){
        b = true;
    }
    return b;
}

int posXE(char M[][10][3]){
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


int posYE(char M[][10][3]){
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

int posXS(char M[][10][3]){
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


int posYS(char M[][10][3]){
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


void backtracking(char***& matrix, char c){

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

    return 0;
}