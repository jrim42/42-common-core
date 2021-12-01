/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrim <jrim@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/25 16:09:15 by jrim              #+#    #+#             */
/*   Updated: 2021/11/30 13:53:23 by jrim             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINT_F_H
# define FT_PRINT_F_H

# include <stdarg.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <limits.h>
# include "libft/libft.h"

# define TYPE "cspdiuxX%"
# define HEX_U "0123456890ABCDEF"
# define HEX_L "0123456890abcdef"
//# define FLAG "-+0.* #" 

int     ft_printf(const char *form_str, ...);
int	    parse_form(char *form, va_list ap);
int	    detect_type(char type, va_list ap);

int     print_char(va_list arg_ptr);
int     print_str(va_list arg_ptr);
int     print_per(void);

int     print_int(va_list arg_ptr);
int     print_uns(va_list arg_ptr);
int     print_hex(char type, va_list arg_ptr);
char    *ft_itoa_base(long long num, char *base);
size_t  numlen_base(long long num, size_t base_len);

#endif