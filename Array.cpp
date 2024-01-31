#include "Array.h"
#include <stdexcept>   

//
// Array (const Array &)
// copy constructor
//
template <typename T>
Array <T>::Array (const Array & array)
{
    this->cur_size_=array.cur_size_;
    this->max_size_=array.max_size_;
    for(int i=0;i<this->cur_size_;i++){
        this->data_[i]=array.data_[i];
    }
}

//
// operator =
//
template <typename T>
const Array <T> & Array <T>::operator = (const Array & rhs)
{
    if(*this!=rhs){
        T *temp=new T[rhs.cur_size_];
        this->max_size_=rhs.max_size_;
        this->cur_size_=rhs.cur_size_;
        for(int i=0;i<this->cur_size_;i++){
            temp[i]=rhs.data_[i];
        }
        for(int i=0;i<this->cur_size_;i++){
            this->data_[i]=temp[i];
        }
    }
    return *this;
}


//
// resize
//
template <typename T>
void Array <T>::resize (size_t new_size)
{
    if(new_size!=this->cur_size_)
    {
        if(new_size>this->max_size_){
            T * resize_data_=new T[new_size];
            for(int i=0;i<this->cur_size_;i++){
                resize_data_[i]=this->data_[i];
            }
            delete[] this->data_;
		    this->data_ = new T[new_size];
		    this->max_size_ = new_size;
		    this->cur_size_ = new_size;
		    for (int i = 0; i < new_size; i++)
		    {
			    this->data_[i] = resize_data_[i];
		    }
		    delete[] resize_data_;
        }
    } 
}
