#include <iostream>

//No usamos string muchachos...

using namespace std;

int main(){

    char c; //solo un caracter será nuestro elemento de lectura

    cout << "Insert number of rows and columns" << endl;
    int a, b;

    //columnas y filas

    cin >> a >> b;

    //insertamos columnas y filas. No importan los espacios en blanco

    cout << "rows: " << a << " columns: " << b << endl;

    //mostramos filas y columnas

    int i = 0;
    //elemento iterador, nos dirá hasta cuando iterar por la línea (columnas)

    while(i < b){   // La magia...
        cin >> c;
        // este caracter se podrá mover por toda  la fila

        if(c != ' '){ 
            //si el caracter es vacío no mostramos ni contamos esa entrada como válida (no aumentamos el iterador)
            i++;
            cout << c << endl;
            //mostramos en pantalla lo que escribamos
        } 
    }

    return 0;
}

// And that's it...