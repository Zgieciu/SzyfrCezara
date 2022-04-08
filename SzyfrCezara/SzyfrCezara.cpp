#include <iostream>
#include <string>
#include <fstream>
#include <stdio.h>

using namespace std;

//funkcja do szyfrowania, argumenty to tekst do zaszyfrowania i przesunięcie, zwraca zaszyfrowany tekst
string encryption(string text, int shift) {
    for (int i = 0; i < text.length(); i++)
    {
        if (text[i] >= 65 && text[i] <= 90) { // duże litery
            text[i] += shift;
            if (text[i] > 90) text[i] -= 26;
        }
        else if (text[i] >= 97 && text[i] <= 122) { // małe litery 
            int pom = text[i];
            pom += shift;                     //zmienna pomocnicza, używana do tego, aby index nie przekroczył rozmiaru tablicy ASCII
            if (pom > 122) pom -= 26;
            text[i] = pom;
        }
    }

    return text;
}

//funkcja do odszyfrowania, argumenty to tekst do odszyfrowania i przesunięcie, zwraca odszyfrowany tekst
string decryption(string text, int shift) {
    for (int i = 0; i < text.length(); i++)
    {
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
    int shift, option, option2;
    string text, line;
    fstream file;

    cout << "Szyfr Cezara" << endl;
    cout << "Podaj wartość przesunięcia:";
    cin >> shift;
    while (shift < 1) {
        cout << "Przesunięcie nie może być liczbą ujemną oraz 0, podaj przesunięcie jeszcze raz:";
        cin >> shift;
    }
    if (shift > 26) shift = 26;

    cout << endl << "Wybierz opcję 1/2:" << endl;
    cout << "1. Szyfrowanie" << endl;
    cout << "2. Deszyfrowanie" << endl;
    cout << endl;

    do {
        cin >> option;
        if (option == 1) {
            cout << "Wybrno szyfrowanie\n";                   //szyfrowanie

            cout << endl << "Wybierz opcję 1/2:" << endl;
            cout << "1. Szyfrowanie poprzez wpisanie tekstu" << endl;
            cout << "2. Szyfrowanie z pliku" << endl;
            cout << endl;

            do {
                cin >> option2;

                if (option2 == 1) {                       
                    cout << endl << "Podaj tekst do zaszyfrowania: " << endl;
                    getline(cin >> ws, text);
                }
                else if (option2 == 2) {
                    file.open("szyfrowanie.txt");         //podczas szyfrowania z pliku, w pliku ostatnia linijka musi zostać pusta

                    do {
                        getline(file, line);
                        text += line + " ";
                        
                    } while (line != "");

                    file.close();
                }
                else {
                    cout << "Wybrano nie poprawną opcję, wybierz 1 lub 2" << endl;
                }
  
            } while (option2 != 1 && option2 != 2);

            text = encryption(text, shift);
        }
        else if (option == 2) {
            cout << "Wybrno deszyfrowanie\n";                       //deszyfrowanie

            cout << endl << "Wybierz opcję 1/2:" << endl;
            cout << "1. Deszyfrowanie poprzez wpisanie tekstu" << endl;
            cout << "2. Deszyfrowanie z pliku" << endl;
            cout << endl;

            do {
                cin >> option2;

                if (option2 == 1) {
                    cout << endl << "Podaj tekst do deszyfrowania: " << endl;
                    getline(cin >> ws, text);
                }
                else if (option2 == 2) {
                    file.open("deszyfrowanie.txt");          //podczas deszyfrowania z pliku, w pliku ostatnia linijka musi zostać pusta

                    do {
                        getline(file, line);
                        text += line + " ";

                    } while (line != "");

                    file.close();
                }
                else {
                    cout << "Wybrano nie poprawną opcję, wybierz 1 lub 2" << endl;
                }

            } while (option2 != 1 && option2 != 2);
              
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
