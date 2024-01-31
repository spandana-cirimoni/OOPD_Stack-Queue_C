// $Id: Stack.cpp 827 2011-02-07 14:20:53Z hillj $

// Honor Pledge:
//
// I pledge that I have neither given nor received any help
// on this assignment.
//
// Stack
//
template <typename T>
Stack <T>::Stack (void):
top_(-1),
stack_max_size_(0)
{
}

//
// Stack
//
template <typename T>
Stack <T>::Stack (const Stack & stack):
top_(stack.top_),
stack_max_size_(stack.max_size_)
{
    stack_data_.resize(stack.stack_max_len_);
    if(!(stack.is_empty())){
        for(int i=0;i<stack.top_;i++){
            stack_data_[i]=stack.stack_data_[i];
        }
    }
}

//
// ~Stack
//
template <typename T>
Stack <T>::~Stack (void)
{
    top_=-1;
}

//
// push
//
template <typename T>
void Stack <T>::push (T element)
{
    if(this->is_empty())
    {
        stack_data_.resize(10);
    }
    top_++;
    stack_data_.set(top_,element);
}

//
// pop
//
template <typename T>
void Stack <T>::pop (void)
{
    if(((int)this->top_)>-1)
    {
        top_--;
    }
    else{
        throw empty_exception();
    }
}

//
// operator =
//
template <typename T>
const Stack <T> & Stack <T>::operator = (const Stack & rhs)
{
    if(this->stack_data_!=rhs.stack_data_){
        this->top_=rhs.top_;
        this->stack_max_size_=rhs.stack_max_size_;
        for(int i=0;i<rhs.top_;i++){
            stack_data_[i]=rhs.stack_data_[i];
        }
    }
    return *this;
}

//
// clear
//
template <typename T>
void Stack <T>::clear (void)
{
    if(!(this->is_empty()))
    {
        top_=-1;
    }
}
