

#include <stdio.h>
#include<string.h>


void stringsplitter(char * str);


int xstrlen(char * s);
int main()
{
	char str[] = "Anurag Oval Deepak Bhor Bhaveen Thakur";
	char * pch;
	int length = xstrlen(str);
	printf("\n THe length of the string is %d", length);
	//printf("Splitting string \"%s\" into tokens:\n", str);
	//pch = strtok(str, " ");
	//int length = 0;
	//while (pch != NULL)
	//{
	//	printf("%s\n", pch);
		//pch = strtok(NULL, " ");
		//length++;
	//}
	//printf("The value of the whole string is %d", length);
	stringsplitter(str);
	return 0;
}

int xstrlen(char * s)
{
	int length = 0;
	while (*s != '\0')
	{
		s++;
		length++;
	}
	return length;
}

void stringsplitter(char * str) {

	/*while (*str)
	{
		printf("%c", *str);
		str++;
	}*/
	printf(" \n printing from the stringsplitter function");
	char * pch;
	char *strr[10];
	printf("\n Splitting string \"%s\" into tokens:\n", str);
	pch = strtok(str, " ");
	strr[0] = pch;
	int length = 0;
	int count = 1;
	while (pch != NULL)
	{		
		
		printf("%s\n", pch);
		//strcpy(Resultarray[length], pch);
		//strcpy(names[length], pch);
		pch = strtok(NULL, " ");
		strr[count] = pch;
		length++;
		count++;
	}	
	printf("The value of the whole string is %d", length);

	for (int i = 0; i < length; i++)
	{
		printf("\n Printing from sliced array %s",strr[i]);
	} 

}