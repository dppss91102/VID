#include"stdafx.h"
#include <stdio.h>
#include <time.h>
#include "ALP_parameter.h"

UCHAR *data[PicNum/2];

void MemoryMove(UCHAR *pImageData)
{
	/*
	for (int i=0;i<PicNum/2;i++)
	{
		data[i]=(UCHAR*) malloc(nSizeX*nSizeY);
	}
	*/
	static int Dir[2]={speed,speed/2};
	static int x=50,y=200;


	x+=Dir[0];
	y+=Dir[1];

	if (y>=(nowYSize-squareSize))
	{
		Dir[1]=-Dir[1];
		y+=Dir[1];
	}
	else if (x>=(nowXSize-squareSize))
	{
		Dir[0]=-Dir[0];
		x+=Dir[0];
	}
	else if (y<=100)
	{
		Dir[1]=-Dir[1];
		y+=Dir[1];
	} 
	else if (x<=0)
	{
		Dir[0]=-Dir[0];
		x+=Dir[0];
	}
	else
	{
	}
	
	for (int j=0;j<7;j++)
	{
		FillMemory( pImageData+j*nSizeX*nSizeY , nSizeX*nSizeY, 0x00 ); 
	}
	
	for (int j=7;j<8;j++)
	{
		for(int i=0;i<squareSize;i++)
		{
			FillMemory( pImageData+j*nSizeX*nSizeY + offSet + offSetY*nSizeX + x + y*nSizeX +i*nSizeX, squareSize, 0x80 ); 
		}
	}
	
	for (int j=8;j<16;j++)
	{
		for(int i=0;i<squareSize;i++)
		{
			FillMemory( pImageData+j*nSizeX*nSizeY + offSet + offSetY*nSizeX + x + y*nSizeX +i*nSizeX, squareSize, 0x80 ); 
		}
		for(int i=squareWidth;i<squareSize-squareWidth;i++)
		{
			FillMemory( pImageData+j*nSizeX*nSizeY + offSet + offSetY*nSizeX + x + squareWidth + y*nSizeX +i*nSizeX, squareSize-2*squareWidth, 0x00 ); 
		}
	}
	for (int j=16;j<17;j++)
	{
		for(int i=0;i<squareSize;i++)
		{
			FillMemory( pImageData+j*nSizeX*nSizeY + offSet + offSetY*nSizeX + x + y*nSizeX +i*nSizeX, squareSize, 0x80 ); 
		}
	}
	
	for (int j=17;j<32;j++)
	{
		FillMemory( pImageData+j*nSizeX*nSizeY , nSizeX*nSizeY, 0x00 ); 
	}
	
	for (int j=32;j<33;j++)
	{
		for(int i=0;i<squareSize;i++)
		{
			FillMemory( pImageData+j*nSizeX*nSizeY + offSet + offSetY*nSizeX + x + y*nSizeX +i*nSizeX, squareSize, 0x80 ); 
		}
	}
	
	for (int j=33;j<41;j++)
	{
		for(int i=0;i<squareSize;i++)
		{
			FillMemory( pImageData+j*nSizeX*nSizeY + offSet + offSetY*nSizeX + x + y*nSizeX +i*nSizeX, squareSize, 0x80 ); 
		}
		for(int i=squareWidth;i<squareSize-squareWidth;i++)
		{
			FillMemory( pImageData+j*nSizeX*nSizeY + offSet + offSetY*nSizeX + x + squareWidth + y*nSizeX +i*nSizeX, squareSize-2*squareWidth, 0x00 ); 
		}
	}
	for (int j=41;j<42;j++)
	{
		for(int i=0;i<squareSize;i++)
		{
			FillMemory( pImageData+j*nSizeX*nSizeY + offSet + offSetY*nSizeX + x + y*nSizeX +i*nSizeX, squareSize, 0x80 ); 
		}
	}
	
	for (int j=42;j<48;j++)
	{
		FillMemory( pImageData+j*nSizeX*nSizeY , nSizeX*nSizeY, 0x00 ); 
	}
	
	////////////////////////////
	/*
	for (int k=0;k<10;k++)
	{
		FillMemory( data[k] , nSizeX*nSizeY, 0x00 ); 
	}

	for(int k=10;k<15;k++)
	{
		for (int i=0;i<squareSize;i++)
		{
			FillMemory( data[k] + offSet + x +  y*nSizeX +i*nSizeX, squareSize, 0x80 ); 
		}
	}

	for (int k=15;k<35;k++)
	{
		for(int i=0;i<squareSize;i++)
		{
			FillMemory( data[k] + offSet + x + y*nSizeX +i*nSizeX, squareSize, 0x80 ); 
		}
		for(int i=squareWidth;i<squareSize-squareWidth;i++)
		{
			FillMemory( data[k] + offSet + x + squareWidth + y*nSizeX +i*nSizeX, squareSize-2*squareWidth, 0x00 ); 
		}
	}

	for(int k=35;k<40;k++)
	{
		for (int i=0;i<squareSize;i++)
		{
			FillMemory( data[k] + offSet + x +  y*nSizeX +i*nSizeX, squareSize, 0x80 ); 
		}
	}

	for (int k=40;k<50;k++)
	{
		FillMemory( data[k] , nSizeX*nSizeY, 0x00 ); 
	}


	for (int k=0;k<PicNum/2;k++)
	{
		for (int i=0;i<sizeof(data[0]);i++)
		{
			*(pImageData+k*sizeof(data[0])+i)=*(data[k]+i);
		}
	}
	for (int k=PicNum/2-1;k>=0;k)
	{
		for (int i=0;i<sizeof(data[0]);i++)
		{
		*(pImageData+sizeof(data[0])*PicNum/2+k*sizeof(data[0])+i)=*(data[k]+i);
		}
	}

	free(data);

	*/
}

