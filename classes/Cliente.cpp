#include "Cliente.h"
#include <iostream>
#include <string>
using namespace std;

string Cliente::getCPF(){
    return this->cpf;
}
void Cliente::setCPF(string cpf_){
    this->cpf = cpf_;
}

string Cliente::getNome(){
    return this->nome;
}
void Cliente::setNome(string nome_){
    this->nome = nome_;
}

string Cliente::getEndereco(){
    return this->endereco;
}
void Cliente::setEndereco(string endereco_){
    this->endereco = endereco_;
}

int Cliente::getCodigoCidade(){
    return this->codigo_cidade;
}
void Cliente::setCodigoCidade(int codigo_cidade_){
    this->codigo_cidade = codigo_cidade;
}

// methods

void Cliente::cadastrar_cliente(Cliente Clientes[], int &total_clientes, int MAX_CADASTROS) {
    system("clear");

    if (total_clientes >= MAX_CADASTROS) {
        cout << "Limite máximo de países alcançado!\n";
        return;
    }

    int codigo_cidade;
    string nome, endereco, cpf;
    cout << "\nRegistrando Novo Cliente: \n";
    cout << "Digite o nome: "; cin >> nome;
    cout << "Digite o CPF (Somente Números): "; cin >> cpf;

    cin.ignore();
    cout << "Digite o endereço: "; getline(cin, endereco);

    cout << "Digite o código da cidade: "; cin >> codigo_cidade;

    int fim = total_clientes - 1;
    bool busca = false;

    for (int i = 0; i < fim; i++)
    {
        if(Clientes[i].getCPF() == cpf){
            cout << "\nEste CPF já está cadastrado!";
            busca = true;
            cin.ignore();
            cout << "\nAperte <Enter> para retornar ao menu anterior!\n";
            cin.get();
        }
    }

    if (!busca) {
        Clientes[total_clientes].setNome(nome);
        Clientes[total_clientes].setCPF(cpf);
        Clientes[total_clientes].setEndereco(endereco);
        Clientes[total_clientes].setCodigoCidade(codigo_cidade);
        total_clientes++;
    }

    system("clear");
}

void Cliente::listar_cliente(Cliente Clientes[], Cidade Cidades[], Pais Paises[], int total_clientes) {
    system("clear");
    int codigo_cidade, codigo_pais;
    string cidade, pais, uf;


    cout << "Listando todos os clientes: \n";
    cout << "CPF        |     Nome      |      Endereço\n";
    for (int i = 0; i < total_clientes; i++) {
        codigo_cidade = Clientes[i].getCodigoCidade();
        cidade = Cidades[codigo_cidade].getNome();
        uf = Cidades[codigo_cidade].getUf();

        codigo_pais = Cidades[codigo_cidade].getCodigoPais() - 1;
        pais = Paises[codigo_pais].getNome();

        cout << " " << Clientes[i].getCPF() << "              " << Clientes[i].getNome() << "             " << Clientes[i].getEndereco() << " " << cidade << " " << uf << " " << pais << endl;
    }
    cin.ignore();
    cout << "\nAperte <Enter> para retornar ao menu anterior!\n";
    cin.get();
    
    system("clear");
}

void Cliente::pesquisar_cliente(Cliente Clientes[], Cidade Cidades[], Pais Paises[], int &total_clientes){
   system("clear");
    string codigo;
    cout << "Digite o cpf que você deseja buscar: "; cin >> codigo;

   system("clear");

    int fim = total_clientes - 1;
    bool busca = false;

    for (int i = 0; i < fim; i++)
    {
        if (codigo == Clientes[i].getCPF()) {
            // Elemento encontrado
            cout << "\n---------------------------------------------------" << endl;
            cout << "                   Busca Encontrada!                  " << endl;
            cout << "---------------------------------------------------" << endl;
            cout << " CPF:         " << Clientes[i].getCPF() << endl;
            cout << " Nome:           " << Clientes[i].getNome() << endl;
            cout << "---------------------------------------------------" << endl;
            busca = true;
        }
    }

    if (!busca) {
        cout << "\nCPF não encontrado!\n";
    }

    cin.ignore();
    cout << "\nAperte <Enter> para retornar ao menu anterior!\n";
    cin.get();
    system("clear");
}

