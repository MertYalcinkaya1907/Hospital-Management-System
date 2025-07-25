#pragma once
#include <iostream>
#include <string>

using namespace std;

class Person {
    private:
        int age;
        string name , surname , email , phone_number , ıd_number , address;
    public:
        void get_data_from_person() {
            cout << "Enter Name:";
            getline(cin>>ws,name);

            cout << "Enter Surname:";
            getline(cin,surname);

            cout << "Enter Age:";
            cin >> age;

            cout << "Enter ID Number:";
            cin >> ıd_number;

            cout << "Enter Phone Number:";
            cin >> phone_number;

            cout << "Enter E-mail Address:";
            cin >> email;
            
            cin.ignore(); // üstteki cinden \n gelir getline önce cin tamponunu kontrol eder kontrol ettiğinde \n gördüğü için atlıyordu bunu aşmak için bunu yazdım.
            
            cout << "Enter Address:";
            getline(cin,address);
        }

        void show_data_of_person() {
            cout << "Name:" << name << endl;
            cout << "Surame:" << surname << endl;
            cout << "Age:" << age << endl;
            cout << "ID Number:" << ıd_number << endl;
            cout << "Phone Number:" << phone_number << endl;
            cout << "E-mail Address:" << email << endl;
            cout << "Address:" << address << endl;
        }

};
/*
int main() {
    Person patient_1;
    patient_1.get_data_from_person();
    patient_1.show_data_of_person();

    return 0;
}
*/    