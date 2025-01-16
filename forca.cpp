#include <iostream>
#include <string>
#include <map>
#include <vector>
#include <fstream>
#include <ctime>
#include <cstdlib>
using namespace std;

string palavra_secreta = "MELANCIA";
map<char, bool> chutou;
vector<char> chutes_errados;
bool letra_existe(char chute){
    /*for(int i = 0; i < palavra_secreta.size(); i++){
        if (chute == palavra_secreta[i]){
            return true;
        }
    }

*///jeito de fazer em C++ e C porem no C++ 11 fizeram um novo jeito como o que vem a seguir
    for(char letra : palavra_secreta){
        if (chute == letra){
            return true;
        }
    }
    return false;
}

bool nao_acertou(){
    for(char letra : palavra_secreta){
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

    for (char letra : palavra_secreta){
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

vector<string> le_arquivo(){
    ifstream arquivo;
    arquivo.open("palavra.txt");

    if (!arquivo){
        cout << "Arquivo nao encontrado!" << endl;
    }else {
        int quantidade_palavras;
        arquivo >> quantidade_palavras;
        
        cout << "O arquivo possui " << quantidade_palavras << " palavras." << endl;

        vector<string> palavras_do_arquivo;
        int escolha;
        cout << "Quer ver as palavras da forca: "<<endl<<"(1)SIM (2)NAO : " ;
        cin >> escolha;
        for(int i = 0; quantidade_palavras > i; i++){
            string palavra_lida;
            arquivo >> palavra_lida;
            if (escolha == 1){
                cout <<"Na linha " << i+1 <<" : " << palavra_lida << endl;
            }
            
            
            palavras_do_arquivo.push_back(palavra_lida);
        }
        return palavras_do_arquivo;
    }
           
    arquivo.close();
}

void sorteia_palavra(){
    vector<string> palavras = le_arquivo();

    srand(time(NULL));
    int indice_sorteado = rand() % palavras.size();
    palavra_secreta = palavras[indice_sorteado];
}

int main () {
    imprime_cabecalho();

    sorteia_palavra();

    while (nao_acertou() && nao_enforcou()){//continua se não acertou ainda ou ainda não acabou as tentativas 
        
        imprime_erros();
        
        imprime_palavra();

        chute_usuario();
    }

    cout << "Fim de jogo!" <<endl << "A palavra secreta era: "<< palavra_secreta<< endl;
    if (nao_acertou()){
        cout << "Voce perdeu!" << endl;
    } else{
        cout << "Parabens! Voce acertou a palavra." << endl;
    }
}   
