/*
Given 4 strings, write a fucntion to get smallest string that consists all four strings. 
In Case of Multiple strings with smallest length,
Return the string which occurs alphabetically first .

Ex : (acat, tiger, silica, licaria) O/P: "silicariacatiger"
Ex : (def,abc,ghi,jkl)   O/P : “abcdefghijkl” (Alphabetically first )
Ex : (apple,pp,pineapple,nea) O/P: "pineapple";
Ex : (zzzabc,abcdef,yyyzzz,cabyyy) O/P: "cabyyyzzzabcdef" (Order Swapped )

Note : Each string given as input ,should be in the same format in the output string. 
Ie if input string is abcd ,it cannot be modified as bdca in the final string .

The Order of Strings in the Final string ,maynot be in the same order 
given in which they are given
Function Signatue : char * smallestword(char *s1,char *s2,char *s3,char *s4);

Note : You can use String.h functions .

Constraints : 
Length of each String will be less than 100 .

Difficulty : Hard
*/

#include <stdlib.h>
#include <string.h>
#include <stdio.h>

char * concat_4strings(char *s1, char *s2, char *s3, char *s4){
	//Return the new string created.
	int index,index1;
	char *res;
	bool *hash_table;
	if (s1 == NULL || s2 == NULL || s3 == NULL || s4 == NULL)
		return NULL;
	res = (char *)malloc(sizeof(char)*(strlen(s1) + strlen(s2) + strlen(s3) + strlen(s4) + 1));
	hash_table = (bool *)calloc(4, sizeof(bool));
	res = "\0";
	for (index = 0; index < 4; index++)
	{
		if (strstr(res, s1) == 0)
		{

		}
	}
}