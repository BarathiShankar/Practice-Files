//Program to create a minheap using vectors
#include<iostream>
#include<vector>
using namespace std;
vector<int> heap;
void bubbleup(int index)//To heapify the child to correct position
{
        int size=heap.size();
        while(index > 0)
        {
                int par=(index-1)/2;
                if(heap[index]<heap[par])
                {
                        swap(heap[index],heap[par]);
                        index=par;
                }
                else
                        break;
        }
}
void bubbledown(int index)//To heapify the deleted hole of parent after deletion
{
        int size=heap.size();
        while(index < size)
        {
                int left=(index*2)+1;
                int right=(index*2)+2;
                int smallest=index;
                if(left<size && heap[left]<heap[smallest])
                {
                        smallest=left;
                }
                if(right<size && heap[right]<heap[smallest])
                {
                        smallest=right;
                }
                if(index!=smallest)
                {
                        swap(heap[index],heap[smallest]);
                                index=smallest;
                }
                else
                {
                        return;
                }
        }
}
void insert()
{
        int v;
        cout<<"Enter the value to be inserted : ";
        cin>>v;
        heap.push_back(v);
        bubbleup(heap.size()-1);
}
void del()
{
        if(heap.empty())
        {
                cout<<"Heap is empty, Unable to delete\n";
                return;
        }
        int del=heap[0];
        heap[0]=heap.back();
        heap.pop_back();
        bubbledown(0);
        cout<<"Deleted value : "<<del<<endl;
}
void print()
{
        if(heap.empty())
        {
                cout<<"Heap is empty\n";
                return;
        }
        for(int i:heap)
        cout<< i <<"\t";
        cout<<endl;
}
int main()
{
        int o;
        while(1)
        {
        cout<<"Main menu -\n0. Exit program\n1. Insert new node\n2. Delete node\n3. Print heap\nEnter your choice : ";
        cin>>o;
        switch(o)
        {
                case 0 : cout<<"Program terminated\n";
                         exit(0);
                case 1 : insert();
                         break;
                case 2: del();
                        break;
                case 3 : print();
                         break;
                default : cout<<"Invalid entry, Try again\n";
        }
        }
}
//COMPLETED
