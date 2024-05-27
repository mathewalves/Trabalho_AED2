#include "Guia.h"
#include "Cidade.h"
#include <iostream>
#include <string>
using namespace std;

int Guia::getCodigo(){
    return this->codigo;
}
void Guia::setCodigo(int codigo_){
    this->codigo = codigo_;
}

string Guia::getNome(){
    return this->nome;
}
void Guia::setNome(string nome_){
    this->nome = nome_;
}

string Guia::getEndereco(){
    return this->endereco;
}
void Guia::setEndereco(string endereco_){
    this->endereco = endereco_;
}

string Guia::getTelefone(){
    return this->telefone;
}
void Guia::setTelefone(string telefone_){
    this->telefone = telefone_;
}

int Guia::getCodigoCidade(){
    return this->codigo_cidade;
}
void Guia::setCodigoCidade(int codigo_cidade_){
    this->codigo_cidade = codigo_cidade_;
}

// methods

void Guia::cadastrar_guia(Guia Guias[], int &total_guias, int MAX_CADASTROS) {
    system("clear");

    if (total_guias >= MAX_CADASTROS) {
        cout << "Limite máximo de cadastros alcançado!\n";
        return;
    }

    string nome, endereco, telefone;
    int codigo_cidade;
    
    cout << "Digite o nome para o Guia: "; cin >> nome;
    cout << "Digite o endereço: "; cin >> endereco;
    cout << "Digite o telefone: "; cin >> telefone;
    cout << "Digite o código da cidade: "; cin >> codigo_cidade;

    Guias[total_guias].setCodigo(total_guias + 1); // define o código
    Guias[total_guias].setNome(nome);
    Guias[total_guias].setTelefone(telefone);
    Guias[total_guias].setEndereco(endereco);
    Guias[total_guias].setCodigoCidade(codigo_cidade);



    total_guias++;

    system("clear");
}

void Guia::listar_guia(Guia Guias[], Cidade Cidades[], Pais Paises[], int total_guias) {
    system("clear");
    int codigo_cidade, codigo_pais;
    string cidade, pais, uf;

    cout << "Listando todos os guias: \n";
    cout << "Código     |     Nome      |      Telefone      |      Endereço\n";
    for (int i = 0; i < total_guias; i++) {
        codigo_cidade = Guias[i].getCodigoCidade() - 1;
        cidade = Cidades[codigo_cidade].getNome();
        uf = Cidades[codigo_cidade].getUf();

        codigo_pais = Cidades[codigo_cidade].getCodigoPais() - 1;
        pais = Paises[codigo_pais].getNome();

        cout << "[" << Guias[i].getCodigo() << "]              " << Guias[i].getNome() << "             " << Guias[i].getTelefone() << "          " << Guias[i].getEndereco() << " " << cidade << " " << uf << " " << pais << endl;
    }
    cin.ignore();
    cout << "\nAperte <Enter> para retornar ao menu anterior!\n";
    cin.get();
    
    system("clear");
}

void Guia::pesquisar_guia(Guia Guias[], Cidade Cidades[], Pais Paises[], int &total_guias){
   system("clear");
    int codigo;
    cout << "Digite o código que você deseja buscar: "; cin >> codigo;

   system("clear");

    int inicio = 0;
    int fim = total_guias - 1;
    int meio;
    bool busca = false;

    int codigo_cidade, codigo_pais;
    string cidade, pais, uf;

    while (inicio <= fim) {
        meio = (inicio + fim) / 2;

        if (codigo == Guias[meio].codigo) {
            // Elemento encontrado
            codigo_cidade = Guias[meio].getCodigoCidade() - 1;
            cidade = Cidades[codigo_cidade].getNome();
            uf = Cidades[codigo_cidade].getUf();

            codigo_pais = Cidades[codigo_cidade].getCodigoPais() - 1;
            pais = Paises[codigo_pais].getNome();

            cout << "\n---------------------------------------------------" << endl;
            cout << "                   Busca Encontrada!                  " << endl;
            cout << "---------------------------------------------------" << endl;
            cout << " Código:         " << Guias[meio].getCodigo() << endl;
            cout << " Nome:           " << Guias[meio].getNome() << endl;
            cout << " Telefone:             " << Guias[meio].getTelefone() << endl;
            cout << " Endereco:             " << Guias[meio].getEndereco() << " " << cidade << " " << uf << " " << pais << endl;
            cout << "---------------------------------------------------" << endl;
            busca = true;
            break;
        } else if (codigo > Guias[meio].getCodigo()) {
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

