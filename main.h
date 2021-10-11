//
// Created by Daniel Paiva Fernandes on 10/10/2021.
//

#ifndef PCO001_FILA_AUTORREFERENCIADA_MAIN_H
#define PCO001_FILA_AUTORREFERENCIADA_MAIN_H

#include <iostream>
#include <cstring>
#include <utility>

using namespace std;

typedef struct TipoFila
{
    int item{};
    TipoFila *proximo{};
} TipoFila;

typedef struct Fila
{
    TipoFila* inicio;
    TipoFila* fim;
} Fila;

bool isVazia(Fila* fila)
{
    return fila->inicio == nullptr;
}

void imprimeFila(Fila *fila)
{
    cout << endl << "Elementos da fila: " << endl;
    if(isVazia(fila))
    {
        cout << "Pilha vazia" <<endl;
        return;
    }
    TipoFila *filaAuxiliar = fila->inicio;
    while (filaAuxiliar->proximo != nullptr)
    {
        cout << "Endereço: " << fila
             << "  Valor:   " << filaAuxiliar->item << endl;
        filaAuxiliar = filaAuxiliar->proximo;
    }
    cout << "Endereço: " << fila
         << "  Valor:   " << filaAuxiliar->item << endl;
}

Fila* criaFilaVazia()
{
    Fila* fila = (Fila*)malloc(sizeof(Fila));
    fila->inicio = fila->fim = nullptr;
    return fila;
}

void inserir(int item, Fila* fila)
{
    auto *no = (TipoFila*) malloc(sizeof (TipoFila));

    no->item = item;
    no->proximo = nullptr;

    if(fila->fim == nullptr)
    {
        fila->inicio = no;
    } else {
        fila->fim->proximo = no;
    }
    fila->fim = no;
}

void remover(Fila* fila)
{
    if(isVazia(fila))
    {
        cout << "Fila está vazia" << endl;
        return;
    }
    auto no = fila->inicio;
    fila->inicio = no->proximo;
    cout << to_string(no->item) + " removido" <<endl;
    free(no);
}

int tamanhoFila(Fila* fila)
{
    int tamanho = 0;
    auto auxiliar = fila->inicio;
    if (isVazia(fila)) return -1;
    while(auxiliar->proximo != nullptr)
    {
        tamanho++;
        auxiliar = auxiliar->proximo;
    }
    return tamanho + 1;
}

void removerElementoIndice(Fila* fila, int indice)
{
    Fila* auxiliar = criaFilaVazia();
    TipoFila* ponteiro = fila->inicio;

    int tamanho = tamanhoFila(fila);

    if(indice > tamanho || isVazia(fila))
    {
        cout << "Índice não existe na fila ou fila vazia" << endl;
        return;
    }
    for(int i = 0; i < indice-1; i++)
    {
        inserir(ponteiro->item, auxiliar);
        ponteiro = ponteiro->proximo;
    }
    cout << to_string(ponteiro->item) + " removido" <<endl;
    ponteiro = ponteiro->proximo;
    while (ponteiro->proximo != nullptr)
    {
        inserir(ponteiro->item, auxiliar);
        ponteiro = ponteiro->proximo;
    }
    inserir(ponteiro->item, auxiliar);
    fila->inicio = auxiliar->inicio;
}

void localizarElementoIndice(Fila* fila, int indice)
{
    Fila* auxiliar = criaFilaVazia();
    TipoFila* ponteiro = fila->inicio;

    int tamanho = tamanhoFila(fila);

    if(indice > tamanho || isVazia(fila))
    {
        cout << "Índice não existe na fila ou fila vazia" << endl;
        return;
    }
    for(int i = 0; i < indice-1; i++)
    {
        inserir(ponteiro->item, auxiliar);
        ponteiro = ponteiro->proximo;
    }
    string shouldChange = "n";
    cout << "Elemento encontrado no índice: " <<ponteiro->item << endl <<
         " Gostaria de alterar? (s/n): " << endl;
    cin >> shouldChange;
    if(shouldChange == "s")
    {
        cout << "Insira o novo valor: ";
        cin >> ponteiro->item;
    }
    while (ponteiro->proximo != nullptr)
    {
        inserir(ponteiro->item, auxiliar);
        ponteiro = ponteiro->proximo;
    }
    inserir(ponteiro->item, auxiliar);
    fila->inicio = auxiliar->inicio;
}

Fila* concatenarFila(Fila* primeiraFila, Fila* segundaFila) {
    Fila *concatenada = criaFilaVazia();
    TipoFila *primeiroPonteiroAuxiliar = primeiraFila->inicio;
    TipoFila *segundoPonteiroAuxiliar = segundaFila->inicio;

    int tamanhoPrimeiraFila = tamanhoFila(primeiraFila);
    int tamanhoSegundoFila = tamanhoFila(segundaFila);

    for(int i = 0; i < tamanhoPrimeiraFila; i++)
    {
        inserir(primeiroPonteiroAuxiliar->item, concatenada);
        primeiroPonteiroAuxiliar = primeiroPonteiroAuxiliar->proximo;
    }
    for(int j = 0; j < tamanhoSegundoFila; j++)
    {
        inserir(segundoPonteiroAuxiliar->item, concatenada);
        segundoPonteiroAuxiliar = segundoPonteiroAuxiliar->proximo;
    }
    return concatenada;
}

void partirFila(Fila* fila, Fila* segundaFila, Fila* terceiraFila)
{
    TipoFila* ponteiroFila = fila->inicio;

    int tamanho = tamanhoFila(fila);

    if(isVazia(fila))
    {
        return;
    }
    for (int i = 0; i < tamanho; i++)
    {
        if (i < tamanho/2)
        {
            inserir(ponteiroFila->item, segundaFila);
        }
        else
        {
            inserir(ponteiroFila->item, terceiraFila);
        }
        ponteiroFila = ponteiroFila->proximo;
    }
}

Fila* copiarFila(Fila* fila)
{
    Fila* filaCopiada = criaFilaVazia();
    TipoFila* ponteiroFila = fila->inicio;

    int tamanho = tamanhoFila(fila);

    for(int i = 0; i < tamanho; i++)
    {
        inserir(ponteiroFila->item, filaCopiada);
        ponteiroFila = ponteiroFila->proximo;
    }
    return filaCopiada;
}

void ordenarFila(Fila* fila)
{
    auto* t = (TipoFila*) malloc(sizeof(TipoFila));
    TipoFila* ponteiro = fila->inicio;
    int temp;

    while(ponteiro != nullptr)
    {
        t = ponteiro->proximo;
        while (t != nullptr)
        {
            if (t->item < ponteiro->item)
            {
                temp = ponteiro->item;
                ponteiro->item = t->item;
                t->item = temp;
            }
            t = t->proximo;
        }
        ponteiro = ponteiro->proximo;
    }
    free(t);
}

void pesquisarItemFila(Fila* fila, const int& elemento)
{
    TipoFila* ponteiro = fila->inicio;
    int tamanho = tamanhoFila(fila);
    bool isFound = false;

    for(int i = 0; i < tamanho; i++)
    {
        if(ponteiro->item == elemento)
        {
            cout << "Elemento " + to_string(elemento) + " encontrado na fila no índice " + to_string(i) << endl;
            isFound = true;
        }
        ponteiro = ponteiro->proximo;
    }
    if(!isFound)
    {
        cout << "Elemento não encontrado" << endl;
    }
}

#endif //PCO001_FILA_AUTORREFERENCIADA_MAIN_H