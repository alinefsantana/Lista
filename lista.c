//código feito em C usando uma estrutura interna, então não foi adicionado o makefile

#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int *elemento;
    int inicio, fim, tamanho, tamanhoF;
} Fila;

void inicializarFila(Fila *f, int tamanhoF) {
    f->tamanhoF = tamanhoF;
    f->elemento = (int*) malloc(tamanhoF * sizeof(int));
    f->inicio = 0;
    f->fim = 0;
    f->tamanho = 0;
}

int filaCheia(Fila *f) {
    return f->tamanho == f->tamanhoF;
}

int filaVazia(Fila *f) {
    return f->tamanho == 0;
}

void enfileirar(Fila *f, int valor) {
    if (filaCheia(f)) {
        printf("Fila cheia!\n");
        return;
    }
    f->elemento[f->fim] = valor;
    f->fim = (f->fim + 1) % f->tamanhoF;
    f->tamanho++;
    printf("Valor %d inserido na fila.\n", valor);
}

int desenfileirar(Fila *f) {
    if (filaVazia(f)) {
        printf("Fila vazia!\n");
        return -1;
    }
    int valor = f->elemento[f->inicio];
    f->inicio = (f->inicio + 1) % f->tamanhoF;
    f->tamanho--;
    printf("Valor %d removido da fila.\n", valor);
    return valor;
}

int consultarInicio(Fila *f) {
    if (filaVazia(f)) {
        printf("Fila vazia!\n");
        return -1;
    }
    printf("Valor no inicio da fila: %d\n", f->elemento[f->inicio]);
    return f->elemento[f->inicio];
}

void menu() {
    printf("\nEscolha uma opcao:\n");
    printf("1. Inserir elemento no fim da fila\n");
    printf("2. Remover elemento do inicio da fila\n");
    printf("3. Ver inicio da fila\n");
    printf("4. Verificar se a fila esta vazia\n");
    printf("5. Verificar se a fila esta cheia\n");
    printf("0. Sair\n");
}

int main() {
    Fila fila;
    int tamanhoF, opcao, valor;

    printf("Qual o tamanho da sua fila: ");
    scanf("%d", &tamanhoF);
    inicializarFila(&fila, tamanhoF);

    do {
        menu();
        printf("Escolha entre as opcoes: ");
        scanf("%d", &opcao);

        switch (opcao) {
            case 1:
                printf("Digite o elemento do final da fila: ");
                scanf("%d", &valor);
                enfileirar(&fila, valor);
                break;
            case 2:
                desenfileirar(&fila);
                break;
            case 3:
                consultarInicio(&fila);
                break;
            case 4:
                if (filaVazia(&fila)) {
                    printf("A fila esta vazia.\n");
                } else {
                    printf("A fila nao esta vazia.\n");
                }
                break;
            case 5:
                if (filaCheia(&fila)) {
                    printf("A fila esta cheia.\n");
                } else {
                    printf("A fila nao esta cheia.\n");
                }
                break;
            case 0:
                printf("Saindo...\n");
                break;
            default:
                printf("Opcao invalida!\n");
        }
    } while (opcao != 0);

    free(fila.elemento);

    return 0;
}
