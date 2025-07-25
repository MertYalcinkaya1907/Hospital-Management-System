#include <iostream>
#include <string>
#include <ctime>

using namespace std;

class Avaliable {
    private:
        char DayOfWeek[15][7] , Shift_1[25],Shift_2[25];
        int i,NumberOfDay;
    public:
        void WhenAvaliable() {
            cout << "Enter number of avaliable days 1-7:" << endl;
            cin >> NumberOfDay;
            
            while(NumberOfDay < 1 && NumberOfDay > 7) {
                cout << "Error,the number you entered is out of range." << endl;
                cout << "Enter the number between 1-7" << endl;
                cin >> NumberOfDay;
            }

            cout << "Enter " << NumberOfDay << " days of week for Dr. avaliable?:" << endl;
            
            for(i = 0; i < NumberOfDay; i++) {
                cin >> DayOfWeek[i];   
            }

            cout << "Enter Dr. first shift:" << endl;
            cin >> Shift_1;
            cout << "Enter Dr. second shift:" << endl;
            cin >> Shift_2;

        }
        
        void DisplayAvaliable() {
            time_t raw_time; // time_t is a data type. raw_time is a variable.
            struct tm * timeinfo; // tm daha önceden yazılmış bir structtur ctime kütüphanesinde.
            time(&raw_time); // Şu anki zamanı alır ve raw_time değişkenine atar.
            timeinfo = localtime(&raw_time); 
            cout << "Local time: ";
            cout << asctime(timeinfo);

            cout << "Dr. is avaliable for " << NumberOfDay << " days in weeek" << endl;
            cout << "**Avaliable day are**" << endl;

            for (i = 0; NumberOfDay < i; i++) {
                cout << DayOfWeek[i] << endl;
            }
            cout << "**Dr. Shift are**" << endl;
            cout << Shift_1 << endl;
            cout << Shift_2 << endl;
        }

};
/*
int main() {
    Avaliable a1;

    a1.WhenAvaliable();
    a1.DisplayAvaliable();

    return 0;
}
*/
