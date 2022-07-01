#include <stdio.h>
#include <stdlib.h> //Para usar calloc()
#include <stdbool.h>
#include <time.h>
#include <math.h>

//Chamando a função para preencher o array com os numeros aleatorios
void fill_random(int array[], int length, int max);

void swap(int *a, int *b) {
  int t = *a;
  *a = *b;
  *b = t;
}

int partition(int array[], int menor, int maior) {
  
  int pivot = array[maior]; // tamanho do array
  
  int i = (menor - 1); // atribuição do contador

  for (int j = menor; j < maior; j++) {
    if (array[j] <= pivot) {
        
      i++;
      
      swap(&array[i], &array[j]);
    }
  }

  swap(&array[i + 1], &array[maior]);
  
  return (i + 1);
}

void quickSort(int array[], int menor, int maior) {
  if (menor < maior) {
    
    int pi = partition(array, menor, maior);
    
    quickSort(array, menor, pi - 1);
    
    quickSort(array, pi + 1, maior);
  }
}
// Essa é a função que mostra o array no console
void printArray(int array[], int size) {
  for (int i = 0; i < size; ++i) {
    printf("%d  ", array[i]);
  }
  printf("\n");
}

int main() {
  srand( time(NULL) ); //é a função que manda para o rand o horario do computador
  
  int i;
  int a=100; //tamanho da array
  int *ptr; //ponteiro utilizado para alocar memoria dinamica com o calloc
  ptr = (int *)calloc(a, sizeof(int)); /*Aloca a números inteiros ptr pode agora ser tratado como um 
                                              vetor com a posicoes. ptr retorna um ponteiro void*/

  fill_random(ptr, 100, 1000);
  
  printf("Unsorted Array\n");
  printArray(ptr, a);
  
  quickSort(ptr, 0, a - 1);
  
  printf("Sorted array in ascending order: \n"); // chamando a função (algoritmo) para realizar a ordenação dos numeros
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
