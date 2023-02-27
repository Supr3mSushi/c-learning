#include <stdio.h>
#include <stdlib.h>
// Instructions :
// Sortir la suite de fibonacci en base definit par l'input
// Jusqu'au deuxième input
// Sortir les nombres premiers jusqu'à l'input
// Definir si l'input est impair ou paire, faire de meme pour savoir
// Si c'est un multiple de 3
// Saississez 3 input et retournez le plus grand nombre


int fibonacci(int n){
    if (n == 0){
        return 0;
    }

    else if (n == 1){
        return 1;
    }

    else{
        return fibonacci(n-1) + fibonacci(n-2);
    }
}

int main(){
    int n;
    printf("Veuillez choisir un entier positif n : %d &n", 0);
    printf("Le %d-ième terme de la suite de Fibonacci est : %d\n", fibonacci(n));
    return 0;
}

