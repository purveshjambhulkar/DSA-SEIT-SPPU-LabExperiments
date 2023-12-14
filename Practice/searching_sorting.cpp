#include <iostream>
#include <string.h>
using namespace std;

// Implementation of Searching Sorting Algorithms
/*Consider a student database of SEIT class (at least 15 records). Database contains
different fields of every student like Roll No, Name and SGPA.(array of structure)
a) Design a roll call list, arrange list of students according to roll numbers in
ascending order (Use Bubble Sort)
b) Arrange list of students alphabetically. (Use Insertion sort)
c) Arrange list of students to find out first ten toppers from a class. (Use Quick
sort)
d) Search students according to SGPA. If more than one student having same
SGPA, then print list of all students having same SGPA.
e) Search a particular student according to name using binary search
 without recursion. (all the student records having the presence of
 search key should be displayed) */

struct stud
{
    int roll_num;
    char name[20];
    float SGPA;
};

int size = 0;

void CreateDatabase(stud s[10], int &size)
{
    cout << "Enter how many Students Data you want to enter : ";
    cin >> size;
    for (int i = 0; i < size; i++)
    {
        cout << "Enter name : ";
        cin >> s[i].name;
        cout << "Enter RollNo : ";
        cin >> s[i].roll_num;
        cout << "Enter SGPA : ";
        cin >> s[i].SGPA;
    }
    cout << endl
         << "Database Created Succesfully" << endl;
}

void DisplayDatabase(stud s[10], int &size)
{
    cout << "Displaying the Database\n";

    for (int i = 0; i < size; i++)
    {
        cout << "Name : " << s[i].name << "| Roll No : " << s[i].roll_num << "| SGPA : " << s[i].SGPA << endl;
    }
    cout << endl;
}

// arrange list of students according to roll numbers in ascending order (Use Bubble Sort)

void BubbleSort(stud s[10], int size)
{
    stud temp;
    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < size - 1; j++)
        {
            if (s[j].roll_num > s[j + 1].roll_num)
            {
                temp = s[j];
                s[j] = s[j + 1];
                s[j + 1] = temp;
            }
        }
    }
}

// Arrange list of students alphabetically. (Use Insertion sort)

void insertion_sort(stud s[10], int size)
{

    for (int i = 1; i < size; i++)
    {
        int j = i - 1;
        stud key = s[i];
        while (j >= 0 && strcmp(s[j].name, key.name) > 0)
        {
            s[j + 1] = s[j];
            j--;
        }
        s[j + 1] = key;
    }
}

// Arrange list of students to find out first ten toppers from a class. (Use Quicksort)

int partition(stud s[10], int start, int end)
{
    stud pivot = s[start];
    int count = 0;
    for (int i = start + 1; i <= end; i++)
    {
        if (pivot.SGPA >= s[i].SGPA)
        {
            count++;
        }
    }
    int partitionindex = count + start;
    return partitionindex;
}

void quick_sort(stud s[10], int start, int end)
{

    // base case
    if (start >= end)
    {
        return;
    }

    int p = partition(s, start, end);

    // recursive call for half part
    quick_sort(s, start, p - 1);
    // other half part
    quick_sort(s, p + 1, end);
}

// Search students according to SGPA. If more than one student having same SGPA, then print list of all students having same SGPA.

void linearsearch(stud s[10], int size, float SGPA)
{

    // brute force
    bool flag = false;
    for (int i = 0; i < size; i++)
    {
        if (s[i].SGPA == SGPA)
        {
            flag = true;
            cout << "Name : " << s[i].name << "| Roll No : " << s[i].roll_num << "| SGPA : " << s[i].SGPA << endl;
        }
    }

    if (flag)
    {
        cout << "These Records were Found" << endl;
    }
    else
    {
        cout << "No Records found for SGPA : " << SGPA << endl;
    }
}

/*Search a particular student according to name using binary search
 without recursion. (all the student records having the presence of
 search key should be displayed) */

int binarySearch(stud s[10], int low, int high, char key[20])
{

    int mid = low + (high - low) / 2;

    while (low <= high)
    {

        if (strcmp(key, s[mid].name) == 0)
        {
            return mid;
        }

        if (strcmp(key, s[mid].name) > 0)
        {
            low = mid + 1;
        }

        if (strcmp(key, s[mid].name) < 0)
        {
            high = mid - 1;
        }

        mid = low + (high - low) / 2;
    }
    return -1;
}

int main()
{
    stud s[10];
    int size;

    while (true)
    {
        cout << "Enter which operation you want to perform" << endl;
        cout << "1 - CreateDatabase\n"
             << "2 - DisplayDatabase\n"
             << "3 - BubbleSort\n"
             << "4 - InsertionSort\n"
             << "5 - Quicksort\n"
             << "6 - linearSearch\n"
             << "7 - BinarySearch\n"
             << "-1 - Exit\n"
             << endl;

        int op;
        cout << "Enter which operation you want perform : ";
        cin >> op;

        if (op == -1)
        {
            break;
        }

        switch (op)
        {
        case 1:
            CreateDatabase(s, size);
            break;
        case 2:
            DisplayDatabase(s, size);
            break;
        case 3:
            BubbleSort(s, size);
            cout << endl
                 << "Displaying Data after BubbleSort\n";
            DisplayDatabase(s, size);
            break;
        case 4:
            insertion_sort(s, size);
            cout << endl
                 << "Displaying Data after InsertionSort\n";
            DisplayDatabase(s, size);
            break;
        case 5:
            quick_sort(s, 0, size - 1);
            cout << endl
                 << "Displaying Data after quickSort\n";
            DisplayDatabase(s, size);
            break;
        case 6:
            cout << "Enter the SGPA you want to Search : ";
            float z;
            cin >> z;
            linearsearch(s, size, z);
            break;

        case 7:
            char temp[20];
            cout << "Enter the name you want to search : ";
            cin >> temp;
            int mid = binarySearch(s, 0, size - 1, temp);
            if (mid == -1)
            {
                cout << "No Record Found" << endl;
            }
            else
            {
                cout << "Name : " << s[mid].name << "| Roll No : " << s[mid].roll_num << "| SGPA : " << s[mid].SGPA << endl;
            }

            break;

        default:
            break;
        }
    }
}