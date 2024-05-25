#ifndef CLIENTE_H
#define CLIENTE_H

#include <string>

#include "Pais.h"
#include "Cidade.h"

using namespace std;
class Cliente
{
    private:
        string cpf;
        string nome;
        string endereco;
        int codigo_cidade;
    public:
        string getCPF();
        void setCPF(string cpf_);

        string getNome();
        void setNome(string nome_);

        string getEndereco();
        void setEndereco(string endereco_);

        int getCodigoCidade();
        void setCodigoCidade(int codigo_cidade_);

    // methods
        void cadastrar_cliente(Cliente Clientes[], int &total_clientes, int MAX_CADASTROS);
        void listar_cliente(Cliente Clientes[], Cidade Cidades[], Pais Paises[], int total_clientes);
        void pesquisar_cliente(Cliente Clientes[], Cidade Cidades[], Pais Paises[], int &total_clientes);
};

#endif // CLIENTE_H