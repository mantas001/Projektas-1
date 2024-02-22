#include <iostream>
#include <string>
#include <iomanip>
#include <cstdlib> //rand and srand
#include <ctime>   //time
using namespace std;

const int M=20;//namu darbu uzduociu kiekis

const int N=10;
struct stud {
    string vard, pav;
    double* rez_nd;
    double rez_egz;
    double vid;
    double med;
};

int main() {

    string vardai[] = {"Vardas1", "Vardas2", "Vardas3", "Vardas4", "Vardas5", "Vardas6", "Vardas7"};
    string pavardes[] = {"Pavarde1", "Pavarde2", "Pavarde3", "Pavarde4", "Pavarde5", "Pavarde6", "Pavarde7"};

    srand(time(NULL));
    int pasirinkimas;
    do{
        do
        {
            cout << "1 - Ivesti duomenis ranka\n2 - Generuoti pazymius\n3 - Generuoti ir pazymius, ir studentu vardus, pavardes\n4 - Baigti darba" << endl;
            cin>>pasirinkimas;
        } while (!(pasirinkimas == 1 || pasirinkimas == 2 || pasirinkimas == 3 || pasirinkimas == 4));

        if (pasirinkimas==4) break;
        
        int n = 0;
        cout << "Kiek studentu yra grupeje? ";
        cin >> n;

        stud* grupe = new stud[n];

        if(n>0){
            for (int i = 0; i < n; i++) {
                if (pasirinkimas==1){
                    cout << "Studento vardas ir pavarde: ";
                    cin >> grupe[i].vard >> grupe[i].pav;
                    cout << endl;
                    do
                    {
                        cout << "Studento egzamino rezultatas: ";
                                cin >> grupe[i].rez_egz;
                                cout << endl;
                    } while ((grupe[i].rez_egz< 0 || grupe[i].rez_egz> 10));
                }
                else if(pasirinkimas==2){
                    cout << "Studento vardas ir pavarde: ";
                    cin >> grupe[i].vard >> grupe[i].pav;
                    cout << endl;
                    grupe[i].rez_egz=1.0 + rand() / (RAND_MAX / (10.0 - 1.0));
                }
                else if(pasirinkimas==3){
                    grupe[i].rez_egz=1.0 + rand() / (RAND_MAX / (10.0 - 1.0));
                    grupe[i].vard=vardai[0 + rand() % 7]; 
                    grupe[i].pav=pavardes[0 + rand() % 7];
                }
                
                int m;
                if(pasirinkimas==1){
                    do
                    {
                    cout << "Studento " << grupe[i].vard << " " << grupe[i].pav << " " << "namu darbu uzduociu kiekis: ";
                    cin >> m;
                    } while (m<0);
                }
                else if (pasirinkimas==2 || pasirinkimas==3){
                    m=1 + rand() % M;   
                }
                
                grupe[i].rez_nd = new double[m+1];

                int sum = 0;
                for (int j = 0; j < m; j++) {
                    if(pasirinkimas==1){
                        do
                        {
                        cout << "Studento " << grupe[i].vard << " " << grupe[i].pav << " " << j + 1 << "-os uzduoties rezultatas(1-10): ";
                        cin >> grupe[i].rez_nd[j];
                        } while ((grupe[i].rez_nd[j]< 0 || grupe[i].rez_nd[j]> 10));
                        
                        sum += grupe[i].rez_nd[j];
                    }
                    else if (pasirinkimas==2 || pasirinkimas==3){
                        double randomNumber = 1.0 + rand() / (RAND_MAX / (10.0 - 1.0));
                        grupe[i].rez_nd[j]=randomNumber;
                    } 
                }
                //mediana
                grupe[i].rez_nd[m]=grupe[i].rez_egz;
                for (int h = 0; h < m + 1; h++) {
                    for (int j = 0; j < m; j++) {
                        if (grupe[i].rez_nd[j] > grupe[i].rez_nd[j + 1]) {
                            int temp = grupe[i].rez_nd[j];
                            grupe[i].rez_nd[j] = grupe[i].rez_nd[j + 1];
                            grupe[i].rez_nd[j + 1] = temp;
                        }
                    }
                }
                if ((m + 1) % 2 != 0)
                    grupe[i].med = grupe[i].rez_nd[(m + 1) / 2];
                else
                    grupe[i].med = (grupe[i].rez_nd[m / 2] + grupe[i].rez_nd[(m + 1) / 2]) / 2.0;

                grupe[i].vid = (double)sum / m;
                cout << endl;
            }

            cout << endl;
            cout << "Vardas        Pavarde       Galutinis (Vid.) /  Galutinis (Med.)" << endl
                << "----------------------------------------------------------------" << endl;
            for (int i = 0; i < n; i++) {
                double galutinis=(0.4*(grupe[i].vid))+(0.6*(grupe[i].rez_egz));
                double mediana=(double)grupe[i].med;
                cout <<left<<setw(14)<< grupe[i].vard <<left<< setw(14) << grupe[i].pav <<left<< setw(20) << setprecision(2) << galutinis <<left<< setw(14) << setprecision(2) << mediana << endl;
                delete[] grupe[i].rez_nd;
            }
        }
        cout << "----------------------------------------------------------------\n";
        cout << endl;
        delete[] grupe;

    }while(pasirinkimas!=4);
    return 0;

}