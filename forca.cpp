#include <iostream>
#include <string>
#include <map>
#include <vector>
using namespace std;

const string PALAVRA_SECRETA = "MELANCIA";
map<char, bool> chutou;
vector<char> chutes_errados;
bool letra_existe(char chute){
    /*for(int i = 0; i < PALAVRA_SECRETA.size(); i++){
        if (chute == PALAVRA_SECRETA[i]){
            return true;
        }
    }

*///jeito de fazer em C++ e C porem no C++ 11 fizeram um novo jeito como o que vem a seguir
    for(char letra : PALAVRA_SECRETA){
        if (chute == letra){
            return true;
        }
    }
    return false;
}



int main () {
    
    cout << "*****************************************" << endl;
    cout << "*******Bem vindos ao jogo da forca*******" << endl;
    cout << "*****************************************" << endl << endl;
    
    
    bool nao_acertou = true;
    bool nao_enforcou = true;

    while (nao_acertou && nao_enforcou){//continua se não acertou ainda ou ainda não acabou as tentativas 
        
        cout << "Chutes errados: ";
        for (char letra : chutes_errados) {
            cout << letra << " ";
        }
        cout << endl;
        for (char letra : PALAVRA_SECRETA){
            if (chutou[letra]){
                cout << letra << " ";
            }else{
                cout << "_ ";
            }
        } 
        cout << endl;
        cout << "Tente uma letra: ";
        char chute;
        cin >> chute;
 
        chutou[chute] = true;


        if(letra_existe(chute)){
            cout << endl<< "Voce acertou! Seu chute esta na palavra." << endl << endl;
        } else{
            cout << endl<< "Voce errou! Seu chute nao esta na palavra." << endl << endl;
            chutes_errados.push_back(chute);
        }
    }
}   
