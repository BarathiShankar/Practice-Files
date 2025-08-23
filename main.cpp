#include<iostream>
using namespace std;

struct node {
    int data;
    node* prev;
    node* next;
};

node* head = NULL;

void inserthead() {
    node* newnode = new node;
    cout << "Enter the value to be inserted: ";
    cin >> newnode->data;
    newnode->prev = NULL;
    newnode->next = head;

    if (head != NULL)
        head->prev = newnode;

    head = newnode;
    cout << "Successfully inserted at head\n";
}

void inserttail() {
    node* newnode = new node;
    cout << "Enter the value to be inserted: ";
    cin >> newnode->data;
    newnode->next = NULL;

    if (head == NULL) {
        newnode->prev = NULL;
        head = newnode;
    } else {
        node* cur = head;
        while (cur->next != NULL)
            cur = cur->next;

        cur->next = newnode;
        newnode->prev = cur;
    }
    cout << "Successfully inserted at tail\n";
}

void insertmid() {
    int pos, i = 1;
    cout << "Enter the value to be inserted: ";
    node* newnode = new node;
    cin >> newnode->data;
    newnode->next = NULL;
    newnode->prev = NULL;

    cout << "Enter the position to be inserted (from index 1): ";
    cin >> pos;

    if (pos <= 1 || head == NULL) {
        inserthead();
        return;
    }

    node* cur = head;
    while (cur != NULL && i < pos) {
        cur = cur->next;
        i++;
    }

    if (cur == NULL) {
        inserttail();
        return;
    }

    newnode->next = cur;
    newnode->prev = cur->prev;
    if (cur->prev != NULL)
        cur->prev->next = newnode;
    cur->prev = newnode;

    if (pos == 1)
        head = newnode;

    cout << "Successfully inserted at position " << pos << endl;
}

void dlthead() {
    if (head == NULL) {
        cout << "List is empty, unable to delete head\n";
        return;
    }

    node* temp = head;
    int val = temp->data;
    head = head->next;

    if (head != NULL)
        head->prev = NULL;

    delete temp;
    cout << "Successfully deleted " << val << " from head\n";
}

void dlttail() {
    if (head == NULL) {
        cout << "List is empty, unable to delete tail\n";
        return;
    }

    node* cur = head;
    if (cur->next == NULL) {
        int val = cur->data;
        delete cur;
        head = NULL;
        cout << "Successfully deleted " << val << " from tail\n";
        return;
    }

    while (cur->next != NULL)
        cur = cur->next;

    int val = cur->data;
    cur->prev->next = NULL;
    delete cur;
    cout << "Successfully deleted " << val << " from tail\n";
}

void dltmid() {
    int pos, i = 1;
    cout << "Enter the position to be deleted (as index 1): ";
    cin >> pos;

    if (head == NULL || pos <= 1) {
        dlthead();
        return;
    }

    node* cur = head;
    while (cur != NULL && i < pos) {
        cur = cur->next;
        i++;
    }

    if (cur == NULL) {
        cout << "Out of bounds condition\nActivating tail deletion\n";
        dlttail();
        return;
    }

    int val = cur->data;
    if (cur->prev != NULL)
        cur->prev->next = cur->next;
    if (cur->next != NULL)
        cur->next->prev = cur->prev;

    delete cur;
    cout << "Successfully deleted " << val << " from position " << pos << endl;
}

void disp() {
    if (head == NULL) {
        cout << "List is empty\n";
        return;
    }

    node* cur = head;
    cout << "List elements: ";
    while (cur != NULL) {
        cout << cur->data << "\t";
        cur = cur->next;
    }
    cout << endl;
}

void search() {
    int key, pos = 1, found = 0;
    cout << "Enter the element to be searched: ";
    cin >> key;

    node* cur = head;
    while (cur != NULL) {
        if (cur->data == key) {
            cout << "Element found at position: " << pos << endl;
            found = 1;
        }
        cur = cur->next;
        pos++;
    }

    if (!found)
        cout << "Element not found\n";
}

int main() {
    int o, so;
    while (true) {
        cout << "\nProgram to implement a doubly linked list\nMenu -\n";
        cout << "0. Exit program\n1. Insert node\n2. Delete node\n3. Search data\n4. Print list\nEnter your choice: ";
        cin >> o;

        switch (o) {
            case 0:
                cout << "Program terminated\n";
                return 0;

            case 1:
                while (true) {
                    cout << "Where to insert -\n1. Head\n2. Middle\n3. Tail\n4. Exit insertion\nEnter your choice: ";
                    cin >> so;
                    if (so == 1) inserthead();
                    else if (so == 2) insertmid();
                    else if (so == 3) inserttail();
                    else if (so == 4) break;
                    else cout << "Invalid entry, try again\n";
                }
                break;

            case 2:
                while (true) {
                    cout << "Where to delete -\n1. Head\n2. Middle\n3. Tail\n4. Exit deletion\nEnter your choice: ";
                    cin >> so;
                    if (so == 1) dlthead();
                    else if (so == 2) dltmid();
                    else if (so == 3) dlttail();
                    else if (so == 4) break;
                    else cout << "Invalid entry, try again\n";
                }
                break;

            case 3:
                search();
                break;

            case 4:
                disp();
                break;

            default:
                cout << "Invalid entry, try again\n";
        }
    }
}
