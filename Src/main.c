#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "stdbool.h"
#include "cura.h"

//int num[5] = {1, 2, 3, 4, 1};

char date[500][5];

#define MAXLEN 445296
int cnt = 0;
//读取文件filename的内容到dest数组，最多可以读maxlen个字节
//成功返回文件的字节数，失败返回－1
int read_file(const char *filename)
{
    FILE *file;
    int pos, temp, i;

    //打开文件
    file = fopen(filename, "r");
    fseek(file,0,SEEK_SET);
    if( NULL == file )
    {
        fprintf(stderr, "open %s error\n", filename);
        return -1;
    }
    //循环读取文件中的内容
    for(i=0; i<100; i++)
    {
        for(int j=0;j<5;j++)
        {
            fscanf(file,"%s",&date[i][j]);
            fseek(file,1L,SEEK_CUR);
        }
    }
    for(i=0; i<SEEK_END; i++)
    {
        printf("%s\t",&date[i][0]);
    }
    //关闭文件
    fclose(file);
    //在数组末尾加0

    return pos;
}


int main() {
//    int a = 5;
//    char High = a >> 8;
//    char low = (a << 8) >> 8;
//    printf("%x %x", High, low);
    char buffer[MAXLEN];
    read_file("C://Users/22755/Documents/Tencent Files/3280736583/FileRecv/123.xlsx");
//    containsDuplicate(num, 5);
    return 0;
}

