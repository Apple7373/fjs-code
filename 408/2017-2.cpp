#include <bits/stdc++.h>

using namespace std;

int main()
{
    vector<int> nums(10);
    for (int i = 0; i < 10; i++) cin >> nums[i];

    for (auto it : nums) 
        cout << it << ' ';
    
    cout << "请输入要查找的元素：";
    int tar;
    cin >> tar;
    int l = 0, r = nums.size()-1;
    int cnt = 0;
    while (l < r) {
        int mid = l + r >> 1;
        if (nums[mid] < tar) l = mid+1;
        else r = mid-1;
        cnt++;
    }
    if (nums[r] != tar) {
        cout << "查找失败,比较次数为" << cnt;
    } else cout << "成功，位置为" << r << "比较次数" << cnt;
}