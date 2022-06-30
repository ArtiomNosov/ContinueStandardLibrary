#pragma once
#include <iostream>
namespace csl {
    template<typename T, typename Container>
    Container* bubbleSort(Container* cont, int (*cmp)(T&, T&))
    {
        Container* res = new Container(*cont);
        int size = res->size();
        if (size < 2)
            return res;
        auto itJ = res->begin();
        int i = 0, t = true;
        while (t) {
            t = false;
            itJ = res->begin();
            for (int j = 0; j < size - i - 1; j++) {
                if (cmp((*res)[j], (*res)[j + 1]) > 0) {
                    std::iter_swap(itJ, std::next(itJ, 1));
                    t = true;
                }
                itJ++;
            }
            i = i + 1;
        }
        return res;
    }

    template<typename T, typename Container>
    Container* shakerSort(Container* cont, int (*cmp)(T&, T&))
    {
        Container* res = new Container(*cont);
        int size = res->size();
        if (size < 2)
            return res;
        int begin = -1, end = size - 2, swapped = true;
        auto itI = res->begin();
        while (swapped) {
            swapped = false;
            begin++;
            itI = res->begin();
            itI = std::next(itI, begin);
            for (int i = begin; i < end + 1; i++) {
                if (cmp((*res)[i], (*res)[i + 1]) > 0) {
                    std::iter_swap(itI, std::next(itI, 1));
                    swapped = true;
                }
                itI++;
            }
            if (!swapped)
                break;
            swapped = false;
            end--;
            itI = res->begin();
            itI = std::next(itI, end);
            for (int i = end; i > begin - 1; i--) {
                if (cmp((*res)[i], (*res)[i + 1]) > 0)
                    std::iter_swap(itI, std::next(itI, 1));
                swapped = true;
                if (i > 0)
                    itI--;
            }
        }
        return res;
    }

    template<typename T, typename Container>
    Container* insertionSort(Container* cont, int (*cmp)(T&, T&))
    {
        Container* res = new Container(*cont);
        int size = res->size();
        if (size < 2)
            return res;
        auto itJ = res->begin();
        for (int i = 1; i < size; i++) {
            int j = i - 1;
            itJ = res->begin();
            itJ = std::next(itJ, j);
            while (j >= 0 && cmp((*res)[j], (*res)[j + 1]) > 0) {
                std::iter_swap(itJ, std::next(itJ, 1));
                j--;
                if (j > 0)
                    itJ--;
            }
        }
        return res;
    }

    template<typename T, typename Container>
    Container* selectionSort(Container* cont, int (*cmp)(T&, T&))
    {
        Container* res = new Container(*cont);
        int size = res->size();
        if (size < 2)
            return res;
        auto itI = res->begin();
        auto itJ = itI;
        for (int i = 0; i < size - 1; i++) {
            itJ = std::next(itI, 1);
            for (int j = i + 1; j < size; j++) {
                if (cmp((*res)[i], (*res)[j]) > 0)
                    std::iter_swap(itI, itJ);
                itJ++;
            }
            itI++;
        }
        return res;
    }

    template<typename T, typename Container>
    Container* countingSort(Container* cont, int (*cmp)(T&, T&), int(*getKey)(T&), int keyCount) {
        int size = cont->size();
        Container* res = new Container(size);
        if (size < 2)
            return res;
        int* P = new int[keyCount];
        for (int i = 0; i < keyCount; i++)
            P[i] = 0;
        for (int i = 0; i < size; i++)
            P[getKey((*cont)[i])]++;
        int carry = 0, temporary = 0;
        for (int i = 0; i < keyCount; i++) {
            temporary = P[i];
            P[i] = carry;
            carry += temporary;
        }
        for (int i = 0; i < size; i++) {
            (*res)[P[getKey((*cont)[i])]] = (*cont)[i];
            P[getKey((*cont)[i])]++;
        }
        delete[] P;
        return res;
    }

    template<typename T, typename Container>
    int binSearch(Container* cont, int (*cmp)(T&, T&), T& key, int l, int r) 
    {
        l--;
        r++;
        int m = 0;
        while (l < r - 1) {            
            m = (l + r) / 2;          
            if (cmp((*cont)[m], key) < 0)
                l = m;
            else
                r = m;           
        }
        return r;
    }
    template<typename T, typename Container>
    Container* binaryInsertionSort(Container * cont, int (*cmp)(T&, T&)) {
        Container* res = new Container(*cont);
        int size = res->size();
        if (size < 2)
            return res;
        int k = 0, j = 0;
        auto itM = res->begin();
        for (int i = 1; i < size; i++) {
            j = i - 1;
            k = binSearch(res, cmp, (*res)[i], 0, j);
            itM = std::next(res->begin(), j);
            for (int m = j; m > k - 1; m--) {
                std::iter_swap(itM, std::next(itM, 1));
                if (m > 0)
                    itM--;
            }
        }
        return res;
    }

