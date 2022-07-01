#include <stdbool.h>
#include <stdlib.h> //Para usar calloc()
#include <time.h>
#include <math.h>
#include <stdio.h>
 
 //Chamando a função para preencher o array com os numeros aleatorios
void fill_random(int array[], int length, int max);

// Aqui é a implementação do Insertion Sort no codigo
void insertionSort(int arr[], int n)
{
    int i, key, j;
    for (i = 1; i < n; i++) {
        key = arr[i];
        j = i - 1;
 
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        arr[j + 1] = key;
    }
}
 
 // Essa é a função que mostra o array no console
void printArray(int arr[], int n)
{
    int i;
    for (i = 0; i < n; i++)
        printf("%d ", arr[i]);
    printf("\n");
}
 // Testa as funções acima
int main()
{
   
    srand( time(NULL) ); //é a função que manda para o rand o horario do computador
  
    int i;
    int a=10000; //tamanho da array
    int *ptr; //ponteiro utilizado para alocar memoria dinamica com o calloc
    ptr = (int *)calloc(a, sizeof(int)); /*Aloca a números inteiros ptr pode agora ser tratado como um 
                                              vetor com a posicoes. ptr retorna um ponteiro void*/

// preenche com numeros inteiros aleatorios
    fill_random(ptr, 10000, 10000000);
 
    insertionSort(ptr, a); // chamando a função (algoritmo) para realizar a ordenação dos numeros
    printArray(ptr, a); //mostrar os numeros ordenados
    system("pause"); // pausar antes de fechar o console
    return 0; // finalizar o programa
}

void fill_random(int array[], int length, int max) //função que preenche o array com numeros aleatorios
{
 // esse for está rodando a array[i] para preenche-lá
  for (int i = 0; i < length; i++)
    array[i] = ((rand() * rand()) % max) + 1;
    // Esse array multiplica o tamanho de rand para conseguir sortear numeros maiores. Max é rand maximo de numeros
    //aleatorios que pode gerar, e o +1 é para não começar do 0.
}
