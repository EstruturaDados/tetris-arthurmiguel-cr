#include <stdio.h>
// Exibe o estado atual da fila
void exibirFila(Fila *f) {
printf("\nFila de pecas:\n");


if (f->tamanho == 0) {
printf("[vazia]\n");
return;
}


int idx = f->inicio;
for (int i = 0; i < f->tamanho; i++) {
printf("[%c %d] ", f->itens[idx].nome, f->itens[idx].id);
idx = (idx + 1) % MAX_FILA;
}
printf("\n");
}


int main() {
srand(time(NULL));


Fila fila;
inicializarFila(&fila);


int proximoId = 0;


// Inicializa a fila com 5 pecas
for (int i = 0; i < MAX_FILA; i++) {
enqueue(&fila, gerarPeca(proximoId++));
}


int opcao;


do {
exibirFila(&fila);


printf("\nOpcoes:\n");
printf("1 - Jogar peca (dequeue)\n");
printf("2 - Inserir nova peca (enqueue)\n");
printf("0 - Sair\n");
printf("Escolha: ");
scanf("%d", &opcao);


if (opcao == 1) {
Peca removida;
if (dequeue(&fila, &removida)) {
printf("Voce jogou a peca [%c %d]!\n", removida.nome, removida.id);
} else {
printf("Fila vazia! Nao ha peca para jogar.\n");
}
}
else if (opcao == 2) {
if (fila.tamanho == MAX_FILA) {
printf("Fila cheia! Nao e possivel adicionar outra peca.\n");
} else {
enqueue(&fila, gerarPeca(proximoId++));
printf("Nova peca adicionada!\n");
}
}


} while (opcao != 0);


printf("Encerrando...\n");


return 0;
}