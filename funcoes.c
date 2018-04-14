#include <stdlib.h>
#include <stdio.h>
#include <sys/time.h>
#include "funcoes.h"

//CHOOSING THE VETOR SIZE

int Choose_Size (int sortType) {
    int elementos, i, cont;
    long int media[10], mediatotal = 0;

    printf("Escolha um tamanho de vetor:\n");
    printf("1. 1000\n");
    printf("2. 5000\n");
    printf("3. 10000\n");
    printf("4. 20000\n");
    printf("5. 50000\n");
    printf("6. 100000\n");
    printf("7. 500000\n");
    printf("8. 100 - RadixSort\n");


    scanf("%d", &elementos);

    switch(elementos){

        case 1:
            elementos = 1000;
            break;

        case 2:
            elementos = 5000;
            break;

        case 3:
            elementos = 10000;
            break;

        case 4:
            elementos = 20000;
            break;

        case 5:
            elementos = 50000;
            break;

        case 6:
            elementos = 100000;
            break;
        case 7:
            elementos = 500000;
            break;
        case 8:
            elementos = 100;
            break;
        default:
            printf("Numero Invalido, Settando 20000 como padrão");
            elementos = 20000;
            break;
    }

    int vetor[elementos];

    for(cont = 0; cont<10; cont++){

    GeraVetor(vetor, elementos);

    struct timeval tvalBefore, tvalAfter;  // removed comma

    switch(sortType){
        case 1:
            gettimeofday (&tvalBefore, NULL);
            BubbleSort(vetor, elementos);
            gettimeofday (&tvalAfter, NULL);
            free(vetor);
            break;
        case 2:
            gettimeofday (&tvalBefore, NULL);
            InsertionSort(vetor, elementos);
            gettimeofday (&tvalAfter, NULL);
            free(vetor);
            break;
        case 3:
            gettimeofday (&tvalBefore, NULL);
            SelectionSort(vetor, elementos);
            gettimeofday (&tvalAfter, NULL);
            free(vetor);
            break;
        case 4:
            gettimeofday (&tvalBefore, NULL);
            ShellSort(vetor, elementos);
            gettimeofday (&tvalAfter, NULL);
            free(vetor);
            break;
        case 5:
            gettimeofday (&tvalBefore, NULL);
            HeapSort(vetor, elementos);
            gettimeofday (&tvalAfter, NULL);
            free(vetor);
            break;
        case 6:
            gettimeofday (&tvalBefore, NULL);
            QuickSort(vetor, 0, elementos-1);
            gettimeofday (&tvalAfter, NULL);
            free(vetor);
            break;
        case 7:
            gettimeofday (&tvalBefore, NULL);
            MergeSort(vetor, elementos);
            gettimeofday (&tvalAfter, NULL);
            free(vetor);
            break;
        case 8:
            gettimeofday (&tvalBefore, NULL);
            RadixSort(vetor, elementos);
            gettimeofday (&tvalAfter, NULL);
            free(vetor);
            break;
        default:
            gettimeofday (&tvalBefore, NULL);
            printf("Nem sei como ce conseguiu chegar aq, mas isso n ta valido nao");
            gettimeofday (&tvalAfter, NULL);
            free(vetor);
            break;
    }

    media[cont] = ((tvalAfter.tv_sec - tvalBefore.tv_sec)*1000000L+tvalAfter.tv_usec) - tvalBefore.tv_usec;

    mediatotal += media[cont];

    // Changed format to long int (%ld), changed time calculation

    printf("\nTime in microseconds: %ld microseconds in test number %d\n",
            ((tvalAfter.tv_sec - tvalBefore.tv_sec)*1000000L
            +tvalAfter.tv_usec) - tvalBefore.tv_usec, cont
          ); // Added semicolon

    }

    system("pause");
    system("cls");

    printf("%d", mediatotal);

    mediatotal = mediatotal / 10;

    printf("\n A media total de tempo do Sort e %d milisegundos\n", mediatotal);

}

//GERAR NOVOS VETORES

int GeraVetor(int *vetor, int elementos){
    int i;
    int n = time(0);
    srand(n);

    for (i=0; i<elementos; i++){
        vetor[i]=rand()%elementos;
    }
    return vetor;
}



// BUBBLESORT

void BubbleSort(int *v, int n){
    int i, continua, aux, fim = n;
    do{
        continua = 0;
        for(i = 0; i < fim - 1; i++){
            if(v[i] > v[i+1]){
                aux = v[i];
                v[i] = v[i+1];
                v[i+1] = aux;
                continua = i;
            }
        }
        fim--;
    }while(continua!=0);
}

//SelectionSort

void SelectionSort(int *v, int n){
    int i, j, menor, troca;
    for(i=0; i<n-1 ; i++){
        menor = i;
        for(j = i+1; j < n; j++){
            if(v[j] < v[menor]){
                menor = j;
            }
        }
        if(i!=menor){
            troca = v[i];
            v[i] = v[menor];
            v[menor] = troca;
        }
    }
}

