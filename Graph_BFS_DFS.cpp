//Program to impliment a graph to use BFS and DFS traversals to print the elements in it
#include<iostream>
#include<queue>
#include<vector>
using namespace std;
vector<vector<int>> graph;
void BFS()
{
}
void DFS()
{
}
void insert()
{
        int v;
        cout<<"Enter the value to be inserted : ";
        cin>>v;
}
int main()
{
        int o;
        while(1)
        {
                cout<<"Main menu -\n0. Exit program\n1. Insert node\n2. Perform BFS\n3. Perform DFS\nEnter your choice : ";
                cin>>o;
                switch(o)
                {
                        case 0 : cout<<"Program terminated\n";
                                 exit(0);
                        case 1 : insert();
                                 break;
                        case 2 : BFS();
                                 break;
                        case 3 : DFS();
                                 break;
                        default : cout<<"Invalid entry, Try again\n";
                }
        }
}
