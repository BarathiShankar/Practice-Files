//Program to create a maxheap using linked list
#include<iostream>
using namespace std;
struct node
{
        int data;
        node* next;
};
node* root=nullptr;
void heapify();
void insert()
{
        int d;
        cout<<"Enter the value to be inserted : ";
        cin>>d;
        if(root==nullptr)
                root->data=d;
        else
        {
                node* newnode=nullptr;

        }
        heapify();
}
void del()
{
}
void heapify()
{
}
node* inorder(node* n)
{
}
node* postoder(node* n)
{
}
node* preorder(node* n)
{
}
void print()
{
        int o;
        cout<<"Enter the type of traveral -\n1. Preorder\n2.Inorder\n3.Postorder\n Enter here : ";
        cin>>o;
        switch(o)
                {
                        case 1 : preorder();
                        break;
                        case 2 : inorder();
                        break;
                        case3 : postorder();
                        break;
                        default : cout<<"Invalid entry,exited from traverals\n";
                }
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
                case 1 : insert()
                         break;
                case 2: del();
                        break;
                case 3 : print();
                         break;
                default : cout<<"Invalid entry, Try again\n";
        }
        }
}
//UNDER DEVELOPMENT
