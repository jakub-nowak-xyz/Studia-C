#include <stdio.h>
#include <math.h>
#include <stdlib.h>

#define N_MAX 1000

double obliczSuma(double tab[], int len) {
    double sum = 0;
    for (int i = 0; i < len; i++) {
        sum += tab[i];
    }
    return sum;
}

double obliczSrednia(double tab[], int len) {
    double sum = obliczSuma(tab, len);
    return sum / len;
}

double obliczOdchylenie(double tab[], int len) {
    double sum = 0;
    double srednia = obliczSrednia(tab, len);

    for (int i = 0; i < len; i++) {
        sum += pow(tab[i] - srednia, 2);
    }

    return sqrt(sum / len);
}

int main() {
    FILE *file;
    file = fopen("wynik.txt","w");

    if(file == NULL){
        printf("Nie otworzono pliku");
    }


    int n = 0;

    do {
        printf("Podaj ilosc liczb do sredniej: ");
        scanf("%d", &n);
    } while (n == 0 || n > N_MAX);

    double tab[n];
    for (int i = 0; i < n; i++) {
        printf("Podaj %d liczbe do sredniej: ", i + 1);
        scanf("%lf", &tab[i]);
    }

    double srednia = obliczSrednia(tab, n);
    fprintf(file,"Srednia = %.2lf\n", srednia);

    double odchylenie = obliczOdchylenie(tab, n);
    fprintf(file,"Odchylenie = %.2lf\n", odchylenie);

    fclose(file);

    return 0;
}
