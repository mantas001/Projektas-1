#include "functions.h"
#include <iostream>
#include <iomanip>
#include <fstream>
#include <chrono>
#include <sstream>
#include <algorithm>
#include <cstdlib> // Include for rand()
#include <ctime> // Include for srand()

using namespace std;

const int M = 15; // namu darbu uzduociu kiekis kai generuojama atsitiktinai

void pasirinkimas1(list<stud>& grupe) {
    try {
        int n;
        cout << "Kiek studentu yra grupeje? ";
        cin >> n;
        if (cin.fail() || n <= 0) {
            throw runtime_error("Netinkamas studentu skaicius.");
        }
        for (int i = 0; i < n; ++i) {
            stud student;
            cout << "Studento vardas ir pavarde: ";
            cin >> student.vard >> student.pav;
            cout << "Studento egzamino rezultatas (1-10): ";
            cin >> student.rez_egz;
            if (cin.fail() || student.rez_egz < 1 || student.rez_egz > 10) {
                throw runtime_error("Netinkamas egzamino rezultatas.");
            }
            cout << "Namu darbu kiekis: ";
            int m;
            cin >> m;
            if (cin.fail() || m <= 0) {
                throw runtime_error("Netinkamas namu darbu kiekis.");
            }
            for (int j = 0; j < m; ++j) {
                double nd;
                cout << j + 1 << "-os uzduoties rezultatas (1-10): ";
                cin >> nd;
                if (cin.fail() || nd < 1 || nd > 10) {
                    throw runtime_error("Netinkamas namu darbo rezultatas.");
                }
                student.rez_nd.push_back(nd);
            }
            MedianaVidurkis(student);
            grupe.push_back(student);
        }
        printrez(grupe);
    } catch (const exception& e) {
        cerr << "Klaida: " << e.what() << endl;
        cin.clear(); // Clear error flags
        cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Ignore invalid input
    }
}

void pasirinkimas2(list<stud>& grupe) {
    try {
        int n;
        cout << "Kiek studentu yra grupeje? ";
        cin >> n;
        if (cin.fail() || n <= 0) {
            throw runtime_error("Netinkamas studentu skaicius.");
        }
        for (int i = 0; i < n; ++i) {
            stud student;
            cout << "studento vardas ir pavarde: ";
            cin >> student.vard >> student.pav;
            student.rez_egz = 1 + rand() % 10;;
            int m = 1 + rand() % M;
            for (int j = 0; j < m; ++j) {
                student.rez_nd.push_back(1 + rand() % 10);
            }
            MedianaVidurkis(student);
            grupe.push_back(student);
        }
        printrez(grupe);
    } catch (const exception& e) {
        cerr << "Klaida: " << e.what() << endl;
        cin.clear(); // Clear error flags
        cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Ignore invalid input
    }
}

void pasirinkimas3(list<stud>& grupe) {
    try {
        int n;
        cout << "Kiek studentu yra grupeje? ";
        cin >> n;
        if (cin.fail() || n <= 0) {
            throw runtime_error("Netinkamas studentu skaicius.");
        }
        for (int i = 0; i < n; ++i) {
            stud student;
            student.vard = "Vardas" + to_string(1 + rand() % 10);
            student.pav = "Pavarde" + to_string(1 + rand() % 10);
            student.rez_egz = 1 + rand() % 10;
            int m = 1 + rand() % M;
            for (int j = 0; j < m; ++j) {
                student.rez_nd.push_back(1 + rand() % 10);
            }
            MedianaVidurkis(student);
            grupe.push_back(student);
        }
        printrez(grupe);
    } catch (const exception& e) {
        cerr << "Klaida: " << e.what() << endl;
        cin.clear(); // Clear error flags
        cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Ignore invalid input
    }
}

