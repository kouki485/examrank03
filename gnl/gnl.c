//735

#include "gnl.h"

char *get_next_line(int fd)
{
	int len;
	int i = 0;
	char c;
	char *str = malloc(10000);

	while((len = read(fd,&c,1)) > 0)
	{
		str[i] = c;
		if (str[i] == '\n')
		{
			i++;
			break;
		}
		i++;
	}
	if(len == -1 || (len == 0 && i == 0))
	{
		free(str);
		return(NULL);
	}
	str[i] = '\0';
	return (str);
}

int main()
{
	int fd = open("hoge",0);
	char *str;

	while(42)
	{
		str = get_next_line(fd);
		printf("%s",str);
		if(str == NULL)
			break;
	}
}