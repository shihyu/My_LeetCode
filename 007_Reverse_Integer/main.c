#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <limits.h>

int reverse(int x);
int main(int argc, const char *argv[])
{
	
	int input=1534236469;
	int result=0;
	result=reverse(input);
	
	printf("result=%d\n", result);

	return 0;
}

int reverse(int x) {

	int positive=1;
  int count=0;
	int result=0;
	int Q = 0;

	if (x<0)
	{
		positive=-1;
		x*=-1;
	}
	if(x==0)
		return 0;
	



	//calculate counts
	
	while(x >= (pow(10,count)))
		count++;


	for(int i=1; i<=count;i++)
	{
		Q=x / pow(10,count-i);
		x= (int)(x % (int)pow(10,count-i));
		
		//prevent overflow here
		if((i-1)>=9 && (Q>=2 && result > 147483647))
		{
				return 0;
		}
			
		result=result+Q*pow(10,i-1);
	}
	
	result*=positive;


	printf("result=%d\n", result);
	return result;

	    

}
