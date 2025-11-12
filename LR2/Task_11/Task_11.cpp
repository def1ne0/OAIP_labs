#include <iostream>
using namespace std;

int main(){
    int h1, m1, h2, m2;
    cout << "Введите h1, m1, h2, m2 соответственно" << endl;
    cin >> h1 >> m1 >> h2 >> m2;

    int h_m = (h2*60 + m2 - (h1*60 + m1));

    if(h_m < 0){
        h_m += 24*60;
    }
        
    int h = h_m / 60;
    int m = h_m % 60;



    cout << "Студент решал задачи " << h << " часов " << m << " минут" << endl; 
}