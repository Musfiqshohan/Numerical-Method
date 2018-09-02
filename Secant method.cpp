#include<bits/stdc++.h>
using namespace std;

double f(double x)
{
    double r1=(x-4)*(x-4);
    double r2=(x+2);
    return r1*r2;
}


double find_point(double x0, double x1)
{
    double r1,r2;

   // cout<<f(x1)<< " "<<f(x0)<<endl;
    r1=x0*f(x1) - x1*f(x0);
    r2= f(x1)-f(x0);

   // cout<<r1<<" "<<r2<<" "<<r1/r2<<endl;
    return r1/r2;

}
int main()
{


    double x0,x1,x2;
    cin>>x0>>x1;
    double rError=1000;

    x2=x1;
    x1=x0;

    int cnt=0;
    while(rError>=0.0001 )       ///not completed
    {

        x0=x1;
        x1=x2;

        x2= find_point(x0,x1);

        rError=fabs((x2-x1)/x2);
        printf("iter=%d x0=%.4f  f=%.4f x1=%.4f f1=%.4f x2=%.4f rError=%.6f\n",++cnt,x0,f(x0), x1,f(x1),x2 ,rError);
        //printf("x1=%.4f  rError=%.4f\n",x1, rError);
    }


    cout<<x2<<endl;








}

