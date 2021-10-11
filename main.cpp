//
// Created by Daniel Paiva Fernandes on 10/10/2021.
//
#include "main.h"

int main()
{
    Fila *primeiraFila;
    Fila *segundaFila;

    cout << "01. Criação da estrutura de dados vazia" << endl;
    primeiraFila = criaFilaVazia();
    segundaFila = criaFilaVazia();
    imprimeFila(primeiraFila);
    imprimeFila(segundaFila);
    // cout << "Enter para continuar..."; cin.get();

    cout << endl << "02. Inserir um novo item imediatamente após o i-ésimo item" << endl;
    int valoresPrimeiraFila[] = {54, 23, 657, 12, 45, 89, 5, 3};
    int valoresSegundaFila[] = {645, 78, 30, 64, 40, 1, 9, 34};
    for(int i: valoresPrimeiraFila) { inserir(i, primeiraFila);}
    for(int j: valoresSegundaFila) { inserir(j, segundaFila);}
    imprimeFila(primeiraFila);
    imprimeFila(segundaFila);
    // cout << "Enter para continuar..."; cin.get();

    cout << endl <<  "03. Retirar o primeiro item" << endl;
    remover(primeiraFila);
    remover(segundaFila);
    imprimeFila(primeiraFila);
    imprimeFila(segundaFila);
    // cout << "Enter para continuar..."; cin.get();

    cout << endl << "04. Retirar o i-ésimo item" << endl;
    removerElementoIndice(primeiraFila, 1);
    removerElementoIndice(segundaFila, 3);
    imprimeFila(primeiraFila);
    imprimeFila(segundaFila);
    // cout << "Enter para continuar..."; cin.get();

    cout << endl <<  "05. Localizar um item na Lista" << endl;
    localizarElementoIndice(primeiraFila, 2);
    localizarElementoIndice(primeiraFila, 4);
    localizarElementoIndice(segundaFila, 6);
    localizarElementoIndice(segundaFila, 5);
    // cout << "Enter para continuar..."; cin.get();

    cout << endl << "06. Combinar duas ou mais estruturas em uma" << endl;
    Fila* novaFila;
    novaFila = concatenarFila(segundaFila, primeiraFila);
    imprimeFila(novaFila);
    // cout << "Enter para continuar..."; cin.get();

    cout << endl << "07. Partir uma estrutura em duas ou mais" << endl;
    partirFila(novaFila, primeiraFila, segundaFila);
    imprimeFila(primeiraFila);
    imprimeFila(segundaFila);
    // cout << "Enter para continuar..."; cin.get();

    cout << endl << "08. Fazer uma cópia" << endl;
    Fila* filaCopiada = copiarFila(novaFila);
    imprimeFila(filaCopiada);
    // cout << "Enter para continuar..."; cin.get();

    cout << endl << "09. Ordenar os itens da estrutura" << endl;
    ordenarFila(novaFila);
    imprimeFila(novaFila);
    // cout << "Enter para continuar..."; cin.get();

    cout << endl << "10. Buscar a ocorrência de um valor particular" << endl;
    inserir(256, novaFila);
    imprimeFila(novaFila);
    pesquisarItemFila(novaFila, 256);
    // cout << "Enter para continuar..."; cin.get();
}
