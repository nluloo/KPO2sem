#include "LT.h"

LT::LexTable LT::Create(int size)
{
    LexTable table;
    if (size > LT_MAXSIZE) {
        throw ERROR_THROW(116);
    }
    else {

        table.maxsize = size;
        table.size = 0;
        table.table = new Entry[size];
    }
    return table;
}

void LT::Add(LexTable& lextable, Entry entry)
{
    if(lextable.size < lextable.maxsize)
    lextable.table[lextable.size] = entry;
    lextable.size++;
}


LT::Entry LT::GetEntry(LexTable& lextable, int n)
{
    return lextable.table[n];
}

void LT::Delete(LexTable& lextable) {
    delete[] lextable.table;
    lextable.size = 0;
}
