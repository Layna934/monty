#include "monty.h"


char *checkStrings(char *str1, char *str2)
{
	while(*str1 != '\0' && *str2 != '\0')
	{
		if (*str1 != *str2)
		{
			printf("Unknown element");
			return (NULL);
		}
		str1++;
		str2++;
	}
	if (*str1 == '\0' && *str2 == '\0')
		return(str1);
}

void push(int element)
{
        top++;
        box[top] = element;
}

void pall()
{
        int i;
        for (i = top; i >= 0; i--)
        {
                printf("%d\n", box[i]);
        }
}
