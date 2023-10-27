#include <stdio.h>
#include <stdlib.h>

int main(){

    int a,b;

    do{
        printf("Podaj liczbe a: ");
        scanf("%d",&a);
    }while(a < 0);

    do{
        printf("Podaj liczbe b: ");
        scanf("%d",&b); 
    }while(b < 0);


    if(b > a){
        int temp = a;
        a = b;
        b = temp;
    }

    int m = a;
    int n = b;

    while( m > n){
        if( n == 0){
            printf("NWD(%d,%d) = %d",a,b,m);
            break;
        }

        int temp = n;
        n = m % n;
        m = temp;
    }

    return 0;
}



//REKURENCYJNE

int NWD(int a,int b){
    if(b > a){
        int temp = a;
        a = b;
        b = temp;
    }

    if( b == 0) return a;
    else if( b > 0) return NWD(b, a % b);
}

/*
void main(){
    int a,b;

    do{
        printf("Podaj liczbe a: ");
        scanf("%d",&a);
    }while(a < 0);

    do{
        printf("Podaj liczbe b: ");
        scanf("%d",&b); 
    }while(b < 0);

    int nwd = NWD(a,b);
    printf("NWD(%d,%d) = %d",a,b,nwd);
}
*/