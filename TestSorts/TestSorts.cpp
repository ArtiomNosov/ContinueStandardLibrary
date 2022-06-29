#include "pch.h"
/*
*	TestSorts.cpp
*	Version 0.1
*	Author: Nosov Artiom
*	Company: Continue
*	Email: artiom-nj@mail.ru
*/
// EXPECT_EQ(1, 1);
#include <vector>
#include "../Sorts/Sorts.h"
int cmpInt(int& a, int& b) {
	if (a > b)
		return 1;
	else if (a < b)
		return -1;
	else
		return 0;
}
template<typename T, typename Container>
int checkSorted(Container& cont, int (*cmp)(T&, T&))
{
	int size = cont.size();
	int res = true;
	for (int i = 0; i < size - 1; i++)
		if (cmp(cont[i], cont[i + 1]) > 0)
			res = false;
	return res;
}
TEST(TestBubbleSort_, TestSorts_) {
	std::vector<int> v;
	for (int i = 0; i < 10; i++)
		v.push_back(i % 4);
	auto res = csl::bubbleSort(v, cmpInt);
	EXPECT_TRUE(checkSorted(res, cmpInt));
}