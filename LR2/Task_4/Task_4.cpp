#include <iostream>
using namespace std;

int main(){
    int X, Y;
    double A, B, C, K;
    cout << "Введите X, Y" << endl;
    cin >> X >> Y;
    cout << "Введите A, B, C, K" << endl;
    cin >> A >> B >> C >> K;
    if(X == Y){
        X = 0;
        Y = 0;
    }
    else if(X < Y){
        X = 0;
    }
    else{
        Y = 0;
    }

    if(A > B){
        if(A > C){
            A -= K;
        }
        else{
            C -= K;
        }
    }
    else{
        if(B > C){
            B -= K;
        }
        else
        {
            C -= K;
        }
    }
    cout << "X: " << X << endl; 
    cout << "Y: " << Y << endl;
    cout << "A: " << A << endl;
    cout << "B: " << B << endl;
    cout << "C: " << C << endl;
    cout << "K: " << K << endl;

    return 0;
}