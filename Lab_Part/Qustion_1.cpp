/* QUESTION: If Mr. Rimon accesses the 5 web pages consecutively and 1 web page
is needed to be removed between the 3 and 5 no. web pages. Therefore how
Mr. Rimon is displayed in the mentioned scenario
AUTHOR: MD. SAMI ALAM 
ID: 222-16-656
*/

#include <iostream>
using namespace std;
// GLOBAL DECLARATION
struct Node
{
    int data;
    struct Node *next;
};
struct Node *head = NULL;

// FUNCTION DECLARATION
void Create_Single_Link_List();
void Display_Single_Link_List();
void Delete_At_Given_position();

// MAIN FUNCTION SECTION
int main()
{
    cout << "---------WELCOME TO RIMON'S WEB PAGE---------" << endl;
    Create_Single_Link_List();
    cout << endl;
    cout << "Here is the here is the web pages You've created" << endl;
    Display_Single_Link_List();

    int x;

    cout << "1. Delete At Given Position" << endl;

lebel:
    cout << "Press (1): ";
    cin >> x;
    switch (x)
    {
    case 1:
        Delete_At_Given_position();
        break;
    default:
        cout << "Invalid Input!!!" << endl;
        goto lebel;
        break;
    }
    return 0;
}

// FUNCTION DEFINITION SECTION
void Create_Single_Link_List()
{
    struct Node *new_node, *temp;
    int num;
    cout << "Enter the Number of web page & if you want to close press(0): ";
    cin >> num;

    while (num != 0)
    {
        new_node = (struct Node *)malloc(sizeof(struct Node));
        new_node->data = num;
        new_node->next = NULL;

        if (head == NULL)
        {
            head = temp = new_node;
        }
        else
        {
            temp->next = new_node;
            temp = new_node;
        }

        cout << "Enter the Number of web page & if you want to close press(0): ";
        cin >> num;
    }
}

void Display_Single_Link_List()
{
    struct Node *temp;
    temp = head;
    int i = 1;

    while (temp != NULL)
    {
        cout << "Web Page " << i++ << ": " << temp->data << endl;
        temp = temp->next;
    }
}
// Function for Deleting In the the position
void Delete_At_Given_position()
{
    struct Node *temp;
    struct Node *next_node;
    int i = 1, position;
    temp = head;
    cout << "Enter the Web Page position that you wanna delete: "
         << " ";
    cin >> position;
    while (i < position - 1)
    {
        temp = temp->next;
        i++;
    }
    next_node = temp->next;       // for delete
    temp->next = next_node->next; // 1st node and last node
    free(next_node);
    cout << endl;
    cout << "After Deleting the Web Page New List is Here......." << endl;
    Display_Single_Link_List();
}