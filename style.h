#include <iomanip>
#include <iostream>

void header_menu(const string& titulo) {
    cout << "============================================================" << endl;
    // Centralizando o título
    int padding = (60 - titulo.length()) / 2;  // Ajustando o comprimento total da linha
    cout << setw(padding) << "" << titulo << setw(padding) << "" << endl;
    cout << "============================================================" << endl;
}

void pergunta(const string& mensagem) {
    cout << "====================     ???     ====================" << endl;
    // Centralizando a mensagem
    int padding = (60 - mensagem.length()) / 2;  // Ajustando o comprimento total da linha
    cout << setw(padding) << "" << mensagem << setw(padding) << "" << endl;
    cout << "====================     ???     ====================" << endl;
}