#include <bits/stdc++.h>
#include "myclass.h"
#include <vector>
/*
demo2.o
demo3.o
*/
using namespace std;




void change(int *p, int va) { // 指针的方式
    for (int i = 0; i < 10000; i++)
        p[i] = va;
}
int main() 
{
    int a[10000];
    // 初始化；
    for (int i = 0; i < 10000; i++) {
        a[i] = i;
    }
    // 假设有这样一个需求，第一次把数组a全修改为1，然后输出；第二次需要修改为2然后输出
    // 第三次需要修改为3然后输出
    // 如果不封装成函数 直接在main函数里面使用for循环修改
    for (int i = 0; i < 10000; i++) 
        a[i] = 1;
    // 输出一次a
    for (int i = 0; i < 10000; i++) 
        a[i] = 2;
    // 输出一次a
    for (int i = 0; i < 10000; i++) 
        a[i] = 3;
    // 输出一次a
    


    // 如果封装成函数
    change(a, 1);
    // 输出a
    change(a, 2);
    // 输出a
    change(a, 3);
    // 输出a         封装成函数代码会显得清晰

}