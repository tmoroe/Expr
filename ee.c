#include <stdio.h>
#include "libft.h"
#include "ee.h"

int eval_expr(char *expr)
{
	t_order			**order;
	t_order			*empty;
	static char		*exp;

	exp = expr;
	empty = create_elem(-1, -1);
	order = &empty;
	while (*exp != '\0') 
	{
		if (*exp >= '0' && *exp <= '9')
			exp += extractno(exp, order);
		else if (*exp == '(' )
		{
			exp++;
			push_back(create_elem(T_NO, eval_expr(exp)), order);
		}
		else if(*exp == ')' && exp++)
		{
			
			return (calc(order));
		}
		else if (*exp == '/' || *exp == '-' || *exp == '+' || *exp == '%'|| *exp == '*')
		{
    		if(*exp == '-')
			{
    				if(exp[1] != ' ')
						exp += extractno(exp, order);
			}
			else
				exp += addop(exp, order);
		}
		else
			exp++;
	}
	return(calc(order));
}

int addop(char *exp, t_order **order)
{
	t_order op;
	short type;
	int value;

	type = T_OP;
  	if(*exp == '-')
		value = O_MINUS;
  	if(*exp == '%')
		value = O_MOD;
	if(*exp == '/')
		value = O_DIV;
	if(*exp == '*')
		value = O_MULT;
	if(*exp == '+')
		value = O_PLUS;
	push_back(create_elem(type, value), order);

	return (1);
}

int extractno(char *exp, t_order **order)
{
  char	arr[8];
  int 	value;
  int	i;

	i = 0;
	if(*exp == '-')
	{
		arr[i] = *exp;
		i++;
		exp++;
	}
	while((*exp >= '0' && *exp <= '9') && *exp != '\0')
		{
			arr[i] = *exp;
			i++;
			exp++;
  		}
	value = ft_atoi((char*)arr);
	push_back(create_elem(T_NO, value), order);
	return (i);
}

