#include <iostream>
#define epsilon 1e-9
#define PI 3.14159265358979323846
using namespace std;

double pow(double num, int deg){
    double result = 1;
    if(num == 0){
        return 0;
    }
    else if(num == 1){
       return 1;
    }
    else if(deg == 1){
        return num;
    }
    else{
        for(int i = 0; i < deg; i++){
            result *= num;
        }
        return result;
    }

}

int factorial(int num){
    if(num == 0){
        return 1;
    }
    else if(num == 1){
        return 1;
    }
    else{
        return num*factorial(num - 1);
    }
}

double sqrt(double num){
    /*double result = 0;
    num -= 1;
    for(int i = 0; i < 20; i++){
        result += pow(-1, i)*factorial(2*i)/((1 - 2*i)*(pow(factorial(i), 2))*pow(4, i))*pow(num, i);
    }

    return result;*/ //для x < 1
    

    /*do{
        result = (result + num/result)/2;
    } while (result*result - num > epsilon || result*result - num < -epsilon);*/ // с точность epsilon

    double result = 1;
    if(num == 0){
        return 0;
    }
    else if(num == 1){
        return 1;
    }
    else{
        for(int i = 0; i < 20; i++){
            result = (result + num/result)/2;
        }
    }
    
    return result;
}

double cos(double arg){
    double result = 0;

    if(arg == 0){
        return 1;
    }
    else{
        for(int i = 0; i < 15; i++){
            result += pow(-1, i)*pow(arg, 2*i)/(factorial(2*i));
        }
    }

    return result;
}

double sin(double arg){
    double result = 0;

    if(arg == 0){
        return 1;
    }
    else{
        for(int i = 0; i < 15; i++){
            result += pow(-1, i)*pow(arg, 2*i + 1)/(factorial(2*i+1));
        }
    }

    return result;
}

double arccos(double arg){
    double result = 1;

    for(int i = 0; i < 20; i++){
        result = result + (cos(result) - arg)/sin(result);
    }

    return result;
}

double area_Heron(double a, double b, double c){
    double p = (a + b + c)/2;
    return sqrt(p*(p-a)*(p-b)*(p-c));
}

double height(double side, double area){
    return 2*area/side;
}

double median(double a, double b, double c){
    return 0.5*sqrt(2*b*b + 2*c*c - a*a);
}

double bisector(double a, double b, double c){
    double p = (a + b + c)/2;
    return 2*sqrt(b*c*p*(p-a))/(b+c);
}

double angle_in_radian(double a, double b, double c){
    return arccos((b*b + c*c - a*a)/(2*b*c));
}

double normalize_angle(double angle){
    return angle*180/PI;
}

double inscribed_radius(double area, double a, double b, double c){
    return 2*area/(a + b + c);
}

double described_radius(double area, double a, double b, double c){
    return a*b*c/(4*area);
}

double circle_area(double radius){
    return PI*radius*radius;
}

double circle_length(double radius){
    return 2*PI*radius;
}

double area_for_r(double radius, double p){
    return p*radius/2;
}

double area_for_R(double radius, double a, double b, double c){
    return a*b*c/(4*radius);
}

int main(){
    double x1, y1, x2, y2, x3, y3;
    cout << "Введите координаты вершины A(x1, y1), B(x2, y2), C(x3, y3)" << endl;
    cin >> x1 >> y1 >> x2 >> y2 >> x3 >> y3;
    double a = sqrt(pow(x2-x1, 2) + pow(y2-y1, 2)); //1 сторона
    double b = sqrt(pow(x3-x2, 2) + pow(y3-y2, 2)); //2 сторона
    double c = sqrt(pow(x3-x1, 2) + pow(y3-y1, 2)); //3 сторона

    double area_for_Heron = area_Heron(a, b, c);
    
    double h_a = height(a, area_for_Heron);
    double h_b = height(b, area_for_Heron);
    double h_c = height(c, area_for_Heron);

    double m_a = median(a, b, c);
    double m_b = median(b, a, c);
    double m_c = median(c, b, a);

    double b_a = bisector(a, b, c);
    double b_b = bisector(b, a, c);
    double b_c = bisector(c, a, b);

    double alpha = angle_in_radian(a, b, c); //напротив стороны а
    double beta = angle_in_radian(b, a, c); //напротив стороны b
    double gamma = angle_in_radian(c, a, b); //напротив стороны c

    double n_alpha = normalize_angle(alpha);
    double n_beta = normalize_angle(beta);
    double n_gamma = normalize_angle(gamma);

    double in_radius = inscribed_radius(area_for_Heron, a, b, c);
    double out_radius = described_radius(area_for_Heron, a, b, c);

    double in_circle = circle_area(in_radius);
    double out_circle = circle_area(out_circle);

    double perimeter = a + b + c;
    double area_for_in_radius = area_for_r(in_radius, perimeter);
    double are_for_out_radius = area_for_R(out_radius, a, b, c);

}