void printrez(list<stud>& grupe) {
    string vid_med;
    cout << "Skaiciuoti galutini ivertinima naudojant vidurki ar mediana? (v, m) ";
    do {
        cin >> vid_med;
        if (vid_med != "v" && vid_med != "m") cout << "Netinkama ivestis(irasykite 'v' arba 'm'): ";
    } while (vid_med != "v" && vid_med != "m");

    // Calculate final grade for each student
    for (auto& student : grupe) {
        double a = (vid_med == "v") ? student.vid : student.med;
        double galutinis = (0.4 * a) + (0.6 * student.rez_egz);
        student.galut_iv = galutinis;
    }

    sorting(grupe); // Sort students

    // Print student information
    cout << "Vardas              Pavarde             ";
    if (vid_med == "v")
        cout << "Galutinis (Vid.)" << endl;
    else if (vid_med == "m")
        cout << "Galutinis (Med.)" << endl;
    cout << "--------------------------------------------------------" << endl;
    for (const auto& student : grupe) {
        cout << left << setw(20) << student.vard << left << setw(20) << student.pav << left << setw(20) << setprecision(3) << student.galut_iv << endl;
    }
    cout << "--------------------------------------------------------\n";
    cout << endl;
}

void MedianaVidurkis(stud& student) {
    student.rez_nd.sort();
    int m_size = student.rez_nd.size();
    auto it = student.rez_nd.begin();
    for (int i = 0; i < m_size / 2; ++i) {
        ++it;
    }
    if (m_size % 2 != 0)
        student.med = *it;
    else
        student.med = (*it + *(--it)) / 2.0;

        double sum = 0;
    for (auto& nd : student.rez_nd) {
        sum += nd;
    }
    student.vid = sum / m_size;
}

void pasirinkimas4(list<stud>& grupe) {
    string filename;
    cout << "Iveskite failo pavadinima: ";
    cin >> filename;
    ifstream infile(filename);
    if (!infile) {
        cerr << "Nepavyko atidaryti failo." << endl;
        return;
    }

    string line;
    while (getline(infile, line)) {
        stringstream ss(line);
        stud student;
        ss >> student.vard >> student.pav;
        double grade;
        while (ss >> grade) {
            student.rez_nd.push_back(grade);
        }
        if (!student.rez_nd.empty()) {
            student.rez_egz = student.rez_nd.back();
            student.rez_nd.pop_back();
        }
        MedianaVidurkis(student);
        grupe.push_back(student);
    }

    printrez(grupe);
}

void sorting(list<stud>& grupe) {
    grupe.sort([](const stud& a, const stud& b) {
        return a.galut_iv > b.galut_iv;
    });
}

void saunuoliai_vargsai(list<stud>& grupe, list<stud>& saunuoliai, list<stud>& vargsai) {
    for (const auto& student : grupe) {
        if (student.galut_iv >= 5) {
            saunuoliai.push_back(student);
        } else {
            vargsai.push_back(student);
        }
    }
}

void duomenu_sukurimas(list<stud>& grupe, chrono::duration<double>& duom_create_diff, int& duom) {
    try {
        auto start = chrono::steady_clock::now();

        for (int i = 0; i < duom; ++i) {
            stud student;
            student.vard = "Vardas" + to_string(1 + rand() % 10);
            student.pav = "Pavarde" + to_string(1 + rand() % 10);
            student.rez_egz = 1 + rand() % 10;
            int m = 1 + rand() % M;
            for (int j = 0; j < m; ++j) {
                student.rez_nd.push_back(1 + rand() % 10);
            }
            MedianaVidurkis(student);
            grupe.push_back(student);
        }

        auto end = chrono::steady_clock::now();
        duom_create_diff = end - start;

        cout << "Nauji duomenys sukurti." << endl;
    } catch (const exception& e) {
        cerr << "Klaida: " << e.what() << endl;
    }
}

void pasirinkimas6(list<stud>& grupe, string& filename2, int& duom, chrono::duration<double>& duom_create_diff) {
    list<stud> saunuoliai;
    list<stud> vargsai;
    saunuoliai_vargsai(grupe, saunuoliai, vargsai);

    if (!saunuoliai.empty() && !vargsai.empty()) {
        cout << "Rezultatai isrusiuoti i saunuolius ir vargsiukus." << endl;
    } else {
        cout << "Klaida: Nepavyko suskirstyti studentu i saunuolius ir vargsiukus." << endl;
    }
}
