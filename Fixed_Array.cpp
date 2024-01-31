// $Id: Fixed_Array.cpp 827 2011-02-07 14:20:53Z hillj $

// Honor Pledge:
//
// I pledge that I have neither given nor received any help
// on this assignment.

//
// Fixed_Array
//
template <typename T, size_t N>
Fixed_Array <T, N>::Fixed_Array (void)
:Array_Base<T>::Array_Base(N)
{

}

//
// Fixed_Array
//
template <typename T, size_t N>
Fixed_Array <T, N>::Fixed_Array (const Fixed_Array <T, N> & arr)
: Array_Base<T>::Array_Base(arr)
{
	
}

//
// Fixed_Array
//
template <typename T, size_t N>
template <size_t M>
Fixed_Array <T, N>::Fixed_Array (const Fixed_Array <T, M> & arr)
:Array_Base<T>::Array_Base(M)
{
    if (M<N)
	{
		for (size_t i = 0; i < M; i++)
		{
			this->operator[](i)=arr[i];
		}
	}
	else
	{
		for (size_t i = 0; i < N; i++)
		{
			this->operator[](i)=arr[i];
		}
	}	
}

//
// Fixed_Array
//
template <typename T, size_t N>
Fixed_Array <T, N>::Fixed_Array (T fill)
:Array_Base<T>::Array_Base(N,fill)
{
}

//
// ~Fixed_Array
//
template <typename T, size_t N>
Fixed_Array <T, N>::~Fixed_Array (void)
{
}

//
// operator =
//
template <typename T, size_t N>
const Fixed_Array <T, N> & Fixed_Array <T, N>::operator = (const Fixed_Array <T, N> & rhs)
{
    Array_Base::=(rhs);
}

//
// operator =
//
template <typename T, size_t N>
template <size_t M>
const Fixed_Array <T, N> & Fixed_Array <T, N>::operator = (const Fixed_Array <T, M> & rhs)
{
    this->max_size_=M;
    this->cur_size_=M;
    Array_Base::=(rhs);
}
