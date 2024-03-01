#include "functions.h"
#include <iostream>
#include <iomanip>
#include <fstream>
#include <chrono>
#include <sstream>
#include <algorithm>
using namespace std;
const int M = 15; // namu darbu uzduociu kiekis kai generuojama atsitiktinai

void pasirinkimas1(vector<stud>& grupe) {//done
    try {
        int n;
        cout << "Kiek studentu yra grupeje? ";
        cin >> n;
        if (cin.fail() || n <= 0) {
            throw runtime_error("Netinkamas studentu skaicius.");
        }
        grupe.resize(n);
        for (int i = 0; i < n; ++i) {
            cout << "Studento vardas ir pavarde: ";
            cin >> grupe[i].vard >> grupe[i].pav;
            cout << "Studento egzamino rezultatas (1-10): ";
            cin >> grupe[i].rez_egz;
            if (cin.fail() || grupe[i].rez_egz < 1 || grupe[i].rez_egz > 10) {
                throw runtime_error("Netinkamas egzamino rezultatas.");
            }
            cout << "Namu darbu kiekis: ";
            int m;
            cin >> m;
            if (cin.fail() || m <= 0) {
                throw runtime_error("Netinkamas namu darbu kiekis.");
            }
            grupe[i].rez_nd.resize(m);
            for (int j = 0; j < m; ++j) {
                cout << j + 1 << "-os uzduoties rezultatas (1-10): ";
                cin >> grupe[i].rez_nd[j];
                if (cin.fail() || grupe[i].rez_nd[j] < 1 || grupe[i].rez_nd[j] > 10) {
                    throw runtime_error("Netinkamas namu darbo rezultatas.");
                }
            }
            MedianaVidurkis(grupe[i]);
        }
        printrez(grupe);
    } catch (const exception& e) {
        cerr << "Klaida: " << e.what() << endl;
        cin.clear(); // Clear error flags
        cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Ignore invalid input
    }
}
void pasirinkimas2(vector<stud>& grupe) {//done
    try {
        int n;
        cout << "Kiek studentu yra grupeje? ";
        cin >> n;
        if (cin.fail() || n <= 0) {
            throw runtime_error("Netinkamas studentu skaicius.");
        }
        grupe.resize(n);
        for (int i = 0; i < n; ++i) {
            cout << "studento vardas ir pavarde: ";
            cin >> grupe[i].vard >> grupe[i].pav;
            grupe[i].rez_egz = 1 + rand() % 10;;
            int m = 1 + rand() % M;
            grupe[i].rez_nd.resize(m);
            for (int j = 0; j < m; ++j) {
                grupe[i].rez_nd[j] = 1 + rand() % 10;
            }
            MedianaVidurkis(grupe[i]);
        }
        printrez(grupe);
    } catch (const exception& e) {
        cerr << "Klaida: " << e.what() << endl;
        cin.clear(); // Clear error flags
        cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Ignore invalid input
    }
}

void pasirinkimas3(vector<stud>& grupe) {//done
    try{
        int n;
        cout << "Kiek studentu yra grupeje? ";
        cin >> n;
        if (cin.fail() || n <= 0) {
            throw runtime_error("Netinkamas studentu skaicius.");
        }
        grupe.resize(n);
        for (int i = 0; i < n; ++i) {
            grupe[i].vard = "Vardas" + to_string(1 + rand() % 10);
            grupe[i].pav = "Pavarde" + to_string(1 + rand() % 10);
            grupe[i].rez_egz = 1 + rand() % 10;;
            int m = 1 + rand() % M;
            grupe[i].rez_nd.resize(m);
            for (int j = 0; j < m; ++j) {
                grupe[i].rez_nd[j] = 1 + rand() % 10;
            }
            MedianaVidurkis(grupe[i]);
        }
        printrez(grupe);
    } catch (const exception& e) {
        cerr << "Klaida: " << e.what() << endl;
        cin.clear(); // Clear error flags
        cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Ignore invalid input
    }
}

void printrez(vector<stud>& grupe) {//done
    string vid_med;
    cout << "Skaiciuoti galutini ivertinima naudojant vidurki ar mediana? (v, m) ";
    do{
    cin >> vid_med;
    if (vid_med!="v"&&vid_med!="m") cout << "Netinkama ivestis(irasykite 'v' arba 'm'): ";
    }while(vid_med!="v"&&vid_med!="m");

    //galutinis***************
    double a = -1;
    for (int i = 0; i < grupe.size(); i++) {
        if (vid_med == "v") a = grupe[i].vid;
        else if (vid_med == "m") a = grupe[i].med;
        double galutinis = (0.4 * a) + (0.6 * grupe[i].rez_egz);
        grupe[i].galut_iv=galutinis;
    }
    //rikiavimas
    sorting(grupe);
    //**********

    
    cout << "Vardas              Pavarde             "; if (vid_med == "v") cout <<"Galutinis (Vid.)"<< endl;
                                            else if (vid_med == "m") cout <<"Galutinis (Med.)"<< endl;
    cout << "--------------------------------------------------------" << endl;
    for (int i = 0; i < grupe.size(); i++) {
        cout << left << setw(20) << grupe[i].vard << left << setw(20) << grupe[i].pav << left << setw(20) << setprecision(3) << grupe[i].galut_iv << endl;
    }
    cout << "--------------------------------------------------------\n";
    cout << endl;
}

