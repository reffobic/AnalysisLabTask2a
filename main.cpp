
// Done by Mohamed El Refai 900222334
// Task 1

#include <iostream>
#include <iomanip>

using namespace std;

int exp(int a, int n, int &opCount){
    int num = a;
    int result = 1;

    while (n != 0){
        if (n % 2 == 1){
            result *= num;
            n -= 1;
        } else {
            num *= num;
            n /= 2;
        }
        opCount ++;
    }

    return result;
}

int Poly1 (int a[], int x, int size, int &opCounter)
{
    int p = a[0];

    for (int i = 1; i < size; i++) {
        opCounter ++;
        p = p + a[i] * exp(x, i, opCounter);
    }

    return p;
}

int Poly2 (int a[], int x, int size, int &opCounter)
{
    int p = a[size - 1];

    for (int i = 1; i < size; i++) {
        opCounter++;
        p = p * x + a[size - 1 - i];
    }

    return p;
}

int main() {
    int opCount1 = 0, opCount2 = 0;
    int size = 4, x;

    int a1[] = {2,-4,14,34};
    int a2[] = {2,6,5,3,2,-9,-5,10};
    int a3[] = {4,6,3,1,-4,23,1,-5,7,4,-8};

    cout << "Enter the value of x to evaluate it: ";
    cin >> x;

    cout << "-------------------------------------------------------------------" << endl;
    cout << setw(3) << "Degree" << setw(17) << "Result" << setw(20) << "OpCount1" << setw(20) << "OpCount2" << endl;

    Poly2(a1, x, size, opCount2);
    cout << setw(3) << "3" << setw(20) << Poly1(a1, x, size, opCount1) << setw(20) << opCount1 << setw(20) << opCount2<< endl;

    opCount1 = 0, opCount2 = 0;
    size = 8;
    Poly2(a2, x, size, opCount2);
    cout << setw(3) << "7" << setw(20) << Poly1(a2, x, size, opCount1) << setw(20) << opCount1 << setw(20) << opCount2<< endl;

    opCount1 = 0, opCount2 = 0;
    size = 11;
    Poly2(a3, x, size, opCount2);
    cout << setw(3) << "10" << setw(20) << Poly1(a3, x, size, opCount1) << setw(20) << opCount1 << setw(20) << opCount2<< endl;
    cout << "-------------------------------------------------------------------" << endl;

    return 0;
}
