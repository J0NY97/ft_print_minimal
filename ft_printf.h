/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsalmi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/19 13:09:27 by jsalmi            #+#    #+#             */
/*   Updated: 2020/09/19 16:40:25 by jsalmi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include "./libft/libft.h"
# include <stdarg.h>
# include <math.h>

typedef	struct	s_flags
{
	// flags
	int			minus;
	int			plus;
	int			space;
	int			hash;
	int			zero;
	// width
	int			width;
	int			asterix;
	// precision
	int			precision;
	// length
	int			hh;
	int			h;
	int			l;
	int			ll;
	int			big_l;
	// spec
	char		specifier;
	char		*specifiers;
}				t_flags;

typedef	struct	s_info
{
	int			length;
	va_list		ap;
	char		*input;
	char		*output;
	t_flags		flags;
}				t_info;

int				ft_printf(const char *restrict format, ...);
void			input_parser(t_info *info);

#endif
