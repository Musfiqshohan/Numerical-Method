#include<bits/stdc++.h>
using namespace std;

double f10(double x)
{
    double r= -x*x + 1.8*x +2.5;
    return r;
}

double f11(double x)
{
    double r= -2*x +1.8;
    return r;
}


void print(double v1, double v2, double v3, double v4, double v5)
{
    cout<< "|" << setw(15) << v1 << "|" << setw(15) << v2 << "|" << setw(15) << v3 << "|" << setw(15) << v4 << "|" << setw(15) << v5 << "|"  <<endl;
    for(int i=0; i<80; i++)
        printf("-");
    puts("");
}

void print(string v1, string v2, string v3, string v4, string v5)
{
    cout<< "|" << setw(15) << v1 << "|" << setw(15) << v2 << "|" << setw(15) << v3 << "|" << setw(15) << v4 << "|" << setw(15) << v5 << "|" <<endl;
    for(int i=0; i<80; i++)
        printf("-");
    puts("");
}



double f20(double x)
{
    double r= exp(-0.5*x) * (4-x) -2;
    return r;
}

double f21(double x)
{
    double r= -exp(-0.5*x) - 0.5 * exp(-0.5*x) * (4-x);
    return r;
}

void Newton_Raphson(double initGuess, double input_tolerance, int cs)
{

    double x0, tolerance;;
    x0=initGuess;
    tolerance=input_tolerance;
    double x1=x0,rError=1000;


    print("iteration", "xi", "f(xi)", "f'(xi)", "Relative error");
    int cnt=0;
    while(rError>=tolerance)
    {
        x0=x1;

        double r0,r1;
        if(cs==1)
        {
            r0=f10(x0);
            r1=f11(x0);
        }
        else
        {
            r0=f20(x0);
            r1=f21(x0);
        }

        //printf("iteration=%d xi=%.6f  f(xi)=%.6f f'(xi)=%.6f rError=%.6f\n",++cnt,x0,f0(x0), f1(x0),rError);
        print(++cnt,x0,r0, r1,rError);
        if(r1==0)
        {
            printf("Causing division by zero hence terminating\n");
            return ;
        }
        x1= x0 - r0/r1;
        rError=fabs((x1-x0)/x1);
    }

    printf("root=%.6f\n",x1);


}

int main()
{
     printf("Maximize the screen\n");


    printf("Newton-Raphson:\n1st equation: root of f (x) = -x^2 + 1.8x + 2.5\n");
    printf("Input tolerance:");
    double tol;
    cin>>tol;
    printf("Initial root: 5 tolerance:%.6f\n\n",tol);
    Newton_Raphson (5,tol,1);
    puts("");
    puts("");

    printf("2nd equation: root of f (x) = e^(-0.5x) (4 - x) - 2\n");
    tol=0.0001;
    printf("Initial root: 2 tolerance:%.6f\n\n",tol);
    Newton_Raphson (2,tol,2);
    puts("");
    puts("");

    printf("Initial root: 6 tolerance:%.6f\n\n",tol);
    Newton_Raphson (6,tol,2);
    puts("");
    puts("");

    printf("Initial root: 8 tolerance:%.6f\n\n",tol);
    Newton_Raphson (8,tol,2);
    puts("");
    puts("");


}
