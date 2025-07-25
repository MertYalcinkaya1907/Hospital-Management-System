#include "AvaliableOn.cpp"
#include "Disease.cpp"
#include "Person.cpp"

#include <iostream>
#include <string>
#include <cstring>
#include <fstream>

using namespace std;

class Doctor:public Person {
    private:
        int doctorID;
        Disease disease;
        Avaliable avaliable;
        char doctor_file[20] = "doctorData.dat";
        char doctor_temp_file[20] = "doctorData2.dat";
    public:
        void getDoctorData() {
            cout << "Enter data of doctor\n";
            get_data_from_person();
            cout << "Enter doctor ID:";
            cin >> doctorID;
            cout << "Enter the name of specializations";
            disease.getDiseaseDetails();
            avaliable.WhenAvaliable();
        }
        void showDoctorData() {
            cout << "\n\tDetails of doctor are:\n";
            show_data_of_person();
            cout << "Doctor ID is " << doctorID << endl;
            disease.showDiseaseList();        
            avaliable.DisplayAvaliable();
            cout << endl;
        }
        void addDoctorData() {
            getDoctorData();
            ofstream doctorDatabase(doctor_file, ios::binary | ios::out | ios::app);
            doctorDatabase.write((char*)this, sizeof(Doctor));
        }
        void showDoctorDataFromFile() {
            ifstream readDataFromDatabase(doctor_file, ios::binary | ios::in);
            while(!readDataFromDatabase.eof()) {
                if(readDataFromDatabase.read((char*)this, sizeof(Doctor)))
                    show_data_of_person();
            }
        }
        void deleteDoctor() {
            int n, flag = 0;
            cout << "Enter the doctor ID of the doctor you want to delete." << endl;
            cin >> n;

            ifstream ifdoctor;
            ifdoctor.open(doctor_file, ios::binary | ios::in);
            ofstream ofdoctor;
            ofdoctor.open(doctor_temp_file, ios::binary | ios::out);

            while(!ifdoctor.eof()) {
                ifdoctor.read((char*)this,sizeof(Doctor));
            
            if(ifdoctor) {
                if(n == doctorID) {
                    flag = 1;
                }
                else {
                    ofdoctor.write((char*)this,sizeof(Doctor));
                }
            }
        }
        ifdoctor.close();
        ofdoctor.close();
        remove(doctor_file);
        rename(doctor_temp_file,doctor_file);
        
        if(flag == 1)
            cout << "\nRecord successfully deleted\n";
        else 
            cout << "\nRecord not found\n";
    }
    void editDoctor() {
        int n, pos, flag = 0;
        cout << "Enter the doctor ID of the doctor you want to edit";
        cin >> n;

        fstream fdoctor;
        fdoctor.open(doctor_file, ios::binary | ios::in | ios::out);
    
        while(!fdoctor.eof()) {
            pos = fdoctor.tellg();
            fdoctor.read((char*)this, sizeof(Doctor));

            if(fdoctor) {
                if(n == doctorID) {
                    flag = 1;
                    getDoctorData();
                    fdoctor.seekp(pos);
                    
                    fdoctor.write((char*)this, sizeof(Doctor));

                    showDoctorData();
                    break;
                }
            }
        }
        fdoctor.close();

        if(flag == 1) {
            cout << "\nRecord successfully modified\n";
        }
        else {
            cout << "\nRecord not found\n";
        }
    }
    void doDoctorRelatedWork() {
        char flag;
        int choice;
        
        do {
            cout << "Enter option 1 to add doctor" << endl;
            cout << "Enter option 2 to show all data" << endl;
            cout << "Enter option 3 to delete" << endl;
            cout << "Enter option 4 to edit doctor's data" << endl;
            cout << "Enter option 5 to exit program" << endl;
            cin >> choice;

            if (choice == 1) {
                do{
                    addDoctorData();
                    cout << "Add another doctor? 1 or yes";
                    cin >> flag;
                } while(flag == 1);    
            }
            else if (choice == 2) {
                showDoctorDataFromFile();
            }
            else if (choice == 3) {
                deleteDoctor();
            }
            else if (choice == 4) {
                editDoctor();
            }
        } while(choice == 1 | choice == 2 | choice == 3 | choice == 4);
    }    
};
/*
int main() {
    Doctor d;

    d.doDoctorRelatedWork();

    return 0;
}
*/    

