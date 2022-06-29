#pragma once
#include <iostream>
namespace csl {
    template<typename T, typename Container>
    Container& bubbleSort(Container& cont, int (*cmp)(T&, T&))
    {
        Container res = cont;
        int size = res.size();
        if (size < 2)
            return res;
        auto itJ = res.begin();
        int i = 0, t = true;
        while (t) {
            t = false;
            for (int j = 0; j < size - i - 1; j++) {
                if (cmp(res[j], res[j + 1]) > 0) {
                    std::iter_swap(itJ, std::next(itJ, 1));
                    t = true;
                }
            }
            i = i + 1;
        }
        return res;
    }
}