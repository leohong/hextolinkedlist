# Hex to linked-list
This program will read each segment of hex file into a link list node. Users can get the specific segment by calling the "utilIntel_Hex_List_Find" function.
## Make
```
$ make
gcc -g   -c -o utilHexToBin.o utilHexToBin.c
gcc -g   -c -o main.o main.c
gcc utilHexToBin.o main.o -o HexToLinklist
```
## Example
```
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
```
Result:
```
$ ./HexToLinklist docking_board.hex 
Program Start
File Name: docking_board.hex
=========================
Address =1
Size = 0
Bufpoint =0x7f956a9b99a0
=========================
Address =1A000000
Size = 29696
Bufpoint =0x558cf0c168d0
=========================
Address =1A008000
Size = 1024
Bufpoint =0x558cf0c1d930
=========================
Address =1A008200
Size = 77824
Bufpoint =0x558cf0c1d970
=========================
Address = 1A008000
Size = 400
=========================
Address = 1A008200
Size = 13000
```
