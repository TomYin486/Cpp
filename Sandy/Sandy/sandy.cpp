#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include<vector>
#include<algorithm>
using namespace std;

int main()
{
    vector<int> vec = { 1,5,3,9,8,7,10,2,5,6,10,2,2,6,6,6,6 };

    // 对 vec 中的元素进行升序排序
    sort(vec.begin(), vec.end());

    // 将 vec 中的相邻重复元素移动到容器末尾，并返回一个指向去重后新末尾的地址 last
    // unique 并不会真正删除元素，只是将重复元素移动到末尾
    auto last = unique(vec.begin(), vec.end());

    // 删除 unique 操作后移动到末尾的重复元素(从 last 到 vec.end() 之间的元素)
    vec.erase(last, vec.end());

    for (auto& num : vec)
    {
        cout << num << ' ';
    }

    return 0;
}