void MemoryJump(UCHAR *pImageData)
{
	/*
	for (int i=0;i<PicNum/2;i++)
	{
		data[i]=(UCHAR*) malloc(nSizeX*nSizeY);
	}
	*/

	static int Rand,RandZ,x,y,cnt=5;
	/////////////////// Getting Random Number //////////////////

	if (cnt==5)
	{
		srand(time(NULL));
		do
		{
			Rand=rand()%(nowXSize*nowYSize)+1; //亂數位置
			RandZ=0; //亂數Z方向   rand()%picNum
			x=Rand%nowXSize; //取餘數
			y=Rand/nowXSize;
		}
		while(x>(nowXSize-squareSize)||Rand>(nowXSize*(nowYSize-squareSize)));
		cnt=0;
	}
	
		
		/*
		Rand
		↓
		-------------
		|			|
		|			|
		|			|
		-------------

		*/
	/////////////////// Fill the Memory  //////////////////
	for (int j=0;j<10;j++)
	{
		for(int i=0;i<squareSize;i++)
		{
			FillMemory( pImageData+j*nSizeX*nSizeY + offSet + offSetY*nSizeX + x + y*nSizeX +i*nSizeX, squareSize, 0x80 ); 
		}
		for(int i=squareWidth;i<squareSize-squareWidth;i++)
		{
			FillMemory( pImageData+j*nSizeX*nSizeY + offSet + offSetY*nSizeX + x + squareWidth + y*nSizeX +i*nSizeX, squareSize-2*squareWidth, 0x00 ); 
		}
	}

	for(int j=10;j<15;j++)
	{
		for (int i=0;i<squareSize;i++)
		{
			FillMemory( pImageData+j*nSizeX*nSizeY + offSet + offSetY*nSizeX + x +  y*nSizeX +i*nSizeX, squareSize, 0x00 ); 
		}
	}


	for (int j=15;j<35;j++)
	{
		FillMemory( pImageData+j*nSizeX*nSizeY , nSizeX*nSizeY, 0x00 ); 
	}

	for(int j=35;j<40;j++)
	{
		for (int i=0;i<squareSize;i++)
		{
			FillMemory( pImageData+j*nSizeX*nSizeY + offSet + offSetY*nSizeX + x +  y*nSizeX +i*nSizeX, squareSize, 0x00 ); 
		}
	}


	for (int j=40;j<50;j++)
	{
		for(int i=0;i<squareSize;i++)
		{
			FillMemory( pImageData+j*nSizeX*nSizeY + offSet + offSetY*nSizeX + x + y*nSizeX +i*nSizeX, squareSize, 0x80 ); 
		}
		for(int i=squareWidth;i<squareSize-squareWidth;i++)
		{
			FillMemory( pImageData+j*nSizeX*nSizeY + offSet + offSetY*nSizeX + x + squareWidth + y*nSizeX +i*nSizeX, squareSize-2*squareWidth, 0x00 ); 
		}
	}
	for(int j=50;j<65;j++)
	{
		for (int i=0;i<squareSize;i++)
		{
			FillMemory( pImageData+j*nSizeX*nSizeY + offSet + offSetY*nSizeX + x +  y*nSizeX +i*nSizeX, squareSize, 0x00 ); 
		}
	}

	for (int j=65;j<85;j++)
	{
		FillMemory( pImageData+j*nSizeX*nSizeY , nSizeX*nSizeY, 0x00 ); 
	}
	for(int j=85;j<90;j++)
	{
		for (int i=0;i<squareSize;i++)
		{
			FillMemory( pImageData+j*nSizeX*nSizeY + offSet + offSetY*nSizeX + x +  y*nSizeX +i*nSizeX, squareSize, 0x00 ); 
		}
	}
	for (int j=90;j<100;j++)
	{
		for(int i=0;i<squareSize;i++)
		{
			FillMemory( pImageData+j*nSizeX*nSizeY + offSet + offSetY*nSizeX + x + y*nSizeX +i*nSizeX, squareSize, 0x00 ); 
		}
		for(int i=squareWidth;i<squareSize-squareWidth;i++)
		{
			FillMemory( pImageData+j*nSizeX*nSizeY + offSet + offSetY*nSizeX + x + squareWidth + y*nSizeX +i*nSizeX, squareSize-2*squareWidth, 0x00 ); 
		}
	}
			/*/////////////////////////

	for (int k=0;k<10;k++)
	{
		FillMemory( data[k] , nSizeX*nSizeY, 0x00 ); 
	}

	for(int k=10;k<15;k++)
	{
		for (int i=0;i<squareSize;i++)
		{
			FillMemory( data[k] + offSet + x +  y*nSizeX +i*nSizeX, squareSize, 0x80 ); 
		}
	}

	for (int k=15;k<35;k++)
	{
		for(int i=0;i<squareSize;i++)
		{
			FillMemory( data[k] + offSet + x + y*nSizeX +i*nSizeX, squareSize, 0x80 ); 
		}
		for(int i=squareWidth;i<squareSize-squareWidth;i++)
		{
			FillMemory( data[k] + offSet + x + squareWidth + y*nSizeX +i*nSizeX, squareSize-2*squareWidth, 0x00 ); 
		}
	}

	for(int k=35;k<40;k++)
	{
		for (int i=0;i<squareSize;i++)
		{
			FillMemory( data[k] + offSet + x +  y*nSizeX +i*nSizeX, squareSize, 0x80 ); 
		}
	}

	for (int k=40;k<50;k++)
	{
		FillMemory( data[k] , nSizeX*nSizeY, 0x00 ); 
	}


	for (int k=0;k<PicNum/2;k++)
	{
		for (int i=0;i<sizeof(data[0]);i++)
		{
			*(pImageData+k*sizeof(data[0])+i)=*(data[k]+i);
		}
	}
	for (int k=PicNum/2-1;k>=0;k)
	{
		for (int i=0;i<sizeof(data[0]);i++)
		{
		*(pImageData+sizeof(data[0])*PicNum/2+k*sizeof(data[0])+i)=*(data[k]+i);
		}
	}

	free(data);

	*/


	cnt++;
}


