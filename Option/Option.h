#pragma once
// ���� � habr https://habr.com/ru/post/544636/
enum OptionStatus
{
	None,
	Some,
};
template<class T>
class Option
{
	T* Data;
public:
	Option();
	Option(T*);
	~Option();

	OptionStatus �ontains();
private:

};

template<class T>
Option<T>::Option()
{
}
template<class T>
Option<T>::Option(T* data):
	Data(data)
{
	// LOGIC
}

template<class T>
Option<T>::~Option()
{
}

template<class T>
OptionStatus Option<T>::�ontains()
{
	if (Data == nullptr)
	{
		return OptionStatus::None;
	}
	return OptionStatus::Some;
}