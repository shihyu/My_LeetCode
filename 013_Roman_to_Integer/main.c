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
	
	//char *roman1="MCMXCVI";
	char *roman1="MMCCCXCIX";
	//char *roman1="MMMCMXCIX";
	int result=0;
	result=romanToInt(roman1);

	printf("\nthe result = %d\n", result);

	return 0;
}

int romanToInt(char* s) 
{
	int * romanArr=NULL;
	int * romanArr2=NULL;
	int origin_length=0;
	int arr2Index=0;
	int same_count=0;
	int result=0;
	origin_length=strlen(s);
	
  
	romanArr2 = malloc(sizeof(int)*origin_length);
	memset(romanArr2,0,origin_length);

	//convert char to Integer
	romanArr = charToIntArr(s);
	
//conbine same interger

	romanArr2[0]=romanArr[0];

	for(int i=1; i<origin_length; i++)
	{
		if(romanArr2[arr2Index]==romanArr[i])
		{
			same_count++;
		}
		else
		{
			if(same_count==0)
			{
				romanArr2[++arr2Index]=romanArr[i];
			}
			else
			{	
				romanArr2[arr2Index]=romanArr2[arr2Index]*(same_count+1);
				romanArr2[++arr2Index]=romanArr[i];
				same_count=0;
			}
		}
	}//end of for



//perform right combination rule
//if left >= right then add
//else then substract

	result=romanArr2[origin_length-1];
	printf("%d ", result);
	for (int i = origin_length-2;i>=0;i--)
	{
		if(romanArr2[i] < result )
		{
			result = result - romanArr2[i];
		}
		else 
		{
			result = romanArr2[i] + result;

		}
		printf("%d ", result);
	}//end of for



	free(romanArr);
	free(romanArr2);
	return result;

}

int* charToIntArr(char* s)
{
	int length=0;
	int* retArr=NULL;
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
			case 'M':
				retArr[i]=1000;
			break;
		}
	}//end of for

	return retArr;

}
