#include "Cliente.h"
#include "Venda.h"
#include <iostream>
#include <string>
using namespace std;

int Venda::getCodigo(){
    return this->codigo;
}
void Venda::setCodigo(int codigo_){
    this->codigo = codigo_;
}

long int Venda::getCpfCliente(){
    return this->cpf_cliente;
}
void Venda::setCpfCliente(long int cpf_cliente_){
    this->cpf_cliente = cpf_cliente_;
}

int Venda::getCodigoPacote(){
    return this->codigo_pacote;
}
void Venda::setCodigoPacote(int codigo_pacote_){
    this->codigo_pacote = codigo_pacote_;
}

int Venda::getValorTotal(){
    return this->valor_total;
}
void Venda::setValorTotal(int valor_total_){
    this->valor_total = valor_total_;
}

// methods

void Venda::fazer_venda(Venda Vendas[], Cliente Clientes[], Pacote Pacotes[], int &total_vendas, int &total_clientes, int &total_pacotes, int MAX_CADASTROS){
    system("clear");

    if (total_vendas >= MAX_CADASTROS) {
        cout << "Limite máximo de vendas alcançado!\n";
        return;
    }

    int codigo, codigo_pacote, valor_total;
    long int cpf;
    cout << "\nPDV: \n";
    cout << "Digite o código do pacote: "; cin >> codigo_pacote;
    cout << "Digite o CPF do cliente (Somente Números): "; cin >> cpf;
    cout << "Digite a quantidade de participantes: "; cin >> valor_total;

    bool busca_cpf = false;
    bool busca_pacote = false;

    if (Pacotes[codigo_pacote - 1].getTotalParticipantes() >= Pacotes[codigo_pacote -1].getQuantMaxParticipantes())
    {
        cout << "\nNúmero máximo de vendas para esse pacote foi alcançado!";
        return;
    }
    
    for (int i = 0; i < total_clientes; i++){
        if(Clientes[i].getCPF() == cpf){
            cout << "\nCPF Encontrado!" << endl;
            cout << Clientes[i].getCPF() << endl;
            busca_cpf = true;
            Vendas[total_vendas].setCpfCliente(cpf);
            cout << "\nAperte <Enter> para continuar!\n";
            cin.ignore();
            cin.get();
        }
    }

    if (!busca_cpf){
        cout << "\nCPF Não Encontrado, por favor insira um CPF válido!" << endl;
        cout << cpf << endl;
        cout << "\nAperte <Enter> para continuar!\n";
        cin.ignore();
        cin.get();
    }

        system("clear");


    for (int i = 0; i < total_pacotes; i++){
        if(Pacotes[i].getCodigo() == codigo_pacote){
            cout << "\nPacote Encontrado!" << endl;
            cout << Pacotes[i].getDescricao() << endl;
            busca_pacote = true;
            Vendas[total_vendas].setCodigoPacote(codigo_pacote);
            cout << "\nAperte <Enter> para continuar!\n";
            cin.ignore();
            cin.get();
        }
    }

    if (!busca_pacote){
        cout << "\nPacote Não Encontrado, por favor insira um código de pacote válido!" << endl;
        cout << codigo_pacote << endl;
        cout << "\nAperte <Enter> para continuar!\n";
        cin.ignore();
        cin.get();
    }
    
    if (busca_cpf == true && busca_pacote == true){
        Vendas[total_vendas].setCodigo(total_vendas + 1);
        Vendas[total_vendas].setValorTotal(valor_total);
        int total_participantes;

        total_participantes = Pacotes[codigo_pacote - 1].getTotalParticipantes();
        cout << total_participantes;
        Pacotes[codigo_pacote - 1].setTotalParticipantes(total_participantes + valor_total);
        cout << codigo_pacote - 1;
        cout << Pacotes[codigo_pacote - 1].getTotalParticipantes();
        total_vendas++;

        cout << endl << "Venda Finalizada com sucesso" << endl;
    }

    system("clear");
}

void Venda::listar_venda(Venda Vendas[], Cliente Clientes[], Pacote Pacotes[], int total_vendas, int total_clientes, int total_pacotes){
    system("clear");
    int codigo, codigo_pacote, total_participantes, quant_max_participantes, valor_total;
    long int cpf;
    string nome;

    cout << "Listando todas as vendas:";
    for (int i = 0; i < total_vendas; i++){
        codigo = Vendas[i].getCodigo();
        codigo_pacote = Vendas[i].getCodigoPacote() - 1;
        total_participantes = Vendas[i].getValorTotal();
        quant_max_participantes = Pacotes[codigo_pacote].getQuantMaxParticipantes();
        
        cpf = Vendas[i].getCpfCliente();

        cout << endl << "Código de venda: [" << codigo << "]" << endl;
        cout << "Cliente: " << cpf  << endl;
        cout << "Pacote: [" << codigo_pacote + 1 << "] " << Pacotes[codigo_pacote].getDescricao() << endl;
        cout << "Total participantes/Qtde Máxima de participantes do pacote: " << total_participantes << "/" << quant_max_participantes << endl;
        cout << "Total da Venda: " << Pacotes[i].getValorPorPessoa() * total_participantes;
        cout << "\n"; 
    }

    cin.ignore();
    cout << "\nAperte <Enter> para retornar ao menu anterior!\n";
    cin.get();
    
    system("clear");
}