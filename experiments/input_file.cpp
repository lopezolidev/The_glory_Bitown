#include <iostream>

//No usamos string muchachos...

using namespace std;

int vitalityEntry(){
    cout << "Insert vitality" << endl;
    int v = 0;
    cin >> v;
    while(v < 1){
        cout << "invalid vitality: " << endl;
        cin >> v;
    }
    cout << "vitality: " << v << endl;
    return v;
} // character vitality

string characterType(){
    char c; //solo un caracter será nuestro elemento de lectura

    cout << "insert type: " << endl;
    char type[2];

    int i = 0;
    while(i < 2){
        if(c != ' '){
            cin >> c;
            type[i] = c;
            i++;
        }
    } // loop to insert character type
    cout << "Type: " << type << endl;

    string t(type, type + sizeof(type));
    cout << "Type in string: " << t << endl;
    return t;
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

bool validator(char c){
    bool b = false;
    if(c == '*' || c == '.' || c == 'P' || c == 'E' || c == 'S' || c == 'O' || c == 'G' || c == 'A' || c == 'R'){
        b = true;
    }else if(c == '1' || c == '2' || c == '3' || c == '4' || c == '5' || c == '6' || c == '7' || c == '8' || c == '9'){
        b = true;
    }

    return b;
}

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

    // vitalityEntry();

    // characterType();

    int q = dungeonsQuant();

    int k = 0;
    while(k < q){

        dungeonCreator();
        k++;
    }

}

int main(){

    dataEntry();

    return 0;
}

// And that's it...