//
// Created by jhchen<jianhuchen@163.com> on 2019-11-12 15:03:37.
//
// 题目链接: https://pintia.cn/problem-sets/994805260223102976/problems/994805302786899968
// 题目描述: 给定任一个各位数字不完全相同的 4 位正整数，如果我们先把 4 个数字按非递增排序，再按非递减排序，然后用第 1 个数字减第 2 个数字，将得到一个新的数字。一直重复这样做，我们很快会停在有“数字黑洞”之称的 `6174`，这个神奇的数字也叫 Kaprekar 常数。
//
// 例如，我们从`6767`开始，将得到
// ```
// 7766 - 6677 = 1089
// 9810 - 0189 = 9621
// 9621 - 1269 = 8352
// 8532 - 2358 = 6174
// 7641 - 1467 = 6174
// ... ...
// ```
//
// 现给定任意 4 位正整数，请编写程序演示到达黑洞的过程。
//
// ### 输入格式：
//
// 输入给出一个 $$(0, 10^4)$$ 区间内的正整数 $$N$$。
//
// ### 输出格式：
//
// 如果 $$N$$ 的 4 位数字全相等，则在一行内输出 `N - N = 0000`；否则将计算的每一步在一行内输出，直到 `6174` 作为差出现，输出格式见样例。注意每个数字按 `4` 位数格式输出。
//
// ### 输入样例 1：
// ```in
// 6767
// ```
//
// ### 输出样例 1：
// ```out
// 7766 - 6677 = 1089
// 9810 - 0189 = 9621
// 9621 - 1269 = 8352
// 8532 - 2358 = 6174
// ```
//
// ### 输入样例 2：
// ```in
// 2222
// ```
//
// ### 输出样例 2：
// ```out
// 2222 - 2222 = 0000
// ```

#include <iostream>
#include<algorithm>
using namespace std;

int main() {
    int n;
    string N, increaseStr, decreaseStr;
    cin >> N;
    N.insert(0, 4 - N.length(), '0');
    do {
        sort(N.begin(), N.end(), less<char>());
        increaseStr = N;
        sort(N.begin(), N.end(), greater<char>());
        decreaseStr = N;
        n = stoi(decreaseStr) - stoi(increaseStr);
        N = to_string(n);
        N.insert(0, 4 - N.length(), '0');
        cout << decreaseStr << " - " << increaseStr << " = " << N << endl;
    } while (n != 6174 && n != 0);

    return 0;
}
