#include <stdio.h>
#include <stdlib.h>

typedef struct cell
{
    struct cell *Next;
    struct cell *Prev;
    int Val;
} *Cell;

typedef struct
{
    Cell Start;
    Cell End;
    int length;
} ListDouble;
ListDouble initialization()
{
    ListDouble L;
    L.End = L.Start = NULL;
    L.length = 0;
    return L;
}
Cell createCell(int x)
{
    Cell Nv = malloc(sizeof(Cell));
    Nv->Val = x;
    Nv->Next = Nv->Prev = NULL;
    return Nv;
}

void AddBegin(ListDouble *L, int x)
{
    Cell New = createCell(x);
    if (!L->Start)
    {
        L->Start = L->End = New;
        L->length = 1;
        return;
    }
    New->Next = L->Start;
    L->Start->Prev = New;
    L->Start = New;
    L->length++;
}

void AddEnd(ListDouble *L, int x)
{
    Cell New = createCell(x);
    if (!L->End)
    {
        L->Start = L->End = New;
        L->length = 1;
        return;
    }
    New->Prev = L->End;
    L->End->Next = New;
    L->End = New;
    L->length++;
}
void PrintLD(ListDouble L)
{
    int i;
    for (i = 0; i < L.length; i++)
    {
        printf("%d ->", L.Start->Val);
        L.Start = L.Start->Next;
    }
    puts("NULL\n=================================================");
}

void RemoveBegin(ListDouble *L)
{
    if (!L->length)
    {
        *L = initialization();
        return;
    }
    Cell cll;
    cll = L->Start;
    (*L).Start = (*L).Start->Next;
    if (L->Start)
        (*L).Start->Prev = NULL;
    else
        L->End = NULL;
    (*L).length--;
    free(cll);
}

void RemoveAll(ListDouble *L)
{
    if (!L->length)
        return;
    int i, l;
    l = L->length;
    for (i = 0; i < l; i++)
    {
        RemoveBegin(L);
    }
}
int main(int argc, char const *argv[])
{
    ListDouble L = initialization();
    AddBegin(&L, 3);
    AddBegin(&L, 4);
    AddBegin(&L, 2);
    AddBegin(&L, 1);
    PrintLD(L);
    AddEnd(&L, 10);
    PrintLD(L);
    RemoveAll(&L);
    // RemoveBegin(&L);
    AddEnd(&L, 10);
    PrintLD(L);
    return 0;
}
