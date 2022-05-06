#pragma once
#define ESCAPE 0xB1
#define TERMINATOR '\0'
#define MINRUN 4
#define ENCODESTR 4
#define BUFFLEN 300
#define RADIX 10
#define MAXVAL 255

#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <ctype.h>

int encode(char*, char*);

int decode(char*, char*);