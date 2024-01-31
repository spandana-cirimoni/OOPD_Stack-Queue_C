// $Id: Array.cpp 827 2011-02-07 14:20:53Z hillj $

// Honor Pledge:
//
// I pledge that I have neither given nor receieved any help
// on this assignment.

#include "Array_Base.h"
#include <stdexcept>         // for std::out_of_bounds exception

//
// Array_Base
//
template <typename T>
Array_Base <T>::Array_Base (void):
data_(nullptr),
cur_size_(0),
max_size_(0)
{
    data_=new T[max_size_];
}

//
// Array_Base (size_t)
//
template <typename T>
Array_Base <T>::Array_Base (size_t length):
data_(new T[length]),
cur_size_(length),
max_size_(length)
{
}

//
// Array_Base (size_t, char)
//
template <typename T>
Array_Base <T>::Array_Base (size_t length, T fill):
data_(new T[length]),
cur_size_(length),
max_size_(length)
{
    for(int i=0;i<this->cur_size_;i++){
        this->data_[i]=fill;
    }
}

//
// ~Array_Base
//
template <typename T>
Array_Base <T>::~Array_Base (void)
{
    if(data_!=nullptr)
    {
        delete [] data_;
    }
}


//
// operator []
//
template <typename T>
T & Array_Base <T>::operator [] (size_t index)
{
    if (index < this->max_size_) {
        this->cur_size_=index;
        return this->data_[index];
    }
    throw std::out_of_range ("Array Out of Bound Exception");
}

//
// operator [] 
//
template <typename T>
const T & Array_Base <T>::operator [] (size_t index) const
{
    if (index < this->max_size_) {
        return this->data_[index];
    }
    throw std::out_of_range ("Array Out of Bound Exception");
}

//
// get
//
template <typename T>
T Array_Base <T>::get (size_t index) const
{
    if (index < this->max_size_) {
        return this->data_[index];
    }
    throw std::out_of_range ("Array Out of Bound Exception");
}

//
// set
//
template <typename T>
void Array_Base <T>::set (size_t index, T value)
{
    if (index < this->max_size_) {
        this->data_[index]=value;
    }
    else{
    throw std::out_of_range ("Array Out of Bound Exception");
    }
}

//
// resize
//
template <typename T>
void Array_Base <T>::resize (size_t new_size)
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

//
// find (char)
//
template  <typename T>
int Array_Base <T>::find (T value) const
{
    int flag=-1;
    for(int i=0;i<this->cur_size_;i++){
        if(this->data_[i]==value){
            flag=i;
            break;
        }
    }
    return (flag==-1)? -1 : flag;
}

//
// find (char, size_t) 
//
template <typename T>
int Array_Base <T>::find (T val, size_t start) const
{
    if (start < this->max_size_) {
        int flag=-1;
        for(int i=start;i<this->cur_size_;i++){
        if(this->data_[i]==val){
            flag=i;
            break;
        }
    }
    return (flag==-1)? -1 : flag;
    }
    throw std::out_of_range ("Array Out of Bound Exception");
}

//
// operator ==
//
template <typename T>
bool Array_Base <T>::operator == (const Array_Base & rhs) const
{
    if(cur_size_==rhs.cur_size_){
        for(int i=0;i<this->cur_size_;i++){
            if(this->data_[i]!=rhs.data_[i]){
                return false;
            }
        }
        return true;
    }
    else{
        return false;
    }
}

//
// operator !=
//
template <typename T>
bool Array_Base <T>::operator != (const Array_Base & rhs) const
{
    return !(this==rhs);
}

//
// fill
//
template <typename T>
void Array_Base <T>::fill (T value)
{
    for(int i=0;i<max_size_;i++){
        this->data_[i]=value;
    }
    this->cur_size_=this->max_size_;
}