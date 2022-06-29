#include <iostream>
template<class T>
class Object
{
	T Data;
public:
	Object(T&);
	// Object() { Data(); };
	~Object();

	/*T Get()
	{
		return Data;
	}*/
	T Get()
	{
		return Data;
	}
	Object& operator=(Object& val)
	{
		Data = val.Data;
		return *this;
	}
	Object& operator=(T& val)
	{
		Data = val;
		return *this;
	}
};
class Cat
{
public:
	Cat();
	~Cat();

private:

};

Cat::Cat()
{
}

Cat::~Cat()
{
}

template<class T>
Object<T>::Object(T& data)
{
	Data = data;
}

template<class T>
Object<T>::~Object()
{
	// delete Data;
}
int main()
{
	int a = 5;
	int b = 10;
	Object<int> A(a);
	Object<int> B(b);
	Object<int> C(B);
	B = a;
	// B = A.Get();
	a = A.Get();
	// B = A.Get();
	B = a;
	std::cout << "Hello World!\n";
}
