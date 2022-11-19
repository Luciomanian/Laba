#include <iostream>
#include <string>

using namespace std;
    class Time{
    public:
        int hours;
        int minutes;
        int seconds;
        int InitTime(int hours, int minutes, int seconds){
            this -> hours = hours;
            this -> minutes = minutes;
            this -> seconds = seconds;
            return hours,minutes,seconds;
        }
    };
    class Train{
    private:
        int number; // номер потяга
        string name; // ім'я машиніста
        string cargo; // тип вантажу TRUE - вантаж FALSE - пасажирський
    public:
        Train(){
            cin >> number; // задати номер потяга
            cin >> name; // задати ім'я машиніста
        }
        bool cargoType(bool OG) {
            if (OG == true) {
                cargo = "cargo:";
                string type;
                cout << "Name of cargo.\n";
                cin >> type;
                cargo += type;
                cout << cargo;
            }
            else {
                cargo = "Pasangers";
            }
        }

    };
    class Kase {

    };
    class dispatcher : Train{
    private:
        Time time; // час зупинки
        Time arrival_time; // час прибуття
        Time departure_time; // час відправлення
        int way; // номер шляху для прибуваючого потяга
    public:
        int wayFinder(){ // функція визначення шляху для потяга
            cin >> way; // диспетчер вводить шлях вручну
        }
        int stopTime (int hrs, int min, int sec) { // функція визначення часу для зупинки потяга
            time.hours = hrs;
            time.minutes = min;
            time.seconds = sec;
        }
        int ArrivalAndDeparture (int hrs, int min, int sec) { // час прибуття потяга
            arrival_time.hours = hrs;
            arrival_time.minutes = min;
            arrival_time.seconds = sec;
            // визначення часу відправлення - час прибуття + час зупинки
            departure_time.hours = arrival_time.hours + time.hours;
            departure_time.minutes = arrival_time.minutes + time.minutes;
            departure_time.seconds = arrival_time.seconds + time.seconds;  // СКОРОЧЕННЯ!!!
            return 0;
        }
    };
int main() {
    dispatcher a;
    a.stopTime(1, 20, 0);
    a.ArrivalAndDeparture(18,20,0);
    a.cargoType(true);
    return 0;
}
