#pragma once
typedef unsigned char SString[256];

void getNext(SString);
int indexKMP(SString, SString, int);
int getLen(SString);