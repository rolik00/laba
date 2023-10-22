#include <iostream>
#include <chrono>
#include <ctime>
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
            table[i][j] = ((n / m) * i + j + 1) * 2;
        // FIRST WAY
        //auto start_1 = std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count(); //с помощью этой функции считала время работы алгоритма
        std::cout << "First way:  ";
        int i_1 = binary_search(target, n, m).first;
        int j_1 = binary_search(target, n, m).second;
        if (j_1 != -1 && i_1 != -1 && table[i_1][j_1] == target) std::cout << "YES" << std::endl;
        else std::cout << "NO" << std::endl;
        //auto end_1 = std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();
        //std::cout << "1 " << end_1 - start_1 << "\n";
        // SECOND WAY
        //auto start_2 = std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();
        std::cout << "Second way: ";
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
        //auto end_2 = std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();
        //std::cout << "2 " << end_2 - start_2 << "\n";
        // THIRD WAY
        //auto start_3 = std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();
        std::cout << "Third way:  ";
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
        //auto end_3 = std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();
        //std::cout << "3 " << end_3 - start_3 << "\n";
    }
    return 0;
}
