#include <stdio.h>
#include <stdlib.h>
#include <string.h>
/*
 *
 * Given a roman numeral, convert it to an integer.
 *
 * Input is guaranteed to be within the range from 1 to 3999.
 */



int romanToInt(char* s);
int* charToIntArr(char* s);

int main(int argc, const char *argv[])
{
	
	char *roman1="CDLXXXXVI";
	int result=0;
	result=romanToInt(roman1);

	printf("\nthe result = %d\n", result);

	return 0;
}

int romanToInt(char* s) 
{
	int * romanArr;
	int * romanArr2;
	int origin_length=0;
	int arr2Index=0;
	origin_length=strlen(s);
	
  
	romanArr2 = malloc(sizeof(int)*origin_length);
	memset(romanArr2,0,origin_length);

	//convert char to Integer
	romanArr = charToIntArr(s);
	
//conbine same interger

	romanArr2[0]=romanArr[0];
	for(int i=1; i<origin_length; i++)
	{
		int same_count=0;	
		if(romanArr2[arr2Index]==romanArr[i])
		{
			same_count++;
		}
		else
		{
			if(same_count==0)
			{
				romanArr2[arr2Index++]=romanArr[i];
			}
			else
			{	
				romanArr2[arr2Index]+=romanArr2[arr2Index]*same_count;
				arr2Index++;
				same_count=0;
			}
		}
	}//end of for

	for(int i=0;i<strlen(s);i++)
	{
		printf("%d ", romanArr2[i]);
	}


//perform right combination rule
//if left >= right then add
//else then substract


	free(romanArr);
	free(romanArr2);
	return 0;

}

int* charToIntArr(char* s)
{
	int length=0;
	int* retArr;
	length =	strlen(s);
  
	retArr = malloc(sizeof(int)*length);

	for (int i=0;i<length;i++)
	{
		switch (s[i])
		{
			case 'I':
				retArr[i]=1;
			break;	
			case 'V':
				retArr[i]=5;
			break;
			case 'X':
				retArr[i]=10;
			break;
			case 'L':
				retArr[i]=50;
			break;
			case 'C':
				retArr[i]=100;
			break;
			case 'D':
				retArr[i]=500;
			break;
		}
	}//end of for

	return retArr;

}
