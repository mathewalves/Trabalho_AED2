#include "Sistema.h"
#include "../style.h"

using namespace std;

// methods

Sistema::Sistema(Pais Paises[], Cidade Cidades[], Guia Guias[], Cliente Clientes[], Pacote Pacotes[], Venda Vendas[], int MAX_CADASTROS){
    int total_paises = 0;
    int total_cidades = 0;
    int total_guias = 0;
    int total_clientes = 0;
    int total_pacotes = 0;
    int total_vendas = 0;

    menu_principal(Paises, Cidades, Guias, Clientes, Pacotes, Vendas, total_cidades, total_paises, total_guias, total_clientes, total_pacotes, total_vendas, MAX_CADASTROS);
};

void Sistema::menu_principal(Pais Paises[], Cidade Cidades[], Guia Guias[], Cliente Clientes[], Pacote Pacotes[], Venda Vendas[], int &total_cidades, int &total_paises, int &total_guias, int &total_clientes, int &total_pacotes, int &total_vendas, int MAX_CADASTROS) {
    char opcao = 'x';
    system("clear"); // limpa a tela no Linux
    
    while (opcao != '0') {
        header_menu("Menu Principal");
        cout << "\nSelecione uma das Opções:" << endl;
        cout << "------------------------------------" << endl;
        cout << "[1] Cadastros  [2] Imprimir" << endl;
        cout << "[3] Pesquisar [4] PDV" << endl;
        cout << "[0] Sair" << endl;
        cout << "------------------------------------" << endl;
        cout << "Escolha um opção: ";
        cin >> opcao;

        cout << endl;

        switch (opcao) {
            case '0':
                system("clear");
                cout << "\nPrograma Finalizado!\n";
                break;
            case '1':
                system("clear");
                menu_cadastro(Paises, Cidades, Guias, Clientes, Pacotes, total_cidades, total_paises, total_guias, total_clientes, total_pacotes, MAX_CADASTROS);
                break;
            case '2':
                system("clear");
                menu_imprimir(Paises, Cidades, Guias, Clientes, Pacotes, total_cidades, total_paises, total_guias, total_clientes, total_pacotes);
                break;
            case '3':
                system("clear");
                menu_pesquisa(Paises, Cidades, Guias, Clientes, total_cidades, total_paises, total_guias, total_clientes, MAX_CADASTROS);
                break;
            case '4':
                system("clear");
                menu_pdv(Vendas, Clientes, Pacotes, total_vendas, total_clientes, total_pacotes, MAX_CADASTROS);
                break;
            default:
                system("clear");
                cout << "### Opção Inválida! ###";
                cin.ignore();
                cout << "\nAperte <Enter> para retornar ao menu anterior!\n";
                cin.get();
                system("clear");
                break;
        }
        cout << endl << endl;
    }
}

void Sistema::menu_pdv(Venda Vendas[], Cliente Clientes[], Pacote Pacotes[], int &total_vendas, int &total_clientes, int &total_pacotes, int MAX_CADASTROS){
    char opcao = 'x';

    system("clear");

    while (opcao != '0') {
        header_menu("PDV");
        cout << "\n\nOque você deseja Fazer?\n";
        cout << "[1] Nova Venda [2] Listar Vendas [0] Voltar" <<
        endl << "Escolha uma opção: "; 
        cin >> opcao;
        switch (opcao) {
            case '0':
                system("clear");
                break;
            case '1':
                Vendas->fazer_venda(Vendas, Clientes, Pacotes, total_vendas, total_clientes, total_pacotes, MAX_CADASTROS);
                break;
            case '2':
                Vendas->listar_venda(Vendas, Clientes, Pacotes, total_vendas, total_clientes, total_pacotes);
                break;
            default:
                system("clear");
                cout << "### Opção Inválida! ###";
                cin.ignore();
                cout << "\nAperte <Enter> para retornar ao menu anterior!\n";
                cin.get();
                system("clear");
                break;
        }
    } 
}

