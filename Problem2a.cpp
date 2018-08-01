#include<bits/stdc++.h>


using namespace std;


double K=0.016 , ca0=42, cb0=28, cc0=4;

int fact(int n)
{
    int res=1;

    for(int i=1;i<=n;i++)
        res*=i;

    return res;
}



double pow1(double x, int n)
{
    if(n==0) return 1;

    if(n%2==0)
    {
        double ret=pow1(x,n/2);
        return ret*ret;
    }

    return x*pow1(x,n-1);

}

double f(double x)
{

    double r1=cc0+x;

    double r2= (ca0-2*x)*(ca0-2*x) * (cb0-x);


    double res= r1/r2  -K;
}


int main()
{

    freopen("graph2a.csv", "w", stdout);


    for(double i=0; i<=20; i+=1)
    {
        printf("%.4f %.4f\n",i,f(i));
    }

}
