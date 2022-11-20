#include <iostream>
#include <string>
#include <iomanip>

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
class ChekinDesk  {
private:
    bool ON;
    string Presence;
public:
    void MarkOnBoard () { // ставить  відмітку про успішну посадку пасажира
        ON = true;
        Presence = "ON BOARD!\n";
        cout << Presence << endl;
    }
};
    class Train{
    private:
        int number; // номер потяга
        string name; // ім'я машиніста
        string cargo; // тип вантажу TRUE - вантаж FALSE - пасажирський
    public:
        Train(){
            cout << "Number of a train\n";
            cin >> number; // задати номер потяга
            cout << "Name of engineer\n";
            cin >> name; // задати ім'я машиніста
        }
        bool cargoType() { // вибір типу потяга
            bool OR;
            cout << "Choose type of train. 1 - Cargo, 0 - Passenger's.\n";
            cin >> OR;
            if (OR == true) {
                cargo = "cargo:";
                string type;
                cout << "Name of cargo.\n";
                cin >> type;
                cargo += type;
            }
            else {
                cargo = "Type: Passenger`s\n";
            }
            cout << cargo << endl;
            return OR;
        }
    };
    class Kase  {;
    private:
        int place;
        string Passenger;
    public:
        int ticket() {
            cout << "Passenger`s name.\n";
            cin >> Passenger;
            cout << "Place number.\n";
            cin >> place;
        }
    };
    class dispatcher : public Train, public Kase, public ChekinDesk {
    private:
        Time time; // час зупинки
        Time arrival_time; // час прибуття
        Time departure_time; // час відправлення
        int way; // номер шляху для прибуваючого потяга
    public:
        int wayFinder() { // функція визначення шляху для потяга
            cout << "Enter number of way for arrival.\n";
            cin >> way; // диспетчер вводить шлях вручну
        }

        int stopTime(int hrs, int min, int sec) { // функція визначення часу для зупинки потяга
            time.hours = hrs;
            time.minutes = min;
            time.seconds = sec;
            cout << "Time for stay: " << hrs << "h :" << setw(2) << setfill('0') << min << "m :" << setw(2) << setfill('0') << sec << 's' << endl;
        }

        int ArrivalAndDeparture(int hrs, int min, int sec) { // час прибуття потяга
            arrival_time.hours = hrs;
            arrival_time.minutes = min;
            arrival_time.seconds = sec;
            cout << "Arrival time: " <<  arrival_time.hours << "h :" << setw(2) << setfill('0') << arrival_time.minutes << "m :" << setw(2) << setfill('0') << arrival_time.seconds << 's' << endl;
            // визначення часу відправлення - час прибуття + час зупинки
            departure_time.seconds = (arrival_time.seconds + time.seconds);
            departure_time.minutes += departure_time.seconds % 60;
            departure_time.minutes = (arrival_time.minutes + time.minutes);
            departure_time.hours = departure_time.minutes % 60;
            departure_time.hours = arrival_time.hours + time.hours;
            cout << "Departure time: " << departure_time.hours << "h :" << setw(2) << setfill('0') << departure_time.minutes  << "m :" << setw(2) << setfill('0') << departure_time.seconds << 's' << endl;
            return 0;
        }
};

int main() {
    dispatcher ticket_A;
    ticket_A.ArrivalAndDeparture(18, 2, 0);
    ticket_A.stopTime(1, 3, 0);
        if (ticket_A.cargoType() == 0) {
        ticket_A.ticket();// виклик каси
    };
    ticket_A.wayFinder();
    ticket_A.MarkOnBoard();
    return 0;
}
