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

bool nao_acertou(){
    for(char letra : PALAVRA_SECRETA){
        if (!chutou[letra]) {
            return true;
        }
    }
    return false;
}

bool nao_enforcou(){
    return chutes_errados.size() < 5;
}    

void imprime_cabecalho(){

    cout << "*****************************************" << endl;
    cout << "*******Bem vindos ao jogo da forca*******" << endl;
    cout << "*****************************************" << endl << endl;
    
}

void imprime_erros(){
    cout << "Chutes errados: ";
        for (char letra : chutes_errados) {
            cout << letra << " ";
        }
    cout << endl;
}

void imprime_palavra(){

    for (char letra : PALAVRA_SECRETA){
        if (chutou[letra]){
            cout << letra << " ";
        }else{
            cout << "_ ";
        }
    } 
    cout << endl;
}

void chute_usuario(){
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
int main () {
    imprime_cabecalho();

    while (nao_acertou() && nao_enforcou()){//continua se não acertou ainda ou ainda não acabou as tentativas 
        
        imprime_erros();
        
        imprime_palavra();

        chute_usuario();
    }

    cout << "Fim de jogo!" <<endl << "A palavra secreta era: "<< PALAVRA_SECRETA<< endl;
    if (nao_acertou()){
        cout << "Voce perdeu!" << endl;
    } else{
        cout << "Parabens! Voce acertou a palavra." << endl;
    }
}   
