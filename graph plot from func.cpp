#include<stdio.h>
#include<math.h>

double f(double x)
{
    double r= exp(x)-x*x;
    return r;
}


int main()
{

    freopen("in.txt", "r", stdin);
    freopen("out.csv", "w", stdout);

    for(double i=-1; i<=0; i+=0.01)
    {
        printf("%.4f %.4f\n",i,f(i));
    }

}
