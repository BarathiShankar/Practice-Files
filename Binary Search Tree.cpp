//Program to impliment a binary search tree to insert,delete(node with 1,2 and no child) node and display the nodes ( In inorder,preorder and postorder traversal methods ) the tree.
#include<iostream>
using namespace std;
struct node
{
        int data;
        node* left;
        node* right;
        node() : data(0), left(nullptr), right(nullptr) {}
        node(int v) : data(v), left(nullptr), right(nullptr) {}
};
node* root=nullptr;
void insert()
{
        int val;
        node* cur=root;
        cout<<"Enter the value : ";
        cin>>val;
        node* newnode=new node(val);
        node* par=nullptr;
        if(root==nullptr)
        {
                cout<<"Root node inserted\n";
                root=newnode;
                return;
        }
        while(cur!=nullptr)
        {
                par=cur;
                if((cur->data) > val)
                        cur=cur->left;
                else if((cur->data) < val )
                        cur=cur->right;
                else
                {
                        cout<<"Unable to insert duplicate element\n";
                        return;
                }
        }
        if((par->data) > val)
                par->left=newnode;
        else if((par->data) < val)
                par->right=newnode;
}
void del()
{
    if (root == nullptr)
    {
        cout << "Tree has no branches, unable to delete\n";
        return;
    }
    int val;
    cout << "Enter the value to be deleted: ";
    cin >> val;
    node* cur = root;
    node* par = nullptr;
    while (cur != nullptr && cur->data != val)
    {
        par = cur;
        if (val < cur->data)
            cur = cur->left;
        else
            cur = cur->right;
    }
    if (cur == nullptr)
    {
        cout << "Element not available to be deleted\n";
        return;
    }
    if (cur->left == nullptr && cur->right == nullptr)
    {
        if (par == nullptr) 
            root = nullptr;
        else if (par->left == cur)
            par->left = nullptr;
        else
            par->right = nullptr;
        delete cur;
        cout << "Leaf node deleted\n";
        return;
    }
    if (cur->left == nullptr || cur->right == nullptr)
    {
        node* child = (cur->left != nullptr) ? cur->left : cur->right;
        if (par == nullptr)
            root = child;
        else if (par->left == cur)
            par->left = child;
        else
            par->right = child;
        delete cur;
        cout << "Node with one child deleted\n";
        return;
    }
    node* suc = cur->right;
    node* sucPar = cur;
    while (suc->left != nullptr)
    {
        sucPar = suc;
        suc = suc->left;
    }
    cur->data = suc->data;
    if (sucPar->left == suc)
        sucPar->left = suc->right;
    else
        sucPar->right = suc->right;
    delete suc;
    cout << "Node with two children replaced and deleted\n";
}
void pre(node* n);
void post(node* n);
void in(node* n);
void display()
{
        if(root==nullptr)
        {
                cout<<"Tree is empty\n";
                return;
        }
        int ck;
        cout<<"Select the traversal method -\n1 - Preorder\n2 - Inorder\n3 - Postorder\nEnter yout choice : ";
        cin>>ck;
        switch(ck)
        {
                case 1 : pre(root);
                         cout<<endl;
                         break;
                case 2 : in(root);
                         cout<<endl;
                         break;
                case 3 : post(root);
                         cout<<endl;
                         break;
                default : cout<<"Invalid entry, exited from traversal\n";
        }
}
void pre(node* n)
{
        if(n==nullptr)
                return;
        cout<<(n->data)<<" ";
        pre(n->left);
        pre(n->right);
}
void in(node* n)
{
        if(n==nullptr)
                return;
        in(n->left);
        cout<<(n->data)<<" ";
        in(n->right);
}
void post(node* n)
{
        if(n==nullptr)
                return;
        post(n->left);
        post(n->right);
        cout<<(n->data)<<" ";
}
int main()
{ int ck;
        while(1)
        {
                cout<<"\nMain menu -\n0 - Exit program\n1 - Insert new node\n2 - Delete node\n3 - Display the tree\nEnter your choice : ";
                cin>>ck;
                switch(ck)
                {
                        case 0 : cout<<"Program terminated\n";
                                 return 0;
                        case 1 : insert();
                                 break;
                        case 2 : del();
                                 break;
                        case 3 : display();
                                 break;
                        default : cout<<"Invalid entry,try again\n";
                }
        }
}
//Completed
