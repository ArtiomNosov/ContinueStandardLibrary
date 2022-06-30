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
		if (cmp(cont[i], cont[i + 1]) > 0) {
			res = false;
			break;
		}
	return res;
}
TEST(TestBubbleSort, TestSTDVector) {
	auto v = new std::vector<int>;
	for (int i = 0; i < 10; i++)
		v->push_back(i % 4);
	std::vector<int>* res = csl::bubbleSort(v, cmpInt);
	EXPECT_TRUE(checkSorted(*res, cmpInt));
}
TEST(TestShakerSort, TestSTDVector) {
	auto v = new std::vector<int>;
	for (int i = 0; i < 10; i++)
		v->push_back(i % 4);
	std::vector<int>* res = csl::shakerSort(v, cmpInt);
	EXPECT_TRUE(checkSorted(*res, cmpInt));
}
TEST(TestInsertionSort, TestSTDVector) {
	auto v = new std::vector<int>;
	for (int i = 0; i < 10; i++)
		v->push_back(i % 4);
	std::vector<int>* res = csl::insertionSort(v, cmpInt);
	EXPECT_TRUE(checkSorted(*res, cmpInt));
}
TEST(TestSelectionSortSort, TestSTDVector) {
	auto v = new std::vector<int>;
	for (int i = 0; i < 10; i++)
		v->push_back(i % 4);
	std::vector<int>* res = csl::selectionSort(v, cmpInt);
	EXPECT_TRUE(checkSorted(*res, cmpInt));
}
int getKeyInt(int& n)
{
	return n;
}
TEST(TestCountingSort, TestSTDVector) {
	auto v = new std::vector<int>;
	for (int i = 0; i < 10; i++)
		v->push_back(i % 4);
	std::vector<int>* res = csl::countingSort(v, cmpInt, getKeyInt, 4);
	EXPECT_TRUE(checkSorted(*res, cmpInt));
}
TEST(TestBinaryInsertionSort, TestSTDVector) {
	// Arrange
	auto v = new std::vector<int>;
	for (int i = 0; i < 10; i++)
		v->push_back(i % 4);

	// Act
	std::vector<int>* res = csl::binaryInsertionSort(v, cmpInt);

	// Assert
	EXPECT_TRUE(checkSorted(*res, cmpInt));
}
TEST(TestSquareSort, TestSTDVector) {
	auto v = new std::vector<int>;
	for (int i = 0; i < 10; i++)
		v->push_back(i % 4);
	std::vector<int>* res = csl::squareSort(v, cmpInt);
	EXPECT_TRUE(checkSorted(*res, cmpInt));
}
TEST(TestTreeSort, TestSTDVector) {
	auto v = new std::vector<int>;
	for (int i = 0; i < 10; i++)
		v->push_back(i % 4);
	std::vector<int>* res = csl::treeSort(v, cmpInt);
	EXPECT_TRUE(checkSorted(*res, cmpInt));
}
TEST(TestMergeSortIterative, TestSTDVector) {
	auto v = new std::vector<int>;
	for (int i = 0; i < 10; i++)
		v->push_back(i % 4);
	std::vector<int>* res = csl::mergeSortIterative(v, cmpInt);
	EXPECT_TRUE(checkSorted(*res, cmpInt));
}
TEST(TestHeapSort, TestSTDVector) {
	auto v = new std::vector<int>;
	for (int i = 0; i < 10; i++)
		v->push_back(i % 4);
	std::vector<int>* res = csl::heapSort(v, cmpInt);
	EXPECT_TRUE(checkSorted(*res, cmpInt));
}
TEST(TestQuickSort, TestSTDVector) {
	auto v = new std::vector<int>;
	for (int i = 0; i < 10; i++)
		v->push_back(i % 4);
	std::vector<int>* res = csl::quickSort(v, cmpInt);
	EXPECT_TRUE(checkSorted(*res, cmpInt));
}
TEST(TestShellSort, TestSTDVector) {
	auto v = new std::vector<int>;
	for (int i = 0; i < 10; i++)
		v->push_back(i % 4);
	std::vector<int>* res = csl::shellSort(v, cmpInt);
	EXPECT_TRUE(checkSorted(*res, cmpInt));
}
int inc3(int n)
{
	return n / 3;
}
TEST(TestShellSortWithFunction, TestSTDVector) {
	auto v = new std::vector<int>;
	for (int i = 0; i < 10; i++)
		v->push_back(i % 4);
	std::vector<int>* res = csl::shellSort(v, cmpInt, inc3);
	EXPECT_TRUE(checkSorted(*res, cmpInt));
}
TEST(TestBitonicSort, TestSTDVector) {
	auto v = new std::vector<int>;
	for (int i = 0; i < 10; i++)
		v->push_back(i % 4);
	std::vector<int>* res = csl::bitonicSort(v, cmpInt);
	EXPECT_TRUE(checkSorted(*res, cmpInt));
}
