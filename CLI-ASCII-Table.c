#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdbool.h>

void main(int argc, char** argv)
{
	int iRows=16, iCols=8, iArguement;  
	bool bExtTable=false;	// Prints extended ASCII table if true

	// Check for CLI arguments 
	while((iArguement = getopt(argc, argv, "c:e")) != -1)
	{
	switch(iArguement)
		{
		case 'c':
			iCols = atoi(optarg);
			break;
		case 'e':
			bExtTable = true;
			break;
		default:
			abort();
		}
	}

	// Calculates number of rows to be printed
	if(bExtTable)
	{				
		iRows = (int)(256/iCols);
		if(256%iCols)
		iRows++;
	}
	else
	{
		iRows = (int)(128/iCols);
		if(128%iCols)
		iRows++;
	}

	// Prints the table
	for(int y = 0; y < iRows; y++)
	{
		for(int x = 0; x < iCols; x++)
		{
			int iNumber = y*iCols+x;

			if((iNumber > 127 && !bExtTable) || (iNumber > 255 && bExtTable))
				break;

			if(iNumber < 33 || (iNumber > 127 && iNumber < 160))
				printf("%3i:    ", iNumber);
			else
				printf("%3i: %c  ", iNumber, iNumber);
		}
		printf("\n");
	}
}
