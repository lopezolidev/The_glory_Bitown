#include <iostream>
#include <string>

using namespace std;

int parser(string array, bool op){
    int arr[2];
    int n_1;
    int n_2;

    int pos = array.find(' ');

    n_1 = stoi(array.substr(0, pos));
    n_2 = stoi(array.substr(pos + 1));

    arr[0] = n_1;
    arr[1] = n_2;

    if(op) return arr[0];
    return arr[1];

    // cout << "arr[0] " << arr[0] << endl;
    // cout << "arr[1] " << arr[1] << endl;

    return 0;
}

char** createMat(int filas, int columnas) {
    char** matriz = new char*[filas]; // Crear un arreglo de punteros a chars

    for (int i = 0; i < filas; i++) {
        matriz[i] = new char[columnas]; // Crear un arreglo de chars para cada fila
    }

    return matriz;
}

void fillMat(char** mat, int rows, int cols){
    int i = 0;
    while(i < rows){
        int j = 0;
        while(j < cols){
            int value = i + j;
            string strValue = to_string(value);
            mat[i][j] = strValue[0];
            j++;
        }
        i++;
    }
}

void printMat(char** mat, int rows, int cols){
    int i = 0;
    while(i < rows){
        int j = 0;
        while(j < cols){
            cout << mat[i][j] << " ";
            j++;
        }
        cout << endl;
        i++;
    }
}

int main(){

    int vit = 0;
    char type[2];
    int dungeons = 0;
    string dimensions;
    string dung_conf = "";

    cout << "insert vitality: " << endl;
    cin >> vit;
    cout << endl;

    cout << "Insert type of warrior " << endl;
    cin >> type;
    cout << endl;

    cout << "Insert number of dungeons " << endl;
    cin >> dungeons;
    cout << endl;



    cout << "vitality: " << vit << endl;
    cout << "type: " << type << endl;
    cout << "dungeons: " << dungeons << endl;

    cout << "Matrix " << endl;
    cout << "Insert dimensions of dungeon " << endl;
    cin.ignore();
    getline(cin, dimensions);
    cout << endl;

    int rows = parser(dimensions, true);
    int cols = parser(dimensions, false);

    char** matx = createMat(rows, cols);
    fillMat(matx, rows, cols);
    printMat(matx, rows, cols);

    cout << "dimensions: " << rows << " " << cols << endl; 

    return 0;
}