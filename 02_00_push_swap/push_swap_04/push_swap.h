/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrim <jrim@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/10 23:42:07 by jrim              #+#    #+#             */
/*   Updated: 2022/02/24 11:57:14 by jrim             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft/libft.h"
# include <limits.h>

typedef struct s_node
{
	int				data;
	struct s_node	*prev;
	struct s_node	*next;
}					t_node;

typedef struct s_stk
{
	int		size;
	t_node	*top;
}			t_stk;

typedef struct s_piv
{
	int	b_piv;
	int	s_piv;
}		t_piv;

typedef struct s_elm
{
	t_stk		*a;
	t_stk		*b;
	t_stk		*cmdlst;
	t_piv		*piv;
}				t_elm;

//push_swap.c
void		sort_filter(t_elm *elm, t_stk *a);
void		elm_init(t_elm *elm);
void		elm_free(t_elm *elm);

// _input.c
void		stk_fill(t_elm *elm, int argc, char **argv);
int			check_num(char **input);
int			check_dup(t_stk *stk);
void		err_exit(t_elm *elm);

// _stack_1.c
void		stk_init(t_stk **stk);
t_node		*nd_init(int num);
void		stk_del(t_stk *stk);

// _stack_2.c
void		stk_append(t_stk *stk, t_node *new_nd);
void		stk_push(t_stk *stk, t_node *new_top);
t_node		*stk_pop(t_stk *stk);

// _cmds.c
void		cmd_swap(int new_cmd, t_elm *elm, int *cmd_cnt);
void		cmd_push(int new_cmd, t_elm *elm, int *cmd_cnt);
void		cmd_rotate(int new_cmd, t_elm *elm, int *cmd_cnt);
void		cmd_rev_rotate(int new_cmd, t_elm *elm);

// _cmds_utils.c
void		cmd_cleaner(t_elm *elm);
void		cmd_display_all(t_stk *cmd_lst);
void		cmd_display_one(int cmd);

// _pivot.c
void		piv_select(t_stk *stk, int size, t_piv *piv);
void		arr_fill(t_stk *stk, int *arr, int size);
void		arr_qsort(int *arr, int start, int end);

// _sort.c
void		stk_a2b(t_elm *elm, t_piv *piv, int size);
void		stk_b2a(t_elm *elm, t_piv *piv, int size);

// _sort_n.c
void		sort_2(t_elm *elm, t_stk *stk);
void		sort_3_only(t_elm *elm, t_stk *stk);
void		sort_3_part(t_elm *elm, t_stk *stk);
void		sort_4(t_elm *elm, t_stk *stk);
void		sort_5(t_elm *elm, t_stk *stk);

// _sort_helper.c
int			a2b_helper(t_elm *elm, int size);
int			b2a_helper(t_elm *elm, int size);
void		rrr_helper(t_elm *elm, int ra_cnt, int rb_cnt);
void		rrr_cleaner(t_elm *elm, int new_cmd);

// _sort_utils.c
int			is_sorted(t_stk *stk, int size);
int			is_rev_sorted(t_stk *stk, int size);
int			stk_min(t_stk *stk, int size);
int			stk_max(t_stk *stk, int size);

// _utils.c
long long	ft_atoll(char *str);
int			ft_isspace_or_issign(const char *str, int *sign);
void		det_init(t_piv *piv, int *cnt_1, int *cnt_2, int *cnt_3);
void		stk_display_all(t_stk *stk_a, t_stk *stk_b);
void		data_swap(int *a, int *b);

#endif
