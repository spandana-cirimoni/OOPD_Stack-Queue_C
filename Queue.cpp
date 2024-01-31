// Honor Pledge:
//
// I pledge that I have neither given nor received any help
// on this assignment.
#include <iostream>
using namespace std;

//
// Queue
//
template <typename T>
Queue <T>::Queue (void):
queue_data_(DEFAULT_SIZE),
front_(-1),
rear_(-1),
queue_max_size_(0)
{
}

//
// Queue
//
template <typename T>
Queue <T>::Queue (const Queue & queue):
queue_data_(queue.queue_data_),
front_(queue.front_),
rear_(queue.rear_),
queue_max_size_(queue.queue_max_size_)
{
    if(!(queue.is_empty())){
        for(int i=queue.front_;i<queue.rear_;i++){
            queue_data_[i]=queue.queue_data_[i];
        }
    }
}

//
// ~Queue
//
template <typename T>
Queue <T>::~Queue (void)
{
    front_=-1;
    rear_=-1;
}

//
// Enqueue
//
template <typename T>
void Queue <T>::enqueue (T element)
{
    if(this->front_==-1 || (this->rear_)==-1)
    {
        queue_data_.resize(10);
        this->front_=0;
        this->rear_=0;
        queue_data_[rear_]=element;
    }
    else{
        rear_++;
        queue_data_[rear_]=element;
    }
}

//
// dequeue
//
template <typename T>
T Queue <T>::dequeue (void)
{
    if(this->front_!=this->rear_+1)
    {
        return this->front_++;
    }
    else{
        throw empty_exception();
    }
}

//
// operator =
//
template <typename T>
const Queue <T> & Queue <T>::operator = (const Queue & rhs)
{
    if(this->queue_data_!=rhs.queue_data_){
        this->front_=rhs.front_;
        this->rear_=rhs.rear_;
        this->queue_max_size_=rhs.queue_max_size_;
        for(int i=rhs.front_;i<rhs.rear_;i++){
            queue_data_[i]=rhs.queue_data_[i];
        }
    }
    return *this;
}

//
// clear
//
template <typename T>
void Queue <T>::clear (void)
{
    if(!(this->is_empty()))
    {
        front_=-1;
        rear_=-1;
    }
}
