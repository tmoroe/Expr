
#include "ee.h"
#include <stdlib.h>
#include <unistd.h>

t_order  *create_elem(short type, int value)
{
  t_order *newn;

  newn = (t_order*)malloc(sizeof(t_order));
  newn->type = type;
  newn->value = value;
  newn->next = NULL;
  return (newn);
}

void     push_back(t_order *newn, t_order **order)
{
	t_order *current;
 
  if((*order)->type != -1)
  {
    current = *order;
	while(current->next != NULL)
		current = current->next;
	current->next = newn;
  }
  else
  {
	  *order = newn;
  }
}

