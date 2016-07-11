#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

char* mytrim(char* str);
int myAtoi(char* str);
int charToInt(char ch);
int isNum(int input);

int main(int argc, const char *argv[])
{
	char* input="+-2";
	int result=0;
	result=myAtoi(input);
	printf("result=''%d''\n", result);

	return 0;
}

int charToInt(char ch)
{
	int tmp=(int)ch;

	if(tmp==32)
	{ //if space
		return 32;
	}
	else if(tmp==45)
	{ //if minus -
		return 45;
	}
	else if(tmp<48 && tmp>57)
	{
		return -1;
	}
	return tmp-48;

}

int isNum(int input)
{
	if(input >= 0 && input <= 9 )
	{
		return 1;
	}
	else
	{
		return 0;
	}
}
int* charArrToIntArr(char* str)
{
		int Length=strlen(str);
		int* tempArr=malloc(sizeof(int)*Length);
		for(int i=0; i<Length; i++)
			tempArr[i]=charToInt(str[i]);

		return tempArr;
}

int myAtoi(char* str) 
{
	int* tempArr=NULL;
	int length=0;
	int positive=1;
	int first=-1, last=-1;
	int count=0;
	int result=0;

	//trim the string 
	tempArr=charArrToIntArr(str);
	length=strlen(str);

	//get the position of first sequence 
	for (int i=0; i<length; i++)
	{
		
		if(tempArr[i]==45 && i < length-1 &&first==-1)
		{ //if there is a "-"i, then check next one, 
			//if next one is numeric then go to next circle
			//if not, mean this case is not a numeric case, jsut return 0
			if(isNum(tempArr[i+1]))
			{
				positive=-1;
				continue;
			}
			else
			{
				return 0;
			}			
		}//end of 
		else if(isNum(tempArr[i]) && first==-1)
		{
			//if this is the first found numeric,
			//then record the positon as start and end
			first=i;
			last=i;
		}
		else if(isNum(tempArr[i]) && first !=-1)
		{
			//if this is not the first numeric,
			//just change the index of last 
			last=i;
		}
		else if(!isNum(tempArr[i]) && first != -1)
		{	
			//if last one is numeric and this one isn't
			//meant it's the end of this sequence,
			//just break this loop
			break;
		}
		else if(!isNum(tempArr[i]) && first==-1)
		{
			return 0;
		}

	}//end of for


	count=(last-first);

	//start convert
	for(int i=first; i<=last ; i++)
	{
	
		//prevent overflow here
		if( tempArr[i] > 2 && result > 147483647)
								return 0;	
		
		result+=tempArr[i]*pow(10, count--);


	}//end of for

	result*=positive;

	free(tempArr);

	return result;

}


