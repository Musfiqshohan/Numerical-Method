#include<bits/stdc++.h>


using namespace std;
double K=0.016 , ca0=42, cb0=28, cc0=4;

double f(double x)
{

    double r1=cc0+x;

    double r2= (ca0-2*x)*(ca0-2*x) * (cb0-x);


    double res= r1/r2  -K;
}



double find_point(double x0, double x1)
{
    double r= (f(x0)*(x1-x0))/(f(x0)-f(x1)) + x0;
    return r;
}


int main()
{

    freopen("rerror2cc.csv", "w", stdout);


//    for(double i=0; i<=20; i+=1)
//    {
//        printf("%.4f %.4f\n",i,f(i));
//    }

    double lo,hi, presc;


    printf("Low= ");
    cin>>lo;
    printf("High= ");
    cin>>hi;
    printf("Precs= ");
    cin>>presc;

    puts("");



    int cnt=0;

    double prev=0,rerror=10000,mid=0, initL=lo, initH=hi;
    while(rerror>presc ) // || cnt<15
    {
        cnt++;
        prev=mid;

        mid=(lo+hi)/2;

        if(f(mid)*f(lo)>0)
            lo=mid;
        else if(f(mid)*f(hi)>0)
            hi=mid;

        rerror=(mid-prev)/mid;
        rerror=fabs(rerror);

        //printf("%d hi=%.4f lo=%.4f  xm=%.4f f(xm)=%.4f  rerror=%.10f presc=%.10f\n",cnt, hi,lo,mid, f(mid),rerror,presc);
        printf("%.5f %.5f\n",mid, rerror);

    }

   // printf("initl=%.2f inith=%.2f\n",initL, initH);
    if(fabs(f(mid))>0.00001)
        printf("No solution\n");


}