//InsertionSort

void InsertionSort(int *v, int n){
    int i, j, aux;
    for(i=1; i<n; i++){
        aux = v[i];
        for(j = i; (j>0) && (aux < v[j-1]); j--){
            v[j] = v[j-1];
        }
        v[j] = aux;
    }
}

//ShellSort

void ShellSort(int *v, int n){
    int i, j, gap, k;
    int x, a[5] = {9, 5, 3, 2, 1};

    for (k=0;k<5;k++){
        gap = a[k];
        for(i = gap; i<n;i++){
            x = v[i];
            for(j=i-gap; x<v[j] && j >=0; j = j-gap){
                v[j+gap] = v[j];
            }
            v[j+gap] = x;
        }
    }
}

//MergeSort

void sort(int *vetor, int *aux, int i, int f) {
  if (i >= f) return;

  int m = (i + f) / 2;

  sort(vetor, aux, i, m);
  sort(vetor, aux, m + 1, f);

  /* Se vetor[m] <= vetor[m + 1], então vetor[i..f] já está ordenado. */
  if (vetor[m] <= vetor[m + 1]) return;

  merge(vetor, aux, i, m, f);
}

void merge(int *vetor, int *aux, int i, int m, int f) {
  int z, antesvetor = i, antesaux = m + 1;

  for (z = i; z <= f; z++) aux[z] = vetor[z];

  z = i;

  while (antesvetor <= m && antesaux <= f) {
    /* Invariante: vetor[i..z] possui os valores de vetor[antesvetor..m] e vetor[antesaux..f] em ordem crescente. */

    if (aux[antesvetor] < aux[antesaux]) vetor[z++] = aux[antesvetor++];
    else /* if (c[antesvetor] > c[antesaux]) */ vetor[z++] = aux[antesaux++];
  }

  while (antesvetor <= m) vetor[z++] = aux[antesvetor++];

  while (antesaux <= f) vetor[z++] = aux[antesaux++];
}

void MergeSort(int *vetor, int n) {
  int *aux = malloc(sizeof(int) * n);
  sort(vetor, aux, 0, n - 1);
  free(aux);
}

//RadixSortLSD

int getMax(int vetor[], int elementos) {

    int i, maiorValor = vetor[0];

    for(i = 1; i < elementos; i++) {
        if(vetor[i] > maiorValor) {
            maiorValor = vetor[i];
        }
    }
    return maiorValor;
}

void RadixSort(int vetor[], int elementos) {

    int i, maiorValor, bucket[100], count[10], expo = 1;

    maiorValor = getMax(vetor, elementos);



    while(maiorValor / expo > 0) {


        for(i = 0; i < 10; i++) {
            count[i] = 0;
        }

        for(i = 0; i < elementos; i++) {

            count[ (vetor[i] / expo) % 10 ]++;

        }


        for(i = 1; i < elementos; i++) {

            count[i] += count [i - 1];

        }

        for(i = elementos - 1; i >= 0; i--) {


            bucket[ count[ (vetor[i]/expo) % 10 ]  - 1] = vetor[i];


            count[ (vetor[i]/expo) % 10 ]--;
        }

        for(i = 0; i < elementos; i++) {
            vetor[i] = bucket[i];
        }

        expo *= 10;
    }
}

//QuickSort

void QuickSort(int *vetor, int left, int right) {
    int l, r, x, y;

    l = left;
    r = right;
    x = vetor[(left + right) / 2];

    while(l <= r) {
        while(vetor[l] < x && l < right) {
            l++;
        }
        while(vetor[r] > x && r > left) {
            r--;
        }
        if(l <= r) {
            y = vetor[l];
            vetor[l] = vetor[r];
            vetor[r] = y;
            l++;
            r--;
        }
    }

    if(r > left) {
        QuickSort(vetor, left, r);
    }
    if(l < right) {
        QuickSort(vetor, l, right);
    }
}

//HeapSort

void HeapSort(int *vet, int N){
    int i, k, aux;
    for(i = (N-1) / 2; i>=0; i--){
        criaHeap(vet, i, N-1);
    }
    for(i = N-1; i>=1; i--){
        aux = vet[0];
        vet[0] = vet[i];
        vet[i] = aux;
        criaHeap(vet, 0, i-1);
    }
}


void criaHeap(int *vet, int i, int f){
    int aux = vet[i];
    int j = i * 2 + 1;
    while(j<=f){
        if(j < f){
            if(vet[j] < vet[j+1]){
                    j = j+1;
            }
        }
        if(aux < vet[j]){
            vet[i] = vet[j];
            i = j;
            j = 2 * i + 1;
        }else{
            j = f+1;
        }
    }
    vet[i] = aux;
}
