#include <stdio.h>
#include <stdlib.h>
#include<string.h>

struct sequential
{
    char filename[16];
    int startblock;
    int length;
};
int numberoffilesS=5;
struct sequential s[5]={{"count",0,2},{"tr",14,3},{"mail",19,6},{"list",28,4},{"t",6,2}};

struct linked
{
    char filename[16];
    int startblock;
    int endblock;
};
int numberoffilesL=1;
struct linked l[1]={"jeep",9,25};

struct block
{
    int blocknumber;
    struct block *next;
}blockentry[30];

int i;
int j;
char filename[20];

void sequentialfile()
{
    printf(" enter the sequential file name to be searched\n");
    scanf("%s",filename);
    for(i=0;i<numberoffilesS;i++){
        if(strcmp(filename,s[i].filename)==0)
        {
            printf("\n file name\t Start Block\t number of blocks\tblocks occupied");
            printf("\n%s\t\t%d\t\t%d\t\t",s[i].filename,s[i].startblock,s[i].length);
            j=0;
            do
            {
                printf("%d",s[i].startblock+j);
                j++;
            }while(j<s[i].length&&printf("->"));
            printf("\n");return;
        }
        return;
    }
}

void linkedfile()
{
    int numberofblocks=0;
    printf("\n enter the linked file name to be searched");
    scanf("%s",filename);
    for(i=0;i<numberoffilesL;i++)
        if(strcmp(filename,l[i].filename)==0)
        {
            printf("\n file name\t Start Block\t endblock\t  blocks occupied");
            printf("\n%s\t\t%d\t\t%d\t",l[i].filename,l[i].startblock,l[i].endblock);
            struct block *blockptr=&blockentry[l[i].startblock];
            do
            {
                printf("%d",blockptr->blocknumber);
                blockptr=blockptr->next;
                numberofblocks++;
            }while(blockptr!=NULL&&printf("->"));
            printf("\n number of blocks occupied=%d\n",numberofblocks);
            return;
        }
        return;
}

int main()
{
    sequentialfile();
    blockentry[9].blocknumber=9;blockentry[9].next=&blockentry[16];
    blockentry[16].blocknumber=16;blockentry[16].next=&blockentry[1];
    blockentry[1].blocknumber=1;blockentry[1].next=&blockentry[25];
    blockentry[25].blocknumber=25;blockentry[25].next=NULL;
    linkedfile();
    return 0;
}
