/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_functions.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsalmi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/23 16:14:12 by jsalmi            #+#    #+#             */
/*   Updated: 2020/09/24 12:22:29 by jsalmi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*put_char(char d)
{
	char *new;

	new = (char *)malloc(sizeof(char) + 1);
	new[0] = d;
	new[1] = '\0';
	return (new);
}

char	*put_int(size_t d, t_flags *flags)
{
	char *new;
	char type;

	new = NULL;
	type = flags->specifier;
	if ((long long int)d < 0)
	{
		flags->plus = -1;
		if (type == 'd' || type == 'i')
		{
			flags->negativ = 1;
			d = -d;
		}
	}
	if (type == 'd' || type == 'i')
		new = ft_itoa_base(d, 10);
	else if (type == 'o')
		new = ft_itoa_base(d, 8);
	else if (type == 'x')
		new = ft_itoa_base(d, 16);
	else if (type == 'X')
		new = ft_itoa_base(d, 16);
	else if (type == 'u')
		new = ft_itoa_base(d, 10);
	return (new);
}

char	*put_str(char *d, t_flags *flags)
{
	char *new;
	char *temp;

	new = ft_strdup(d);
	if (flags->precision_given != -1)
	{
		temp = ft_strndup(new, flags->precision);
		ft_strreplace(&new, &temp);
	}
	return (new);
}

char	*put_float(double d, t_flags *flags)
{
	char *new;

	if (d < 0)
	{
		flags->plus = -1;
		flags->negativ = 1;
		d = -d;
	}
	new = ft_ftoa(d, flags->precision);
	return (new);
}
