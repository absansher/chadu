#include <iostream>
#include "currency.h"
#include <Windows.h>
#include <string>
#include <clocale>
#include <io.h>
#include <fcntl.h>

using namespace std;

Currency::Currency(float value1, float coeff, char name) {
    sum = value1;
    coefficient = coeff;
    n = name;
}
Currency& Currency::operator=(float i) {
    sum = i;
    return *this;
}
Currency::operator float() const {
    return sum;
}


Currency& Currency:: operator++() {
    sum++;
    return *this;
}

Currency Currency:: operator++(int) {
    Currency temp{ sum, coefficient, n };
    ++(*this);
    return temp;
}
ostream& operator<<(ostream& out, Currency& os) {
    out << os.sum << " of " << os.n;
    return out;
}
istream& operator>>(istream& in, Currency& os) {
    in >> os.sum;
    return in;
}

float Currency::operator+(Currency& cr) const {
    return sum + cr.sum;
}

float Currency::operator/(int i) const {
    return (float) i/coefficient;
}

float operator*(float a,Currency& cr)  {
    return a*cr.coefficient;
}
float operator*(Currency& cr,float a ) {
    return a * cr.sum;
}
float operator*(Currency& os, Currency&cr) {
    return os.sum*cr.coefficient;
}


float Currency::operator*=(Currency& cr) {
    sum =sum*cr;
    return sum;
}

float Currency::operator>(Currency& cr) const{
    if (sum > cr.sum) {
        return 1;
    }
    else {
        return 0;
    }

}

float Currency::operator-(Currency& cr) const {
    return abs(cr.sum - sum);
}

float Currency::transfer(Currency arr2) const {
    return sum * (1 / arr2.coefficient) * coefficient;
}

float Currency::transfer(Currency arr2, float i) const {
    return i * coefficient/arr2.coefficient;
}

float Currency::summ(Currency arr2) {
    sum *= coefficient;
    arr2 *=arr2;
    return sum + arr2.sum;
}

float Currency::difference(Currency arr2) {
    sum *= coefficient;
    arr2 *= arr2;
    return sum - arr2.sum;
}

float operator/(int i, Currency& cr) {
    return (float)i / cr.sum;
}







float check(float variable) {
    while (!(cin >> variable) || (cin.peek() != '\n')) {
        cin.clear();
        while (cin.get() != '\n');
        cout << "try again" << endl;
    }

    return (variable);
}


int main() {

    float value1 = 0, value2 = 0;
    int firstCurrency = 0, secondCurrency = 0;

    Currency sum[10] = {
            sum[0] = Currency(value1, 1, 'R'),
            sum[1] = Currency(value1, 75.7, 'D'),
            sum[2] = Currency(value1, 89.34, 'E'),
            sum[3] = Currency(value1, 43.5, 'M'),
            sum[4] = Currency(value1, 0.14, 'A'),
            sum[5] = Currency(value1, 22.33, 'L'),
            sum[6] = Currency(value1, 0.18, 'T'),
            sum[7] = Currency(value1, 8.9, 'K'),
            sum[8] = Currency(value1, 82.46, 'F'),
            sum[9] = Currency(value1, 11.4, 'C')
    };


    cout << "Currencies: ";
    cout << "\n1. Russian ruble (R)";
    cout << "\n2. USD (D)";
    cout << "\n3. Euro (E)";
    cout << "\n4. Azerbaijani manat (M)";
    cout << "\n5. Armenian dram (D)";
    cout << "\n6. Georgian lari (L)";
    cout << "\n7. Kazakhstani tenge (T)";
    cout << "\n8. Swedish krona (K)";
    cout << "\n9. Swiss frank (F)";
    cout << "\n10. CNY (C)";

    cout << "\n \nEnter the amount: ";
    value1 = check(value1);

    do {
        cout << "Enter currency: ";
        firstCurrency = (int)check((float)firstCurrency);
    } while (!(1 <= firstCurrency && firstCurrency <= 10));
    firstCurrency--;

    sum[firstCurrency] = value1;
    cout << "You introduced " << sum[firstCurrency] << endl;
    int a = 1;

    do {

        do {
            cout << "\nWhat currency do you want to transfer: ";
            secondCurrency = (int)check((float)secondCurrency);
        } while (!(1 <= secondCurrency && secondCurrency <= 10));
        secondCurrency--;

        sum[secondCurrency] = sum[firstCurrency].transfer(sum[secondCurrency]);

        cout << sum[firstCurrency] << " = " <<  sum[secondCurrency] << ".";

        cout << "\n Do you want to continue transferring to other currencies? 1. Yes 2. No\n";
        cin >> a;

    } while (a == 1);

    cout << "B.";

    do {cout << "\n\nEnter the first amount: ";
        value1 = check(value1);
        do {
            cout << "Enter the currency first: ";
            firstCurrency = (int)check((float)firstCurrency);
        } while (!(1 <= firstCurrency && firstCurrency <= 10));

        cout << "Enter the second amount: ";
        value2 = check(value2);
        do {
            cout << "Enter the currency second: ";
            secondCurrency = (int)check((float)secondCurrency);
        } while (!(1 <= secondCurrency && secondCurrency <= 10));
        firstCurrency--;
        secondCurrency--;

        sum[firstCurrency] = value1;
        sum[secondCurrency]= value2;

        cout << "\n\n" << sum[firstCurrency]<< " + " << sum[secondCurrency] << endl;

        float summ = sum[firstCurrency].summ(sum[secondCurrency]);
        float difference = sum[firstCurrency].difference(sum[secondCurrency]);

        sum[firstCurrency] = sum[firstCurrency].transfer(sum[firstCurrency], summ);
        sum[secondCurrency] = sum[firstCurrency].transfer(sum[secondCurrency], summ);

        cout << "Amount: " << sum[firstCurrency] << " or "<< sum[secondCurrency]<<".\n";

        sum[firstCurrency] = sum[firstCurrency].transfer(sum[firstCurrency], difference);
        sum[secondCurrency] = sum[firstCurrency].transfer(sum[secondCurrency], difference);

        cout << "Difference: " << sum[firstCurrency] << "  or "<< sum[secondCurrency]<<" .\n";

        cout << "\n\nContinue operations with the amounts? \n 1.Yes 2.No    ";
        cin >> a;
    } while (a == 1);

    return 0;
}
