#include <stdio.h>
#include <stdlib.h>

int main(void){
	system("lualatex Team_31_Assignment_2.tex && biber Team_31_Assignment_2 && lualatex Team_31_Assignment_2.tex && lualatex Team_31_Assignment_2.tex");
	return 0;
}