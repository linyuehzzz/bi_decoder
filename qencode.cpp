#include "qencode.h"
#include <QtAlgorithms>
#include <QTextCodec>
#include <QList>
#include <iostream>
#include <QString>
using namespace std;

QEncode::QEncode()
{
}

QList<ENCODE> QEncode::getSortedList(QList<ENCODE> list)
{
    for(int i = 0; i<list.size(); i++)
    {
        for (int j = i+1; j < list.size(); j++)
        {
            //排序条件:按id从小到大
            if(list.at(i).id > list.at(j).id)
            {
                list.swap(i,j);
            }
        }
    }//end.for
    return list;
}

void QEncode::addCode(ENCODE code)
{
    encode.append(code);
}

void QEncode::codePr()
{
    ENCODE code;
    int count=sortedEncode.size();
    for(int i=0;i<count;i++)
    {
        code=sortedEncode.at(i);
        cout << code.ch;
    }
}
