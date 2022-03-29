#include <iostream>
#include <string>

using namespace std;

//funkcja do szyfrowania, argumenty to tekst do zaszyfrowania i przesunięcie, zwraca zaszyfrowany tekst
string encryption(string text, int shift) {
    for (int i = 0; i < text.length(); i++)
    {
        if (text[i] == 32) continue;  // pominięcie spacji
        if (text[i] >= 65 && text[i] <= 90) { // duże litery
            text[i] += shift;
            if (text[i] > 90) text[i] -= 26;
        }
        else if (text[i] >= 97 && text[i] <= 122) { // małe litery 
            text[i] += shift;
            if (text[i] > 122) text[i] -= 26;
        }
    }

    return text;
}

//funkcja do odszyfrowania, argumenty to tekst do odszyfrowania i przesunięcie, zwraca odszyfrowany tekst
string decryption(string text, int shift) {
    for (int i = 0; i < text.length(); i++)
    {
        if (text[i] == 32) continue;  // pominięcie spacji
        if (text[i] >= 65 && text[i] <= 90) { // duże litery
            text[i] -= shift;
            if (text[i] < 65) text[i] += 26;
        }
        else if (text[i] >= 97 && text[i] <= 122) { // małe litery 
            text[i] -= shift;
            if (text[i] < 97) text[i] += 26;
        }
    }

    return text;
}

int main()
{
    setlocale(LC_CTYPE, "Polish");
    int shift, option;
    string text;

    cout << "Szyfr Cezara" << endl;
    cout << "Podaj wartość przesunięcia:";
    cin >> shift;
    if (shift > 26) shift = 26;
    cout << endl << "Wybierz opcję 1/2:" << endl;
    cout << "1. Szyfrowanie" << endl;
    cout << "2. Deszyfrowanie" << endl;
    cout << endl;


    do {
        cin >> option;
        if (option == 1) {
            cout << "Wybrno szyfrowanie\n" << endl << "Podaj tekst do zaszyfrowania: " << endl;
            getline(cin >> ws, text);
            text = encryption(text, shift);
        }
        else if (option == 2) {
            cout << "Wybrno deszyfrowanie\n" << endl << "Podaj tekst do deszyfrowania: " << endl;
            getline(cin >> ws, text);
            text = decryption(text, shift);
        }
        else {
            cout << "Wybrano nie poprawną opcję, wybierz 1 lub 2" << endl;
        }
    } while (option != 1 && option != 2);

    cout << "\nTekst po przejściu przez szyfr Cezara:"<< endl;
    cout << text << endl;

    return 0;
}
