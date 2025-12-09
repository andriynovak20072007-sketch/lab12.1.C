#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include "fileops.h"

int main()
{
    char inputFile[100];
    char outputFile[100];

    printf("enter input file name:");
    scanf("%s", inputFile);

    createFile(inputFile);

    double maxNeg, minPos;

    if (!findValues(inputFile, &maxNeg, &minPos)) {
        printf("The file must contain at least one positive and one negative number.\n");
        return 0;
    }

    printf("enter output file name: ");
    scanf("%s", outputFile);

    writeResults(outputFile, maxNeg, minPos);
    printFile(outputFile);

    return 0;
}