#ifndef LINSVG_H
#define LINSVG_H
#include"LinSetClass.h"
class svg
{
public:
	svg();
	~svg();
    void flush(int total, int *p,fileIfo *Head[],int *color,QString temppath);

private:
    const char * head;
};

#endif
