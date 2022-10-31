#include <stdio.h>
#include <unistd.h>
#include <stdarg.h>
#include <limits.h>
void put_str(char *str,int *len)
{
	int i = 0;
	int k = 0;
	if(str == NULL)
	{
		*len += write(1,"(null)",6);
		return;
	}
	while(str[i])
		k += write(1,&str[i++],1);
	*len = k + 1;
}

void put_nbr(int i,int *len)
{
	char base[10] = "0123456789";

	if(i == INT_MIN)
	{
		*len += write(1,"-2147483648",11);
		return;
	}
	if (i < 0)
	{
		*len += write(1,"-",1);
		i = -i;
	}
	if(i > 9)
		put_nbr(i / 10,len);
	*len += write(1,&base[i % 10],1);
}

void put_hex_nbr(unsigned int i,int *len)
{
	char base[16] = "0123456789abcdef";

	if(i > 15)
		put_hex_nbr(i / 16,len);
	*len += write(1,&base[i % 16],1);
}

int ft_printf(const char *fmt, ... )
{
	int i = 0;
	int len = 0;
	va_list ap;
	va_start(ap,fmt);
	while(fmt[i])
	{
		if(fmt[i] != '%')
			len += write(1,&fmt[i],1);
		else if(fmt[i] == '%' && fmt[i + 1])
		{
			i++;
			if(fmt[i] == 's')
				put_str(va_arg(ap,char *),&len);
			else if(fmt[i] == 'd')
				put_nbr(va_arg(ap,int),&len);
			else if(fmt[i] == 'x')
				put_hex_nbr(va_arg(ap,unsigned int),&len);
		}
		i++;
	}
	va_end(ap);
	return (len);
}

int main()
{
	char *str = NULL;
	int i,j;

	j = printf("%s\n",str);
	i = ft_printf("%s\n",str);
	printf("   printf : %d\nft_printf : %d\n",j,i);

	int k,l,n;
	n = -1;
	k = printf("%d\n",n);
	l = ft_printf("%d\n",n);
	printf("   printf : %d\nft_printf : %d\n",k,l);


	int m,o,p;
	m = -2147483648;
	o = printf("%x\n",m);
	p = ft_printf("%x\n",m);
	printf("   printf : %d\nft_printf : %d\n",o,p);
}