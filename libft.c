#include <unistd.h>
#include <stdlib.h>

void  ft_putchar(char c)
{
  write(1, &c, 1);
}

void  ft_putnbr(int nmbr)
{
	char resultrev[16];
	int remainder;
	int isnegative;
	int i;

	i = 0;
	isnegative = (nmbr < 0) ? 1 : 0;
	nmbr = (isnegative) ? nmbr * -1 : nmbr;
	if(nmbr == 0)
    	ft_putchar('0');
	while (nmbr > 0)
	{
    	remainder = nmbr % 10;
    	resultrev[i++] = (remainder > 10) ? (remainder/10) + '0' : '0' + remainder;
    	nmbr = nmbr / 10;
  	}
  	if (isnegative)
    	ft_putchar('-');
	i--;
  	while (i != -1)
  	{
    	ft_putchar(resultrev[i]);
    	i--;
  	}
}

int   ft_atoi(char *string)
{
	int isneg;
	int result;

	isneg = 0;
	result = 0;
	if (*string == '-' && string++)
    	isneg = 1;
	while (*string >= '0' &&  *string <= '9')
  	{
    	result *= 10;
    	result += *string - 48;
    	string++;
  	}
  	if (isneg)
    	result *= -1;
	return (result);
}
int		ft_strlen(char *str)
{
	int len; 

	len = 0;
	while(str[len] && len++);
	return (len);
}

char	*ft_strdup(char *src)
{
	char *dup;
	int i;

	i = 0;
	dup = (char*)malloc(ft_strlen(src) + 1);
	while(src[i])
	{
		dup[i] = src[i];
		i++;
	}
	dup[i] = '\0';
	return (dup);
}