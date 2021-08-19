#include <iostream>
#include <string>
#include <algorithm>
#include <regex>

using namespace std;

string deleteCharacter(string, string);

string intersection(string, string);

string diference(string, string);

string deleteCharacterDirection(string, string, int);

bool isvalidEmail(string);

int main() {
    string test = "oae";
    const string chain1 = "Sogamoso Ciudad del Sol y del Acero";
    cout<<deleteCharacter(test,chain1)<<endl;
    cout<<intersection(chain1,"colombia")<<endl;
    cout<<diference(chain1,"colombia")<<endl;
    cout << deleteCharacterDirection(chain1, "Acero", 2)<<endl;
    cout<<isvalidEmail("camilo@mail.com");

}

string deleteCharacter(string c, string chain) {
    for (int i = 0; i < chain.length(); ++i) {
        for (char x:c) {
            if (chain[i] == x) chain.erase(i, 1);
        }
    }
    return chain;
}

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

string diference(string chain1, string chain2) {
    string aux = chain1;
    for (char c: chain2) {
        for (char k: chain1) {
            if (c == k) {
                aux = deleteCharacter(to_string(k), aux);
            }
        }
    }

    return aux;
}

string deleteCharacterDirection(string chain1, string chain2, int dir) {
    if (dir == 2) {
        reverse(chain1.begin(), chain1.end());
        reverse(chain2.begin(), chain2.end());
    }
    string aux = chain1;
    for (int i = 0; i < chain1.length(); ++i) {
        if (chain1[i] == chain2[i]) {
            aux = aux.erase(0, 1);
        }
    }

    if (dir == 2) reverse(aux.begin(), aux.end());

    return aux;
}

bool isvalidEmail(string email){
    const regex expresion("([a-z]+)([_.a-z0-9]*)([a-z0-9]+)(@)([a-z]+)([.a-z]+)([a-z]+)");
    return regex_match(email,expresion);
}