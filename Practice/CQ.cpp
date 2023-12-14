#include <iostream>
using namespace std;

/*Implement Circular Queue using Array. Perform following operations on it.
a) Insertion (Enqueue)
b) Deletion (Dequeue)
c) Display
(Note: Handle queue full condition by considering a fixed size of a queue.)*/

int arr[5];
int front = -1;
int rear = -1;
int size = 5;

bool push(int data)
{

    // full or not condtiion
    if (front == rear + 1 || (front == 0 && rear == size - 1))
    {
        return false;
    }

    if (front == -1 && rear == -1)
    {
        front = rear = 0;
    }
    else if (front != 0 && rear == size - 1)
    {
        rear = 0;
    }
    else
    {
        rear++;
    }

    arr[rear] = data;
    return true;
}

int pop()
{

    // empty condition
    if (front == -1 && rear == -1)
    {
        return -1;
    }

    int x = arr[front];
    if (front == rear)
    {
        front = rear = -1;
    }
    else if (front == size - 1)
    {
        front = 0;
    }
    else
    {
        front++;
    }
    return x;
}

void Display()
{

    if (front <= rear)
    {
        for (int i = front; i <= rear; i++)
        {
            cout << arr[i] << " ";
        }
    }
    else if (front > rear)
    {
        for (int i = front; i <= size - 1; i++)
        {
            cout << arr[i] << " ";
        }
        for (int i = 0; i <= rear; i++)
        {
            cout << arr[i] << " ";
        }
    }
}

int main()
{
    int del;
    while (true)
    {
        cout << "1 - Insertion\n"
             << "2 - Deletion\n"
             << "3 - Display\n"
             << "4 - Exit\n"
             << endl;
        cout << "Enter which operation you want to perform : ";
        int op;
        cin >> op;
        if (op == 4)
        {
            break;
        }

        switch (op)
        {
        case 1:
            cout << "How many elements you want to enter in the queue : ";
            int ele;
            cin >> ele;
            for (int i = 0; i < ele; i++)
            {
                int temp;
                cout << "Enter the data : ";
                cin >> temp;
                if (push(temp))
                {
                }
                else
                {
                    cout << "Queue OverFlow\n";
                    break;
                }
            }

            break;
        case 2:
            cout << "Deletion" << endl;
            del = pop();
            if (del == -1)
            {
                cout << "Queue Empty" << endl;
            }
            else
            {
                cout << "the deleted element was : " << del << endl;
            }

            break;
        case 3:
            cout << "Displaying Queue" << endl;
            Display();
            break;
        }
    }
}