void MedianaVidurkis(stud& grupe) {
    sort(grupe.rez_nd.begin(), grupe.rez_nd.end());
    int m_size = grupe.rez_nd.size();
    if (m_size % 2 != 0)
        grupe.med = grupe.rez_nd[m_size / 2];
    else
        grupe.med = (grupe.rez_nd[m_size / 2 - 1] + grupe.rez_nd[m_size / 2]) / 2.0;

    double sum = 0;
    for (double pazym : grupe.rez_nd) {
        sum += pazym;
    }
    grupe.vid = sum / m_size;
}
void pasirinkimas4(vector<stud>& grupe) {
    system("dir *.txt");
    string filename;
    cout << "Irasykite duomenu failo pavadinima: ";
    cin >> filename;
    try {
    ifstream file(filename); // Open the file
    if (!file) {
        throw runtime_error("Nepavyko atidaryti failo.");

    }

    string line;
    int word_count = 0; // Count of words in the first line
    // Read the first line to count the number of words
    getline(file, line);
    istringstream iss_first(line);
    while (iss_first >> line) {
        word_count++;
    }

    int expected_size = word_count - 3; // Deducting 2 for name and surname
    // Read data for each student from the file
    auto start = std::chrono::high_resolution_clock::now();
    while (getline(file, line)) {
        istringstream iss(line);
        stud student;
        iss >> student.vard >> student.pav;

        // Resize rez_nd based on the expected size
        student.rez_nd.resize(expected_size);

        // Read rez_nd values
        for (int j = 0; j < expected_size; ++j) {
            if (iss.eof()) {
                // If there are fewer values than expected, adjust the size
                student.rez_nd.resize(j);
                break;
            }
            iss >> student.rez_nd[j];
        }

        iss >> student.rez_egz;
        
        MedianaVidurkis(student);
        grupe.push_back(student);
    }
    std::chrono::duration<double> diff = std::chrono::high_resolution_clock::now()-start; // Skirtumas (s)
    ofstream fr("rezultatai.txt");
    fr <<"Nuskaityti duomenis uztruko: "<< diff.count() << " s\n";
    file.close();

    string vid_med;
    cout << "Skaiciuoti galutini ivertinima naudojant vidurki ar mediana? (v, m) ";
    do{
    cin >> vid_med;
    if (vid_med!="v"&&vid_med!="m") cout << "Netinkama ivestis(irasykite 'v' arba 'm'): ";
    }while(vid_med!="v"&&vid_med!="m");

    //galutinis***************
    double a = -1;
    for (int i = 0; i < grupe.size(); i++) {
        if (vid_med == "v") a = grupe[i].vid;
        else if (vid_med == "m") a = grupe[i].med;
        double galutinis = (0.4 * a) + (0.6 * grupe[i].rez_egz);
        grupe[i].galut_iv=galutinis;
    }
    //************************
    //rikiavimas
    sorting(grupe);
    //**********
    //printrez i faila*************
    
    
    fr << "Vardas              Pavarde             "; if (vid_med == "v") fr <<"Galutinis (Vid.)"<< endl;
                                            else if (vid_med == "m") fr <<"Galutinis (Med.)"<< endl;
    fr << "--------------------------------------------------------" << endl;
    start = std::chrono::high_resolution_clock::now();
    for (int i = 0; i < grupe.size(); i++) {
        fr << left << setw(20) << grupe[i].vard << left << setw(20) << grupe[i].pav << left << setw(20) << setprecision(3) << grupe[i].galut_iv << endl;
    }
    diff = std::chrono::high_resolution_clock::now()-start; // Skirtumas (s)
    fr << "--------------------------------------------------------\n";
    fr <<"Irasyti duomenis uztruko: "<< diff.count() << " s\n";
    fr.close();
    //**********
    } catch (const exception& e) {
        cerr << "Klaida: " << e.what() << endl;
    }
}
void sorting(vector<stud>& grupe){
    string sort_choice, sort_order;
    cout << "Rikiuoti pagal (v - vardas, p - pavarde, g - galutinis ivertinimas): ";
    do{
    cin >> sort_choice;
    if (sort_choice!="v"&&sort_choice!="p"&&sort_choice!="g") cout << "Netinkama ivestis(irasykite 'v' , 'p' arba 'g'): ";
    }while(sort_choice!="v"&&sort_choice!="p"&&sort_choice!="g");

    cout << "Pasirinkite rikiavimo tvarka (d - didejimo, m - mazejimo): ";
    do{
    cin >> sort_order;
    if (sort_order!="d"&&sort_order!="m") cout << "Netinkama ivestis(irasykite 'd' arba 'm'): ";
    }while(sort_order!="d"&&sort_order!="m");

    switch (sort_choice[0]) {
        case 'v':
            if (sort_order == "d") {
                sort(grupe.begin(), grupe.end(), [](const stud& a, const stud& b) {
                    return a.vard < b.vard;
                });
            } else if (sort_order == "m") {
                sort(grupe.begin(), grupe.end(), [](const stud& a, const stud& b) {
                    return a.vard > b.vard;
                });
            }
            break;
        case 'p':
            if (sort_order == "d") {
                sort(grupe.begin(), grupe.end(), [](const stud& a, const stud& b) {
                    return a.pav < b.pav;
                });
            } else if (sort_order == "m") {
                sort(grupe.begin(), grupe.end(), [](const stud& a, const stud& b) {
                    return a.pav > b.pav;
                });
            }
            break;
        case 'g':
            if (sort_order == "d") {
                sort(grupe.begin(), grupe.end(), [](const stud& a, const stud& b) {
                    return a.galut_iv < b.galut_iv;
                });
            } else if (sort_order == "m") {
                sort(grupe.begin(), grupe.end(), [](const stud& a, const stud& b) {
                    return a.galut_iv > b.galut_iv;
                });
            }
            break;
        default:
            cout << "Neteisingas pasirinkimas" << endl;
            return;
    }
}
void duomenugeneravimas(std::vector<stud>& grupe){
    ofstream fr("rezultatai.txt");
    int duom;
    cout << "Kiek eiluciu duomenu generuoti? ";
}