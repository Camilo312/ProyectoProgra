#include <iostream>
#include <string>

using namespace std;

string deleteCharacter(char, string);

int main() {
    cout<<deleteCharacter('c',"chocolate")<<endl;
//hoolate
}

string deleteCharacter(char c, string chain){
    //char temp = NULL;
    chain.erase(remove(&c));

    return chain;
}