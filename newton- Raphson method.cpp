#include<bits/stdc++.h>
using namespace std;

double f0(double x)
{
    double r1=(x-4)*(x-4);
    double r2=(x+2);
    return r1*r2;
}

double f1(double x)
{
    double r1,r2;
    r1=2*(x-4)*(x+2);
    r2=(x-4)*(x-4);

    return r1+r2;
}


int main()
{


    double x0;
    cin>>x0;
    double x1=x0,rError=1000;



    int cnt=0;
    while(rError>=0.0001)
    {
        x0=x1;
        x1= x0 - f0(x0)/f1(x0);
        printf("iter=%d x0=%.4f  f0=%.4f f1=%.4f rError=%.6f\n",++cnt,x0,f0(x0), f1(x0),rError);
        rError=fabs((x1-x0)/x1);
        //printf("x1=%.4f  rError=%.4f\n",x1, rError);
    }
        printf("iter=%d x0=%.4f  f0=%.4f f1=%.4f rError=%.6f\n",++cnt,x1,f0(x1), f1(x1),rError);


    cout<<x1<<endl;








}
