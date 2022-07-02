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
#define LENGHT_OF_CONTAINER 1000
#define DENOMINATOR_FOR_GENERATE 25
#define prepearContainer(C)									\
															\
    auto v = new C;											\
	forInc(i, 0, LENGHT_OF_CONTAINER)						\
		v->push_back(i % DENOMINATOR_FOR_GENERATE);			\


int cmpInt(int& a, int& b) {
	if (a > b)
		return 1;
	else if (a < b)
		return -1;
	else
		return 0;
}
template<typename T, typename Container>
int checkSorted(Container& cont, int(*cmp)(T&, T&))
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
#define testSortSpec(A, B, C, T, S, A3)				\
TEST(A, B) {										\
/* Arrange */										\
prepearContainer(C<T>)								\
													\
/* Act */											\
auto res = S(v, cmpInt, A3);					    \
													\
/* Assert */										\
EXPECT_TRUE(checkSorted(*res, cmpInt));				\
}																										

#define testSort(A, B, C, T, S)						\
TEST(A, B) {										\
/* Arrange */										\
prepearContainer(C<T>)								\
													\
/* Act */											\
auto res = S(v, cmpInt);							\
													\
/* Assert */										\
EXPECT_TRUE(checkSorted(*res, cmpInt));				\
}													

testSort(bubbleSort, STDVector, std::vector, int, csl::bubbleSort)
testSort(shakerSort, STDVector, std::vector, int, csl::shakerSort)
testSort(insertionSort, STDVector, std::vector, int, csl::insertionSort)
testSort(selectionSort, STDVector, std::vector, int, csl::selectionSort)
int getKeyInt(int& n)
{
	return n;
}
#define ArgCountingSort getKeyInt, DENOMINATOR_FOR_GENERATE
testSortSpec(CountingSort, STDVector, std::vector, int, csl::countingSort, ArgCountingSort)
testSort(BinaryInsertionSort, STDVector, std::vector, int, csl::binaryInsertionSort)
testSort(SquareSort, STDVector, std::vector, int, csl::squareSort)
testSort(TreeSort, STDVector, std::vector, int, csl::treeSort)
testSort(MergeSortIterative, STDVector, std::vector, int, csl::mergeSortIterative)
testSort(HeapSort, STDVector, std::vector, int, csl::heapSort)
testSort(QuickSort, STDVector, std::vector, int, csl::quickSort)
testSort(ShellSort, STDVector, std::vector, int, csl::shellSort)
int inc3(int n)
{
	return n / 3;
}
testSortSpec(ShellSortWithFunction, STDVector, std::vector, int, csl::shellSort, inc3)
// testSort(BitonicSort, STDVector, std::vector, int, csl::bitonicSort)
