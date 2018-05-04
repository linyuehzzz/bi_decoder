#ifndef QENCODE_H
#define QENCODE_H
#include <QList>

struct encode_Struct{
    char ch;
    int id;
};

typedef struct encode_Struct ENCODE;

class QEncode
{
public:
    QEncode();
    QList<ENCODE> encode;
    QList<ENCODE> sortedEncode;
    QList<ENCODE> getSortedList(QList<ENCODE> list);
    void addCode(ENCODE code);
    void codePr();
};

#endif // QENCODE_H
