#include<stdio.h>
#include<math.h>
#include<bits/stdc++.h>
using namespace std;



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



double g=9.8, v=35, t=9, c=15;
double f(double m)
{
    double r= g*m * (1 - exp(-(c/m)*t));
    r=r/c -v;
    return r;
}


void doBisection(double lo, double hi, double prec)
{

    printf("Solving with Bisection method\n\n");

    int iter=0;
    double past=0, cur=0,mid;

    print("iteration", "Upper value", "Lower value", "Xm", "f(Xm)", "Relative error");

    while(1)
    {
        past=mid;
        mid=(lo+hi)/2;
        double r=f(mid);
        if(f(mid)*f(lo)>0)
            lo=mid;
        else if(f(mid)*f(hi)>0)
            hi=mid;

        double rerror= fabs(mid-past)/mid;
        // printf("iteration=%d Upper value=%.4f Lower value=%.4f Xm=%.4f  f(Xm)=%.4f  error=%.4f\n",++iter, hi,lo,mid,f(mid), rerror);
        print(++iter, hi,lo,mid,f(mid), rerror);
        if(rerror<prec) break;
    }

    printf("root=%.4f\n",mid);

}

double find_point(double x0, double x1)
{
    double r= (f(x0)*(x1-x0))/(f(x0)-f(x1)) + x0;
    return r;
}

void doFalsePosition(double lo, double hi, double prec)
{

    printf("\n\n\nSolving with FalsePosition method\n\n");

    int iter=0;
    double past=0, cur=0,mid;

    print("iteration", "Upper value", "Lower value", "Xm", "f(Xm)", "Relative error");
    while(1)
    {

        past=mid;
        mid=find_point(lo,hi);
        double r=f(mid);
        if(f(mid)*f(lo)>0)
            lo=mid;
        else if(f(mid)*f(hi)>0)
            hi=mid;

        double rerror= fabs(mid-past)/mid;
        //  printf("iteration=%d Upper value=%.4f Lower value=%.4f Xm=%.4f  f(Xm)=%.4f  error=%.4f\n",++iter, hi,lo,mid,f(mid), rerror);
        print(++iter, hi,lo,mid,f(mid), rerror);
        if(rerror<prec) break;
    }

    printf("root=%.4f\n",mid);
}


void printLowToHigh(double a, double b)
{

    for(double i=a; i<=b; i+=0.1)
    {
        cout<<i<<" "<<f(i)<<endl;
    }

    puts("");

}


int main()
{

    printf("Maximize the screen\n");
    double lo=-100, hi=0, prec;

    printf("lower limit:");
    cin>>lo;
    printf("higer limit:");
    cin>>hi;
    printf("tolerance:");
    cin>>prec;

    printLowToHigh(lo,hi);


    if(f(lo)*f(hi)>0)
    {
        printf("No root is possible\n");
        return 0;
    }

    doBisection(hi,lo,prec);
    doFalsePosition(hi,lo,prec);



}
