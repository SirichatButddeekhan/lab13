#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;

void stat(const double[],int,double[]);

int main(){
    double A[] = {1.2,3.5,6.9,7.8,12.5,0.5};
    int N = sizeof(A)/sizeof(A[0]);
    double B[6];
    stat(A,N,B);
    cout << fixed << setprecision(2);
    cout << "Arithmetic Mean = " << B[0] << endl;
    cout << "Standard Deviation = " << B[1] << endl;
    cout << "Geometric Mean = " << B[2] << endl;
    cout << "Harmonic Mean = " << B[3] << endl;
    cout << "Max = " << B[4] << endl;
    cout << "Min = " << B[5];
    return 0;
}

void stat(const double src1[],int N,double dest[]){

    double sum=0;
    for(int i=0; i<N ;i++){
        sum += src1[i];
    }
    dest[0] = sum/N;

    double def;
    double newsum = 0 ;
    for(int i=0;i<N;i++){
        def = src1[i] - dest[0];
        newsum += def * def;
    }
    dest[1] = pow(newsum / N,0.5);

    double geomatric = 1;
    for(int i=0;i<N;i++){
        geomatric *= src1[i];
    }
    dest[2] = pow(geomatric,1.0/N);


    double sum_harmonic;
    for(int i=0; i<N ;i++){
        sum_harmonic += 1/src1[i];
    }
    dest[3] = N/sum_harmonic;


    double max = src1[0];
    double min = src1[0];

    for(int i=1;i < N; i++){
        if(src1[i]> max)max = src1[i];
        if(src1[i]< min)min = src1[i];
    }

    dest[4] = max;
    dest[5] = min;

}
