/* 1.9 Character Arrays */

#include <stdio.h>
#define MAXLINE 1000

int max; 				/* maximum length so far */
char line[MAXLINE];		/* current input line */
char longest[MAXLINE]; 	/* longest line saved here */

int getline__(void);
void copy(void);


int main() 
{
	int len;				/* current line length */
	extern int max;
	extern char longest[];

	max = 0;
	while ((len = getline__()) > 0)
		if (len > max) {
			max = len;
			copy();
		}
	if (max > 0) {  /* there was a line */
		printf("%s", longest);
	}
	return 0;	
}

int getline__(void)
{
	int c, i;
	extern char line[];
	
	for (i = 0; i < MAXLINE-1 && (c=getchar()) != 'X' && c!='\n'; ++i)
		line[i] = c;
	if (c == '\n') {
		line[i] = c;
		i++;
	}
	line[i] = '\0';
	return i;
}

void copy()
{
	int i;
	extern char line[], longest[];

	i = 0;
	while ((longest[i] = line[i]) != '\0')
		++i;
}





