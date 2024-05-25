#ifndef GUIA_H
#define GUIA_H

#include "Pais.h"
#include "Cidade.h"

// Guias: código, nome, endereço, telefone, codigo_cidade

#include <string>
using namespace std;
class Guia
{
    private:
        int codigo;
        string nome;
        string endereco;
        string telefone;
        int codigo_cidade;
    public:
        int getCodigo();
        void setCodigo(int codigo_);

        string getNome();
        void setNome(string nome_);

        string getEndereco();
        void setEndereco(string endereco_);

        string getTelefone();
        void setTelefone(string telefone_);

        int getCodigoCidade();
        void setCodigoCidade(int codigo_cidade_);
      
    // methods

    void cadastrar_guia(Guia Guias[], int &total_guias, int MAX_CADASTROS);
    void listar_guia(Guia Guias[], Cidade Cidades[], Pais Paises[], int total_guias);
    void pesquisar_guia(Guia Guias[], int &total_guias);
};

#endif // GUIA_H