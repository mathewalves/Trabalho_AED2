#include "Cidade.h"
#include "Pais.h"
#include <iostream>
#include <string>

using namespace std;

int Cidade::getCodigo(){
    return this->codigo;
}
void Cidade::setCodigo(int codigo_){
    this->codigo = codigo_;
}

string Cidade::getNome(){
    return this->nome;
}
void Cidade::setNome(string nome_){
    this->nome = nome_;
}

int Cidade::getCodigoPais(){
    return this->codigoPais;
}

void Cidade::setCodigoPais(int codigoPais_){
    this->codigoPais = codigoPais_;
}

string Cidade::getUf(){
    return this->uf;
}
void Cidade::setUf(string uf_){
    this->uf = uf_;
}

// methods

void Cidade::cadastrar_cidade(Cidade Cidades[], Pais Paises[], int &total_cidades, int &total_paises, int MAX_CADASTROS) {
    system("clear");

    if (total_cidades >= MAX_CADASTROS) {
        cout << "Limite máximo de cidades alcançado!\n";
        return;
    }

    string nome, uf;
    int codigoPais;
    cout << "\nRegistrando nova [Cidade]: \n";
    cout << "Digite o nome para a cidade: "; cin >> nome;
    cout << "Digite a UF do estado: "; cin >> uf;
    cout << "Código do País: "; cin >> codigoPais;

    int inicio = 0;
    int fim = total_paises - 1;
    int meio;
    bool busca = false;

    while (inicio <= fim) {
        meio = (inicio + fim) / 2;

        if (codigoPais == Paises[meio].getCodigo()) {
            // Elemento encontrado
            Cidades[total_cidades].setCodigo(total_cidades + 1);
            Cidades[total_cidades].setNome(nome);
            Cidades[total_cidades].setUf(uf);
            Cidades[total_cidades].setCodigoPais(codigoPais);
            total_cidades++;
            busca = true;
            system("clear");
            break;
        } else if (codigoPais > Paises[meio].getCodigo()) {
            // Pesquisar na metade direita
            inicio = meio + 1;
        } else {
            // Pesquisar na metade esquerda
            fim = meio - 1;
        }
    }

    // Verifica se o elemento foi encontrado
    if (!busca) {
        cout << "\nCódigo de país não encontrado!\n";
    }

}

void Cidade::listar_cidades(Cidade Cidades[], Pais Paises[], int total_cidades) {
    system("clear");
    int codigoPais;
    cout << "Listando todas as cidades: \n";
    cout << "Código     |     Nome      |      País\n";
    for (int i = 0; i < total_cidades; i++) {
        codigoPais = Cidades[i].getCodigoPais();
        cout << "[" << Cidades[i].getCodigo() << "]             " << Cidades[i].getNome() << "            " << Paises[codigoPais - 1].getNome() << endl;
    }

    cin.ignore();
    cout << "\nAperte <Enter> para retornar ao menu anterior!\n";
    cin.get();

    system("clear");
}

void Cidade::pesquisar_cidade(Cidade Cidades[], Pais Paises[], int &total_cidades){
    system("clear");
    int codigo;
    cout << "Digite o código que você deseja buscar: "; cin >> codigo;

    int inicio = 0;
    int fim = total_cidades - 1;
    int meio;
    bool busca = false;


    while (inicio <= fim) {
        meio = (inicio + fim) / 2;

        if (codigo == Cidades[meio].codigo) {
            // Elemento encontrado
            int codigoPais;
            codigoPais = Cidades[meio].getCodigoPais();
            cout << "\n---------------------------------------------------" << endl;
            cout << "                   Busca Encontrada!                  " << endl;
            cout << "---------------------------------------------------" << endl;
            cout << " Código:         " << Cidades[meio].getCodigo() << endl;
            cout << " Nome:           " << Cidades[meio].getNome() << endl;
            cout << " País:           " << Paises[codigoPais - 1].getNome() << endl;
            cout << "---------------------------------------------------" << endl;
            busca = true;
            break;
        } else if (codigo > Cidades[meio].getCodigo()) {
            // Pesquisar na metade direita
            inicio = meio + 1;
        } else {
            // Pesquisar na metade esquerda
            fim = meio - 1;
        }
    }

    if (!busca) {
        cout << "\nCódigo de cidade não encontrado!\n";
    }

    cin.ignore();
    cout << "\nAperte <Enter> para retornar ao menu anterior!\n";
    cin.get();
    system("clear");

}
