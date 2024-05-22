#ifdef __cplusplus
extern "C" {
#endif // __cplusplus
#include <stdio.h>
#include <Windows.h>

void Show_Cursor(BOOL flag)
{
    CONSOLE_CURSOR_INFO curInfo = { 0 }; //定义光标信息的结构体变量
    curInfo.dwSize = sizeof(CONSOLE_CURSOR_INFO);  //必须
    curInfo.bVisible = flag; //设置光标是否可见
    HANDLE handle = GetStdHandle(STD_OUTPUT_HANDLE); //获取控制台句柄
    SetConsoleCursorInfo(handle, &curInfo); //设置光标信息
}
void Set_CursorPos(SHORT x, SHORT y)
{
    COORD pos = { x,y }; //定义光标位置的结构体变量
    HANDLE handle = GetStdHandle(STD_OUTPUT_HANDLE); //获取控制台句柄
    SetConsoleCursorPosition(handle, pos); //设置光标位置
}

//加载动画
void loading(const char* arr[], size_t arr_size)
{
    CONSOLE_SCREEN_BUFFER_INFO curInfo; //定义光标信息的结构体变量
    HANDLE hOuput = GetStdHandle(STD_OUTPUT_HANDLE);//获取控制台句柄
    GetConsoleScreenBufferInfo(hOuput, &curInfo);//获取光标信息
    Show_Cursor(FALSE);//隐藏光标
    for (size_t i = 0; i < 100; i++)
    {
        Set_CursorPos(curInfo.dwCursorPosition.X, curInfo.dwCursorPosition.Y);
        printf("%3zu%%:", i + 1);//占5个字符位置
        Set_CursorPos(curInfo.dwCursorPosition.X + 5 + (arr_size == 1 ? i : 0), curInfo.dwCursorPosition.Y);
        printf("%s", arr[i % arr_size]);
        Sleep(50);//任务执行
    }
    Show_Cursor(TRUE);//显示光标
    return;
}

void Progress(void)
{
    //加载
    const char* arr1[] = { "|", "/", "-", "\\" };
    loading(arr1, sizeof(arr1) / sizeof(arr1[0]));
    printf("\n");
    //进度条
    const char* arr2[] = { "▌" };
    loading(arr2, sizeof(arr2) / sizeof(arr2[0]));
    printf("\n");
    return;
}
 int main()
 {
     Progress();
 }

#ifdef __cplusplus
}
#endif // __cplusplus