#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <limits.h>

char* mytrim(char* str);
int myAtoi(char* str);
int charToInt(char ch);
int isNum(int input);

int main(int argc, const char *argv[])
{
	char* input="    +11191657170";
	int result=0;
	result=myAtoi(input);
	printf("result=''%d''\n", result);

	return 0;
}

int charToInt(char ch)
{
	int tmp=(int)ch;

  //if 	- + space, just return
	if(tmp==45 || tmp==43 || tmp==32 )
	{
		return tmp;
	}
	else if(tmp<48 && tmp>57)//is not numeric just return -1
	{
		return -1;
	}//else -48, meant 0~9
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
		
		if((tempArr[i]==43 || tempArr[i]==45) && i < length-1 &&first==-1)
		{ //if there is a "-"i, then check next one, 
			//if next one is numeric then go to next circle
			//if not, mean this case is not a numeric case, jsut return 0
			
			if(isNum(tempArr[i+1]))
			{
				positive=44-tempArr[i];
				continue;
			}
			else
			{
				return 0;
			}			
		}//end of
	  else if(first==-1 &&tempArr[i]==0)
		{
			//find the next non zero numeric
			for(int ss=i;ss<length;ss++)
			{
				if(!isNum(tempArr[ss]))
				{
					//if next one is not numeric just return 0
					return 0;
				}
				else if(tempArr[ss]!=0)
				{
					//found the next non zero numeric
					i=ss-1;
					break;
				}
			}	
		
		}	
		else if(isNum(tempArr[i]) && tempArr[i]!=0 && first==-1)
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
		else if(!isNum(tempArr[i]) && tempArr[i]!=32 && first==-1)
		{
			//the first non-numeric is not space
			return 0;
		}

	}//end of for


	//check the overflow
	if(last-first > 9 || (last-first >= 9 && tempArr[first]>2))
	{
		if(positive == 1)
			return INT_MAX;
		else
			return INT_MIN;
	
	}
		
	//start convert
	for(int i=last; i>=first ; i--)
	{
	
		//prevent overflow more detaily here
		if(tempArr[i] >= 2 && result > 147483647)
		{
			if(positive==1)
				return INT_MAX;
			else
				return INT_MIN;	
		}
		result+=tempArr[i]*pow(10, count++);


	}//end of for

	result*=positive;

	free(tempArr);

	return result;

}


