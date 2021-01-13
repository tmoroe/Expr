#ifndef		EE_H
# define	EE_H
# define	T_EMPTY	0
# define	T_OP	1
# define	T_NO	2
# define	O_DIV	1
# define	O_MOD	0
# define	O_MULT	2
# define	O_PLUS	3
# define	O_MINUS	4

typedef struct  s_order
{
  short           type;
  int             value;
  struct s_order  *next;
}               t_order;

int			eval_expr(char *exp);
void		clean(char *input);
int			addop(char *exp, t_order **order);
int			extractno(char *exp, t_order **order);
void		push_back(t_order *newn, t_order **order);
t_order		*create_elem(short type, int value);
int			calc(t_order **order);
void		operations(int op, t_order **order);
#endif