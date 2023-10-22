#include <iostream>
#include <cmath>
int table[10000][10000];

std::pair<int, int> binary_search(int el, int n, int m)
{
    for (int j = 0; j < m; j++)
    {
        int l = 0, r = n - 1, i = 0;
        while (l <= r)
        {
            i = l + (r - l) / 2;
            if (table[i][j] == el) return std::pair<int, int>(i, j);
            else if (table[i][j] < el) l = i + 1;
            else r = i - 1;
        }
    }
    return std::pair<int, int>(-1, -1);
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
        int i_1 = binary_search(target, n, m).first;
        int j_1 = binary_search(target, n, m).second;
        if (j_1 != -1 && i_1 != -1 && table[i_1][j_1] == target) std::cout << "YES" << std::endl;
        else std::cout << "NO" << std::endl;
    }
    return 0;
}
