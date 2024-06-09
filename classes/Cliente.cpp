#include "Cliente.h"
#include <iostream>
#include <string>
using namespace std;

long int Cliente::getCPF(){
    return this->cpf;
}
void Cliente::setCPF(long int cpf_){
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
    string nome, endereco;
    long int cpf;
    cout << "\nRegistrando Novo Cliente: \n";
    cout << "Digite o nome: "; cin.ignore(); getline(cin, nome);
    cout << endl << "Digite o CPF (Somente Números): "; cin >> cpf;

    cin.ignore();
    cout << "Digite o endereço: "; getline(cin, endereco);

    cout << "Digite o código da cidade: "; cin >> codigo_cidade;

    int fim = total_clientes;
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
    cout << "CPF             |       Nome        |      Endereço\n";
    for (int i = 0; i < total_clientes; i++) {
        codigo_cidade = Clientes[i].getCodigoCidade();
        cidade = Cidades[codigo_cidade].getNome();
        uf = Cidades[codigo_cidade].getUf();

        codigo_pais = Cidades[codigo_cidade].getCodigoPais() - 1;
        pais = Paises[codigo_pais].getNome();

        cout << " " << Clientes[i].getCPF() << "          " << Clientes[i].getNome() << "       " << Clientes[i].getEndereco() << " " << cidade << " " << uf << " " << pais << endl;
    }
    cin.ignore();
    cout << "\nAperte <Enter> para retornar ao menu anterior!\n";
    cin.get();
    
    system("clear");
}

void Cliente::pesquisar_cliente(Cliente Clientes[], Cidade Cidades[], Pais Paises[], int &total_clientes){
   system("clear");
    long int codigo;
    cout << "Digite o cpf que você deseja buscar: "; cin >> codigo;

   system("clear");

    int fim = total_clientes;
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
            cout << "\nDeseja excluir o cliente " << Clientes[i].getNome() << "?" << endl;
            cout << "[1] SIM [2]NÃO" << endl;
            int escolha; cin >> escolha;
            if(escolha == 1){
                for (int j = i; j < total_clientes; j++)
                {
                    Clientes[j] = Clientes[j + 1];
                }
                cout << "Cliente " << Clientes[i].getNome() << " Excluído com sucesso!\n";
                total_clientes--;
            }
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