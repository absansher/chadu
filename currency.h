
#ifndef UNTITLED9_CURRENCY_H
#define UNTITLED9_CURRENCY_H


class Currency {
private:
    float coefficient;
public:
    Currency(float s1, float coeff, char name);
    Currency& operator=(float i);
    explicit operator float() const;
    Currency& operator++();
    Currency operator++ (int);
    float operator+(Currency& cr) const;
    float operator-(Currency& cr) const;
    friend float operator / (int i, Currency& cr);
    float operator / (int i) const;
    friend float operator* (float a, Currency& cr);
    friend float operator * (Currency& os, Currency& cr);
    float operator *=(Currency& cr);
    float operator>(Currency& cr) const;
    
    float transfer(Currency arr2) const;
    float transfer(Currency arr2,float i) const;
    float summ(Currency arr2);
    float difference(Currency arr2);

    char n;
    float sum;






};

#endif
