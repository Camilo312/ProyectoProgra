#include <iostream>
#include <string>
#include <cstring>
#include <algorithm>
#include <regex>

using namespace std;

int WordNumber(string, string);
//j
string encrypt(string);

string decrypt(string);

string fillCharacters(string, string, int, char);

string ownName(string sentence);

string deleteCharacter(string, string);

string intersection(string, string);

string diference(string, string);

string deleteCharacterDirection(string, string, char);

string isvalidEmail(string);

void menu();

int main() {
    string wordString = "sogamoso ciudad del sol y del acero";
    char ex = 0;
    int menu, cant;
    char op;

    cout<<"Oracion por defecto: "<<wordString<<endl;
    cout << "Desea utilizar la oracion por defecto?(y/n)\n-----------------------------------------------------------"
    << endl;
    cin >> op;
    if (op == 'n') {
        cout << "Ingrese la oracion:\n-----------------------------------------------------------" << endl;
        cin >> wordString;
    }
    do{
        cout << "1.Convertir en nombre propio el contenido de la cadena\n2.Buscar palabra\n3.Encriptar cadena\n4.Desencriptar"
                "\n5.Llenar cacarter por izquierda o por derecha\n6.Borrar cracteres de una cadena\n7.Interseccion\n8.Diferencia entre dos cadenas"
                "\n9.Borrar caracteres iziquierda o derecha\n"
                "10.Validar correo electronico\n11.Salir\n-----------------------------------------------------------"
                << endl;

        cin >> menu;

        switch (menu) {
            case 1 :
                cout << ownName(wordString) << endl;
                break;
                case 2: {
                    string word;
                    cout << "Ingrese la palabra a buscar:" << endl;
                    cin >> word;
                    cout << "Se ha encontrado: " << WordNumber(wordString, word) << " veces la palabra: " << word << endl;
                    break;
                }
                case 3: {
                    char desenc;
                    string encripted = encrypt(wordString);
                    cout << "La oracion " << wordString << " encriptada es: " << encripted <<endl;
                    cout << "Desea desencriptar la oracion?(y/n)" << endl;
                    cin >> desenc;
                    if (tolower(desenc) == 'y') {
                        cout << "La oracion desencriptada es: " << decrypt(encripted) << endl;
                    }
                    break;
                }
                case 4: {
                    char x;
                    string chain;
                    cout << "Tiene una cadena encriptada?, en caso de no tener una se desencriptara la oracion por defecto(y/n)"<<endl;
                    cin >> x;
                    if (tolower(x) == 'y'){
                        cout<<"Ingrese la cadena"<<endl;
                        cin>>chain;
                        cout << "La oracion desencriptada es: " << decrypt(chain) << endl;
                    }else{
                        string encripted = encrypt(wordString);
                        cout<<"La oracion por defecto encriptada es: "<< encripted<<endl;
                        cout << "La oracion desencriptada es: " << decrypt(encripted) << endl;
                    }
                    break;
                }
                case 5: {
                    string letters;
                    char side;
                    cout << "Digite las letras a rellenar en la oracion:" << endl;
                    cin >> letters;
                    cout << "Ingrese la cantidad de letras con las que se va a rellenar" << endl;
                    cin >> cant;
                    cout << "Ingrese si desea llenar los caracteres por izquierda o por derecha: (i/d) " << endl;
                    cin >> side;
                    cout << "La cadena queda asi: " << fillCharacters(wordString, letters, cant, side) << endl;
                    break;
                }
                case 6: {
                    string characters;
                    cout << "Ingrese los caracteres a eliminar:" << endl;
                    cin >> characters;
                    cout << "Se han eliminado los caracteres " << characters << "de la oracion" << wordString << endl;
                    cout << "El resultado es: " << deleteCharacter(characters, wordString) << endl;
                    break;
                }
                case 7: {
                    string chain2;
                    cout << "La oracion 1 es: " << wordString << endl;
                    cout << "Ingrese la oracion 2: " << endl;

                    cin >> chain2;
                    cout << "La interseccion de las oraciones es: " << intersection(wordString, chain2) << endl;
                    break;
                }
                break;
                case 8:{
                    string chain2;
                    cout << "La oracion 1 es: " << wordString << endl;
                    cout << "Ingrese la oracion 2: " << endl;
                    cin >> chain2;
                    cout << "La difrencia entre las dos cadenas es: " << diference(wordString, chain2) << endl;
                    break;
                }
                case 9:{
                    string chain;
                    char side;
                    cout<<"Ingrese la cadena a eliminar: "<<endl;
                    cin>>chain;
                    cout << "Ingrese si desea eliminar la cadena por izquierda o por derecha: (i/d) " << endl;
                    cin >> side;
                    cout<<"La cadena eliminada: "<<deleteCharacterDirection(wordString,chain,side)<<endl;
                    break;
                }
                case 10:{
                    string email;
                    cout<<"Digite correo electronico: "<<endl;
                    cin>>email;
                    cout<<"El correo "<<email<<" "<<isvalidEmail(email)<<endl;
                    break;
                }
                default:
                    cout<<" Se ha salido "<<endl;
                    exit(0);

        }
        cout<<"Desea volver a utilizar el programa?(y/n)"<<endl;
        cin>>ex;

        ex = tolower(ex)=='n' ? -1 : 0;

    }while(ex == 0);
    return 0;
}

