#include<iostream>
#include<cmath>
using namespace std;

int main()
{
    int n,N;


    cout<<"\nEnter the no. of data pairs you have:\n";
    cin>>N;
    double x[N],y[N];
    cout<<"\nEnter the x values:\n";
    for (int i=0;i<N;i++)
        cin>>x[i];
    cout<<"\nEnter the y values:\n";
    for (int i=0;i<N;i++)
        cin>>y[i];
    cout<<"\nEnter the degree of polynomial:";
    cin>>n;
    double X[2*n+1];
    for (int i=0;i<2*n+1;i++)
    {
        X[i]=0;
        for (int j=0;j<N;j++)
            X[i]=X[i]+pow(x[j],i);
    }
    double B[n+1][n+2],a[n+1];
    for (int i=0;i<=n;i++)
        for (int j=0;j<=n;j++)
            B[i][j]=X[i+j];
    double Y[n+1];
    for (int i=0;i<n+1;i++)
    {
        Y[i]=0;
        for (int j=0;j<N;j++)
        Y[i]=Y[i]+pow(x[j],i)*y[j];
    }
    for (int i=0;i<=n;i++)
        B[i][n+1]=Y[i];
    n=n+1;


double p=0;
for (int i=0;i<n;i++){
        double l=B[i][i];
        for(int k=0;k<n;k++){
            if(i==k){
                for(int j=0;j<n+1;j++){
                    B[k][j]=B[k][j]/l;


            }}
            if(i!=k){
                     p=B[i][i]*B[k][i];
                for(int j=0;j<n+1;j++){

        B[k][j]=B[k][j]-p*B[i][j];




            }}}}



cout<<"After doing Guass Elimination the matrix is:"<<endl;
             for (int i=0;i<n;i++){
                 cout<<"\n";
        for (int j=0;j<=n;j++)
            cout<<B[i][j]<<"\t";
        cout<<"\n";}
 for (int i=n-1;i>=0;i--)
    {
        a[i]=B[i][n];
        for (int j=i+1;j<n;j++)



                a[i]=a[i]-B[i][j]*a[j];

    }
    cout<<"\ncoefficients are:\n";
    for (int i=0;i<n;i++)
        cout<<"x^"<<i<<"="<<a[i]<<endl;

    return 0;

}
