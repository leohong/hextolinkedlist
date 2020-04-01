
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "utilHexToBinAPI.h"

int main(int argc, char **argv)
{
    FILE *fp = NULL;
    sHexList sHeader;
    sHexList sAppCode;
    sHexList *psHead = &sHeader;

    printf("Program Start\n");
    printf("File Name: %s\n", argv[1]);
    utilIntel_Hex_Parser(argv[1], &sHeader, 1024);

	// Show all sections
	while(NULL != psHead) {
		printf("=========================\n");
		printf("Address =%X\n", psHead->address);
		printf("Size = %d\n", psHead->size);
		printf("Bufpoint =%p\n", psHead->pcBuffer);
		psHead = psHead->next;
	}

    printf("=========================\n");
    if (TRUE == utilIntel_Hex_List_Find(&sHeader, 0x1A008000, &sAppCode)) {
        printf("Address = %X\n", sAppCode.address);
        printf("Size = %x\n", sAppCode.size);
    } else {
        printf("Not Found!\n");
    }

    printf("=========================\n");
    if (TRUE == utilIntel_Hex_List_Find(&sHeader, 0x1A008200, &sAppCode)) {
        printf("Address = %X\n", sAppCode.address);
        printf("Size = %x\n", sAppCode.size);
    } else {
        printf("Not Found!\n");
    }

	utilIntel_Hex_List_Free(&sHeader);

    return 0;
}
