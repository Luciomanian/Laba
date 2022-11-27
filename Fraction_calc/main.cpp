#include <iostream>


   // LAB4 EX12 Доповнення КАЛЬКУЛЯТОР ДЛЯ ДРОБІВ + ТАБЛИЦЯ


    using namespace std;
    class fraction{
    private:
        int nume{};       // чисельник
        int denome{};    // знаменник
        int even{};     // ціла частина
        char figure{}; // знак
    public:
        void getfract(){
            cout << "Введіть знак дробу\n";
            cin >> figure;
            cout << "Введіть чисельник\n";
            cin >> nume;
            cout << "Введіть знаменник\n";
            cin >> denome;
            cout << nume << '/' << denome << endl;
        }
        void ArithPlus(fraction I, fraction II) {
            fraction III;
            if(I.figure == '-')
                I.nume = I.nume * -1;
            if (II.denome != I.denome) { //різні знаменники
                III.nume = I.nume * II.denome + II.nume * I.denome;
                III.denome = I.denome * II.denome;
            }
            else{
                III.nume = I.nume + II.nume;
                III.denome = I.denome;
            }
            rst(III);
            if (III.denome < 0 || III.nume < 0){
                III.figure = '-';
                cout << III.figure;
            }
            if(III.denome < III.nume)
                evens(III);
            cout << III.nume << '/' << III.denome << endl;
        }
        void ArithMinus(fraction I, fraction II) {
            fraction III;
            if (I.figure == '-')
                I.nume = I.nume * -1;
            if (II.denome != I.denome) {
                III.nume = I.nume * II.denome - II.nume * I.denome;
                III.denome = I.denome * II.denome;
            } else {
                III.nume = I.nume - II.nume;
                III.denome = I.denome;
                rst(III);
                if (III.denome < 0 && III.nume < 0) {
                    III.figure = '-';
                    cout << III.figure;
                }
                if (III.denome < III.nume)
                    evens(III);

                cout << III.nume << '/' << III.denome << endl;
            }
        }
        void ArithMult(fraction I, fraction II){
            fraction III;
            if(I.figure == '-')// визначення знаку дробу
                I.nume = I.nume * -1;
            III.nume = I.nume * II.nume;
            III.denome = I.denome * II.denome;
            rst(III);// скорочення
            if(III.denome < III.nume)// виділення цілої частини
                evens(III);
            cout << III.nume << '/' << III.denome << " \t";
            cout << chaToDec(III);
        }
        void ArithDiv(fraction& I, fraction& II) {
            fraction III;
            if (I.figure == '-')
                I.nume = I.nume * -1;
            III.nume = I.nume * II.denome;
            III.denome = I.denome * II.nume;
            rst(III);
            if (III.denome < III.nume)
                evens(III);
            cout << III.nume << '/' << III.denome << endl;
        }

        void evens(fraction& ev){
            ev.even = ev.nume / ev.denome;
            ev.nume = ev.nume % ev.denome;
            cout << ev.even << ' ';
        }

        void rst(fraction& re){
            while((re.nume % 9 == 0) && (re.denome % 9 == 0)) {
                re.nume = re.nume / 9; re.denome = re.denome / 9;
            }
            while((re.nume % 7 == 0) && (re.denome % 7 == 0)) {
                re.nume = re.nume / 7; re.denome = re.denome / 7;
            }
            while((re.nume % 5 == 0) && (re.denome % 5 == 0)) {
                re.nume = re.nume / 5; re.denome = re.denome / 5;
            }
            while((re.nume % 3 == 0) && (re.denome % 3 == 0)) {
                re.nume = re.nume / 3; re.denome = re.denome / 3;
            }
            while((re.nume % 2 == 0) && (re.denome % 2 == 0)) {
                re.nume = re.nume / 2; re.denome = re.denome / 2;
            }
        }
        double chaToDec(fraction& de){
            double man;
            man = de.nume / de.denome;
            return man;
        }
        void Table(fraction I, fraction II){
            cin >> I.denome;
            II.denome = I.denome;
            cout << " \t\t";
            for(int j = 1; j < I.denome; j++) {
                II.denome = 1;
                II.nume = 1;
                I.nume = j;
                ArithMult(I,II);
            }
            cout << endl;
            for(int j = 1; j < I.denome; j++) {
                II.denome = 1;
                II.nume = 1;
                I.nume = j;
                ArithMult(I,II);
                I.nume = II.nume = j;
                for(int i = 1; i <= j; i++){
                    II.denome = I.denome;
                    I.nume = i;
                    ArithMult(I,II);
                }
                for(int i = 5; i > j; i--) {
                    II.denome = I.denome;
                    I.nume++;
                    ArithMult(I, II);
                }
                cout << endl;
            }
        }
    }I,II,III;
    int main(){
        fraction t;
        t.Table(I,II);
        III.ArithMult(I,II);
        return 0;
    }

