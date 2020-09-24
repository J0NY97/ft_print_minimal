/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   str_modification.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsalmi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/24 12:00:17 by jsalmi            #+#    #+#             */
/*   Updated: 2020/09/24 12:23:05 by jsalmi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*specifier_to_string(char type, va_list ap, t_flags *flags)
{
	char *new;

	new = NULL;
	if (type == 'c')
		new = put_char(va_arg(ap, int));
	else if (type == 'd' || type == 'i')
		new = put_int((long long int)va_arg(ap, int), flags);
	else if (type == 'x' || type == 'X' || type == 'u' || type == 'o')
		new = put_int((unsigned long long int)va_arg(ap, void *), flags);
	else if (type == 's')
		new = put_str(va_arg(ap, char *), flags);
	else if (type == 'f')
		new = put_float((long double)va_arg(ap, double), flags);
	return (new);
}

char	*add_special_chars(const char *old, t_flags *flags)
{
	char	*new;
	char	*temp;
	int		set;

	set = 0;
	new = ft_strdup(old);
	if (flags->plus == 1 && (set = 1))
		temp = ft_strjoin("+", new);
	else if (flags->hash == 1 &&
			(flags->specifier == 'x' || flags->specifier == 'X') && (set = 1))
		temp = ft_strjoin("0X", new);
	else if (flags->hash == 1 && flags->specifier == 'o'
			&& flags->precision_given == -1 && (set = 1))
		temp = ft_strjoin("0", new);
	if (set == 1)
		ft_strreplace(&new, &temp);
	return (new);
}

void	apply_flags_to_string(char **new, t_flags *flags)
{
	char	*temp;

	if (flags->precision_given != -1 && flags->specifier != 'f')
	{
		temp = specifier_padding(*new, flags);
		ft_strreplace(new, &temp);
	}
	if (flags->zero == -1)
	{
		temp = add_special_chars(*new, flags);
		ft_strreplace(new, &temp);
		flags->negativ == 1 ? temp = ft_strjoin("-", *new) : 0;
		flags->negativ == 1 ? ft_strreplace(new, &temp) : 0;
	}
	if (flags->width > -1)
	{
		temp = padding(*new, flags);
		ft_strreplace(new, &temp);
	}
	if (flags->zero == 1)
	{
		temp = add_special_chars(*new, flags);
		ft_strreplace(new, &temp);
		flags->negativ == 1 ? *new[0] = '-' : 0;
	}
}
