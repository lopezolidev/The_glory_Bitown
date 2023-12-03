/*
    Implementing a backtracking algorithm to locate n-queens ('n' any integer) in a matrix without attacking each other in any number of possible locations
*/

#include <iostream>

using namespace std;

void printBoard(bool **A, int N){

}

bool locateQueen(bool **A, int i, int j){    // aids us to know if there're any more queens in other locations
    int x = 1;
    while(i - x >= 0 && j - x >= 0){
        if(A[i-x][j-x]) return false;
        x++;
    }
    x = 0;
    while(i + x < i && j + x < j){      // ???
        if(A[i + x][j + x]) return false;
        x++;
    }

    return true;
}

void nQueens(bool **A, int N, int row){
    if(row >= N){   //when we're outside of the matrix surpassing the last row
        printBoard(A,N);
        return;
    }
    for(int i = 0; i < N; i++){
        if(locateQueen(A, row, i)){
            A[row][i] = true;
            nQueens(A, N, row + 1);
            A[row][i] = false;
        }
    }
}

int main(){

    return 0;
}