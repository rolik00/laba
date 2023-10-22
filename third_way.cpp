#include <iostream>
#include <cmath>
int table[10000][10000];

int binary_search_down(int j, int st, int end, int target)
{
    int m;
    while (st <= end)
    {
        m = st + (end - st) / 2;
        if (table[m][j] == target) return m;
        else if (table[m][j] < target) st = m + 1;
        else end = m - 1;
    }
    return m;
}

int exp_search_down(int i, int j, int n, int target)
{
    int k = 1, p;
    while (i + k < n && table[i + k][j] <= target) k = k * 2;
    if (i + k >= n) p = binary_search_down(j, i + k / 2, n - 1, target);
    else p = binary_search_down(j, i + k / 2, i + k, target);
    return p;
}

int main()
{
    int n = 8192, m, target = 2 * n - 1;
    for (int k = 1; k <= 13; k++)
    {
        m = pow(2, k);
        std::cout << m << "\n";
        for (int i = 0; i < n; i++) for (int j = 0; j < m; j++)
            table[i][j] = ((n / m) * i + j) * 2;
        int i_3 = 0, j_3 = m - 1, f_3 = 0;
        while (i_3 >= 0 && i_3 < n && j_3 >= 0 && j_3 < m)
        {
            if (table[i_3][j_3] == target)
            {
                f_3 = 1;
                std::cout << "YES" << std::endl;
                break;
            }
            else if (table[i_3][j_3] < target)
            {
                if (i_3 < n - 2) i_3 = exp_search_down(i_3, j_3, n, target);
                else i_3++;
            }
            else j_3--;
        }
        if (f_3 == 0) std::cout << "NO" << std::endl;
    }
    return 0;
}
