#include<iostream>
#include<iomanip>
using namespace std;
int main()
{
    int n,m,i,j,k,y=0;
    cout<<"Enter Number of rows : ";
    cin>>n;
    cout<<endl;
    cout<<"Enter Number of columns : ";
    cin>>m;
    cout<<endl;
    float a[n][m],x[n];
    cout<<"Enter the elements of the augmented-matrix : "<<endl<<endl;

    for (i=0; i<n; i++)
        for (j=0; j<m; j++)
        {
            cin>>a[i][j];
        }
    // Step Pivot
    for (i=0; i<n; i++)
        for (k=i+1; k<n; k++)
        {
            if (a[i][i]<a[k][i])
            {
                for (j=0; j<m; j++)
                {
                    double temp=a[i][j];
                    a[i][j]=a[k][j];
                    a[k][j]=temp;
                }
            }
        }
    cout<<endl<<"The matrix before Pivotisation is : "<<endl<<endl;
    for (i=0; i<n; i++)
    {
        for (j=0; j<m; j++)
            cout<<a[i][j]<<"\t"<<"\t";
        cout<<endl;
    }
    for (i=0; i<n-1; i++)
        for (k=i+1; k<n; k++)
        {
            double t=a[k][i]/a[i][i];
            for (j=0; j<m; j++)
                a[k][j]=a[k][j]-t*a[i][j];
        }
    for (i=n-1; i>=0; i--)
    {
        x[i]=a[i][n];
        for (j=0; j<m-1; j++)
            if (j!=i)
                x[i]=x[i]-a[i][j]*x[j];
        if (a[i][i]==0)
            y=1;
        x[i]=x[i]/a[i][i];
    }

    if (y==1)
        cout<<endl<<"This Equation is Inconsist"<<endl;
    else
    {
        cout<<endl<<"The values of the variables are as follows : "<<endl<<endl;

        cout<<"This Equation is Consist"<<endl<<endl;
        for (i=0; i<m-1; i++)
        {
            cout<<"X"<<i+1<<" = "<<x[i]<<endl;
        }
    }
    return 0;
}
