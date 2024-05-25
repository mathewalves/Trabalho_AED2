#include "includes.h"

int main() {
    const int MAX_CADASTROS = 100;

    Cidade Cidades[MAX_CADASTROS]; Pais Paises[MAX_CADASTROS]; Guia Guias[MAX_CADASTROS]; Cliente Clientes[MAX_CADASTROS];


    Sistema Sistema(Paises, Cidades, Guias, Clientes, MAX_CADASTROS);

    return 0;
}