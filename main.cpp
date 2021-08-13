#include <iostream>
#include <string>

using namespace std;

int main() {
    std::cout << "Hello KK" << std::endl;
    return 0;
}

string deleteCharacter(char c, string chain){
    char temp = NULL;
    for (char & i : chain) {
        if(i == c){
            i = temp;
            cout<<chain;
        }
    }
    return chain;
}