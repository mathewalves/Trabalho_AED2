#include "Pacote.h"
#include <iostream>
#include <string>

using namespace std;

int Pacote::getCodigo(){
    return this->codigo;
}
void Pacote::setCodigo(int codigo_){
    this->codigo = codigo_;
}

int Pacote::getQuantMaxParticipantes(){
    return this->quant_max_participantes;
}
void Pacote::setQuantMaxParticipantes(int quant_max_participantes_){
    this->quant_max_participantes = quant_max_participantes_;
}

int Pacote::getTotalParticipantes(){
    return this->total_participantes;
}
void Pacote::setTotalParticipantes(int total_participantes_){
    this->total_participantes = total_participantes_;
}

float Pacote::getValorPorPessoa(){
    return this->valor_por_pessoa;
}
void Pacote::setValorPorPessoa(float valor_por_pessoa_){
    this->valor_por_pessoa = valor_por_pessoa_;
}

string Pacote::getDescricao(){
    return this->descricao;
}
void Pacote::setDescricao(string descricao_){
    this->descricao = descricao_;
}

int Pacote::getCodigoGuia(){
    return this->codigo_guia;
}
void Pacote::setCodigoGuia(int codigo_guia_){
    this->codigo_guia = codigo_guia_;
}

// methods

void Pacote::cadastrar_pacote(Pacote Pacotes[], int &total_pacotes, int MAX_CADASTROS) {
    system("clear");

    if (total_pacotes >= MAX_CADASTROS) {
        cout << "Limite máximo de cadastros alcançado!\n";
        return;
    }

    string descricao;
    float valor_por_pessoa;
    int codigo_guia, total_participantes, quant_max_participantes;
    
    cin.ignore();
    cout << "Digite a descrição para o pacote: ";  getline(cin, descricao);
    cout << "Digite o valor cobrado por pessoa: "; cin >> valor_por_pessoa;
    cout << "Digite o código do guia: "; cin >> codigo_guia;
    cout << "Digite a quantidade máxima de participantes: "; cin >> quant_max_participantes;

    total_participantes = 1;

    Pacotes[total_pacotes].setCodigo(total_pacotes + 1); // define o código
    Pacotes[total_pacotes].setDescricao(descricao);
    Pacotes[total_pacotes].setValorPorPessoa(valor_por_pessoa);
    Pacotes[total_pacotes].setCodigoGuia(codigo_guia);
    Pacotes[total_pacotes].setTotalParticipantes(total_participantes);
    Pacotes[total_pacotes].setQuantMaxParticipantes(quant_max_participantes);

    total_pacotes++;

    system("clear");
}

void Pacote::listar_pacote(Pacote Pacotes[], Guia Guias[], int total_pacotes) {
    system("clear");
    int codigo, codigo_guia, quant_max_participantes, total_participantes;
    float valor_por_pessoa;
    string guia;

    cout << "Listando todos pacotes:";
    for (int i = 0; i < total_pacotes; i++) {
        codigo = Pacotes[i].getCodigo();
        quant_max_participantes = Pacotes[i].getQuantMaxParticipantes();
        valor_por_pessoa = Pacotes[i].getValorPorPessoa();
        codigo_guia = Pacotes[i].getCodigoGuia() - 1;
        guia = Guias[codigo_guia].getNome();

        cout << endl << "Código: [" << codigo << "]" << endl;
        cout << "Total/Qtde Máxima de participantes: " << Pacotes[i].getTotalParticipantes() << "/" << quant_max_participantes << endl;
        cout << "Valor por Pessoa: R$ " << valor_por_pessoa << endl;
        cout << "Descrição: " << Pacotes[i].getDescricao() << endl;
        cout << "Guia: " << guia;
        cout << "\n"; 
    }

    cin.ignore();
    cout << "\nAperte <Enter> para retornar ao menu anterior!\n";
    cin.get();
    
    system("clear");
}

void Pacote::listar_pacote_vendido(Pacote Pacotes[], Guia Guias[], int total_pacotes) {
    system("clear");
    int codigo, codigo_guia, quant_max_participantes, total_participantes;
    float valor_por_pessoa;
    string guia;

    cout << "Listando todos pacotes:";
    for (int i = 0; i < total_pacotes; i++) {
        codigo = Pacotes[i].getCodigo();
        total_participantes = Pacotes[i].getTotalParticipantes();
        quant_max_participantes = Pacotes[i].getQuantMaxParticipantes();
        valor_por_pessoa = Pacotes[i].getValorPorPessoa();
        codigo_guia = Pacotes[i].getCodigoGuia() - 1;
        guia = Guias[codigo_guia].getNome();

        if(total_participantes == quant_max_participantes){
            cout << endl << "Código: [" << codigo << "]" << endl;
            cout << "Total/Qtde Máxima de participantes: " << Pacotes[i].getTotalParticipantes() << "/" << quant_max_participantes << endl;
            cout << "Valor por Pessoa: R$ " << valor_por_pessoa << endl;
            cout << "Descrição: " << Pacotes[i].getDescricao() << endl;
            cout << "Guia: " << guia;
            cout << "\n"; 
        }
    }

    cin.ignore();
    cout << "\nAperte <Enter> para retornar ao menu anterior!\n";
    cin.get();
    
    system("clear");
}