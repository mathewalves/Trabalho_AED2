#ifndef SISTEMA_H
#define SISTEMA_H

#include "Cidade.h"
#include "Pais.h"
#include "Guia.h"
#include "Cliente.h"
#include <string>

using namespace std;

class Sistema{
    private:
        int MAX_CADASTROS;
    public:

    Sistema(Pais Paises[], Cidade Cidades[], Guia Guias[], Cliente Clientes[], int MAX_CADASTROS);
    void menu_principal(Pais Paises[], Cidade Cidades[], Guia Guias[], Cliente Clientes[], int &total_cidades, int &total_paises, int &total_guias, int &total_clientes, int MAX_CADASTROS);
    void menu_cadastro(Pais Paises[], Cidade Cidades[], Guia Guias[], Cliente Clientes[], int &total_cidades, int &total_paises, int &total_guias, int &total_clientes, int MAX_CADASTROS);
    void menu_imprimir(Pais Paises[], Cidade Cidades[], Guia Guias[], Cliente Clientes[], int &total_cidades, int &total_paises, int &total_guias, int &total_clientes);
    void menu_pesquisa(Pais Paises[], Cidade Cidades[], Guia Guias[], Cliente Clientes[], int &total_cidades, int &total_paises, int &total_guias, int &total_clientes, int MAX_CADASTROS);

    void cadastro_cidade(Pais Paises[], Cidade Cidades[], int &total_paises , int &total_cidades, int MAX_CADASTROS); 
    void cadastro_pais(Pais Paises[], int &total_paises , int MAX_CADASTROS); 
    void cadastro_guia(Guia Guias[], int &total_guias, int MAX_CADASTROS);
    void cadastro_cliente(Cliente Clientes[], int &total_clientes, int MAX_CADASTROS);


};

#endif // SISTEMA_H