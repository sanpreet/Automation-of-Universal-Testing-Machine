#include <iostream>
#include <fstream>
#include <sstream>
#include<stdio.h>
#include <iomanip>
using namespace std;

int main(void) {
    ifstream F1("sensor1.txt"),F4;
    ofstream F2("sensor1_out.txt"),F3;
    string line,line1;
    int x[100],y[100],i=0,j=0,h;
    float b,T,cv,tv,cf1,cf2;
	(getline(F1,line));
      istringstream(line)>>b;
	cf1=b;

    do
    {
	(getline(F1,line));

      istringstream(line)>>b;
        if(b>cf1)
        {   
        x[i]=b;
       i++;
        }
       else if(i!=0)
       {
       break;
       }

    }while(F1);

   int n=i;
    cout<<endl;
    for(i=0;i<n;i++)
    {
    F2<<setprecision(4)<<setw(10)<<x[i]<<endl;
    }

    F1.close();
    F2.close();

    F1.open("sensor1_out.txt");
    F2.open("X-axis.txt");
    
int k=0;
do
  {
    cout<<"Enter ton value(5,25,50):";
    cin>>T;
if(T==5||T==25||T==50)
     {k++;}
else
     {cout<<"Error:Invalid value"<<endl;}
  } while(k==0);

    F4.open("sensor2.txt");
    F3.open("Y-axis.txt");
 	(getline(F4,line));
      istringstream(line)>>h;
	cf2=h;
    while (getline(F4,line))
    {

    istringstream(line) >> h;
    if(h<cf2)
    {
    y[j]=h;
    j++;
    }
    else if(j!=0)
       {
       break;
       }

    }

       if(i>j)
	{
	i=j;
	n=i;	
	}
      else if(j>i)
	{
	j=i;
	n=j;
	}
      else{}

	i=0;
	int m=n;

while(getline(F1,line))
    {
    istringstream(line) >> b;
    float cv=T/305;
    float tv=cv*b;
    F2<<tv<<endl;
    i++;
    if(i==n)
    break;
    }
    F1.close();

	for(n=0;n<m;n++)
	{
	F3.width(6);
	F3<<right<<y[n]<<endl;
	}
F2.close();
F3.close();
return 0;
}
