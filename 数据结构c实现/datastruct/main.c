#include "SqListOperation.h"
#include "LinkListOperation.h"
#include "DLinkListOperation.h"


int main()
{
    SeqList A,B;
    SeqList_Build(&A);
    //SeqList_Build(&B);
    SeqList_Print(A);
    printf("\n");
    //SeqList_Print(B);
    //printf("\n");



    printf("%d", Majority(A));



}
