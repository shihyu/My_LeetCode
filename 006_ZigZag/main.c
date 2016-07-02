#include <stdio.h>
#include <stdlib.h>
#include <string.h>


/*
 *
 *The string "PAYPALISHIRING" is written in a zigzag pattern on a given number of rows like this: (you may want to display this pattern in a fixed font for better legibility)

 P   A   H   N
 A P L S I I G
 Y   I   R
 And then read line by line: "PAHNAPLSIIGYIR"
 Write the code that will take a string and make this conversion given a number of rows:

 string convert(string text, int nRows);
 convert("PAYPALISHIRING", 3) should return "PAHNAPLSIIGYIR".
 *
 *
 */

char* convert(char* s, int numRows);

int main(int argc, const char *argv[])
{
	char* testCase="ABCDEFGHIJKLMNO";	
  char* result;
	result = convert(testCase,4);

	printf("result=%s\n", result);

	free(result);
	return 0;
}

char* convert(char* s, int numRows)
{
	char* tempStr;
	int index=0;
	//int row_count=0;
	int length=strlen(s);
	tempStr=malloc(sizeof(char)*length);
	
	//end of each rows
	for(int i=0;i<numRows;i++)
	{
		//for each columns
		for(int j=i;j<length;j+=(2*(numRows-1)))
		{
		  printf("%c ", s[j]);	
			tempStr[index++]=s[j];
			if(i >0 && i<numRows-1 && (j+((numRows-i-1)*2)) < length)
			{	
				tempStr[index++]=s[j+((numRows-i-1)*2)];
				printf("%c ", s[j+((numRows-i-1)*2)]);
			}//end of if	
					
		}//end of for - columns
	}//end of for - rows 
return tempStr;
}
