#include <stdio.h>
#include <math.h>
#include <stdlib.h>

void obliczPierwiastki(float a, float b, float c){
    float delta =  pow(b,2) - (4*a*c);
    if(delta >= 0){
        float x1 = (-b + sqrt(delta) ) / 2*a;
        float x2 = (-b - sqrt(delta) ) / 2*a;
        printf("Rozwiazanie: x1=%.2f x2=%.2f",x1,x2);
    }else{
        printf("Brak rozwiazan rzeczywistych");
    }

}

int main(){
    float a,b,c;

    do{
        printf("Podaj wsolczynnik a (a != 0): ");
        scanf("%f",&a);
    }while(a == 0);

    printf("Podaj wspolczynnik b: ");
    scanf("%f",&b);

    printf("Podaj wspolczynnik c: ");
    scanf("%f",&c);

    printf("Twoje rownanie ma postac: %.2fx^2 +%.2fx +%.2f\n",a,b,c);
    obliczPierwiastki(a,b,c);



    return 0;
}