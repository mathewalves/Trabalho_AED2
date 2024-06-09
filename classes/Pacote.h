// Pacotes: código, descrição, codigo_guia, valor_por_pessoa, total_participantes, quant_max_participantes

#ifndef PACOTES_H
#define PACOTES_H

#include "Guia.h"

#include <string>
using namespace std;
class Pacote
{
    private:
        int codigo;
        int codigo_guia;
        int total_participantes, quant_max_participantes;
        float valor_por_pessoa;
        string descricao;
    public:
        int getCodigo();
        void setCodigo(int codigo_);

        int getCodigoGuia();
        void setCodigoGuia(int codigo_guia_);

        int getTotalParticipantes();
        void setTotalParticipantes(int total_participantes_);

        int getQuantMaxParticipantes();
        void setQuantMaxParticipantes(int quant_max_participantes_);

        float getValorPorPessoa();
        void setValorPorPessoa(float valor_por_pessoa_);

        string getDescricao();
        void setDescricao(string descricao_);
      
    // methods

    void cadastrar_pacote(Pacote Pacotes[], int &total_pacotes, int MAX_CADASTROS);
    void listar_pacote(Pacote Pacotes[], Guia Guias[], int total_pacotes);
    void listar_pacote_vendido(Pacote Pacotes[], Guia Guias[], int total_pacotes);
};

#endif // PACOTES_H