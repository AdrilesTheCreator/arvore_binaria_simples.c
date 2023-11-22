#include <stdio.h>
#include <stdlib.h>

// Defini��o da estrutura para um n� de �rvore bin�ria
typedef struct tree {
  int num; // N�mero inteiro associado ao n�
  struct tree* sad; // Ponteiro para o filho direito (sub�rvore direita)
  struct tree* sae; // Ponteiro para o filho esquerdo (sub�rvore esquerda)
} Tree;

// Fun��o que cria uma �rvore vazia
Tree* createTree() {
  return NULL;
}

// Fun��o que verifica se uma �rvore � vazia
int treeIsEmpty(Tree* t) {
  // Retorna 1 se a �rvore for vazia e 0 caso contr�rio
  return t == NULL;
}

// Fun��o que mostra a informa��o da �rvore
void showTree(Tree* t) {
  if (!treeIsEmpty(t)) {
    // Mostra os elementos em pr�-ordem
    printf("%d ", t->num); // mostra a raiz
    showTree(t->sae); // mostra a sae (sub�rvore � esquerda)
    showTree(t->sad); // mostra a sad (sub�rvore � direita)
  }
}

// Fun��o que insere um dado na �rvore
void insertTree(Tree** t, int num) {
  if (*t == NULL) {
    *t = (Tree*)malloc(sizeof(Tree)); // Aloca mem�ria para a estrutura
    (*t)->sae = NULL; // Sub�rvore � esquerda � NULL
    (*t)->sad = NULL; // Sub�rvore � direita � NULL
    (*t)->num = num; // Armazena a informa��o
  }
  else {
    if (num < (*t)->num) { // Se o n�mero for menor ent�o vai pra esquerd
      // Percorre pela sub�rvore � esquerda
      insertTree(&((*t)->sae), num);
    }
    else if (num > (*t)->num) {// Se o n�mero for maior ent�o vai pra direita
      // Percorre pela sub�rvore � direita
      insertTree(&((*t)->sad), num);
    }
  }
}

// Fun��o que verifica se um elemento pertence ou n�o � �rvore
int isInTree(Tree* t, int num) {
  if (treeIsEmpty(t)) { // Se a �rvore estiver vazia, ent�o retorna 0
    return 0;
  }

  // O operador l�gico || interrompe a busca quando o elemento for encontrado
  return t->num == num || isInTree(t->sae, num) || isInTree(t->sad, num);
}

// Fun��o que libera a mem�ria alocada pela �rvore
void freeTree(Tree* t) {
  if (t != NULL) {
    freeTree(t->sae);
    freeTree(t->sad);
    free(t);
  }
}

int main() {
  Tree* t = createTree(); // Cria uma �rvore
  // Insere os elementos na �rvore
  insertTree(&t, 12); 
  insertTree(&t, 15);
  insertTree(&t, 10);
  insertTree(&t, 13);
  
  printf("Valores na arvore: \n");
  showTree(t); // Mostra os elementos da �rvore em pr�-ordem
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
  // Verifica se a �rvore est� vazia
  if (treeIsEmpty(t)) {
    printf("Arvore esta vazia!!\n");
  }
  else {
    printf("Arvore NAO esta vazia!!\n");
  }

  // Verifica se o n�mero 15 pertence � �rvore
  if (isInTree(t, 13)) {
    printf("O numero 13 pertence a arvore!\n");
  }
  else {
    printf("O numero 13 NAO pertence a arvore!\n");
  }

  // Verifica se o n�mero 22 pertence � �rvore
  if (isInTree(t, 22)) {
    printf("O numero 22 pertence a arvore!");
  }
  else {
    printf("O numero 22 NAO pertence a arvore!");
  }

  freeTree(t); // Libera a mem�ria alocada pela estrutura �rvore

  return 0;
}

