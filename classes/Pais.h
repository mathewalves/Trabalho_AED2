#ifndef PAIS_H
#define PAIS_H

#include <string>
using namespace std;
class Pais
{
    private:
        int codigo;
        string nome;
        string uf;
    public:
        int getCodigo();
        void setCodigo(int codigo_);

        string getNome();
        void setNome(string nome_);

        string getUf();
        void setUf(string uf_);

    // methods
        void cadastrar_pais(Pais Paises[], int &total_paises, int MAX_PAISES);
        void listar_paises(Pais Paises[], int total_paises);
        void pesquisar_pais(Pais Paises[], int &total_paises);
};

#endif // PAIS_H