string ownName(string sentence) {
    char sentenceAux[sentence.length() + 1];
    strcpy(sentenceAux, sentence.c_str());
    for (int i = 0; i < strlen(sentenceAux) - 2; ++i) {
        if (sentenceAux[i] == ' ' || sentenceAux[i] == '.' || sentenceAux[i] == ',' || sentenceAux[i] == 'y') {
            sentenceAux[0] = toupper(sentenceAux[0]);
            sentenceAux[i + 1] = toupper(sentenceAux[i + 1]);
        }
    }
    return sentenceAux;
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
            count++;
        }
        tok = strtok(NULL, " .,:;");
    }
    return count;
}

//Encriptar una cadena de caracteres
string encrypt(string sentence) {
    for (int i = 0; i < sentence.length(); ++i) {
        sentence[i] = (char) (sentence[i] + (char) 8);
    }
    return sentence;
}

//Desencriptar una cadena de caracteres
string decrypt(string sentence) {
    for (int i = 0; i < sentence.length(); ++i) {
        sentence[i] = (char) (sentence[i] - (char) 8);
    }
    return sentence;
}

//Llenar caracteres por izquierda o por derecha
string fillCharacters(string wordString, string letters, int cant, char side) {
    string z = "", b = "";
    string finalSentence = "";
    for (int i = 0; i < cant; i++) {
        b = letters;
        z += b;
    }
    if (tolower(side) == 'i') {
        finalSentence = z + wordString;
    } else if (tolower(side) == 'd') {
        finalSentence = wordString + z;
    }
    return finalSentence;
}

//Elimina los caracteres de una cadena
string deleteCharacter(string c, string chain) {
    for (int i = 0; i < chain.length(); ++i) {
        for (char x:c) {
            if (tolower(chain[i]) == tolower(x)) chain.erase(i, 1);
        }
    }
    return chain;
}

//Intersecta los caracteres que coinciden en dos cadenas
string intersection(string chain1, string chain2) {
    string aux;
    for (char c: chain2) {
        for (char k: chain1) {
            if (c == k) {
                if (aux.find(k) < aux.length()) {
                    continue;
                }
                aux += k;
            }
        }
    }

    return aux;
}

//Se mira la diferncia entre dos cadenas de caracteres
string diference(string chain1, string chain2) {
    string aux = chain1;
    for (char c: chain2) {
        for (char k: chain1) {
            if (c == k) {
                aux = deleteCharacter(string(1,k), aux);
            }
        }
    }

    return aux;
}

//Borra la cadena dependiendo de la direccion y si coincide
string deleteCharacterDirection(string chain1, string chain2, char dir) {
    if (tolower(dir) == 'd') {
        reverse(chain1.begin(), chain1.end());
        reverse(chain2.begin(), chain2.end());
    }
    string aux = chain1;
    for (int i = 0; i < chain1.length(); ++i) {
        if (chain1[i] == chain2[i]) {
            aux = aux.erase(0, 1);
        }
    }

    if (tolower(dir) == 'd') reverse(aux.begin(), aux.end());

    return aux;
}

//Validar correo electronico
string isvalidEmail(string email) {
    const regex expresion("([a-z]+)([_.a-z0-9]*)([a-z0-9]+)(@)([a-z]+)([.a-z]+)([a-z]+)");
    return regex_match(email, expresion)?"Valido":"Invalido";
}