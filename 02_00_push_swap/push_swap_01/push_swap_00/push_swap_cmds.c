/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_cmds.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrim <jrim@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/05 21:40:29 by jrim              #+#    #+#             */
/*   Updated: 2022/02/05 21:42:12 by jrim             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	commands(char *cmd, t_stack *a, t_stack *b);
void	cmd_push(char *cmd, t_stack *from, t_stack *to);
void	cmd_swap(char *cmd, t_stack *stk);
void	cmd_rotate(char *cmd, t_stack *stk);
void	cmd_rev_rotate(char *cmd, t_stack *stk);

void	commands(char *cmd, t_stack *a, t_stack *b)
{
}

void	cmd_push(char *cmd, t_stack *from, t_stack *to)
{
	stk_push(to, stk_pop(from));
	write(1, cmd, 2);
	write(1, "\n", 1);
}

void	cmd_swap(char *cmd, t_stack *stk)
{
	t_node	*cur_top;
	int		tmp;

	cur_top = stk->top;
	if (cur_top && cur_top->next)
	{
		tmp = cur_top->data;
		cur_top->data = cur_top->next->data;
		cur_top->next->data = tmp;
	}
	if (cmd == NULL)
		return ;
	write(1, cmd, 2);
	write(1, "\n", 1);
}

void	cmd_rotate(char *cmd, t_stack *stk)
{
	t_node	*cur_top;

	cur_top = stk->top;
	stk->top = cur_top->next;
	if (cmd == NULL)
		return ;
	write(1, cmd, 2);
	write(1, "\n", 1);
}

void	cmd_rev_rotate(char *cmd, t_stack *stk)
{
	t_node	*cur_top;

	cur_top = stk->top;
	stk->top = cur_top->prev;
	if (cmd == NULL)
		return ;
	write(1, cmd, 3);
	write(1, "\n", 1);
}
