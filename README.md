# Trabalho 2 de Análise e Desenvolvimento de Sistemas - Algoritmos II

Este trabalho foi desenvolvido no segundo ano do curso de Análise e Desenvolvimento de Sistemas para a disciplina de Algoritmos II, utilizando a linguagem de programação C++.

## Descrição do Trabalho

O objetivo deste trabalho é criar um programa para simular arquivos sequenciais para uma aplicação de gerenciamento de uma Agência de Turismo. As estruturas de dados que serão simuladas são as seguintes:

- Países: código, nome
- Cidades: código, nome, UF, código_país
- Guias: código, nome, endereço, telefone, código_cidade
- Clientes: CPF, nome, endereço, código_cidade
- Pacotes: código, descrição, código_guia, valor_por_pessoa, total_participantes, quant_max_participantes
- Vendas: código, CPF_Cliente, código_pacote, quantidade_pessoas, valor_total

## Funcionalidades Implementadas

1. Leitura dos dados das estruturas: Países, Cidades, Guias, Clientes. :white_check_mark:
2. Inclusão de novos registros na tabela de Guias. :white_check_mark:
   - Garantia de que o código do guia a ser inserido não existe na tabela de Guias. :white_check_mark:
   - Busca automática do código da cidade na tabela de Cidades e exibição das informações relacionadas. :white_check_mark:
3. Inclusão de novos registros na tabela de Clientes. :white_check_mark:
   - Garantia de que o CPF do cliente a ser inserido não existe na tabela de clientes. :white_check_mark:
   - Busca automática do código da cidade na tabela de Cidades e exibição das informações relacionadas. :white_check_mark:
4. Exclusão de registros na tabela de Clientes.
5. Inclusão de novos registros na tabela de Pacotes.
   - Busca automática do código do guia na tabela de Guias e exibição das informações relacionadas.
6. Inclusão de novos registros na tabela de Vendas.
   - Busca automática do CPF do cliente na tabela de Clientes e exibição das informações relacionadas.
   - Busca automática do código do pacote na tabela de Pacotes e exibição das informações relacionadas.
   - Adição da quantidade de pessoas ao total de participantes do pacote.
   - Cálculo e exibição do valor total da venda.
7. Consulta dos dados de determinado pacote.
   - Exibição de todos os dados do pacote e do valor total arrecadado pelo pacote.
8. Exibição de todos os registros da tabela de Pacotes que tenham sido completamente vendidos.
   - Exibição do código, descrição, nome do guia e valor total arrecadado pelo pacote.
9. Exibição de todos os registros da tabela de Vendas.
   - Exibição do código, nome do cliente, descrição do pacote, quantidade de pessoas e valor total da venda.
   - Exibição do valor total vendido.

## Observações

- Não foram utilizadas variáveis globais.
- Todas as funções são acessadas através de um menu de opções chamado a partir da função main().

## Data de Entrega

O trabalho deverá ser entregue até o dia 06/06/2024.