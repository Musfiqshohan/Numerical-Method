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

    freopen("Problem1b.csv", "w", stdout);

    double lo,hi, presc;


//    for(double i=1;i<=3;i+=0.1)
//    {
//        printf("%.4f %.4f\n",i,f(i,0,10));
//    }

    puts("");

    printf("Low= ");
    cin>>lo;
    printf("High= ");
    cin>>hi;
    printf("Precs= ");
    cin>>presc;

    puts("");


    if(f(lo,0,10)*f(hi,0,10)>0)
        printf("No solution\n");



    int cnt=0;

    double prev=0,rerror=10000,mid=0;
    while(rerror>presc) // || cnt<15
    {
        cnt++;
        prev=mid;

        mid=(lo+hi)/2;

        if(f(mid,0,10)*f(lo,0,10)>0)
            lo=mid;
        else if(f(mid,0,10)*f(hi,0,10)>0)
            hi=mid;

        rerror=(mid-prev)/mid;
        rerror=fabs(rerror);

       // printf("%d hi=%.4f lo=%.4f  xm=%.4f f(xm)=%.4f  rerror=%.10f presc=%.10f\n",cnt, hi,lo,mid, f(mid,0,10),rerror,presc);
        printf("%d %.5f\n",cnt, rerror);

    }


}