void Mouse(UCHAR *pImageData,int X,int Y)
{
	int x=X-squareSize/2-squareWidth*3;
	int y=Y-squareSize/2-squareWidth*3;
	/*
											x,y
											↓
		-------------						-------------
		|	X,Y		|						|			|
		|	  ↓	|						|			|
		|			|						|			|
		-------------						-------------

	*/


	for (int i=0;i<squareWidth;i++)
	{
		FillMemory(pImageData + offSet + offSetY*nSizeX + x + y*nSizeX +i*nSizeX ,squareSize+squareWidth*6,0x80);
		FillMemory(pImageData + offSet + offSetY*nSizeX + x + y*nSizeX +i*nSizeX + lineLength,squareSize+squareWidth*6-2*lineLength,0x00);
	}
	for (int i=0;i<lineLength;i++)
	{
		FillMemory(pImageData + offSet + offSetY*nSizeX + x + y*nSizeX +i*nSizeX ,squareWidth,0x80);
		FillMemory(pImageData + offSet + offSetY*nSizeX + x + y*nSizeX +i*nSizeX + squareSize+squareWidth*6-squareWidth,squareWidth,0x80);
	}
	for (int i=0;i<lineLength;i++)
	{
		FillMemory(pImageData + offSet + offSetY*nSizeX + x + (y+squareSize-lineLength)*nSizeX +i*nSizeX ,squareWidth,0x80);
		FillMemory(pImageData + offSet + offSetY*nSizeX + x + (y+squareSize-lineLength)*nSizeX +i*nSizeX + squareSize+squareWidth*6-squareWidth,squareWidth,0x80);
	}
	for (int i=0;i<squareWidth;i++)
	{
		FillMemory(pImageData + offSet + offSetY*nSizeX + x + (y+squareSize+1)*nSizeX +i*nSizeX ,squareSize+squareWidth*6,0x80);
		FillMemory(pImageData + offSet + offSetY*nSizeX + x + (y+squareSize+1)*nSizeX +i*nSizeX + lineLength,squareSize+squareWidth*6-2*lineLength,0x00);
	}
}