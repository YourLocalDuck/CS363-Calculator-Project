//
// Defauit Constructor
//
template <typename T>
Array_Base<T>::Array_Base(void)
	: cur_size_(defaultSize),
	  data_(nullptr)
{
	//data_ = new T[defaultSize];
}

//
// Copy Constructor
//
template <typename T>
Array_Base<T>::Array_Base(const Array_Base &arr)
	: cur_size_(arr.size()),
	  data_(nullptr)
{
	data_ = new T[arr.size()];
	for (size_t i = 0; i < arr.size(); i++)
	{
		data_[i] = arr.get(i);
	}
}

//
// Destructor. Delete the Data assigned on the heap.
//
template <typename T>
Array_Base<T>::~Array_Base(void)
{
	if (data_ != nullptr)
	{
		delete[] data_;
		data_ = nullptr;
	}

}

//
// Return the element at the given index from the array.
//
template <typename T>
T &Array_Base<T>::operator[](size_t index)
{
	if (index < cur_size_)
	{
		return data_[index];
	}
	else
	{
		throw std::out_of_range("Out of Range");
	}
}

//
// Return the element at the given index from the array. Constant
//
template <typename T>
const T &Array_Base<T>::operator[](size_t index) const
{
	if (index < cur_size_)
	{
		return data_[index];
	}
	else
	{
		throw std::out_of_range("Out of Range");
	}
}

//
// Return the element at the given index from the array.
//
template <typename T>
T Array_Base<T>::get(size_t index) const
{
	if (index < cur_size_)
	{
		return data_[index];
	}
	else
	{
		throw std::out_of_range("Out of Range");
	}
}

//
// Given an element and index, Modify data_ such that the element at index gets value.
//
template <typename T>
void Array_Base<T>::set(size_t index, T value)
{
	if (index < cur_size_)
	{
		data_[index] = value;
	}
	else
	{
		throw std::out_of_range("Out of Range");
	}
}

//
// Traverse the array and find the element value.
//
template <typename T>
int Array_Base<T>::find(T value) const
{
	for (int i = 0; i < cur_size_; i++)
	{
		if (value == data_[i])
		{
			return i;
		}
	}
	return -1;
}

//
// Traverse the array from start and find the element val.
//
template <typename T>
int Array_Base<T>::find(T val, size_t start) const
{
	if (start > cur_size_)
	{
		throw std::out_of_range("Out of Range");
	}
	else
	{
		for (int i = start; i < cur_size_; i++)
		{
			if (val == data_[i])
			{
				return i;
			}
		}
		return -1;
	}
}

//
// Return true of this has the same size AND elements as rhs. If not, return false.
//
template <typename T>
bool Array_Base<T>::operator==(const Array_Base &rhs) const
{
	if (this == &rhs)
	{
		return true;
	}
	if (rhs.size() == this->cur_size_)
	{
		for (int i = 0; i < this->cur_size_; i++)
		{
			if (data_[i] != rhs.get(i))
			{
				return false;
			}
		}
		return true;
	}
	return false;
}

//
// If size or any element is not the same from this and rhs, return true. else return false.
//
template <typename T>
bool Array_Base<T>::operator!=(const Array_Base &rhs) const
{
	if (this->operator==(rhs))
	{
		return false;
	}
	return true;
}

//
// Traverse through the entire array and set every single element to T.
//
template <typename T>
void Array_Base<T>::fill(T value)
{
	for (int i = 0; i < this->cur_size_; i++)
	{
		data_[i] = value;
	}
}

//
// Using a temporary variable, reverse the position of every element in the array.
//
template <typename T>
void Array_Base<T>::reverse(void)
{
	T tempvar;
	int index = (this->cur_size_ - 1);
	for (int i = 0; i < index; i++)
	{
		tempvar = data_[i];
		data_[i] = data_[index];
		data_[index] = tempvar;
		index--;
	}
}
