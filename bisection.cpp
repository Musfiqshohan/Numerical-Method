#include<stdio.h>
#include<math.h>


double f(double x)
{
    double r= exp(x)-x*x;
    return r;
}

int main()
{

//     freopen("in.txt", "r", stdin);
    freopen("rerror.csv", "w", stdout);

    double lo=-100, hi=0 ,mid;



    int itert=32;
    int cnt=itert;
    double past=0, cur=0;

    while(cnt--)
    {

        past=mid;
        mid=(lo+hi)/2;
        double r=f(mid);
        if(f(mid)*f(lo)>0)
            lo=mid;
        else if(f(mid)*f(hi)>0)
            hi=mid;

        if(cnt<31){
        double rerror= fabs(mid-past)/mid;
        printf("%d %.8f \n",itert-cnt-1, fabs(rerror));
        }
       // printf("%.4f %.4f %.4f  f=%.4f\n",lo,hi,mid,f(mid));
    }

   // printf("root=%.4f\n",mid);


}
