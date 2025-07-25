#pragma once
#include <iostream>
#include <string>

using namespace std;

class Disease {
    private:
        string disease_name , virus_name;
    public:
        void getDiseaseDetails() {
            cout << "Enter name of disease:";
            getline(cin,disease_name);
            
            cout << "Enter name of virus:";
            getline(cin,virus_name);
        }
        void showDiseaseList() {
            cout << "Disease:" << disease_name << endl;
            cout << "Virus:" << virus_name << endl;
        }

};
/*
int main() {
    Disease disease_1;
    disease_1.getDiseaseDetails();
    disease_1.showDiseaseList();
        
    return 0;
}
*/    