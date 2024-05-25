#ifndef CIDADE_H
#define CIDADE_H

#include <string>
#include "Pais.h"

using namespace std;
class Cidade
{
    private:
        int codigo;
        string nome;
        int codigoPais;
    public:
        int getCodigo();
        void setCodigo(int codigo_);

        string getNome();
        void setNome(string nome_);

        int getCodigoPais();
        void setCodigoPais(int codigoPais_);

    // methods
        void cadastrar_cidade(Cidade Cidades[], Pais Paises[], int &total_cidades, int &total_paises, int MAX_CADASTROS);
        void listar_cidades(Cidade Cidades[], Pais Paises[], int total_cidades);
        void pesquisar_cidade(Cidade Cidades[], Pais Paises[], int &total_cidades);
};

#endif // CIDADE_H