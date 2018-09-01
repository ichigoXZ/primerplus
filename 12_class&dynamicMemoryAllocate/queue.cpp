#include "queue.h"
#include <cstdlib>

// customer method

// when is the time at which the customer arrives
// the arrival time is set to when and the processing
// time set to a random value in the range 1 - 3
void Customer::set(long when) {
    arrive = when;
    processtime = std::rand() % 3 + 1;
}

// Queue methods
Queue::Queue(int qs):qsize(qs) {
    front =  rear = nullptr;
    items = 0;
}

Queue::~Queue() {
    Node * temp;
    while(front != NULL){
        temp = front;
        front = front->next;
        delete temp;
    }
}

bool Queue::isempty() const {
    return items == 0;
}

bool Queue::isfull() const {
    return items == qsize;
}

int Queue::queuecount() const {
    return items;
}

bool Queue::enqueue(const Item &item) {
    if (isfull())
        return false;
    Node *temp = new Node;
    temp->item = item;
    temp->next = NULL;
    items ++;
    if (front == NULL)
        front = temp;
    else
        rear->next= temp;
    rear = temp;
    return true;
}

bool Queue::dequeue(Item &item) {
    if (front==NULL)
        return false;
    item = front->item;
    Node * temp = front;
    front = temp->next;
    delete temp;
    items--;
    if(items==0)
        rear = NULL;
    return true;
}



