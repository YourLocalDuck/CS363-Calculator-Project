//
// size
//
template <typename T>
inline size_t Queue<T>::size(void) const
{
    return data_->size();
}

//
// max_size
//
template <typename T>
inline size_t Queue<T>::max_size(void) const
{
    return data_->max_size();
}

//
// front
//
template <typename T>
inline T Queue<T>::front(void) const
{
    if (this->is_empty())
    {
        throw empty_exception();
    }
    return front_;
}

//
// is_empty
//
template <typename T>
inline bool Queue<T>::is_empty(void) const
{
    if (size() == 0)
    {
        return true;
    }
    return false;
}