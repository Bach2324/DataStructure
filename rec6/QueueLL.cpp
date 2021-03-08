#include <iostream>
#include "QueueLL.hpp"

using namespace std;

QueueLL::QueueLL()
{
    queueFront = nullptr;
    queueEnd = nullptr;
}

QueueLL::~QueueLL()
{
    while( !isEmpty() )
        dequeue();
}

bool QueueLL::isEmpty()
{
    /*if(queueFront == nullptr || queueEnd == nullptr)
        return true;
    return false;*/
    return (!queueFront || !queueEnd);
}

// TODO
void QueueLL::enqueue(int key)
{
    // TODO Complete this function, handle the case when you're enqueuing in an empty queue
    Node *nn = new Node;
    nn->key = key;
    nn->next = nullptr;

    if (queueFront == nullptr)      // If enqueuing in empty queue
    {
        queueFront = nn;            // Both pointers will be pointing to the same node
        queueEnd = nn;
    }
    else
    {
        queueEnd->next = nn;
        queueEnd = nn;
    }
}
//TODO
void QueueLL::dequeue()
{
    if(!isEmpty())
    {
        // TODO Complete this function, handle the case when your queue becomes empty after dequeuing
        Node * temp = queueFront;
        queueFront = temp->next;
        delete temp;
    }
    else{
        cout<<"queue is empty. can not deque"<<endl;
    }
}

int QueueLL::peek()
{
    if( !isEmpty() )
        return queueFront->key;
    else
    {
        cout<< " queue is empty. can not peek"<<endl;
        return -1;
    }
    //return 0;
}
