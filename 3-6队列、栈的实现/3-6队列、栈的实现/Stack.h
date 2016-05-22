#pragma once
template<class T>
class Stack
{
protected:
	T* _array;
	size_t _size;
	size_t _capacity;
public:
	Stack()
		:_array(NULL)
		, _size(0)
		, _capacity(0)
	{}
	~Stack()
	{
		if (_array)
		{
			delete[] _array;
		}
	}
public:
	void Push(const T& x)
	{
		_CheckCapacity();
		_array[_size++] = x;
	}
	void _CheckCapacity()
	{
		if (_size >= _capacity)
		{
			_capacity = 2 * _capacity + 3;
			T*tmp = new T[_capacity];
			for (size_t i = 0; i < _size; i++)
			{
				tmp[i] = _array[i];
			}
			delete[] _array;
			_array = tmp;
		}
	}
	void Pop()
	{
		assert(_size>0);
		--_size;
	}
	const T& Top()
	{
		assert(_size>0);
		/*if (_size <= 0)
		{
			cout << "Õ»Îª¿Õ" << endl;
			return -1;
		}
		else*/
			return _array[_size - 1];
	}
	size_t Size()
	{
		return _size;
	}
	bool Empty()
	{
		return _array == NULL;
	}
};

void Test1()
{
	Stack<int> s;
	s.Push(1);
	s.Push(2);
	s.Push(3);
	s.Push(4);
	s.Push(5);
	while (!s.Empty())
	{
		cout << s.Top() << endl;
		s.Pop();
	}
}