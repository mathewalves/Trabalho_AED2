#ifndef VENDA_H
#define VENDA_H

// Vendas: codigo, CPF_Cliente, codigo_pacote, quantidade_pessoas, valor_total

#include <string>

#include "Pacote.h"
#include "Cliente.h"

using namespace std;
class Venda
{
    private:
        int codigo;
        long int cpf_cliente;
        int codigo_pacote;
        int valor_total ;
    public:
        int getCodigo();
        void setCodigo(int codigo_);

        long int getCpfCliente();
        void setCpfCliente(long int cpf_cliente_);

        int getCodigoPacote();
        void setCodigoPacote(int codigo_pacote_);

        int getValorTotal();
        void setValorTotal(int valor_total_);

    // methods
        void fazer_venda(Venda Vendas[], Cliente Clientes[], Pacote Pacotes[], int &total_vendas, int &total_clientes, int &total_pacotes, int MAX_CADASTROS);
        void listar_venda(Venda Vendas[], Cliente Clientes[], Pacote Pacotes[], int total_vendas, int total_clientes, int total_pacotes);
};

#endif // VENDA_H