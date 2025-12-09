#pragma once
#ifndef FILEOPS_H
#define FILEOPS_H

void createFile(const char* filename);

int findValues(
    const char* filename,
    double* maxNeg,
    double* minPos
);

void writeResults(
    const char* filename,
    double maxNeg,
    double minPos
);

void printFile(const char* filename);

#endif