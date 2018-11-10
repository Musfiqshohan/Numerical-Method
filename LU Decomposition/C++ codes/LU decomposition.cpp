#include<bits/stdc++.h>
using namespace std;


double A[10][10],L[10][10],U[10][10];
int n;

void LU()
{

    for(int i=0; i<n; i++)
    {
        for(int k=i; k<n; k++)
        {
            int s=0;

            for(int j=0; j<i; j++)
                s+= L[i][j]*U[j][k];

            U[i][k]=A[i][k]-s;
           // printf("%.2lf %.2lf\n",U[i][j],s);
        }

        for(int k=i; k<n; k++)
        {
            if(i==k)
            {
                L[i][k]=1;
            }
            else
            {
                int s=0;
                for(int j=0; j<i; j++)
                    s+=L[k][j]*U[j][i];

                L[k][i]=(A[k][i]-s)/U[i][i];
            }
            //printf("%.2lf %.2lf\n",L[i][j],s2);
        }

    }
}


void printMat(double a[10][10])
{

    for(int i=0; i<n; i++)
    {

        for(int j=0; j<n; j++)
        {
            printf("%lf ",a[i][j]);
        }
        puts("");
    }
    puts("");

}


int main()
{

    freopen("in.txt", "r", stdin);


    cin>>n;


    for(int i=0; i<n; i++)
    {
        for(int j=0; j<n; j++)
        {
            cin>>A[i][j];
        }
    }

    //printMat(A);

    LU();

    printMat(A);
    printMat(L);
    printMat(U);









}
