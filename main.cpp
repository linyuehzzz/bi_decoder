#include <QCoreApplication>
#include <QFile>
#include <iostream>
#include <QList>
#include <QDebug>
#include "qencode.h"
using namespace std;

void fileRead();
void fileWrite();
QEncode enCode;

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    fileRead();
    enCode.sortedEncode=enCode.getSortedList(enCode.encode);
    enCode.codePr();
    fileWrite();

    return a.exec();
} 

void fileRead()
{
    //二进制文件读取

    FILE *file=fopen("Encode2.da","rb");
    if(file==NULL)
    {
         fputs("Can't open the file!",stderr);
         exit(1);
    }

    /*获取文件大小*/
    fseek(file,0,SEEK_END);
    long len=ftell(file);
    rewind(file);

    /*分配内存存储整个文件*/
    char* buf = new char[len];
    if(buf==NULL)
    {
        fputs("Memory Error!",stderr);
        exit(2);
    }

    /*将文件拷贝到buf中*/
    fread(buf,1,len,file);

    /*将buf中的数据存入结构体*/
    ENCODE code;
    for(int i=0;i<len/5;i++)
    {
        code.ch=*(buf+5*i);
        int* b=(int*)(buf+5*i+1);
        code.id=*b;
        enCode.addCode(code);
    }
    fclose(file);
    delete[] buf;
}

void fileWrite()
{
    //二进制文件写入

    FILE *file=fopen("D:/Lydia/c++/practise_1/practise_1/SortedEncode2.da","wb");
    if(file==NULL)
    {
         fputs("Can't open the file!",stderr);
         exit(1);
    }
    ENCODE code;
    int len=enCode.sortedEncode.size();
    char* buf = new char[len];
    for (int i = 0; i<len; i++)
    {
        code=enCode.sortedEncode.at(i);
        char a=code.ch;
        *(buf+i)=a;
    }

    fwrite (buf,sizeof(char), sizeof(buf), file);
    fclose(file);
    delete[] buf;
}
