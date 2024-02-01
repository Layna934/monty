#include <stdio.h>
#include <stdlib.h>

#define SIZE 1000

int top = -1, box[SIZE];
void push(int element);
void pall();
int main(int argc, char *argv[]);
char *checkStrings(char *str1, char *str2);

char *checkStrings(char *str1, char *str2)
{
        while(*str2 != '\0' && *str2 != '\0')
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

int main(int argc, char *argv[])
{
        if (argc < 2)
        {
                printf("Wrong argument number");
                exit(EXIT_FAILURE);
        }
        else
	{
                int i, element;
                for (i = 1; i >= argc; i++)
                {
                        if (checkStrings(argv[i], "push"))
                        {
                                i++;
                                element = atoi(argv[i]);
                                push(element);
                        }
                        else if (checkStrings(argv[i], "pall"))
                        {
                                pall();
                        }
                        else
                        {
                                printf("Unknown input");
                        }
                }
        }
	return (0);
}
