#include <iostream>
using namespace std;

// Circular Queue with Array

int arr[5];
int front = -1;
int rear = -1;
int size = 5;

bool push(int data)
{

    // check whether queue full or not
    if (front == rear + 1 || (front == 0 && rear == size - 1))
    {
        // cout << "Queue OverFlow\n";
        return false;
    }

    // adding the first element to the queue
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
    // check whether the queue is empty or not
    if (front == -1 && rear == -1)
    {
        // cout << "Queue UnderFlow\n";
        return -1;
    }

    int popped = arr[front];

    // popping elements
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

    return popped;
}

void Display()
{
    int iter = front;

    if (iter <= rear)
    {
        for (int i = iter; i <= rear; i++)
        {
            cout << arr[i] << " ";
        }
    }
    else if (rear < iter)
    {
        for (int i = iter; iter < size; i++)
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
    cout << "-----Circular Queue-----\n";
    int op;

    while (true)
    {
        cout << "Which operation you want to perform ?\n";
        cout << "1 - Insert/Enqueue\n"
             << "2 - Delete/Dequeue\n"
             << "3 - Display Queue\n"
             << "4 - Exit\n"
             << endl;
        cout << "Enter Valid Option : ";
        cin >> op;

        if (op == 4)
        {
            break;
        }
        int data;

        switch (op)
        {
        case 1:
            cout << "Inserting element in the Queue\n";
            cout << "Enter the element : ";
            cin >> data;

            if (push(data))
            {
                cout << "Element inserted\n";
            }
            else
            {
                cout << "Queue OverFlow\n";
            }

            cout << endl;
            break;
        case 2:
            cout << "Deleting element in the Queue\n";
            data = pop();
            if (data == -1)
            {
                cout << "Queue Underflow\n"
                     << endl;
                continue;
            }

            cout << "The Deleted element was " << data << endl;
            cout << "Element Deleted\n";
            cout << endl;
            break;
        case 3:
            cout << "Displaying elements in the Queue\n";
            Display();
            cout << endl;
            break;
        }
    }
}