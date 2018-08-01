#include<stdio.h>
#include<math.h>


double f(double x)
{
    double r= exp(x)-x*x;
    return r;
}

//double f(double x)
//{
//    double r= x*x*x - 0.165*x*x +3.993*0.0001;
//    return r;
//}

double find_point(double x0, double x1)
{
    double r= (f(x0)*(x1-x0))/(f(x0)-f(x1)) + x0;
    return r;
}

int main()
{

    //freopen("in.txt", "r", stdin);
    freopen("rerror2.csv", "w", stdout);

    //double lo=-1, hi=0.99 ,mid;
    double lo=-1, hi=0 ,mid;



    int itert=32;
    int cnt=itert;
    double past=0, cur=0;

    while(cnt--)
    {

        past=mid;
        mid=find_point(lo,hi);
        double r=f(mid);
        if(f(mid)*f(lo)>0)
            lo=mid;
        else if(f(mid)*f(hi)>0)
            hi=mid;

        if(cnt<31){
        double rerror= fabs(mid-past)/mid;
        printf("%d %.8f\n",itert-cnt-1, fabs(rerror));
        }
        //printf("%.4f %.4f %.4f  f=%.8f\n",lo,hi,mid,f(mid));
    }

   // printf("root=%.4f\n",mid);


}
