#include <stdio.h>
#include <math.h>

int isPrime(int x){
    if (x < 2) return 0;

    for(int i = 2; i <= (int)sqrt(x); i++){
        if(x % i == 0){
            return 0;
        }
    }

    return 1;
}

int main(){
    int n;
    printf("Podaj liczbe n: ");
    scanf("%d", &n);

    int tab[n];
    for(int i =0; i < n; i++){

        if( i == 0 || i ==1) tab[i] = 0;
        else tab[i] = 1;
    }
    //Dziala

    for(int i =2 ; i < n; i++){
        if(tab[i] == 1){
            for(int j = i;j < n; j+=i){
                if(i != j)
                    tab[j] = 0;

            }
        }
    }

    for(int i = 0; i < n; i++){
        if(tab[i] == 1){
            printf("%d ", i);
        }
    }

}
