#include "Disease.cpp"
#include "Person.cpp"
#include <fstream>
#include <cstring>

using namespace std;

class Patient:public Person {
    private:
        int patientId;
        Disease disease;
        string appoint_date;
        char patient_file[20] = "PatientData.dat";
        char patient_temp_file[20] = "PatientData2.dat";
    public:
        void getPatientInformation() {
            cout << "Enter the data for the person" << endl;
            get_data_from_person();
            cout << "Disease details" << endl;
            disease.getDiseaseDetails();
            cout << "Appoint date:";
            cin >> appoint_date;
        }
        void addPatient() {
            cout << "Patient ID:";
            cin >> patientId;

            getPatientInformation();
            ofstream PateintDatabase(patient_file,ios::binary | ios::out | ios::app);

            PateintDatabase.write((char*)this,sizeof(Patient));
        }
        void ShowPatientData() { 
            cout << "---Patient Date---" << endl;
            cout << "Patient ID:" << patientId;
            ShowPatientData(); // Şu fonksiyonun ismi yanlış olabilir.
            disease.showDiseaseList();
            cout << "Appointment Date:" << appoint_date << endl;
        }
        void ShowPatientDataFromFile() {
            ifstream readdatafromdatabase(patient_file, ios::binary | ios::in);
            
            while (!readdatafromdatabase.eof()) {
                if (readdatafromdatabase.read((char*)this,sizeof(Patient)))
                ShowPatientData();
            }
        }
        void DischargePatient() {
            int n , flag = 0;
            cout << "\nEnter the ID of the patient you what to delete:" << endl;
            cin >> n;
        
            ifstream ifpatient;
            ifpatient.open(patient_temp_file,ios::in | ios::binary);

            ofstream ofpatient;
            ofpatient.open(patient_temp_file,ios::out | ios::binary);
            
            while(!ifpatient.eof()) {
                ifpatient.read((char*)this,sizeof(Patient));

                if(ifpatient) {
                    if(n == patientId) {
                        flag = 1;
                    }
                    else {
                        ofpatient.write((char*)this,sizeof(Patient));
                    }
                }
            }
            ifpatient.close();
            ofpatient.close();
            remove(patient_file);
            rename(patient_temp_file,patient_file);
            
            if(flag == 1) {
                cout << "\nRecord successfully deleted\n";
            }
            else {
                cout << "\nRecord not found\n";
            }
        }
        void editPatient() {
            int n,pos,flag = 0;
            cout << "\nEnter the ID of patient you want to edit" << endl;
            cin >> n;

            fstream fpatient;
            fpatient.open(patient_file,ios::binary | ios::in | ios::out);

            while(!fpatient.eof()) {
                pos = fpatient.tellg();
                fpatient.read((char*)this,sizeof(Patient));
                if(fpatient) {
                    if(n == patientId) {
                        flag = 1;
                        getPatientInformation();
                        fpatient.seekp(pos);
                        fpatient.write((char*)this,sizeof(Patient));
                        show_data_of_person();
                        break;
                    }
                }
            }
            fpatient.close();

            if(flag == 1) {
                cout << "\nRecord successfully modified\n";
            }
            else {
                cout << "\nRecord not found\n";
            }
        }
        void doPatientRelatedWork() {
            char flag;
            int choice;
            
            do {
                cout << "Enter option 1 to add patient" << endl;
                cout << "Enter option 2 to show all data" << endl;
                cout << "Enter option 3 to discharge patient" << endl;
                cout << "Enter option 4 to edit patient's data" << endl;
                cout << "Enter option 5 to exit program" << endl;
                cin >> choice;

                if (choice == 1) {
                    do{
                        addPatient();
                        cout << "Add another patient? 1 or yes";
                        cin >> flag;
                    } while(flag == 1);    
                }
                else if (choice == 2) {
                    ShowPatientDataFromFile();
                }
                else if (choice == 3) {
                    DischargePatient();
                }
                else if (choice == 4) {
                    editPatient();
                }
            } while(choice == 1 | choice == 2 | choice == 3 | choice == 4);
        }    
};
/*
int main() {
    Patient p;
    
    p.doPatientRelatedWork();

    return 0;
}
*/