void Sistema::menu_imprimir(Pais Paises[], Cidade Cidades[], Guia Guias[], Cliente Clientes[], Pacote Pacotes[], int &total_cidades, int &total_paises, int &total_guias, int &total_clientes, int &total_pacotes){
    char opcao = 'x';

    system("clear");

    while (opcao != '0') {
        header_menu("Cadastro");
        cout << "\n\nOque você deseja Imprimir?\n";
        cout << "[1] País [2] Cidade [3] Guia [4] Clientes" << 
        endl <<  "[5] Pacote [0] Voltar" << 
        endl << "Escolha uma opção: "; 
        cin >> opcao;
        switch (opcao) {
            case '0':
                system("clear");
                break;
            case '1':
                Paises->listar_paises(Paises, total_paises);
                break;
            case '2':
                Cidades->listar_cidades(Cidades, Paises, total_cidades);
                break;
            case '3':
                Guias->listar_guia(Guias, Cidades, Paises, total_guias);
                break;
            case '4':
                Clientes->listar_cliente(Clientes, Cidades, Paises, total_clientes);
                break;
            case '5':
                Pacotes->listar_pacote(Pacotes, Guias, total_pacotes);
                break;
            default:
                system("clear");
                cout << "### Opção Inválida! ###";
                cin.ignore();
                cout << "\nAperte <Enter> para retornar ao menu anterior!\n";
                cin.get();
                system("clear");
                break;
        }
    } 
}

void Sistema::menu_cadastro(Pais Paises[], Cidade Cidades[], Guia Guias[], Cliente Clientes[], Pacote Pacotes[], int &total_cidades, int &total_paises, int &total_guias, int &total_clientes, int &total_pacotes, int MAX_CADASTROS) {
   char opcao = 'x';

    system("clear");

    while (opcao != '0') {
        header_menu("Cadastro");
        cout << "\n\nOque você deseja cadastrar?\n";
        cout << "[1] País [2] Cidade [3] Guia [4] Cliente" << 
        endl <<  "[5] Pacote [0] Voltar" << 
        endl << "Escolha uma opção: "; 
        cin >> opcao;
        switch (opcao) {
            case '0':
                system("clear");
                break;
            case '1':
                this->cadastro_pais(Paises, total_paises, MAX_CADASTROS);
                break;
            case '2':
                this->cadastro_cidade(Paises, Cidades,total_paises , total_cidades, MAX_CADASTROS);
                break;
            case '3':
                this->cadastro_guia(Guias, total_guias, MAX_CADASTROS);
                break;
            case '4':
                this->cadastro_cliente(Clientes, total_clientes, MAX_CADASTROS);
                break;
            case '5':
                this->cadastro_pacote(Pacotes, total_pacotes, MAX_CADASTROS);
            default:
                system("clear");
                cout << "### Opção Inválida! ###";
                cin.ignore();
                cout << "\nAperte <Enter> para retornar ao menu anterior!\n";
                cin.get();
                system("clear");
                break;
        }
    } 
}

void Sistema::menu_pesquisa(Pais Paises[], Cidade Cidades[], Guia Guias[], Cliente Clientes[], int &total_cidades, int &total_paises, int &total_guias, int &total_clientes, int MAX_CADASTROS) {
    char opcao = 'x';

    system("clear");

    while (opcao != '0') {
        header_menu("Pesquisa");
        cout << "\n\nOque você deseja Pesquisar?\n";
        cout << "[1] País [2] Cidade [3] Guia [4] Cliente" << 
        endl <<  "[0] Voltar" << 
        endl << "Escolha uma opção: "; 
        cin >> opcao;
        switch (opcao) {
            case '0':
                system("clear");
                break;
            case '1':
                Paises->pesquisar_pais(Paises, total_paises);
                break;
            case '2':
                Cidades->pesquisar_cidade(Cidades, Paises, total_cidades);
                break;
            case '3':
                Guias->pesquisar_guia(Guias, Cidades, Paises, total_guias);
                break;
            default:
                cout << "### Opção Inválida! ###";
                system("clear");
                cin.ignore();
                cout << "\nAperte <Enter> para retornar ao menu anterior!\n";
                cin.get();
                system("clear");
                break;
        }
    }   
}

