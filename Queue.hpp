template <typename T>
Queue<T>::Queue(void)
    : data_(nullptr),
      front_(0)
{
    data_ = new Array<T>();
    this->clear();
}

template <typename T>
Queue<T>::Queue(const Queue &q)
    : data_(nullptr),
      front_(0)
{
    data_ = new Array<T>(q.size());
    for (size_t i = 0; i < this->size(); i++)
    {
        data_->set(i, q.data_->get(i));
    }
}

template <typename T>
Queue<T>::~Queue(void)
{
    delete data_;
}

template <typename T>
const Queue<T> &Queue<T>::operator=(const Queue &rhs)
{
    if (this == &rhs)
    {
        return *this;
    }
    this->clear();
    for (int i = 0; i < rhs.size(); i++)
    {
        this->enqueue(rhs.data_->get(i));
    }
    return *this;
}

template <typename T>
void Queue<T>::enqueue(T element)
{
    data_->resize(data_->size() + 1);
    data_->set((data_->size() - 1), element);
    front_ = data_->get(0);

    // Old C array implementation
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
    data_[size_ - 1] = element;
    front_ = data_[0];*/
}

template <typename T>
T Queue<T>::dequeue(void)
{
    if (data_->size() == 0)
    {
        throw empty_exception();
    }
    T toReturn = data_->get(0);
    for (int i = 0; i < (size() - 1); i++)
    {
        data_->set(i, data_->get(i + 1));
    }
    front_ = data_->get(0);
    data_->resize(data_->size() - 1);
    return toReturn;
    // Old C array Implementation
    /*if (size_ == 0)
    {
        throw empty_exception();
    }
    T toReturn = data_[0];
    for (int i = 0; i < (size_ - 1); i++)
    {
        data_[i] = data_[i + 1];
    }
    size_--;
    front_ = data_[0];
    return toReturn;*/
}

template <typename T>
void Queue<T>::clear(void)
{
    data_->resize(0);
}