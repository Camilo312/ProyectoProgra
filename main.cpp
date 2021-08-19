#include <iostream>
#include <string>
#include <cstring>

using namespace std;

int WordNumber(string sentence, string word);

string encrypt(string sentence);

string desencriptar(string sentence);

string fillCharacters(string wordString, string letters, int cant, string side);


int main() {
    int menu;
    char op;
    string word;
    string stringencrypted;
    string letters;
    string side;
    int cant;
    string wordString = "Sogamoso Ciudad del Sol y del Acero";
    cout
            << "1.Convertir en nombre propio el contenido de la cadena\n2.Buscar palabra\n3.Encriptar cadena\n4.Desencriptar"
               "\n5.Llenar cacarter por izquierda o por derecha\n6.Borrar cracteres de una cadena\n7.Interseccion\n8.Diferencia entre dos cadenas"
               "\n9.Borrar caracteres iziquierda o derecha\n"
               "10.Validar correo electronico\n11.Salir\n--------------------------------" << endl;
    cin >> menu;
    cout << "Desea utilizar la oracion por defecto?(y/n)\n--------------------------------" << endl;
    cin >> op;
    if (op == 'n') {
        cout << "Ingrese la oracion:\n--------------------------------" << endl;
        cin >> wordString;
    }
    switch (menu) {
        case 1 :
            break;
        case 2:
            cout << "Ingrese la palabra a buscar:\n--------------------------------" << endl;
            cin >> word;
            cout<<WordNumber(wordString, word);
            break;
        case 3:
            cout << "La oracion " << wordString << " encriptada es: " << encrypt(wordString);
            break;
        case 4:
            cout << "Debe encriptar primero una oracion, ingrese una a encriptar" << endl;
            cin >> stringencrypted;
            cout << "La oracion encriptada es: " << encrypt(stringencrypted) << endl;
            cout << "La oracion desencriptada es: " << desencriptar(stringencrypted) << endl;
            break;
        case 5:
            cout << "Digite las letras a rellenar en la oracion:" << endl;
            cin >> letters;
            cout << "Ingrese la cantidad de letras con las que se va a rellenar" << endl;
            cin >> cant;
            cout << "Ingrese si desea llenar los caracteres por izquierda o por derecha: (i/d) " << endl;
            cin >> side;
            cout<<"La cadena queda asi: "<<fillCharacters(wordString, letters, cant, side)<<endl;
        case 6:

            break;
    }

    return 0;
}


//Contar el numero de veces que existe una palabra en una cadena
int WordNumber(string chain, string word) {
    char chainaux[chain.length() + 1];
    char wordaux[word.length() + 1];
    strcpy(chainaux, chain.c_str());
    strcpy(wordaux, word.c_str());
    int count = 0;
    char *tok;
    tok = strtok(chainaux, " .,:;");
    while (tok != NULL) {
        if (stricmp(tok, wordaux) == 0) {
            cout << "entro";
            count++;
        }
        tok = strtok(NULL, " .,:;");
    }
    return count;
}

//Encriptar
string encrypt(string sentence) {
    for (int i = 0; i < sentence.length(); ++i) {
        sentence[i] = (char) (sentence[i] + (char) 8);
    }
    return sentence;
}

//Desencriptar
string desencriptar(string sentence) {
    for (int i = 0; i < sentence.length(); ++i) {
        sentence[i] = (char) (sentence[i] - (char) 8);
    }
    return sentence;
}

//Llenar caracteres por izquierda o por derecha
string fillCharacters(string wordString, string letters, int cant, string side) {
    string z = "", b = "";
    string finalSentence = "";
    for (int i = 0; i < cant; i++) {
        b = letters;
        z += b;
    }
    if (side == ("i")) {
        finalSentence = z + wordString;
    } else if (side == ("d")) {
        finalSentence = wordString + z;
    }
    return finalSentence;
}