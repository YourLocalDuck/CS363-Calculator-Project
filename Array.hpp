// $Id: Array.cpp 827 2011-02-07 14:20:53Z hillj $

// Honor Pledge:
//
// I pledge that I have neither given nor receieved any help
// on this assignment.

//#include "Array.h"


//
// Array
//
template <typename T>
Array<T>::Array(void)
{
	this->max_size_ = this->cur_size_;
	this->data_ = new T[this->max_size_];
}

//
// Array (size_t)
//
template <typename T>
Array<T>::Array(size_t length)
{
	this->cur_size_ = length;
	this->max_size_ = length;
	this->data_ = new T[this->max_size_];
}

//
// Array (size_t, char)
//
template <typename T>
Array<T>::Array(size_t length, T fill)
{
	this->cur_size_ = length;
	this->max_size_ = length;
	this->data_ = new T[this->max_size_];
	for (int i = 0; i < this->cur_size_; i++)
	{
		this->data_[i] = fill;
	}
}

//
// Array (const Array &)
//
template <typename T>
Array<T>::Array(const Array &array)
{
	this->cur_size_ = array.size();
	this->max_size_ = this->cur_size_;
	this->data_ = new T[array.size()];
	for (size_t i = 0; i < array.size(); i++)
	{
		this->data_[i] = array.get(i);
	}
}

//
// ~Array
//
template <typename T>
Array<T>::~Array(void)
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
template <typename T>
const Array<T> &Array<T>::operator=(const Array &rhs)
{
	if (this == &rhs)
	{
		return *this;
	}
	if (this->cur_size_ != rhs.cur_size_)
	{
		if (this->cur_size_ < rhs.cur_size_)
		{
			T *newdata_ = rawResizeToLarger(rhs.cur_size_);
			delete[] this->data_;
			this->data_ = newdata_;
			this->max_size_ = this->cur_size_;
		}
		else if (this->cur_size_ > rhs.cur_size_)
		{
			this->cur_size_ = rhs.cur_size_;
		}
	}
	for (int i = 0; i < rhs.cur_size_; i++)
	{
		this->set(i, rhs.get(i));
	}
	return *this;
}

//
// resize
//
template <typename T>
void Array<T>::resize(size_t new_size)
{
	if (new_size <= this->max_size_)
	{
		this->cur_size_ = new_size;
	}
	else if (new_size > this->max_size_)
	{
		T *newdata_ = rawResizeToLarger(new_size);
		T *olddata_ = this->data_;
		this->data_ = newdata_;

		for (int i = 0; i < this->max_size_; i++)
		{
			this->data_[i] = olddata_[i];
		} // Old Data is copied over to data_
		this->max_size_ = new_size;
		delete[] olddata_; // Old Data is freed
	}
	else
	{
	}
}

template <typename T>
T *Array<T>::rawResizeToLarger(size_t new_size) // Helper method to modify the size of an array if the new size is greater than max_size_. This method exists because it does not touch data at all, it will only make a new array of char of the needed size and return it.
{
	if (new_size > this->max_size_)
	{
		this->cur_size_ = new_size;
		T *newdata_ = new T[new_size]; // data_ now points to a new character array, while the old data still remains for now
		return newdata_;
	}
	return this->data_;
}
