#include <iostream>
#include <cmath>
int table[10000][10000];

int main()
{
    int n = 8192, m, target = 2 * n - 1;
    for (int k = 1; k <= 13; k++)
    {
        m = pow(2, k);
        std::cout << m << "\n";
        for (int i = 0; i < n; i++) for (int j = 0; j < m; j++)
            table[i][j] = ((n / m) * i + j) * 2;
        int i_2 = 0, j_2 = m - 1, f_2 = 0;
        while (i_2 >= 0 && i_2 < n && j_2 >= 0 && j_2 < m)
        {
            if (table[i_2][j_2] == target)
            {
                f_2 = 1;
                std::cout << "YES" << std::endl;
                break;
            }
            else if (table[i_2][j_2] < target) i_2++;
            else j_2--;
        }
        if (f_2 == 0) std::cout << "NO" << std::endl;
    }
    return 0;
}
