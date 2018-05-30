#pragma once
#include <time.h>
#include <TCHAR.h>
#include <windows.h>
#include <conio.h>
#include <stdio.h>
#include "..\alp.h"

#define speed		0
#define nowXSize	400//460
#define nowYSize	550//680
#define offSet		280 //notice the parameter should less than 1024-2*width of picturebox
#define offSetY		70
#define nSizeX		1024
#define nSizeY		768
#define PicNum		48
#define squareSize	150
#define squareWidth	8
#define lineLength	60

void MemoryMove(UCHAR *pImageData);
void MemoryJump(UCHAR *pImageData);
void Mouse(UCHAR *pImageData,int x,int y);