    template<typename T, typename Container>
    Container* squareSort(Container* cont, int (*cmp)(T&, T&))
    {
        Container* res = new Container(*cont);
        int size = res->size();
        if (size < 2)
            return res;
        int min = 0;
        auto itI = res->begin();
        auto itJ = itI, itMin = itI;
        for (int i = 0; i < size - 1; i++) {
            min = i;
            itMin = itI;
            itJ = std::next(itI, 1);
            for (int j = i + 1; j < size; j++) {
                if (cmp((*res)[j], (*res)[min]) < 0) {
                    min = j;
                    itMin = itJ;
                }
                itJ++;
            }
            std::iter_swap(itI, itMin);
            itI++;
        }
        return res;
    }

    template<typename T, typename Container>
    Container* treeSort(Container* cont, int (*cmp)(T&, T&), int(*getKey)(T&))
    {
        int size = cont->size();
        Container* res = new Container(size);
        if (size < 2)
            return res;
        int i = 0;
        std::map<T, int> tree;
        for (i = 0; i < size; i++)
            tree[getKey((*cont)[i])] = (*cont)[i];
        i = 0;
        for (const auto& [key, value] : tree) {
            (*res)[i] = value;
            i++;
        }
        return res;
    }

    template<typename T, typename Container>
    void merge(Container* cont, int (*cmp)(T&, T&), int left, int mid, int right)
    {
        int it1 = 0, it2 = 0;
        Container* result = new Container(right - left);

        while (left + it1 < mid && mid + it2 < right) {
            if (cmp((*cont)[left + it1], (*cont)[mid + it2]) < 0) {
                (*result)[it1 + it2] = (*cont)[left + it1];
                it1 += 1;
            } else {
                (*result)[it1 + it2] = (*cont)[mid + it2];
                it2 += 1;
            }
        }
        while (left + it1 < mid) {
            (*result)[it1 + it2] = (*cont)[left + it1];
                it1 += 1;
        }
        while (mid + it2 < right) {
            (*result)[it1 + it2] = (*cont)[mid + it2];
            it2 += 1;
        }
        for (int i = 0; i < it1 + it2; i++)
            (*cont)[left + i] = (*result)[i];
        delete result;
    }

    template<typename T, typename Container>
    Container* mergeSortIterative(Container* cont, int (*cmp)(T&, T&))
    {
        Container* res = new Container(*cont);
        int size = res->size();
        if (size < 2)
            return res;
        for (int i = 1; i < size; i *= 2)
            for (int j = 0; j < size - i + 1; j += 2 * i)
                merge(res, cmp, j, j + i, std::min(j + 2 * i, size));
        return res;
    }

    template<typename T, typename Container, typename Iterator>
    void heapify(Container* cont, int size, int (*cmp)(T&, T&), int i, Iterator itI)
    {
        int largest = i;
        int l = 2 * i + 1;
        int r = 2 * i + 2;

        if (l < size && (cmp((*cont)[l], (*cont)[largest]) > 0))
            largest = l;

        if (r < size && (cmp((*cont)[r], (*cont)[largest]) > 0))
            largest = r;

        auto itLargest = std::next(cont->begin(), largest);
        if (largest != i) {
            std::iter_swap(itI, itLargest);
            heapify(cont, size, cmp, largest, itLargest);
        }
    }

    template<typename T, typename Container>
    Container* heapSort(Container* cont, int (*cmp)(T&, T&))
    {
        Container* res = new Container(*cont);
        int size = res->size();
        if (size < 2)
            return res;
        auto itI = std::next(res->begin(), size / 2 - 1);
        for (int i = size / 2 - 1; i >= 0; i--) {
            heapify(res, size,  cmp, i, itI);
            if (i > 0)
                itI--;
        }

        itI = std::next(res->begin(), size - 1);
        for (int i = size - 1; i >= 0; i--) {
            std::iter_swap(res->begin(), itI);
            heapify(res, i, cmp, 0, itI);
            if (i > 0)
                itI--;
        }
        return res;
    }

    template<typename T, typename Container>
    int partition(Container* cont, int (*cmp)(T&, T&), int start, int end)
    {

        T pivot = (*cont)[start];

        int count = 0;
        auto itI = std::next(cont->begin(), start + 1);
        for (int i = start + 1; i <= end; i++) {
            if (cmp(*itI, pivot) <= 0)
                count++;
        }

        int pivotIndex = start + count;
        itI = std::next(cont->begin(), start);
        auto itJ = std::next(itI, count);
        std::iter_swap(itJ, itI);

        int i = start, j = end;
        itI = std::next(cont->begin(), start);
        itJ = std::next(cont->begin(), end);
        while (i < pivotIndex && j > pivotIndex) {

            while (cmp(*itI, pivot) <= 0) {
                i++;
                itI++;
            }

            while (cmp(*itJ, pivot) > 0) {
                j--;
                if (j > 0)
                    itJ--;
            }

            if (i < pivotIndex && j > pivotIndex) {
                std::iter_swap(itJ, itI);
                i++;
                itI++;
                j--;
                if (j > 0)
                    itJ--;
            }
        }

        return pivotIndex;
    }

