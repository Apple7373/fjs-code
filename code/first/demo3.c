#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

int isFloat(const char* str) {
    char* endptr;
    
    // 处理前导空格
    while (isspace(*str)) str++;
    
    // 使用 strtod 尝试转换为浮点数
    double val = strtod(str, &endptr);
    
    // 如果 endptr 指向的不是字符串的末尾，则说明转换失败
    if (*endptr != '\0') {
        return 0;
    }
    
    // 如果转换后的值为 0 且原字符串不以 '0' 开头，则说明转换失败
    if (val == 0 && str == endptr) {
        return 0;
    }

    return 1;
}

int main() {
    const char* test1 = " ";
    const char* test2 = "abc";
    
    printf("Is test1 a float? %d\n", isFloat(test1)); // 输出 1 (true)
    printf("Is test2 a float? %d\n", isFloat(test2)); // 输出 0 (false)
    
    return 0;
}
