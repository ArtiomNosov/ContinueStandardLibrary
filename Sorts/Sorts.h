#pragma once
#include <iostream>
/*
*	Sorts.h
*	Version 0.2
*	Author: Nosov Artiom
*	Company: Continue
*	Email: artiom-nj@mail.ru
*/
namespace csl {

    #define checkSize                           \
                                                \
        if (size < 2)                           \
            return res;                         \
    
    #define initResContAndCheckSize             \
                                                \
        Container* res = new Container(*cont);  \
        int size = res->size();                 \
                                                \
        checkSize                               \
     
    #define initResSizeAndCheckSize             \
                                                \
        int size = cont->size();                \
        Container* res = new Container(size);   \
                                                \
        checkSize                               \
     
    #define iterSwap(A, B) std::iter_swap(A, B);
    #define iterNext(A, N) std::next(A, N)
    #define iterBegin(A) A->begin()
    #define iterEnd(A) A->end()
    #define getElem(C, I) (*C)[I]
    #define assign(A, I, B, J) getElem(A, I) = getElem(B, J)
    #define forIncSpec(A, B, E, O) for (int A = B; A < E; A O)
    #define forDecSpec(A, B, E, O) for (int A = B; A > E; A O)
    #define forInc(A, B, E) forIncSpec(A, B, E, ++)
    #define forDec(A, B, E) forDecSpec(A, B, E, --)
    // 01.07.2022
    template<typename T, typename Container>
    Container* bubbleSort(Container* cont, int (*cmp)(T&, T&))
    {
        initResContAndCheckSize

        auto itJ = iterBegin(res);
        int i = 0, t = true;
        while (t) {
            t = false;
            itJ = iterBegin(res);
            forInc(j, 0, size - i - 1) {
                if (cmp(getElem(res,j), getElem(res,j + 1)) > 0) {
                    iterSwap(itJ, iterNext(itJ, 1));
                    t = true;
                }
                itJ++;
            }
            i = i + 1;
        }

        return res;
    }
    // 01.07.2022
    template<typename T, typename Container>
    Container* shakerSort(Container* cont, int (*cmp)(T&, T&))
    {
        initResContAndCheckSize

        int begin = -1, end = size - 2, swapped = true;
        auto itI = iterBegin(res);
        while (swapped) {
            swapped = false;
            begin++;
            itI = iterBegin(res);
            itI = iterNext(itI, begin);
            forInc(i, begin, end + 1) {
                if (cmp(getElem(res, i), getElem(res, i + 1)) > 0) {
                    iterSwap(itI, iterNext(itI, 1));
                    swapped = true;
                }
                itI++;
            }
            if (!swapped)
                break;
            swapped = false;
            end--;
            itI = iterBegin(res);
            itI = iterNext(itI, end);
            forDec(i, end, begin) {
                if (cmp(getElem(res, i), getElem(res, i + 1)) > 0)
                    iterSwap(itI, iterNext(itI, 1));
                swapped = true;
                if (i > 0)
                    itI--;
            }
        }

        return res;
    }
    // 01.07.2022
    template<typename T, typename Container>
    Container* insertionSort(Container* cont, int (*cmp)(T&, T&))
    {
        initResContAndCheckSize

        auto itJ = iterBegin(res);
        forInc(i, 1, size) {
            int j = i - 1;
            itJ = iterBegin(res);
            itJ = iterNext(itJ, j);
            while (j >= 0 && cmp(getElem(res, j), getElem(res, j + 1)) > 0) {
                iterSwap(itJ, iterNext(itJ, 1));
                j--;
                if (j > 0)
                    itJ--;
            }
        }

        return res;
    }
    // 01.07.2022
    template<typename T, typename Container>
    Container* selectionSort(Container* cont, int (*cmp)(T&, T&))
    {
        initResContAndCheckSize

        auto itI = iterBegin(res);
        auto itJ = itI;
        forInc(i, 0, size - 1) {
            itJ = iterNext(itI, 1);
            forInc(j, i + 1, size) {
                if (cmp(getElem(res, i), getElem(res, j)) > 0)
                    iterSwap(itI, itJ);
                itJ++;
            }
            itI++;
        }

        return res;
    }
    // 01.07.2022
    template<typename T, typename Container>
    Container* countingSort(Container* cont, int (*cmp)(T&, T&), int(*getKey)(T&), int keyCount) {
        initResSizeAndCheckSize

        int* P = new int[keyCount];
        forInc(i, 0, keyCount)
            P[i] = 0;
        forInc(i, 0, size)
            P[getKey(getElem(cont, i))]++;
        int carry = 0, temporary = 0;
        forInc(i, 0, keyCount) {
            temporary = P[i];
            P[i] = carry;
            carry += temporary;
        }
        forInc(i, 0, size) {
            getElem(res, P[getKey(getElem(cont, i))]) = getElem(cont, i);
            P[getKey(getElem(cont, i))]++;
        }

        delete[] P;

        return res;
    }
    // 01.07.2022 help function
    namespace sorts {
        template<typename T, typename Container>
        int binSearch(Container* cont, int (*cmp)(T&, T&), T& key, int l, int r)
        {
            l--;
            r++;

            int m = 0;
            while (l < r - 1) {
                m = (l + r) / 2;
                if (cmp(getElem(cont, m), key) < 0)
                    l = m;
                else
                    r = m;
            }

            return r;
        }
    }
    // 01.07.2022
    template<typename T, typename Container>
    Container* binaryInsertionSort(Container * cont, int (*cmp)(T&, T&)) {
        initResContAndCheckSize

        int k = 0, j = 0;
        auto itM = iterBegin(res);
        forInc(i, 1, size) {
            j = i - 1;
            k = sorts::binSearch(res, cmp, getElem(res, i), 0, j);
            itM = iterNext(iterBegin(res), j);
            forDec(m, j, k - 1) {
                iterSwap(itM, iterNext(itM, 1));
                if (m > 0)
                    itM--;
            }
        }

        return res;
    }
    // 01.07.2022
    template<typename T, typename Container>
    Container* squareSort(Container* cont, int (*cmp)(T&, T&))
    {
        initResContAndCheckSize

        int min = 0;
        auto itI = iterBegin(res);
        auto itJ = itI, itMin = itI;
        forInc(i, 0, size - 1) {
            min = i;
            itMin = itI;
            itJ = iterNext(itI, 1);
            forInc(j, i + 1, size) {
                if (cmp(getElem(res, j), getElem(res, min)) < 0) {
                    min = j;
                    itMin = itJ;
                }
                itJ++;
            }
            iterSwap(itI, itMin);
            itI++;
        }

        return res;
    }
    // 01.07.2022 help struct
    namespace sorts {
        template<typename T>
        struct Node {
            T* data;
            struct Node<T>* left, * right;
        };
        template<typename T>
        struct Node<T>* newnode(T* data)
        {
            struct Node<T>* temp = new Node<T>;
            temp->data = data;
            temp->left = NULL;
            temp->right = NULL;
            return temp;
        }
        template<typename T>
        Node<T>* insert(Node<T>* node, T* data, int (*cmp)(T&, T&))
        {
            if (node == NULL)
                return newnode(data);
            if (cmp(*data, *(node->data)) <= 0)
                node->left = insert(node->left, data, cmp);
            else
                node->right = insert(node->right, data, cmp);

            return node;
        }
        template<typename T, typename Iterator>
        void store(Node<T>* root, Iterator& itI)
        {
            if (root != NULL)
            {
                store(root->left, itI);
                *itI = *(root->data);
                itI++;
                store(root->right, itI);
            }
        }
    }
    // 01.07.2022 
    template<typename T, typename Container>
    Container* treeSort(Container* cont, int (*cmp)(T&, T&))
    {
        initResSizeAndCheckSize

        struct sorts::Node<T>* root = NULL;
        
        auto itI = iterBegin(cont);
        root = sorts::insert(root, itI._Ptr, cmp);
        forInc(i, 1, size) {
            itI++;
            sorts::insert(root, itI._Ptr, cmp);
        }
        
        int i = 0;
        itI = iterBegin(res);
        sorts::store(root, itI);

        return res;
    }
    // 01.07.2022 help function
    namespace sorts {
        template<typename T, typename Container>
        void merge(Container* cont, int (*cmp)(T&, T&), int left, int mid, int right)
        {
            int it1 = 0, it2 = 0;
            Container* result = new Container(right - left);

            while (left + it1 < mid && mid + it2 < right) {
                if (cmp(getElem(cont, left + it1), getElem(cont, mid + it2)) < 0) {
                    assign(result, it1 + it2, cont, left + it1);
                    it1 += 1;
                }
                else {
                    assign(result, it1 + it2, cont, mid + it2);
                    it2 += 1;
                }
            }
            while (left + it1 < mid) {
                assign(result, it1 + it2, cont, left + it1);
                it1 += 1;
            }
            while (mid + it2 < right) {
                assign(result, it1 + it2, cont, mid + it2);
                it2 += 1;
            }
            forInc(i, 0, it1 + it2)
                assign(cont, left + i, result, i);

            delete result;
        }
    }
    template<typename T, typename Container>
    Container* mergeSortIterative(Container* cont, int (*cmp)(T&, T&))
    {
        initResContAndCheckSize

            forIncSpec(i, 1, size, *= 2)
            forIncSpec(j, 0, size - i + 1, += 2 * i)
            sorts::merge(res, cmp, j, j + i, std::min(j + 2 * i, size));

        return res;
    }
    // 01.07.2022 help function
    namespace sorts {
        template<typename T, typename Container, typename Iterator>
        void heapify(Container* cont, int size, int (*cmp)(T&, T&), int i, Iterator itI)
        {
            int largest = i;
            int l = 2 * i + 1;
            int r = 2 * i + 2;

            if (l < size && (cmp(getElem(cont, l), getElem(cont, largest)) > 0))
                largest = l;

            if (r < size && (cmp(getElem(cont, r), getElem(cont, largest)) > 0))
                largest = r;

            auto itLargest = iterNext(iterBegin(cont), largest);
            if (largest != i) {
                iterSwap(itI, itLargest);
                heapify(cont, size, cmp, largest, itLargest);
            }
        }
    }
    // 01.07.2022
    template<typename T, typename Container>
    Container* heapSort(Container* cont, int (*cmp)(T&, T&))
    {
        initResContAndCheckSize

        auto itI = iterNext(iterBegin(res), size / 2 - 1);
        forDec(i, size / 2 - 1, -1) {
            sorts::heapify(res, size,  cmp, i, itI);
            if (i > 0)
                itI--;
        }
        itI = iterNext(iterBegin(res), size - 1);
        forDec(i, size - 1, -1) {
            iterSwap(iterBegin(res), itI);
            sorts::heapify(res, i, cmp, 0, itI);
            if (i > 0)
                itI--;
        }

        return res;
    }
    // 01.07.2022 help function
    namespace sorts {
        template<typename T, typename Container>
        void reqursiveQuickSort(Container* cont, int low, int high, int (*cmp)(T&, T&))
        {
            int i = low;
            int j = high;
            T pivot = getElem(cont, (i + j) / 2);
            auto itI = iterNext(iterBegin(cont), low);
            auto itJ = iterNext(iterBegin(cont), high);
            while (i <= j)
            {
                while (cmp(*itI, pivot) < 0) {
                    i++;
                    itI++;
                }
                while (cmp(*itJ, pivot) > 0) {
                    j--;
                    if (j > 0)
                        itJ--;
                }
                if (i <= j)
                {
                    iterSwap(itI, itJ);
                    i++;
                    itI++;
                    j--;
                    if (j > 0)
                        itJ--;
                }
            }
            if (j > low)
                reqursiveQuickSort(cont, low, j, cmp);
            if (i < high)
                reqursiveQuickSort(cont, i, high, cmp);

        }
    }
    // 01.07.2022
    template<typename T, typename Container>
    Container* quickSort(Container* cont, int (*cmp)(T&, T&))
    {
        initResContAndCheckSize

        sorts::reqursiveQuickSort(res, 0, size - 1, cmp);

        return res;
    }
    // 01.07.2022 help function
    namespace sorts {
        int incBase(int n)
        {
            return n / 2;
        }
    }
    // 01.07.2022
    template<typename T, typename Container>
    Container* shellSort(Container* cont, int (*cmp)(T&, T&), int(*inc)(int) = sorts::incBase)
    {
        initResContAndCheckSize

        forDecSpec(gap, inc(size), 0, =inc(gap))
        {
            forInc(i, gap, size)
            {
                T temp = getElem(res, i);

                int j;
                for (j = i; j >= gap && (cmp(getElem(res, j - gap), temp) > 0); j -= gap)
                    assign(res, j, res, j - gap);

                getElem(res, j) = temp;
            }
        }

        return res;
    }
    // 01.07.2022 help functions
    namespace sorts {
        /*The parameter dir indicates the sorting direction, ASCENDING
        or DESCENDING; if (a[i] > a[j]) agrees with the direction,
        then a[i] and a[j] are interchanged.*/
        template<typename T, typename Container, typename Iterator>
        void compAndSwap(Container* cont, int (*cmp)(T&, T&), Iterator itI, Iterator itJ, int dir)
        {
            if (dir == (cmp(*itI, *itJ) > 0))
                iterSwap(itI, itJ);
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
                auto itI = iterNext(iterBegin(cont), low);
                auto itIK = iterNext(itI, k);
                forInc(i, low, low + k) {
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

                // Will merge whole sequence in "dir" order
                bitonicMerge(cont, cmp, low, cnt, dir);
            }
        }
        // TODO: change this shit because this is repeat yourself because somfing like this is exist
        template<typename Container>
        void reverseContainer(Container* cont)
        {
            int size = cont->size();
            if (size < 1)
                return;

            auto itI = iterBegin(cont);
            auto itJ = iterEnd(cont);
            forInc(i, 0, size / 2) {
                itJ--;
                iterSwap(itI, itJ);
                itI++;
            }
        }
    }
    // 01.07.2022
    template<typename T, typename Container>
    Container* bitonicSort(Container* cont, int (*cmp)(T&, T&))
    {
        initResContAndCheckSize

        sorts::reqursiveBitonicSort(res, cmp, 0, size, 0);
        sorts::reverseContainer(res);

        return res;
    }

}

