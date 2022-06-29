#include <iostream>
#include <setjmp.h>
jmp_buf env;
void print(int n);
void Foo(int z);
void Bar(int w);
int main()
{
	int s = 0;
	if(s == 0) //first time
	{
		s = _setjmp(env);
		Foo(s);
	}
	else
	{
		Bar(2);
	}
}

void print(int n) {
	std::cout << n << "\n";
}

void Foo(int z)
{
	int x = 2;
	print(x + z);
	longjmp(env, 100);
}

void Bar(int w)
{
	int y = 3;
	print(y - w);
}
