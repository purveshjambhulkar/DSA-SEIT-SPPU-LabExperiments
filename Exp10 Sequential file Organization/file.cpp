
#include <iostream>
#include <fstream>
using namespace std;
void create();
void display();
int search(int roll);
void add();
void del();
void modify();
int rollno;
char name[10];
char dept[10];
fstream f, r, temp;
int main()
{
    int x = 1, ch;
    while (x)
    {
        cout << "\nWhat you want to do:-\n1. Create\n2. Display\n3. Add\n4. Modify\n5. Delete\n6. Exit\n";
        cin >> ch;
        switch (ch)
        {
        case 1:
            create();
            break;
        case 2:
            display();
            break;
        case 3:
            add();
            break;
        case 4:
            modify();
            break;
        case 5:
            del();
            break;
        case 6:
            x = 0;
            break;
        default:
            cout << "\nPLease enter correct choice!\n";
            break;
        }
    }
}
void modify()
{
    int x, roll;
    cout << "\nEnter roll no:-\n";
    cin >> roll;
    x = search(roll);
    if (x == 1)
    {
        f.open("data.txt", ios::in);
        temp.open("temp.txt", ios::out);
        f >> rollno >> name >> dept;
        while (!f.eof())
        {
            if (roll == rollno)
            {
                cout << "\nEnter name and department:-\n";
                cin >> name >> dept;
                temp << rollno << "\t" << name << "\t" << dept << "\n";
                f >> rollno >> name >> dept;
                continue;
            }
            temp << rollno << "\t" << name << "\t" << dept << "\n";
            f >> rollno >> name >> dept;
        }
        f.close();
        temp.close();
        f.open("data.txt", ios::out);
        temp.open("temp.txt", ios::in);
    }
}
