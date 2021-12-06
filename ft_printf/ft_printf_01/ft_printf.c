/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrim <jrim@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/25 16:08:41 by jrim              #+#    #+#             */
/*   Updated: 2021/12/06 20:42:50 by jrim             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_printf(const char *form, ...);
void	init_detail(t_detail *detail);

int	ft_printf(const char *form, ...)
{
	va_list	ap;
	int		len;

	va_start(ap, form);
	len = parse_form((char *)form, ap);
	va_end(ap);
	return (len);
}

void	init_detail(t_detail *detail)
{
	detail->type = 0;
	detail->align = LEFT;
	detail->pad = OFF;
	detail->sp = OFF;
	detail->prec = OFF;
	detail->wid = OFF;
	detail->alt = OFF;
	detail->minus = OFF;
	detail->plus = OFF;
	detail->base = 10;
}