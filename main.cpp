#include <iostream>
#include <fstream>
#include <sstream>
#include<stdio.h>
#include <iomanip>
using namespace std;

int main(void) {
    ifstream F1("sensor2.txt"),F4;
    ofstream F2("sensor2_out.txt"),F3;
    string line;
    
    int x[100000],y[100000],i=0,j=0,h;
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
                    y[i]=b;
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
	
            F2<<setprecision(4)<<setw(10)<<y
            
            
            
            
            
            [i]<<endl;
        }

   F1.close();
   F2.close();

   F1.open("sensor2_out.txt");
   F2.open("Y-axis.txt");
    
   int k=0;
    do
        {
            cout<<"Enter ton value(5,25,50):";
            cin>>T;
            if(T==5||T==25||T==50)
            {
                k++;
            }
            else
            {
                cout<<"Error:Invalid value"<<endl;
            }
        } while(k==0);

    F4.open("sensor1.txt");
    F3.open("X-axis.txt");
 	(getline(F4,line));
    istringstream(line)>>h;
	cf2=h;
    while (getline(F4,line))
    {
        
         
            istringstream(line) >> h;
            if(h<cf2)
            {
				x[j]=h;
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
	int m=n,area,pi=3.14,radius;
   // cout<<"Enter radius:";
   // cin>>radius;
   // area=pi*radius*radius;
    while(getline(F1,line))
    {
        istringstream(line) >> b;
        float cv=T/310;
        float tv=cv*b;
       // float stress=tv/area;
        F2<<tv<<endl;
        i++;
        if(i==n)
            break;
    }
    F1.close();

	for(n=0;n<m;n++)
	{
		
	    F3.width(6);
	    F3<<right<<x[n]<<endl;
	}
    F2.close();
    
    
    F3.close();
return 0;
}
