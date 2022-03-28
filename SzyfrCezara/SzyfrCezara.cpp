#include <iostream>
#include <string>

using namespace std;

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
            cout << endl << "Wybrno szyfrowanie" << endl << "Podaj tekst do zaszyfrowania: " << endl;
            getline(cin >> ws, text);
            for (int i = 0; i < text.length(); i++)
            {
                if (text[i] == 32) continue;  // pominięcie spacji 
                if (text[i] < 97) text[i] += 32;
                text[i] += shift;
                if (text[i] > 122) text[i] -= 26;
            }
        }
        else if (option == 2) {
            cout << endl << "Wybrno deszyfrowanie" << endl << "Podaj tekst do deszyfrowania: " << endl;
            getline(cin >> ws, text);
            for (int i = 0; i < text.length(); i++)
            {

            }
        }
        else {
            cout << "Wybrano nie poprawną opcję, wybierz 1 lub 2" << endl;
        }
    } while (option != 1 && option != 2);

    cout << "Tekst po przejściu przez szyfr Cezara:" << endl;
    cout << text << endl;

    return 0;
}
