#include <stdio.h> 
#include <stdlib.h>

//typedef unsigned char  Integer;
//typedef unsigned short Integer;
  typedef unsigned int   Integer;
//typedef unsigned long  Integer;

void Binary(Integer, Integer *); 
void PrintBinary(Integer);
Integer Process(Integer);

int main(void) 
{ 
	Integer num, result; 
   
	while (1) {  
		printf("Enter the number: ");
		scanf("%i", &num); 

		printf("Your number: %i = 0x%0*X = ", num, 8, num);
		PrintBinary(num);
		printf(" \n");

		result = Process(num);

		printf("Result     : %i = 0x%0*X = ", result, 8, result);
		PrintBinary(result);
		printf(" \n");
	}

	return 0; 
}

void Binary(Integer Num, Integer *p) 
{ 
	Integer quotient, i;
	i = (sizeof(Integer) * 8) - 1; 

	while (Num > 0) { 
		quotient = Num / 2; 
		p[i] = Num - (quotient * 2); 
		Num = quotient; 
		i--; 
	} 

}

void PrintBinary(Integer Num)
{
	Integer *b_arr, size, i;
	size = sizeof(Integer) * 8;
	b_arr = (Integer *)malloc(size * sizeof(Integer));

	for (i = 0; i < size; i++) 
		b_arr[i] = 0;
	Binary(Num, b_arr);
 
	for (i = 0; i < size; i++) { 
		printf("%d", b_arr[i]);
		
		if((i+1) % 8 == 0)
			printf(" ");
	}

	free(b_arr);
}

Integer Process(Integer Num)
{
	Integer *array, i, j, a, b, size, result;
	result = 0;
	size = sizeof(Integer);
	array = (Integer *)malloc(size * size);

	for(i = 0, j = size * 8; i < size; i++, j -= 8) {
		array[i] = Num >> (i * 8);
		array[i]  = array[i] & 0xFF;

		a = (array[i] & 0xF) << 4;
		b = array[i] >> 4;
		array[i] = a | b;

		array[i] = array[i] << (j - 8);
		result = result | array[i];
	}

	free(array);
	return result;
}

