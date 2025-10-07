//Program to impliment quick,merge and binary sort for the array elements provided
#include<iostream>
#include<vector>
using namespace std;
int ar[10];
void read()
{
        cout<"Enter the array elements \n";
        int v=0;
        for(int i=0;i<10;i++)
        {
                cout<<"Element "<<i+1<<" : ";
                cin>>v;
                ar[i]=v;
        }
}
void print(vector<int> sort[])
{
        cout<<"Sorted array : ";
        for(int i:sort)
        {
                cout<<i<<"\t";
        }
        cout<<endl;
}
void binary()
{
        read();
        print(sort[]);
}
void merge()
{
        read();
        print(sort[]);
}
void quick()
{
        read();
        print(sort[]);
}
int main()
{
        int o;
        while(1)
        {
                cout<<"\n\nMain Menu -\n0.Exit Program\n1.Binary Sort\n2.Merge Sort\n3.Quick sort\nEnter your choice : ";
                cin>>o;
                switch(o)
                {
                        case 0 : cout<<"Program Terminated\n";
                                 return 0;
                        case 1 : binary();
                                 break;
                        case 2 : merge();
                                 break;
                        case 3 : quick();
                                 break;
                        default : cout<<"Invalid entry, try again\n";
                }
        }
}
//UNDER DEVELOPMENT
