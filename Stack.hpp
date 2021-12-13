// $Id: Stack.cpp 827 2011-02-07 14:20:53Z hillj $

// Honor Pledge:
//
// I pledge that I have neither given nor received any help
// on this assignment.

//
// Stack
//

template <typename T>
Stack<T>::Stack(void)
    : data_(nullptr)
{
    data_ = new Array<T>();
    this->clear();
}

//
// Stack
//
template <typename T>
Stack<T>::Stack(const Stack &stack)
    : data_(nullptr)
{
    data_ = new Array<T>(stack.size());
    for (size_t i = 0; i < this->size(); i++)
    {
        data_->set(i, stack.data_->get(i));
    }
    top_ = stack.top();
}

//
// ~Stack
//
template <typename T>
Stack<T>::~Stack(void)
{
    delete data_;
}

//
// push
//
template <typename T>
void Stack<T>::push(T element)
{
    data_->resize(size() + 1);
    data_->set((size() - 1), element);
    top_ = element;

    // Old C Array implementation
    /*size_++;
    if (this->size_ > this->max_size_)
    {
        T *newData_ = new T[size_];
        T *oldData = data_;
        data_ = newData_;

        for (int i = 0; i < max_size_; i++)
        {
            data_[i] = oldData[i];
        }
        max_size_++;
        delete[] oldData;
    }
    top_ = element;
    data_[size_ - 1] = element;*/
}

//
// pop
//
template <typename T>
void Stack<T>::pop(void)
{
    if (size() == 0)
    {
        throw empty_exception();
    }
    data_->resize(size() - 1);
    /*if (size() == 0)
    {
        top_ = 0;
        return;
    }*/
    if (!this->is_empty())
        top_ = data_->get(size() - 1);

    // Old C Array implementation
    /*if (size_ == 0)
    {
        throw empty_exception();
    }
    size_--;
    if (size_ == 0)
    {
        return;
    }
    top_ = data_[size_ - 1];*/
}

//
// operator =
//
template <typename T>
const Stack<T> &Stack<T>::operator=(const Stack &rhs)
{
    if (this == &rhs)
    {
        return *this;
    }
    data_->resize(rhs.size());
    for (size_t i = 0; i < this->size(); i++)
    {
        data_->set(i, rhs.data_->get(i));
    }
    top_ = rhs.top();

    return *this;
    /*this->clear();
    for (int i = 0; i < rhs.size(); i++)
    {
        this->push(rhs.top());
        data_.set(i, rhs.data_->get(i));
    }
    top_ = rhs.top();*/
}

//
// clear
//
template <typename T>
void Stack<T>::clear(void)
{
    data_->resize(0);
    //top_ = 0;
}
