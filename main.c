/**
 * @brief プログラムメイン
 * 
 * @file main.c
 * @author your name
 * @date 20XX-XX-XX
 */
#include <stdio.h>
#include <stdarg.h>
#include <string.h>
/**
 * @brief 
 * 
 * @param format 
 * @param ... 
 * @return int 
 */
int add_prefix_printf (const char *format, ...)
{
    int ret;
    va_list ap;
    char add_prefix_format[128];
    memset(add_prefix_format, 0, sizeof(add_prefix_format));
    snprintf(add_prefix_format, sizeof(add_prefix_format), "[command line info]: %s", format);
    add_prefix_format[sizeof(add_prefix_format)-1] = 0;
    va_start(ap, format);
    ret = vprintf(add_prefix_format, ap);
    va_end(ap);
    return ret;
}

/**
 * @brief ユーザー実行内容を表示するプログラムのエントリーポイント
 * 
 * @param argc 引数の数（argument count の略）
 * @param argv 引数文字列の配列（argument vector の略）
 * @return int プログラム終了コード
 */
int main(int argc, char const *argv[])
{
    /* 引数の数分ループ */
    for(int i = 0; i < argc; i++)
    {
        /* 標準出力：各引数文字列 */
        add_prefix_printf("%s\n", argv[i]);
    }
    /* プログラム終了コード返却 */
    return 0;
}
