#include "Pais.h"
#include <iostream>
#include <string>
using namespace std;

int Pais::getCodigo(){
    return this->codigo;
}
void Pais::setCodigo(int codigo_){
    this->codigo = codigo_;
}

string Pais::getNome(){
    return this->nome;
}
void Pais::setNome(string nome_){
    this->nome = nome_;
}

string Pais::getUf(){
    return this->uf;
}
void Pais::setUf(string uf_){
    this->uf = uf_;
}

// methods

void Pais::cadastrar_pais(Pais Paises[], int &total_paises, int MAX_PAISES) {
    system("clear");

    if (total_paises >= MAX_PAISES) {
        cout << "Limite máximo de países alcançado!\n";
        return;
    }

    string nome; string uf;
    cout << "\nRegistrando Novo País: \n";
    cout << "Digite o nome para o país: "; cin >> nome;
    cout << "Digite a UF do país: "; cin >> uf;


    Paises[total_paises].setCodigo(total_paises + 1); // define o código
    Paises[total_paises].setNome(nome);
    Paises[total_paises].setUf(uf);
    total_paises++;

    system("clear");
}

void Pais::listar_paises(Pais Paises[], int total_paises) {
    system("clear");

    cout << "Listando todos os países: \n";
    cout << "Código     |     UF      |      Nome\n";
    for (int i = 0; i < total_paises; i++) {
        cout << "[" << Paises[i].getCodigo() << "]              " << Paises[i].getUf() << "             " << Paises[i].getNome() << endl;
    }
    cin.ignore();
    cout << "\nAperte <Enter> para retornar ao menu anterior!\n";
    cin.get();
    
    system("clear");
}

void Pais::pesquisar_pais(Pais Paises[], int &total_paises){
   system("clear");
    int codigo;
    cout << "Digite o código que você deseja buscar: "; cin >> codigo;

   system("clear");

    int inicio = 0;
    int fim = total_paises - 1;
    int meio;
    bool busca = false;

    while (inicio <= fim) {
        meio = (inicio + fim) / 2;

        if (codigo == Paises[meio].codigo) {
            // Elemento encontrado
            cout << "\n---------------------------------------------------" << endl;
            cout << "                   Busca Encontrada!                  " << endl;
            cout << "---------------------------------------------------" << endl;
            cout << " Código:         " << Paises[meio].getCodigo() << endl;
            cout << " Nome:           " << Paises[meio].getNome() << endl;
            cout << " UF:             " << Paises[meio].getUf() << endl;
            cout << "---------------------------------------------------" << endl;
            busca = true;
            break;
        } else if (codigo > Paises[meio].getCodigo()) {
            // Pesquisar na metade direita
            inicio = meio + 1;
        } else {
            // Pesquisar na metade esquerda
            fim = meio - 1;
        }
    }


    if (!busca) {
        cout << "\nCódigo de Páis não encontrado!\n";
    }

    cin.ignore();
    cout << "\nAperte <Enter> para retornar ao menu anterior!\n";
    cin.get();
    system("clear");
}

