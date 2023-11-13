#include <stdio.h>
#include <string.h>

char* AddNumbers(char* n1, char* n2) {
    char* r = "";
    int carry = 0;
    int i = strlen(n1) - 1;
    int j = strlen(n2) - 1;
    while (i >= 0 && j >= 0) {
        int t1 = n1[i] - '0';
        int t2 = n2[j] - '0';
        int sum = t1 + t2 + carry;
        carry = sum / 10;
        char temp[2];
        sprintf(temp, "%d", sum % 10);
        strcat(temp, r);
        r = temp;
        i--;
        j--;
    }
    while (i >= 0) {
        int sum = (n1[i] - '0') + carry;
        carry = sum / 10;
        char temp[2];
        sprintf(temp, "%d", sum % 10);
        strcat(temp, r);
        r = temp;
        i--;
    }
    while (j >= 0) {
        int sum = (n2[j] - '0') + carry;
        carry = sum / 10;
        char temp[2];
        sprintf(temp, "%d", sum % 10);
        strcat(temp, r);
        r = temp;
        j--;
    }
    if (carry != 0) {
        char temp[2];
        sprintf(temp, "%d", carry);
        strcat(temp, r);
        r = temp;
    }
    return r;
}

char* MultiplyNumbers(char* n1, char* n2) {
    char* result = "0";
    for (int j = strlen(n2) - 1; j >= 0; j--) {
        int t1 = n2[j] - '0';
        char* temp = "0";
        for (int i = strlen(n1) - 1; i >= 0; i--) {
            int t2 = n1[i] - '0';
            char temp2[100];
            sprintf(temp2, "%d", t1 * t2);
            char temp3[100];
            sprintf(temp3, "%s%s", temp2, "0");
            temp = AddNumbers(temp, temp3);
        }
        char temp4[100];
        sprintf(temp4, "%s%s", temp, "0");
        result = AddNumbers(result, temp4);
    }
    return result;
}

int main()
{
    char num1[100];
    char num2[100];
    printf("Enter the first number: ");
    scanf("%s", num1);
    printf("Enter the second number: ");
    scanf("%s", num2);
    char* result = MultiplyNumbers(num1, num2);
    printf("%s", result);
    return 0;
}


