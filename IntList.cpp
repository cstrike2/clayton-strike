#include <iostream>
#include <cstdlib>
#include "IntList.h"


using namespace std;

IntList::IntList()
{
    head = NULL; // Initialize head to equal NULL
}

IntList::IntList(const IntList &list1)
{

    ListNode *nodePtr; // nodePtr to iterate through the list

    nodePtr = list1.head; // setting nodePtr equal to head of our original list

    head = nodePtr; // head is equal to a pointer that points to the head of the original list
                    // Basically head of new list is equal to head of old list

    while (nodePtr != NULL)
    {
        nodePtr = nodePtr->next; // As the old list is iterated, new list is updated.
    }

}



void IntList::appendNode(int val)
{
    ListNode *newNode; // node to be inserted
    ListNode *nodePtr; // pointer to iterate through list

    newNode = new ListNode; // these three lines initialize the new node
    newNode->value = val;
    newNode->next = NULL;


    if (!head) // If no head exists
    {
        head = newNode; // Then make the new node the head of the list
    }
    else // If a head does exist
    {
        nodePtr = head; // make nodePtr the head

        while (nodePtr->next != NULL)
        {
            nodePtr = nodePtr->next; // Iterate through the list
        }

        nodePtr->next = newNode; // Insert new node after the last node of the list

    }

}

void IntList::displayList()
{

    ListNode *nodePtr; // nodePtr to iterate through the list

    nodePtr = head; // nodePtr starts at head

    while (nodePtr != NULL) // while loop iterates until the node is NULL
    {
        cout << nodePtr->value << endl; // cout the value of the nodePtr
        nodePtr = nodePtr->next; // go to the next node of the list
    }

}

void IntList::removeByVal(int val)
{
    ListNode *nodePtr; // traverses the list searching for a match
    ListNode *previousNode; // node behind nodePtr

    if (!head) // If theres no head, theres no list to search
    {
        return;
    }

    if (head->value == val) // If the value of the head matches the search value ...
    {
        nodePtr = head->next; // nodePtr is equal to node after head
        delete head; // delete the head
        head = nodePtr; // make the nodePtr the new head
    }

    else
    {
        nodePtr = head; // make our nodePtr the head

        while (nodePtr != NULL && nodePtr->value != val) //iterate thru the list
        {
            previousNode = nodePtr; // make previous node = nodePtr
            nodePtr = nodePtr->next; // push nodePtr to next node
        }

        if (nodePtr) // if there is a nodePtr
        {
            previousNode->next = nodePtr->next; // put previousNode is the position of nodePtr
            delete nodePtr; // delete nodePtr
        }
    }

}

void IntList::removeByPos(int pos)
{
    ListNode *nodePtr; // traverses thru the list
    ListNode *previousNode;

    if (!head) // If theres no head, theres no list
    {
        return;
    }

    if (pos == 1) // if the position is the head
    {
        nodePtr = head->next; // nodePtr equals node after head
        delete head; // delete the head
        head = nodePtr; // nodePtr is the new head
    }

    else //If position is not the head
    {
        nodePtr = head; // make nodePtr the head
        int counter = 1; // counter variable

        while (nodePtr != NULL && counter < pos) // while loop iterates thru the list
        {
            previousNode = nodePtr; // previousNode becomes nodePtr
            nodePtr = nodePtr->next; // nodePtr goes to next node
            counter++; // counter increments
        }

        // If you ran thru the whole while loop without reaching pos
        if (counter < pos)
        {
            cout << "Error. There is no position " << pos << endl;
        }

        if (nodePtr) // if nodePtr exists
        {
            previousNode->next = nodePtr->next; // previousNode now becomes nodePtr
            delete nodePtr; // delete the nodePtr
        }
    }

}

void IntList::insertByPos(int val, int pos)
{
    ListNode *nodePtr; // This pointer traverses the list
    ListNode *previousNode;
    ListNode *newNode;

    // Initialize a node to be inserted into the list
    newNode = new ListNode;
    newNode->value = val;
    newNode->next = NULL;

    // If there is no head, insert the newNode as the head.
    if(!head)
    {
        head = newNode;
    }
    else
    {
        nodePtr = head; // starts the search at the head
        previousNode = NULL; // Initializes previous node to NULL
        int counter = 0; // counter variable

        // Iterate while loop until end of linked list or position is found
        while (nodePtr != NULL && counter != pos)
        {
            previousNode = nodePtr;
            nodePtr = nodePtr->next;
            counter++;
        }

        // If the position is found, then we add the node.
        if (counter == pos)
        {
            if (pos == 0) // To add the node at head if necessary
            {
                head = newNode;
                newNode->next = nodePtr;
            }
            else // To add the node anywhere but the head
            {
                previousNode->next = newNode;
                newNode->next = nodePtr;
            }
        }
    }
}

int IntList::search (int val)
{
    ListNode *nodePtr; // traverses list

    nodePtr = head; // start nodePtr at head

    int counter = 1; // counter variable

    while (nodePtr != NULL)
    {
        if (nodePtr->value == val) // if value matches
        {
            return counter; // return position
        }

        nodePtr = nodePtr->next; // If no match, move forward node

        counter++; // increment counter
    }

    if (nodePtr == NULL) // if no match is found
    {
        return -1;
    }

}

IntList::~IntList()
{


    ListNode *nodePtr = head; // Traverses the list
    ListNode *nextNode; // Points to the next node

    while (nodePtr != NULL) // while loop that iterates thru list
    {
        if (nodePtr->next != NULL) // if next node is not empty
        {
            nextNode = nodePtr->next; // nextNode is equal to next node
            delete nodePtr; // delete current node
            nodePtr = nextNode; // nodePtr is equal to next node
        }
        else // If the next node is empty
        {
            delete nodePtr; // delete the last node
            break;
        }
    }
}
