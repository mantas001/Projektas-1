#include <iostream>
#include <ctime>
#include <vector>
#include <string>
#include <cstdlib>
#include "functions.h"

using namespace std;

int main() {
    srand(time(NULL));
    vector<stud> grupe;
    string pasirinkimas;
    do {
        do {
            cout << "1 - Ivesti duomenis ranka\n2 - Generuoti pazymius\n3 - Generuoti ir pazymius, ir studentu vardus, ir pavardes\n4 - Skaityti duomenis is failo\n5 - Baigti darba\nPasirinkimas: ";            cin >> pasirinkimas;
        } while (!(pasirinkimas == "1" || pasirinkimas == "2" || pasirinkimas == "3" || pasirinkimas == "4"|| pasirinkimas == "5"));
        if (pasirinkimas=="1") pasirinkimas1(grupe);
        else if (pasirinkimas=="2") pasirinkimas2(grupe);
        else if (pasirinkimas=="3") pasirinkimas3(grupe);
        else if (pasirinkimas=="4") pasirinkimas4(grupe);
        else if (pasirinkimas=="5"){
            cout <<"Programa darba baige" << endl;
            break;
        }
        else cout << "Neteisingas pasirinkimas. Bandykite dar karta.\n";

    } while (pasirinkimas != "5");
    return 0;
}