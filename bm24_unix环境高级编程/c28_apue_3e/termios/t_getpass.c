#include "apue.h"

// getpass函数用于获取用户输入的密码,不会在终端上显示输入的内容
// @param prompt 提示用户输入密码的字符串
// @return 返回用户输入的密码字符串,如果出错则返回NULL
char *getpass(const char *);

int main(void)
{
    char *ptr;  // 定义一个指针变量,用于存储用户输入的密码

    // 调用getpass函数获取密码,如果返回NULL表示出错
    if ((ptr = getpass("Enter password:")) == NULL)
        err_sys("getpass error");   // 如果出错,打印错误信息并退出程序
    printf("password: %s\n", ptr);  // 打印获取到的密码(仅供演示,实际应用中不应打印密码)

    /* now use password (probably encrypt it) ... */

    // 为了安全起见,在使用完密码后将其清零
    while (*ptr != 0)
        *ptr++ = 0;  // 将密码字符串的每个字符都设置为0
    exit(0);         // 安全退出程序
}
