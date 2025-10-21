#include <iostream>
using namespace std;

struct Node
{
    int data;
    Node *next;
    Node(int val)
    {
        data = val;
        next = NULL;
    }
};

void printList(Node *head)
{
    while (head != NULL)
    {
        cout << head->data << " ";
        head = head->next;
    }
    cout << endl;
}

Node *getTail(Node *curr)
{
    while (curr != NULL && curr->next != NULL)
    {
        curr = curr->next;
    }
    return curr;
}

Node *partition(Node *head, Node *end, Node **newHead, Node **newEnd)
{
    Node *pivot = end;
    Node *prev = NULL;
    Node *curr = head;
    Node *tail = pivot;
    while (curr != pivot)
    {
        if (curr->data < pivot->data)
        {
            if ((*newHead) == NULL)
            {
                (*newHead) = curr;
            }
            prev = curr;
            curr = curr->next;
        }
        else
        {
            if (prev)
            {
                prev->next = curr->next;
            }
            Node *tmp = curr->next;
            curr->next = NULL;
            tail->next = curr;
            tail = curr;
            curr = tmp;
        }
    }
    if ((*newHead) == NULL)
    {
        (*newHead) = pivot;
    }
    (*newEnd) = tail;
    return pivot;
}

Node *quickSortRecur(Node *head, Node *end)
{
    if (!head || head == end)
    {
        return head;
    }
    Node *newHead = NULL;
    Node *newEnd = NULL;
    Node *pivot = partition(head, end, &newHead, &newEnd);
    if (newHead != pivot)
    {
        Node *tmp = newHead;
        while (tmp->next != pivot)
        {
            tmp = tmp->next;
        }
        tmp->next = NULL;
        newHead = quickSortRecur(newHead, tmp);
        Node *tail = getTail(newHead);
        tail->next = pivot;
    }
    pivot->next = quickSortRecur(pivot->next, newEnd);
    return newHead;
}

void quickSort(Node **headRef)
{
    (*headRef) = quickSortRecur(*headRef, getTail(*headRef));
}

void addNode(Node *&head, int val)
{
    Node *newNode = new Node(val);
    if (head == NULL)
    {
        head = newNode;
        return;
    }
    Node *temp = head;
    while (temp->next != NULL)
    {
        temp = temp->next;
    }
    temp->next = newNode;
}

int main()
{
    Node *head = NULL;
    addNode(head, 10);
    addNode(head, 7);
    addNode(head, 8);
    addNode(head, 9);
    addNode(head, 1);
    addNode(head, 5);
    addNode(head, 3);
    cout << "Original List:\n";
    printList(head);
    quickSort(&head);
    cout << "\nSorted List:\n";
    printList(head);
    return 0;
}
