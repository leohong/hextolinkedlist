#ifndef UTILHEXTOBINAPI_H
#define UTILHEXTOBINAPI_H
// ===============================================================================
// FILE NAME: utilHexToBinAPI.h
// DESCRIPTION:
//
//
// Modification History
// --------------------
// 2014/06/14, Leo Create
// --------------------
// ===============================================================================

#include "types.h"

struct node {
    int address;
    int size;
    struct node *next;
    char *pcBuffer;
};

typedef struct node sHexList;


BOOL utilIntel_Hex_Parser(const char *fileName, sHexList *psHeader, int pageSize);
void utilIntel_Hex_List_Free(sHexList *psHeader);
BOOL utilIntel_Hex_List_Find(sHexList *psHeader, int address, sHexList *psNode);
#endif /* UTILHEXTOBINAPI_H.h */
