#include <stdio.h>
#include <stdlib.h>

// Definição da estrutura para um nó de árvore binária
typedef struct tree {
  int num; // Número inteiro associado ao nó
  struct tree* sad; // Ponteiro para o filho direito (subárvore direita)
  struct tree* sae; // Ponteiro para o filho esquerdo (subárvore esquerda)
} Tree;

// Função que cria uma árvore vazia
Tree* createTree() {
  return NULL;
}

// Função que verifica se uma árvore é vazia
int treeIsEmpty(Tree* t) {
  // Retorna 1 se a árvore for vazia e 0 caso contrário
  return t == NULL;
}

// Função que mostra a informação da árvore
void showTree(Tree* t) {
  if (!treeIsEmpty(t)) {
    // Mostra os elementos em pré-ordem
    printf("%d ", t->num); // mostra a raiz
    showTree(t->sae); // mostra a sae (subárvore à esquerda)
    showTree(t->sad); // mostra a sad (subárvore à direita)
  }
}

// Função que insere um dado na árvore
void insertTree(Tree** t, int num) {
  if (*t == NULL) {
    *t = (Tree*)malloc(sizeof(Tree)); // Aloca memória para a estrutura
    (*t)->sae = NULL; // Subárvore à esquerda é NULL
    (*t)->sad = NULL; // Subárvore à direita é NULL
    (*t)->num = num; // Armazena a informação
  }
  else {
    if (num < (*t)->num) { // Se o número for menor então vai pra esquerd
      // Percorre pela subárvore à esquerda
      insertTree(&((*t)->sae), num);
    }
    else if (num > (*t)->num) {// Se o número for maior então vai pra direita
      // Percorre pela subárvore à direita
      insertTree(&((*t)->sad), num);
    }
  }
}

// Função que verifica se um elemento pertence ou não à árvore
int isInTree(Tree* t, int num) {
  if (treeIsEmpty(t)) { // Se a árvore estiver vazia, então retorna 0
    return 0;
  }

  // O operador lógico || interrompe a busca quando o elemento for encontrado
  return t->num == num || isInTree(t->sae, num) || isInTree(t->sad, num);
}

// Função que libera a memória alocada pela árvore
void freeTree(Tree* t) {
  if (t != NULL) {
    freeTree(t->sae);
    freeTree(t->sad);
    free(t);
  }
}

int main() {
  Tree* t = createTree(); // Cria uma árvore
  // Insere os elementos na árvore
  insertTree(&t, 12); 
  insertTree(&t, 15);
  insertTree(&t, 10);
  insertTree(&t, 13);
  
  printf("Valores na arvore: \n");
  showTree(t); // Mostra os elementos da árvore em pré-ordem
  printf("\n");
  
  int vetor[4] {12,15,10,13}; // Preenche um vetor
  
  for(int i=0;i<4;i++){
    int menor = i;
    for(int j=i+1;j<4;j++){
        // Se o vetor for menor que a variavel menor a variavel recebe o valor do vetor
        if(vetor[j] < vetor[menor]) menor = j;
	  }
	  //
	  int aux = vetor[i];
	  vetor[i] = vetor[menor];
	  vetor[menor] = aux;
  }
  // Mostra o vetor em ordem crescente
  printf("Valores em forma crescente: \n");
  for (int i=0;i<4;i++){
  	printf("%i ", vetor[i]);
  }
	printf("\n\n");
  // Verifica se a árvore está vazia
  if (treeIsEmpty(t)) {
    printf("Arvore esta vazia!!\n");
  }
  else {
    printf("Arvore NAO esta vazia!!\n");
  }

  // Verifica se o número 15 pertence à árvore
  if (isInTree(t, 13)) {
    printf("O numero 13 pertence a arvore!\n");
  }
  else {
    printf("O numero 13 NAO pertence a arvore!\n");
  }

  // Verifica se o número 22 pertence à árvore
  if (isInTree(t, 22)) {
    printf("O numero 22 pertence a arvore!");
  }
  else {
    printf("O numero 22 NAO pertence a arvore!");
  }

  freeTree(t); // Libera a memória alocada pela estrutura árvore

  return 0;
}

