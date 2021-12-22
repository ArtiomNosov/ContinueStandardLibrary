#include "Combinatorics.h"
bool next_combination(std::vector<int>& a, int n) {
    int m = (int)a.size();
    return inc_vector_as_number(a, n);
}
bool inc_vector_as_number(std::vector<int>& a, int notation) {
    int m = (int)a.size();
    for (int i = 0; i < m; i++)
    {
        if (a[i] == notation - 1)
        {
            a[i] = 0;
        }
        else
        {
            a[i]++;
            return true;
        }
    }
    return false;
}