    template<typename T, typename Container>
    void reqursiveQuickSort(Container* cont, int (*cmp)(T&, T&), int start, int end)
    {
        // base case
        if (start >= end)
            return;

        // partitioning the array
        int p = partition(cont, cmp, start, end);

        // Sorting the left part
        reqursiveQuickSort(cont, cmp, start, p - 1);

        // Sorting the right part
        reqursiveQuickSort(cont, cmp, p + 1, end);
    }
    // res - copy of cont with sorted part between l and r indexes	 
    template<typename T, typename Container>
    Container* quickSort(Container* cont, int (*cmp)(T&, T&))
    {
        Container* res = new Container(*cont);
        int size = res->size();
        if (size < 2)
            return res;
        reqursiveQuickSort(res, cmp, 0, size - 1);
        return res;
    }
    int incBase(int n)
    {
        return n / 2;
    }
    template<typename T, typename Container>
    Container* shellSort(Container* cont, int (*cmp)(T&, T&), int(*inc)(int) = incBase)
    {
        Container* res = new Container(*cont);
        int size = res->size();
        if (size < 2)
            return res;
        for (int gap = inc(size); gap > 0; gap = inc(gap))
        {
            for (int i = gap; i < size; i += 1)
            {
                T temp = (*res)[i];

                int j;
                for (j = i; j >= gap && (cmp((*res)[j - gap], temp) > 0); j -= gap)
                    (*res)[j] = (*res)[j - gap];

                (*res)[j] = temp;
            }
        }
        return res;
    }

    /*The parameter dir indicates the sorting direction, ASCENDING
or DESCENDING; if (a[i] > a[j]) agrees with the direction,
then a[i] and a[j] are interchanged.*/
    template<typename T, typename Container, typename Iterator>
    void compAndSwap(Container* cont, int (*cmp)(T&, T&), Iterator itI, Iterator itJ, int dir)
    {
        if (dir == (cmp(*itI, *itJ) > 0))
            std::iter_swap(itI, itJ);
    }

    /*It recursively sorts a bitonic sequence in ascending order,
    if dir = 1, and in descending order otherwise (means dir=0).
    The sequence to be sorted starts at index position low,
    the parameter cnt is the number of elements to be sorted.*/
    template<typename T, typename Container>
    void bitonicMerge(Container* cont, int (*cmp)(T&, T&), int low, int cnt, int dir)
    {
        if (cnt > 1)
        {
            int k = cnt / 2;
            auto itI = std::next(cont->begin(), low);
            auto itIK = std::next(itI, k);
            for (int i = low; i < low + k; i++) {
                compAndSwap(cont, cmp, itI, itIK, dir);
                itI++;
                itIK++;
            }
            bitonicMerge(cont, cmp, low, k, dir);
            bitonicMerge(cont, cmp, low + k, k, dir);
        }
    }

    /* This function first produces a bitonic sequence by recursively
        sorting its two halves in opposite sorting orders, and then
        calls bitonicMerge to make them in the same order */
    template<typename T, typename Container>
    void reqursiveBitonicSort(Container* cont, int (*cmp)(T&, T&), int low, int cnt, int dir)
    {
        if (cnt > 1)
        {
            int k = cnt / 2;

            // sort in ascending order since dir here is 1
            reqursiveBitonicSort(cont, cmp, low, k, 1);

            // sort in descending order since dir here is 0
            reqursiveBitonicSort(cont, cmp, low + k, k, 0);

            // Will merge whole sequence in ascending order
            // since dir=1.
            bitonicMerge(cont, cmp, low, cnt, dir);
        }
    }
    template<typename Container>
    void reverseContainer(Container* cont) 
    {
        int size = cont->size();
        if (size < 1)
            return;
        auto itI = cont->begin();
        auto itJ = cont->end();
        for (int i = 0; i < size / 2; i++) {
            itJ--;
            std::iter_swap(itI, itJ);
            itI++;
        }
    }
    /* Caller of bitonicSort for sorting the entire array of
    length N in ASCENDING order */
    template<typename T, typename Container>
    Container* bitonicSort(Container* cont, int (*cmp)(T&, T&))
    {
        Container* res = new Container(*cont);
        int size = res->size();
        if (size < 2)
            return res;
        reqursiveBitonicSort(res, cmp, 0, size, 0);
        reverseContainer(res);
        return res;
    }

}

