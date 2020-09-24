/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsalmi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/19 13:09:27 by jsalmi            #+#    #+#             */
/*   Updated: 2020/09/24 12:06:19 by jsalmi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include "./libft/libft.h"
# include <stdarg.h>

typedef	struct	s_flags
{
	int			minus;
	int			plus;
	int			space;
	int			hash;
	int			zero;
	int			negativ;
	int			width;
	int			asterix;
	int			precision_given;
	int			precision;
	int			hh;
	int			h;
	int			l;
	int			ll;
	int			big_l;
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
char			*ft_sprintf(const char *restrict format, ...);
int				ft_fprintf(int fd, const char *restrict format, ...);
void			input_parser(t_info *info);
char			*put_char(char d);
char			*put_int(size_t d, t_flags *flags);
char			*put_str(char *d, t_flags *flags);
char			*put_float(double d, t_flags *flags);
void			apply_flags_to_string(char **new, t_flags *flags);
char			*add_special_chars(const char *old, t_flags *flags);
char			*specifier_to_string(char type, va_list ap, t_flags *flags);
char			*specifier_padding(char *str, char type, t_flags *flags);
char			*padding(char *str, char type, t_flags *flags);
void			flag_filter(t_flags *flags);
char			*specifier_padding(char *str, char type, t_flags *flags);
char			*padding(char *str, char type, t_flags *flags);

#endif
