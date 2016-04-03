/*
Given an array which has two arithmetic sequences and 
one geometric sequence (in any order).
Copy indexes where each sequence starts and ends into an Array and return it.

Note : Each sequence will be of atleast LENGTH 3,and The sequences can be overlapping

Ex : 1, 3, 5, 7, 2, 4, 8, 16 18 20, output is [0, 3, 7, 9, 4, 7]
Ex : 1 ,2, 4, 8, 12, 16, 21, 26     output is [2, 5, 5, 7, 0, 3]
Ex : 10 15 20 30 50 70 100 200 400 800  output is [0, 2, 3, 5, 6, 9]

The final_arr[0], final_arr[1] values in final array  
will be start and end indexes of First A.P in the Original Array

The final_arr[2], final_arr[3] values in final array  
will be start and end indexes of Second A.P 

The final_arr[4], final_arr[5] values in final array  
will be start and end indexes of First  G.P (Only)

Input: Array and Length of Array
Output : New Array which has 6 integers , which denote the (start,end) indexes .

Note : All elements in the array will be part of atleast 1 sequence .
Two A.P cannot start at same index . 

Difficulty : Medium
*/

#include <stdlib.h>
#include <stdio.h>
#include <math.h>
 
void geometric(int *arr, int size, int *res)
{
	int index,ratio;
	for (index = 0; index < size - 2; index++)
	{
		if (((float)arr[index + 1] / arr[index]) == ((float)arr[index + 2] / arr[index + 1]))
		{
			ratio = arr[index + 1] / arr[index];
			break;
		}
	}
	res[4] = index;
	for (index+=1; index < size; index++)
	{
		if (arr[index] != arr[index - 1] * ratio)
			break;
	}
	res[5] = index - 1;
}
 void arithe_matic(int *arr, int size,int start, int *res, int res_index)
{
	int index, index_start, diff;

	for (index = start; index < size-2; index++)
	{
		if (arr[index + 1] - arr[index] == arr[index + 2] - arr[index + 1])
		{
			index_start = index;
			diff = arr[index + 1] - arr[index];
			break;
		}
	}
	res[res_index++] = index_start;
	for (index+=1; index < size; index++)
	{
		if (arr[index] != arr[index - 1] + diff)
			break;
	}
	res[res_index] = index - 1;
}
int * find_sequences(int *arr, int len){
	//Return final array which has 6indexes [AP1_S,AP1_E,AP2_S,AP2_E,GP1_S,GP2_E]
	int *res, index, index_start;
	if (arr == NULL || len <= 0)
		return NULL;
	res = (int *)malloc(sizeof(int)* 6);
	arithe_matic(arr, len,0, res, 0);
	arithe_matic(arr, len,res[1], res, 2);
	geometric(arr, len, res);
	return res;
}
