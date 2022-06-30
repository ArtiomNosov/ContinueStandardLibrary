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
                if (cmp( (*res)[j], (*res)[j + 1]) > 0) {
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
}