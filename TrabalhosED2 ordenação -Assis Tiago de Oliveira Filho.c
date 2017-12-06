UNICAP – Universidade Católica de Pernambuco
Estrutura de Dados 2
Aluno:Assis Tiago de Oliveira Filho
Professor(a): Ana Eliza



#include<stdio.h>
#include<stdlib.h>
#include<time.h>

#define VAR -32768

void exibir(int vet[], int tam);
void random(int vet[], int tam);
void bubble_sort_decrescente (int vet[], int tam);
void gnome_sort (int vet[],int tam);
void bubble_sort (int vet[], int tam);
void merge(int vetor[], int inicio, int meio, int fim) ;
void merge_sort(int v[], int inicio, int fim);
void shell_sort(int Vetor[], int tamanho);
void heap_sort (int vet[], int n);
void quick_sort (int vet[], int i, int f);
void heap (int v[] , int n, int r) 
int keyval (int v[], int n, int i);
void particao(int vet[], int i, int f, int *k);



void exibir(int vet[], int tam){
	int i;
	for(i=0;i<tam;++i){
		printf("%d  ",vet[i]);
	}
	printf("\n");
}





void random(int vet[], int tam){
	int i;
	for(i=0;i<tam;++i){
		vet[i] = rand() % 1000; 
	}
}




void bubble_sort_decrescente (int vet[], int tam) {
	int i, j, tmp;
	for (i = 0; i < tam - 1; i++){
		for (j = tam - 1; j > i; j--){
			if( vet[j] > vet[j - 1] ){
				tmp = vet[j - 1];
				vet[j - 1] = vet[j];
				vet[j] = tmp;
			}
		}
	}

}




void gnome_sort (int vet[],int tam) {
	int i, chave;
	for (i = 1; i <= tam - 1; i++) {

           if(vet[i-1] <= vet[i]){
                 i++;
		}
	else{
          chave    =  vet[i];
          vet[i]   =  vet[i-1];
          vet[i-1] =  tmp;
           i--;  
                 if(i == 0)
                    i = 1;
             }
      }
}




void bubble_sort (int vet[], int tam) {
	int i, fim, pos, troca, chave; 
	troca = 1; fim = tam - 2; pos = 0;
	while (troca == 1) {
		troca = 0;
		for (i = 0; i <= fim; i++) {
			if (vet[i] > vet[i+1]) {
				chave = vet[i]; 
				vet[i] = vet[i+1]; 
				vet[i+1] = chave;
				pos = i; troca = 1;
			}
		}
		fim = pos-1;
	}
}


void merge(int vetor[], int inicio, int meio, int fim) {
	int prim = inicio;
	int seg = meio + 1;
	int aux[10000], i = inicio;
	// enquanto tiver elementos nos dois conjuntos
	while ((prim <= meio) && (seg <= fim)) {
		// insere elemento do primeiro
		if (vetor[prim] <= vetor[seg]) {
			aux[i] = vetor[prim];
			prim++;
		} else { // insere elemento do segundo
			aux[i] = vetor[seg];
			seg++;
		}
		i++;
	}
	// sobrou elementos do segundo
	if (prim > meio) {
		while (seg <= fim) {
			aux[i] = vetor[seg];
			seg++;
			i++;
		}
		// sobrou elementos do primeiro
	} else {
		while (prim <= meio) {
			aux[i] = vetor[prim];
			prim++;
			i++;
		}
	}
	// copia o vetor auxiliar no vetor principal
	for (i = inicio; i <= fim; i++) {
		vetor[i] = aux[i];
	}
}



void merge_sort(int v[], int inicio, int fim) {
	int meio;
	if (inicio == fim) { // tamanho = 1
		return;
	} else {
		// encontra o meio
		meio = (inicio + fim) / 2;
		// ordena 1a metade
		merge_sort(v, inicio, meio);
		// ordena 2a metade
		merge_sort(v, meio + 1, fim);
		// intercala
		merge(v, inicio, meio, fim);
	}
}


