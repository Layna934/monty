#include <stdio.h>
#include <stdlib.h>
#include "monty.h"

int main(int argc, char *argv[])
{
	 int top = -1, box[SIZE];
	 int i, element;


	 if (argc < 2)
	 {
		 printf("Wrong argument number");
		 exit(EXIT_FAILURE);
	 }
	 else
	 {
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
