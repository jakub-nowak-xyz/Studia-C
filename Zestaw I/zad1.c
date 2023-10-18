#include <stdio.h>
#include <math.h>
#include <stdlib.h>

#define N_MAX 10



double obliczSrednia(double tab[]){
    double sum = 0;

    for(int i = 0; i < N_MAX; i++){
        sum += tab[i];
    }


    return sum / N_MAX;
}

double obliczOdchylenie(double tab[],double srednia){
    double sum = 0;
    
    for(int i = 0; i < N_MAX;i++){
        sum += pow(tab[i] - srednia,2);
    }

    double wariancja = sum / N_MAX;

    return sqrt(wariancja);
}


int main(){
    double tab[N_MAX];

    for(int i =0; i < N_MAX;i++){
        printf("Podaj %d liczbe do sredniej: ",i+1);
        scanf("%lf",&tab[i]);
    }

    double srednia = obliczSrednia(tab);
    printf("Srednia = %.2lf\n",srednia);
    double odchylenie = obliczOdchylenie(tab,srednia);
    printf("Odchylenie = %.2lf\n",odchylenie);

    return 0;
}