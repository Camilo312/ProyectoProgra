#include <iostream>
#include <string>
#include <stdlib.h>
#include <stdio.h>
#include <cstring>

using namespace std;

int WordNumber(char sentence[ ],char word[ ]);
string encrypt(char sentence[ ]);
string desencripatr(char sentence[]);
string fillCharacters(string wordString, string letters, int cant, string side);
int main() {
    int menu;
    char sentence[ ]="Sogamoso Ciudad del Sol y del Acero";
    string wordString ="Sogamoso Ciudad del Sol y del Acero";
    char word[ ]="del";
   cout<<"1.Convertir en nombre propio el contenido de la cadena\n2.Buscar palabra\n3.Encriptar cadena\n4.Desencriptar"
         "\n5.Llenar cacarter por izquierda o por derecha\n6.Borrar cracteres de una cadena\n7.Interseccion\n8.Diferencia entre dos cadenas"
         "\n9.Borrar caracteres iziquierda o derecha\n"
         "10.Validar correo electronico\n11.Salir"<<endl;
   cin>>menu;

    switch (menu) {
        case 1:
            break;
        case 2:
            int count;
            char *tok;
            tok = strtok(sentence," .,:;");
            count=0;
            while(tok != NULL){
                if(stricmp(tok,word)==0){
                    count++;
                }
                tok = strtok(NULL," .,:;");
            }
            cout<<"La palabra "<<word<<" se necuentra "<<count<<" veces"<<endl;
            //No funciona la pasada por parametros
            //cout<<WordNumber(sentence,word)<<endl;
            break;
        case 3:
            for (int i = 0; i < strlen(sentence); ++i) {
                sentence[i] = (char)(sentence[i]+(char)8);
            }
            cout<<"Encriptacion de la cadena "<<sentence<<endl;
            //No funciona la pasada por parametros
            //cout<<encrypt(sentence)<<endl;
            break;
        case 4:
            for (int i = 0; i < strlen(sentence); ++i) {
                sentence[i] = (char)(sentence[i]-(char)8);
            }
            cout<<"Desencriptacion de la cadena "<<sentence<<endl;
            //No funciona la pasado por parametros
            //cout<< desencripatr(sentence)<<endl;
            break;
        case 5:
            cout<<fillCharacters(wordString,"a",5,"izquierda")<<endl;
            break;
        case 6:
            break;
        case 7:
            break;
        case 8:
            break;
        case 9:
            break;
        case 10:
            break;
        case 11:
            exit(0);
            break;
    }
    return 0;
}
//Contar el numero de veces que existe una palabra en una cadena
int WordNumber(char sentence[ ],char word[ ]){
    int count=0;
    char *tok;

    tok = strtok(sentence," .,:;");
    while(tok != NULL){
        if(stricmp(tok,word)==0){
            count++;
        }
        tok = strtok(NULL," .,:;");
    }
    return count;
}

//Encriptar
string encrypt(char sentence[]){
    for (int i = 0; i < strlen(sentence); ++i) {
        sentence[i] = (char)(sentence[i]+(char)8);
    }
    return sentence;
}

//Desencriptar
string desencripatr(char sentence[]){
    for (int i = 0; i < strlen(sentence); ++i) {
        sentence[i] = (char)(sentence[i]-(char)8);
    }
    return sentence;
}

//Llenar caracteres por izquierda o por derecha
string fillCharacters(string wordString, string letters, int cant, string side){
    string z = "", b = "";
    string finalSentence = "";
    for (int i = 0; i < cant; i++) {
        b = letters;
        z += b;
    }
    if (side==("izquierda")) {
        finalSentence = z + wordString;
    } else if (side==("derecha")) {
        finalSentence = wordString + z;
    }
    return finalSentence;
}