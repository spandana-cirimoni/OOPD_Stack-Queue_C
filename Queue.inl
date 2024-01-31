// Honor Pledge:
//
// I pledge that I have neither given nor received any help on
// this assignment.

//
// size
//
template <typename T>
inline
size_t Queue <T>::size (void) const
{
    if(rear_==-1 && front_==-1)
    {
        return 0;
    }
    else{
        return (this->rear_-this->front_)+1;
    }
}

//
// is_empty
//
template <typename T>
inline
bool Queue <T>::is_empty (void) const
{
    return (this->rear_==this->front_)? true : false;
}