void shell_sort(int Vetor[], int tamanho){
	int i = (tamanho - 1) / 2;
	int chave, k, aux;
	while(i != 0){
		do{
			chave = 1;
			for(k = 0; k < tamanho - i; ++k) {
				if(Vetor[k] > Vetor[k + i]){
					aux = Vetor[k];
					Vetor[k] = Vetor[k + i];
					Vetor[k + i] = aux;
					chave = 0;
				}
			}
		} while(chave == 0);
		i = i / 2;
	}
}



void heap_sort (int vet[], int n) {
	int i, r, n1, auxkey;
	i = n / 2 - 1;
	for (r = i; r >= 0; r--) {
		heap (vet, n, r);
	}
	for (n1 = n-2; n1 >= 0; n1--) {
		auxkey = vet[0];
		vet[0] = vet[n1+1];
		vet[n1+1] = auxkey;
		heap (vet, n1, 0);
	}

}


void quick_sort (int vet[], int i, int f) {
	int k;
	if (f > i) {
		particao (vet, i, f, &k);
		quick_sort (vet,i,k-1);
		quick_sort (vet, k+1, f);
	}
}




int keyval (int v[], int n, int i) {
	if (i > n) 
		return VAR;
	else
		return v[i];
}



void heap (int v[] , int n, int r) { 
	int i, h, troca, auxkey;
	i = r; troca = 1;
	while (troca == 1) {
		troca = 0;
		if (keyval(v, n, 2*i+1) > keyval(v, n, 2*i+2))
			h = 2*i+1;
		else
			h = 2*i+2;
		if (v[i] < keyval(v, n, h)) {
			auxkey = v[i]; v[i] = v[h]; v[h] = auxkey; i = h; troca = 1;
		}
	} 
}



void particao(int vet[], int i, int f, int *k){
	int chave = vet[i];
	char lado = 'E';
	while(i != f){
		if(lado == 'E'){
			if(vet[f] < chave){
				vet[i] = vet[f];
				++i;
				lado = 'D';
			} else{
				--f;
			}
		} else{
			if(vet[i] > chave){
				vet[f] = vet[i];
				--f;
				lado = 'E';
			} else{
				++i;
			}
		}
	}
	vet[i] = chave;
	*k = i;
}



int main() {
	int vet1[100],vet2[1000],vet3[10000];
	double duracao;
	clock_t t;
	srand(time(NULL));
	random(vet3,10000);
	
	bubble_sort_decrescente (vet3, 10000);
	t = clock();

	gnome_sort (vet3, 10000);                    //GnomeSort
	t = clock() - t;
	duracao = (double) (t) / CLOCKS_PER_SEC;
	printf("GnomeSort\t%f\n",duracao);
	bubble_sort_decrescente (vet3, 10000);
	t = clock();

	quick_sort (vet3, 0, 10000);                 //QuickSort
	t = clock() - t;
	duracao = (double) (t) / CLOCKS_PER_SEC;
	printf("QuickSort\t%f\n",duracao);

	bubble_sort_decrescente (vet3, 10000);
	t = clock();
	heap_sort (vet3, 10000);                     //HeapSort
	t = clock() - t;
	duracao = (double) (t) / CLOCKS_PER_SEC;
	printf("HeapSort\t%f\n",duracao);
	bubble_sort_decrescente (vet3, 10000);
	t = clock();

	merge_sort(vet3, 0, 10000);                  //MergeSort
	t = clock() - t;
	duracao = (double) (t) / CLOCKS_PER_SEC;
	printf("MergeSort\t%f\n",duracao);
	bubble_sort_decrescente (vet3, 10000);
	t = clock();

	shell_sort(vet3, 10000);                     //ShellSort
	t = clock() - t;
	duracao = (double) (t) / CLOCKS_PER_SEC;
	printf("ShellSort\t%f\n",duracao);
	bubble_sort_decrescente (vet3, 10000);
	t = clock();
	bubble_sort (vet3, 10000);                   //BubbleSort
	t = clock() - t;
	duracao = (double) (t) / CLOCKS_PER_SEC;
	printf("BubbleSort\t%f\n",duracao);
	


	system("pause>>nul");
	return 0;
}
