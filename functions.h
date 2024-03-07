#ifndef FUNCTIONS_H
#define FUNCTIONS_H

#include <vector>
#include <string>

struct stud {
    std::string vard, pav;
    std::vector<double> rez_nd;
    double rez_egz;
    double vid;
    double med;
    double galut_iv;
};

void pasirinkimas1(std::vector<stud>& grupe);
void pasirinkimas2(std::vector<stud>& grupe);
void pasirinkimas3(std::vector<stud>& grupe);
void pasirinkimas5(std::vector<stud>& grupe);
void printrez(std::vector<stud>& grupe);
void MedianaVidurkis(stud& grupe);
void pasirinkimas4(std::vector<stud>& grupe);
void sorting(std::vector<stud>& grupe);


#endif