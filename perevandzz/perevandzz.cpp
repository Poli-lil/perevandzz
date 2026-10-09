#include <iostream>

using namespace std;

class Fraction {
private:
    int numer;
    int denom;

public:
    Fraction() {
        numer = 0;
        denom = 1;
    }

    Fraction(int numer, int denom) {
        this->numer = numer;
        this->denom = denom;
    }

    // Fract - Fract
    Fraction operator-(const Fraction& other) const {
        return Fraction(
            numer * other.denom - other.numer * denom,
            denom * other.denom             
        );
    }

    // Fract - int
    Fraction operator-(int number) const {
        return Fraction(
            numer - number * denom,
            denom
        );
    }

    // int - Fract
    friend Fraction operator-(int number, const Fraction& fraction) {
        return Fraction(
            number * fraction.denom - fraction.numer,
            fraction.denom
        );
    }

    // Преф. --fract
    Fraction& operator--() {
        numer -= denom;
        return *this;
    }

    // Постф.  fraction--
    Fraction operator--(int) {
        Fraction temp = *this;
        numer -= denom;
        return temp;
    }

    void Print() const {
        cout << numer << "/" << denom << endl;
    }
};

int main() {

    Fraction a(5, 3);
    Fraction b(2, 3);

    // Fract - Fract
    Fraction result1 = a - b;

    // Fract - int
    Fraction result2 = a - 2;

    // int - Fract
    Fraction result3 = 2 - a;

    cout << "Fraction - Fraction: ";
    result1.Print();

    cout << "Fraction - int: ";
    result2.Print();

    cout << "int - Fraction: ";
    result3.Print();

    // Преф.
    cout << "До --a: ";
    a.Print();

    --a;

    cout << "Після --a: ";
    a.Print();

    // Постф. 
    cout << "До a--: ";
    a.Print();

    Fraction old = a--;

    cout << "Старе значення: ";
    old.Print();

    cout << "Після a--: ";
    a.Print();

}