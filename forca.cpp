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

   if(arquivo.is_open()){
        int quantidade_palavras;
        arquivo >> quantidade_palavras;
        
        cout << "O arquivo possui " << quantidade_palavras << " palavras." << endl;

        vector<string> palavras_do_arquivo;
        char escolha;
        cout << "Quer ver as palavras da forca? (S/N): " ;
        cin >> escolha;
        for(int i = 0; quantidade_palavras > i; i++){
            string palavra_lida;
            arquivo >> palavra_lida;
            if (escolha == 'S'){
                cout <<"Na linha " << i+1 <<" : " << palavra_lida << endl;
            }

            
            palavras_do_arquivo.push_back(palavra_lida);
        }
        arquivo.close();
        return palavras_do_arquivo;
    }else{
        cout << "Arquivo nao encontrado!" << endl;
        exit(0);
    }
      
}

void sorteia_palavra(){
    vector<string> palavras = le_arquivo();

    srand(time(NULL));
    int indice_sorteado = rand() % palavras.size();
    palavra_secreta = palavras[indice_sorteado];
}

void salva_arquivo(vector<string> nova_lista){
    ofstream arquivo;
    arquivo.open("palavra.txt");
    if(arquivo.is_open()){
        arquivo << nova_lista.size() << endl;
        for(string palavra : nova_lista) {
            arquivo << palavra << endl;
        }

        arquivo.close();
    }else{
        cout << "Erro ao abrir arquivo!" << endl;
        exit(0);
    }
}

void adiciona_palavra(){
    string palavra;
    cout << "Digite a palavra que deseja adicionar usando letras maiusculas: ";
    cin >> palavra;

    vector<string> lista_palavras = le_arquivo();
    lista_palavras.push_back(palavra);

    salva_arquivo(lista_palavras);
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
        
        
        cout<< "Voce deseja adicionar uma nova palavra ao banco? (S/N)";
        char resposta;
        cin >> resposta;
        if(resposta == 'S'){
            adiciona_palavra();
        }
    }
}   
