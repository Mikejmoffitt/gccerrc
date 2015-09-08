#include "txtcolor.h"
#include <strings.h>
#include <stdio.h>

#define BUFFER_LEN 128

int is_alpha(char c)
{
	return (c >= 'a' && c <= 'z') ? 1 : 0;
}

int is_num(char c)
{
	return (c >= '0' && c <= '9');
}

int main(int argc, char **argv)
{
	textcolor(COL_BRIGHT, COL_WHITE, COL_BLACK);
	char buffer[BUFFER_LEN];
	char *ptr = &buffer[0];
	buffer[0] = '\0';
	int c = '\0';
	while (c != EOF)
	{
		c = getchar();
		if (c == EOF)
		{
			return 0;
		}

		// If it's an alpha character...
		if (is_alpha((char)c) && ptr < &buffer[BUFFER_LEN - 2])
		{	
			// Copy it to our buffer
			*ptr = c;
			ptr++;
			*ptr = '\0';
		}
		else
		{
			if (!strcasecmp("error",buffer))
			{
				textcolor(COL_BRIGHT, COL_RED, COL_BLACK);
			}
			else if (!strcasecmp("warning",buffer))
			{
				textcolor(COL_BRIGHT, COL_YELLOW, COL_BLACK);
			}
			printf("%s",buffer);
			if (is_num(c))
			{
				textcolor(COL_BRIGHT, COL_GREEN, COL_BLACK);
			}
			else if (c == '^')
			{
				textcolor(COL_BRIGHT, COL_MAGENTA, COL_BLACK);
			}
			printf("%c",c);
			textcolor(COL_BRIGHT, COL_WHITE, COL_BLACK);
			ptr = &buffer[0];
			buffer[0] = '\0';
		}
	}
	(void)argv;
	(void)argc;
	return 0;
}
