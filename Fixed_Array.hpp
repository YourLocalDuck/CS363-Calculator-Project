// $Id: Fixed_Array.cpp 827 2011-02-07 14:20:53Z hillj $

// Honor Pledge:
//
// I pledge that I have neither given nor received any help
// on this assignment.

//
// Fixed_Array
//

template <typename T, size_t N>
Fixed_Array<T, N>::Fixed_Array(void)
{
    this->cur_size_ = N;
    this->data_ = new T[N];
}

//
// Fixed_Array
//
template <typename T, size_t N>
Fixed_Array<T, N>::Fixed_Array(const Fixed_Array<T, N> &arr)
{
    this->cur_size_ = N;
    this->data_ = new T[N];
    for (int i = 0; i < N; i++)
    {
        this->data_[i] = arr.get(i);
    }
}

//
// Fixed_Array
//
template <typename T, size_t N>
template <size_t M>
Fixed_Array<T, N>::Fixed_Array(const Fixed_Array<T, M> &arr)
{
    this->cur_size_ = N;
    this->data_ = new T[N];
    for (int i = 0; i < this->N; i++)
    {
        this->data_[i] = arr.get(i);
    }
}

//
// Fixed_Array
//
template <typename T, size_t N>
Fixed_Array<T, N>::Fixed_Array(T fill)
{
    this->cur_size_ = N;
    this->data_ = new T[N];
    for (int i = 0; i < N; i++)
    {
        this->data_[i] = fill;
    }
}

//
// ~Fixed_Array
//
template <typename T, size_t N>
Fixed_Array<T, N>::~Fixed_Array(void)
{
    if (this->data_ != nullptr)
    {
        delete[] this->data_;
        this->data_ = nullptr;
    }
}

//
// operator =
//
template <typename T, size_t N>
const Fixed_Array<T, N> &Fixed_Array<T, N>::operator=(const Fixed_Array<T, N> &rhs)
{
    for (int i = 0; i < this->size_; i++)
    {
        this->data_[i] = rhs.get(i);
    }
}

//
// operator =
//
template <typename T, size_t N>
template <size_t M>
const Fixed_Array<T, N> &Fixed_Array<T, N>::operator=(const Fixed_Array<T, M> &rhs)
{
    for (int i = 0; i < this->size_; i++)
    {
        this->data_[i] = rhs.get(i);
    }
}
