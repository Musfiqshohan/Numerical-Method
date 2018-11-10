#include<bits/stdc++.h>
using namespace std;

int L[10][10],b[10];
int n;
void forward_substitution()
{
    for(int i=0; i<n; i++)
    {

        int s=0;
        for(int j=0; j<i; j++)
        {
            s+= L[i][j]*b[j];
        }

        b[i]-=s;
    }



    printf("%d\n",n);
    for(int i=0; i<n; i++)
        printf("%d ",b[i]);
    puts("");

}
int main()
{

    freopen("in.txt", "r", stdin);

    cin>>n;

    cout<<n<<endl;

    for(int i=0; i<n; i++)
    {
        for(int j=0; j<n; j++)
        {
            cin>>L[i][j];
        }
    }

    for(int i=0;i<n;i++)
        cin>>b[i];


    forward_substitution();

}
