#include<bits/stdc++.h>


using namespace std;

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

double f(double x, int n, int KK)
{
    //puts("gi");
    double r1=pow1(x/2, n);

    double r2=0;

    for(int k=0;k<=KK;k++)
    {
        double t1= pow1(-1,k)* pow1((x*x/4),k);
        double t2= fact(k)* fact(n+k);

       // cout<<t1<< " "<<t2<<endl;
        r2+= (t1/t2);

    }



    double res=r1*r2;
}


int main()
{

   // freopen("graph3.csv", "w", stdout);

    int n;
    cin>>n;

    for(double i=1; i<=3; i+=0.1)
    {

        printf("%.4f %.4f\n",i,f(i, n, 10));
    }

}
