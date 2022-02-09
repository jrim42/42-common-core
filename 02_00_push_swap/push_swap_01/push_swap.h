#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft/libft.h"
# include <stdio.h>

typedef struct      s_node
{
    int             data;
    struct s_node   *prev;
    struct s_node   *next;
}                   t_node;

typedef struct  s_stack
{
    int         size;
    t_node      *top;
}               t_stack;

// typedef struct       s_stk
// {
//     struct s_stack   *a;
//     struct s_stack   *b;
// }                    t_stk;

//push_swap.c
void    push_swap(int argc, char **argv);
int	    select_piv(t_stack *stk, int size);
void	sort_2(t_stack *stk);
int		is_rev_sorted(t_stack *stk);
int		is_sorted(t_stack *stk);

//push_swaP_input.c
void    stk_fill(t_stack *stk, int argc, char **argv);
void	arr_fill(t_stack *stk, int *arr, int size);
int     check_num(char **input);
int     check_dup(t_stack *stk);
void    err_exit(void);

//push_swap_cmds.c
void    commands(char *cmd, t_stack *a, t_stack *b);
void    cmd_push(char *cmd, t_stack *from, t_stack* to);
void    cmd_swap(char *cmd, t_stack *stk);
void    cmd_rotate(char *cmd, t_stack *stk);
void    cmd_rev_rotate(char *cmd, t_stack *stk);

//push_swap_utils.c
void    stk_init(t_stack **stk);
t_node  *nd_init(int num);
void    stk_push(t_stack *stk, t_node *new_top);
t_node  *stk_pop(t_stack *stk);

//push_swap_sort.c
void    stk_a2b(t_stack *a, t_stack *b, int size);
void    stk_b2a(t_stack *a, t_stack *b, int size);
int     stk_min(t_stack *stk);
int     stk_max(t_stack *stk);
void	arr_quicksort(int *arr, int start, int end);

//unnecessary.c
void    stk_display_all(t_stack *stk_a, t_stack *stk_b);
void    data_swap(int *a, int *b);

#endif