#include "Patient.cpp"
#include "Doctor.cpp"

using namespace std;

int main() {
    Patient p;
    Doctor d;
    int choice;

    do{
        cout << "\n\nEnter option 1 for patient\n";
        cout << "Enter option 2 for doctor\n";
        cin >> choice;

        switch(choice) {
            case 1: cout << "\n---Patient---" << endl;
                    p.doPatientRelatedWork();
                    break;
            case 2: cout << "\n---Doctor---" << endl;
                    d.doDoctorRelatedWork();
                    break;
            default:
                    break;
        }
    }while(choice == 1 | choice == 2);

    return 0;

}