void Sistema::cadastro_cidade(Pais Paises[], Cidade Cidades[], int &total_paises , int &total_cidades, int MAX_CADASTROS) {
    char opcao = 'x';

    system("clear");

    Cidades->cadastrar_cidade(Cidades, Paises, total_cidades, total_paises, MAX_CADASTROS);


    while (opcao != '0') {
        pergunta("Deseja Cadastrar outra cidade");
        cout << "[1] Sim" << endl << "[0] Não" << endl;
        cout << "Escolha uma opção: "; 
        cin >> opcao;
        switch (opcao) {
            case '0':
                system("clear");
                break;
            case '1':
                Cidades->cadastrar_cidade(Cidades, Paises, total_cidades, total_paises, MAX_CADASTROS);
        }
    }
}

void Sistema::cadastro_pais(Pais Paises[], int &total_paises, int MAX_CADASTROS) {
    char opcao = 'x';

    system("clear");
    Paises->cadastrar_pais(Paises, total_paises, MAX_CADASTROS);


     while (opcao != '0') {
        pergunta("Deseja Cadastrar outro País");
        cout << "[1] Sim" << endl << "[0] Não" << endl;
        cout << "Escolha uma opção: ";  
        cin >> opcao;
        switch (opcao) {
            case '0':
                system("clear");
                break;
            case '1':
                Paises->cadastrar_pais(Paises, total_paises, MAX_CADASTROS);
        }
    }
}

void Sistema::cadastro_guia(Guia Guias[], int &total_guias, int MAX_CADASTROS) {
    char opcao = 'x';

    system("clear");
    Guias->cadastrar_guia(Guias, total_guias, MAX_CADASTROS);


     while (opcao != '0') {
        pergunta("Deseja Cadastrar outro Guia");
        cout << "[1] Sim" << endl << "[0] Não" << endl;
        cout << "Escolha uma opção: ";  
        cin >> opcao;
        switch (opcao) {
            case '0':
                system("clear");
                break;
            case '1':
                Guias->cadastrar_guia(Guias, total_guias, MAX_CADASTROS);
        }
    }
}

void Sistema::cadastro_cliente(Cliente Clientes[], int &total_clientes, int MAX_CADASTROS) {
    char opcao = 'x';

    system("clear");
    Clientes->cadastrar_cliente(Clientes, total_clientes, MAX_CADASTROS);


     while (opcao != '0') {
        pergunta("Deseja Cadastrar outro Cliente");
        cout << "[1] Sim" << endl << "[0] Não" << endl;
        cout << "Escolha uma opção: ";  
        cin >> opcao;
        switch (opcao) {
            case '0':
                system("clear");
                break;
            case '1':
                Clientes->cadastrar_cliente(Clientes, total_clientes, MAX_CADASTROS);
        }
    }
}

void Sistema::cadastro_pacote(Pacote Pacotes[], int &total_pacotes, int MAX_CADASTROS) {
    char opcao = 'x';

    system("clear");
    Pacotes->cadastrar_pacote(Pacotes, total_pacotes, MAX_CADASTROS);


     while (opcao != '0') {
        pergunta("Deseja Cadastrar outro Pacote");
        cout << "[1] Sim" << endl << "[0] Não" << endl;
        cout << "Escolha uma opção: ";  
        cin >> opcao;
        switch (opcao) {
            case '0':
                system("clear");
                break;
            case '1':
                Pacotes->cadastrar_pacote(Pacotes, total_pacotes, MAX_CADASTROS);
        }
    }
}