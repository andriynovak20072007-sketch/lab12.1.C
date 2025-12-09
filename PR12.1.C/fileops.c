#define _CRT_SECURE_NO_WARNINGS
#include "fileops.h"
#include <stdio.h>
#include <stdlib.h>

void createFile(const char* filename)
{
    FILE* f = fopen(filename, "wb");
    if (!f) {
        printf("Failed to create file.\n");
        return;
    }

    double x;
    char cont;

    do {
        printf("enter number: ");
        scanf("%lf", &x);
        fwrite(&x, sizeof(double), 1, f);

        printf("continue? (y/n): ");
        scanf(" %c", &cont);

    } while (cont == 'y' || cont == 'Y');

    fclose(f);
}

int findValues(
    const char* filename,
    double* maxNeg,
    double* minPos
)
{
    FILE* f = fopen(filename, "rb");
    if (!f) {
        printf("Failed to open file.\n");
        return 0;
    }

    double x;
    int foundNeg = 0;
    int foundPos = 0;

    while (fread(&x, sizeof(double), 1, f) == 1)
    {
        if (x < 0)
        {
            if (!foundNeg || x > *maxNeg) {
                *maxNeg = x;
                foundNeg = 1;
            }
        }

        if (x > 0)
        {
            if (!foundPos || x < *minPos) {
                *minPos = x;
                foundPos = 1;
            }
        }
    }

    fclose(f);

    return foundNeg && foundPos;
}

void writeResults(
    const char* filename,
    double maxNeg,
    double minPos
)
{
    FILE* f = fopen(filename, "wb");
    if (!f) {
        printf("Failed to create file.\n");
        return;
    }

    fwrite(&maxNeg, sizeof(double), 1, f);
    fwrite(&minPos, sizeof(double), 1, f);

    fclose(f);
}

void printFile(const char* filename)
{
    FILE* f = fopen(filename, "rb");
    if (!f) {
        printf("Failed to open file.\n");
        return;
    }

    printf("\ncontents of the file \"%s\":\n", filename);

    double x;
    while (fread(&x, sizeof(double), 1, f) == 1)
        printf("%lf\n", x);

    fclose(f);
}