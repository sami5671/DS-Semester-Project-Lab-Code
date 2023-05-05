/* QUESTION: FRONT = 2, REAR = 4, QUEUE: —--, A, C, D, —---, —--- [“-----” denotes an
empty memory cell].a) F is added to the queue.
b) Two letters are deleted.
c) K, L, and M are added to the queue.
d) Two letters are deleted.
e) R is added to the queue.
f) Two letters are deleted.
g) S is added to the queue.
h) Two letters are deleted.
i) One letter is deleted.
j) One letter is deleted.
AUTHOR: MD. SAMI ALAM
ID: 222-16-656
*/

#include <iostream>
using namespace std;
#define max_size 6

// Global declaration
char Queue[max_size];
int front = 0, rear = -1, count = 0;

// Function Declaration
bool Is_Full();
bool Is_Null();
void Enqueue();
void Dequeue();
void Display();

// Main Function
int main()
{
    while (1)
    {
        int x;
    level:
        cout << endl;
        cout << "1.Enqueue\t2.Dequeue\t3.Display\t4.Exit\nEnter the choice: "
             << " ";
        cin >> x;
        switch (x)
        {
        case 1:
            Enqueue();
            break;
        case 2:
            Dequeue();
            break;
        case 3:
            Display();
            break;
        case 4:
            exit(0);
            break;
            cout << "INvalid Input!!" << endl;
            goto level;
        default:
            break;
        }
    }
}

// FUNCTION FOR CHECKING THE QUEUE IS EMPTY OR NOT
bool Is_Full()
{
    if (count == 6)
    {
        return true;
    }
    else
    {
        return false;
    }
}

bool Is_Null()
{
    if (count == 0)
    {
        return true;
    }
    else
    {
        return false;
    }
}
// FUNCTION FOR ENQUEUE ELEMENTS
void Enqueue()
{
    if (Is_Full())
    {
        cout << endl;
        cout << "Queue is fulll" << endl;
    }
    else
    {
        if (rear == 5)
        {
            rear = 0;
            char n;
            cout << "Enter the Element: "
                 << " ";
            cin >> n;
            Queue[rear] = n;
            count++;
        }
        else
        {
            char y;
            cout << "Enter the Element: "
                 << " ";
            cin >> y;
            rear++;
            Queue[rear] = y;
            count++;
        }
    }
}
// FUNCTION FOR DEQUEUE
void Dequeue()
{
    if (Is_Null())
    {
        cout << endl;
        cout << "Queue is empty" << endl;
        cout << endl;
    }
    else
    {
        Queue[front] = '\0';
        count--;
        if (front == 5)
        {
            front = 0;
        }
        else
        {
            front++;
        }
    }
}
// FUNCTION FOR PRINTING
void Display()
{
    for (int i = 0; i < 6; i++)
    {
        cout << "---" << endl;
        if (Queue[i] == '0')
        {
            cout << "0"
                 << " ";
        }
        else
        {
            cout << Queue[i] << endl;
        }
    }
    cout << "---" << endl;
}