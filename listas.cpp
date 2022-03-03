/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

#include <cstdlib>
#include <iostream>

using namespace std;


typedef struct no_ {
    //critério de busca da ordenação
    int chave;

    //'carga útil' do nó
    //num cenario real, poderia ser, por exemplo: nome, endereco...
    int valor;

    struct no_ * prox;
} no;

/**
 * Realiza a alocacao do espaco para que a lista possa comecar
 * a receber nos.
 * @return a lista vazia.
 */
no* inicia_lista() {
    no* tmp = new (no);
    tmp->chave = 0;
    tmp->valor = 0;
    tmp->prox = NULL;

    cout << "-A lista foi iniciada." << endl;
    return tmp;
}

/**
 * Desaloca o espaco previamente alocado para a lista encadeada.
 */
void encerra_lista(no * ptlista) {
    no * ant = ptlista->prox;
    no * pont = ant->prox;

    while (pont != NULL) {
        delete(ant);
        ant = pont;
        pont = pont->prox;
    }
    delete(ant);
    cout << "-A lista foi removida." << endl;

    delete(ptlista);
}

void busca_fim(no * ptlista, int chave, no ** inicio, no ** fim) {
    *inicio = ptlista;
    *fim = NULL;
    no* ptr = ptlista->prox;

    while (ptr != NULL) {
        if (ptr->chave == chave) {
            *fim = ptr;
            ptr = NULL;
        } else {
            *inicio = ptr;
            ptr = ptr->prox;

        }

    }
}

int insere_fim(no * ptlista, int chave, int valor) {
    int retorno = -1;
    no* ptr = new(no);
    no* inicio;
    no* fim;

    busca_fim(ptlista, chave, &inicio, &fim);

    if (fim == NULL) {
        ptr->chave = chave;
        ptr->valor = valor;
        inicio->prox = ptr;
        retorno = 0;
    }

    return retorno;
}

void busca_inicio(no * ptlista, int chave, no ** inicio, no ** pont) {
    *pont = NULL;
    no* ptr = ptlista->prox;

    while (ptr != NULL) {
        if (ptr->chave == chave) {
            *pont = ptr;
            ptr = NULL;
        } else {
            ptr = ptr->prox;
        }

    }
}

int insere_inicio(no * ptlista, int chave, int valor) {
    int retorno = -1;
    no* ptr = new(no);
    no* inicio = ptlista;
    no* pont;

    busca_inicio(ptlista, chave, &inicio, &pont);

    if (pont == NULL) {
        ptr->chave = chave;
        ptr->valor = valor;
        ptr->prox = inicio->prox;
        inicio->prox = ptr;
        retorno = 0;
    }



    return retorno;
}

/**
 * Imprime a lista encadeada.
 */
void imprime(no * ptlista) {
    no * ptr = ptlista->prox;
    cout << "---Estado atual da lista:";
    while (ptr != NULL) {
        cout << "-> (" << ptr->chave << "," << ptr->valor << ") ";
        ptr = ptr->prox;
    }
    cout << endl;
}

