#include "ee.h"
#include <stdlib.h>
#include "unistd.h"

void	mdiv(t_order **order)
{
	t_order *current;
	t_order *prev;

	current = *order;
	while(current->next != NULL)
	{
		prev = current;
		current = current->next;
		if(current->type == T_OP && current->value == O_DIV)
		{
			prev->value = prev->value / current->next->value;
			prev->next = current->next->next;
			free(current->next);
			free(current);
			current = prev;
		}
		else
		{
			current = current->next;
		}
	}
}

void	mult(t_order **order)
{
	t_order *current;
	t_order *prev;

	current = *order;
	while(current->next != NULL)
	{
		prev = current;
		current = current->next;
		if(current->type == T_OP && current->value == O_MULT)
		{
			prev->value = prev->value * current->next->value;
			prev->next = current->next->next;
			free(current->next);
			free(current);
			current = prev;
		}
		else
		{
			current = current->next;
		}
	}
}
void	mmod(t_order **order)
{
	t_order *current;
	t_order *prev;

	current = *order;
	while(current->next != NULL)
	{
		prev = current;
		current = current->next;
		if(current->type == T_OP && current->value == O_MOD)
		{
			prev->value = prev->value % current->next->value;
			prev->next = current->next->next;
			free(current->next);
			free(current);
			current = prev;
		}
		else
		{
			current = current->next;
		}
	}
}

void	mplus(t_order **order)
{
	t_order *current;
	t_order *prev;

	current = *order;
	while(current->next != NULL)
	{
		prev = current;
		current = current->next;
		if(current->type == T_OP && current->value == O_PLUS)
		{
			prev->value = prev->value + current->next->value;
			prev->next = current->next->next;
			free(current->next);
			free(current);
			current = prev;
		}
		else
		{
			current = current->next;
		}
	}
}

void	mminus(t_order **order)
{
	t_order *current;
	t_order *prev;

	current = *order;
	while(current->next != NULL)
	{	
		prev = current;
		current = current->next;
		if(current->type == T_OP && current->value == O_MINUS)
		{
			prev->value = prev->value - current->next->value;
			prev->next = current->next->next;
			free(current->next);
			free(current);
			current = prev;
		}
		else
		{
			current = current->next;
		}
	}
}

int		calc(t_order **order)
{
	int op;
	int result;

	op = 0;
	if((*order)->type != -1)
	{
		while(op <= O_MINUS)
		{
			if(op == O_DIV)
				mplus(order);
			if(op == O_MOD)
				mmod(order);
			if(op == O_MULT)
				mult(order);
			if(op == O_PLUS)
				mplus(order);
			if(op == O_MINUS)
				mminus(order);
			op++;
		}
		return ((*order)->value);
	}
	return (0);
}