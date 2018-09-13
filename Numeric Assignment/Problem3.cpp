#include<bits/stdc++.h>
using namespace std;

double f(double x)
{
    double r1=8*sin(x)*exp(-x)-1;
    return r1;
}


double find_point(double x0, double x1)
{
    double r1,r2;

    r1=x0*f(x1) - x1*f(x0);
    r2= f(x1)-f(x0);
    return r1/r2;

}

void print(double v1, double v2, double v3, double v4, double v5, double v6)
{
    cout<< "|" << setw(15) << v1 << "|" << setw(15) << v2 << "|" << setw(15) << v3 << "|" << setw(15) << v4 << "|" << setw(15) << v5 << "|" << setw(15) << v6<< "|" <<endl;
    for(int i=0; i<100-4; i++)
        printf("-");
    puts("");
}

void print(string v1, string v2, string v3, string v4, string v5, string v6)
{
    cout<< "|" << setw(15) << v1 << "|" << setw(15) << v2 << "|" << setw(15) << v3 << "|" << setw(15) << v4 << "|" << setw(15) << v5 << "|" << setw(15) << v6<< "|" <<endl;
    for(int i=0; i<100-4; i++)
        printf("-");
    puts("");
}
int main()
{
    printf("Maximize the screen\n");

    double x0,x1,x2;
    x0=0.5, x1=0.4;
    double rError=1000,tolerance;

    printf("f(x)=8sin(x)e^(–x)− 1\n");
    printf("Use the secant method, when initial guesses of xi–1 = 0.5 and xi = 0.4\n");
    printf("Input tolerance:");
    cin>>tolerance;

    x2=x1;
    x1=x0;

    print("iteration", "Upper value", "Lower value", "Xm", "f(Xm)", "Relative error");
    int cnt=0;
    while(rError>=tolerance)
    {

        x0=x1;
        x1=x2;
        x2= find_point(x0,x1);
        rError=fabs((x2-x1)/x2);
        //printf("iteration=%d Upper value=%.4f  Lower value=%.4f Xm=%.4f f(Xm)=%.4f rError=%.6f\n",++cnt,x0, x1,x2, f(x2),rError);
        print(++cnt,x0, x1,x2, f(x2),rError);
    }


    printf("root=%.4f\n",x2);

}
