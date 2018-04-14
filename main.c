#include <stdlib.h>
#include <stdio.h>
#include <sys/time.h>
#include "funcoes.h"

int main()
{
    int c;

    do{
    printf("Olá usuário, Seja bem-vindo!!");
    printf("\nPor favor, escolha umas das ordenações a seguir, ou saia do programa");
    printf("\n1 - BubbleSort \n2 - InsertionSort \n3 - SelectionSort \n4 - ShellSort");
    printf("\n5 - HeapSort \n6 - QuickSort \n7 - MergeSort \n8 - RadixSort");
    printf("\nCaso queira sair do programa, tecle zero(0)");
    printf("\nDigite um numero:");
    scanf("%d", &c);

    switch(c){
        case 1:
            system("cls");
            Choose_Size(c);
            system ("pause");
            system("cls");
            break;
        case 2:
            system("cls");
            Choose_Size(c);
            system ("pause");
            system("cls");
            break;
        case 3:
            system("cls");
            Choose_Size(c);
            system ("pause");
            system("cls");
            break;
        case 4:
            system("cls");
            Choose_Size(c);
            system ("pause");
            system("cls");
            break;
        case 5:
            system("cls");
            Choose_Size(c);
            system ("pause");
            system("cls");
            break;
        case 6:
            system("cls");
            Choose_Size(c);
            system ("pause");
            system("cls");
            break;
        case 7:
            system("cls");
            Choose_Size(c);
            system ("pause");
            system("cls");
            break;
        case 8:
            system("cls");
            Choose_Size(c);
            system ("pause");
            system("cls");
            break;
        case 0:
            break;
        default:
            system("cls");
            printf("valor inválido");
            system ("pause");
            system("cls");
            break;
    }
    }while(c != 0);


    printf("\n.\n.\n.\n.\n.");
    printf("\nObrigado!");

}
