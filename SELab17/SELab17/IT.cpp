#include "IT.h"
#include "Error.h"

IT::IdTable IT::Create(int size)
{
    if (size > TI_MAXSIZE) {
        throw ERROR_THROW(116);
    }

    IdTable itable;
    itable.maxsize = size;
    itable.size = 0;
    itable.table = new Entry[size];

    return itable;
}

IT::Entry IT::GetEnrty(IdTable& idtable, int n)
{
    return idtable.table[n];
}

int IT::IsID(IdTable& idtable, char id[ID_MAXSIZE])
{
    for (int i = 0; i < idtable.size; i++) {
        if (strcmp(idtable.table[i].id, id) == 0) {
            return i;
        }
    }
    return 0;
}

void IT::Add(IdTable& idtable, Entry entry) {
    if (idtable.size > idtable.maxsize) {
        throw ERROR_THROW(117);
    }
    idtable.table[idtable.size] = entry;
    idtable.size++;
}

void IT::Delete(IdTable& idtable) {
    delete[] idtable.table;
    idtable.size = 0;
    idtable.maxsize = 0;
}

int IT::search(IdTable& idtable, IT::Entry entry) // Функция для поиска идентификатора
{
    for (int i = 0; i <= idtable.size; i++)
    {
        if (strcmp(entry.id, idtable.table[i].id) == NULL && idtable.table[i].idtype == IT::F)
        {
            return i;
        }
        else
            continue;
    }
    return -1;
}

int IT::search_lt(IdTable& idtable, IT::Entry entry)
{

    return 0;
}
