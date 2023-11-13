

#include <iostream>
#include <string>
using namespace std;


string AddNumbers(string n1, string n2) {
    string r = "";

    int carry = 0;
    int i = n1.length() - 1;
    int j = n2.length() - 1;

    while (i >= 0 && j >= 0) {
        int t1 = n1[i] - '0';
        int t2 = n2[j] - '0';

        int sum = t1 + t2 + carry;
        carry = sum / 10;
        r = to_string(sum % 10) + r;

        i--;
        j--;
    }

    while (i >= 0) {
        int sum = (n1[i] - '0') + carry;
        carry = sum / 10;
        r = to_string(sum % 10) + r;
        i--;
        
    }

    while (j >= 0) {
        int sum = (n2[j] - '0') + carry;
        carry = sum / 10;
        r = to_string(sum % 10) + r;
        j--;

    }

    if (carry != 0) r = to_string(carry) + r;

    return r;
}

string MultiplyNumbers(string n1, string n2) {
    string result = "0";

    for (int j = n2.length() - 1; j >= 0; j--) {
        int t1 = n2[j] - '0';
        string temp = "0";

        for (int i = n1.length() - 1; i >= 0; i--) {
            int t2 = n1[i] - '0';

            temp = AddNumbers(temp, to_string(t1 * t2) + string(n1.length() - i - 1, '0'));
        }

        result = AddNumbers(result, temp + string(n2.length() - j - 1, '0'));
    }

    return result;
}

int main()
{
    string num1;
    string num2;


    cout << "Enter the first number: ";
    cin >> num1;

    cout << "Enter the second number: ";
    cin >> num2;

    string result = MultiplyNumbers(num1, num2);
    cout << result;


}

