#include <iostream>
using namespace std;

int main(){
    double a, b, c, Y;
    int N;
    cout << "Введите a, b, c, N" << endl;
    cin >> a >> b >> c >> N;

    switch(N){
        case 2:
            Y = b*c - a*a;
            break;
        case 56:
            Y = b*c;
            break;
        case 7:
            Y = a*a*a + c;
            break;
        case 3:
            Y = a - b*c;
            break;
        default:
            Y = (a + b)*(a + b)*(a + b);
            break;
    }

    cout << "Y = " << Y << endl;
}