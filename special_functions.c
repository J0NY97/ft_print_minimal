/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   special_functions.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsalmi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/24 12:04:44 by jsalmi            #+#    #+#             */
/*   Updated: 2020/09/24 12:05:37 by jsalmi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*padding(char *str, char type, t_flags *flags)
{
	char	*new;
	int		padd_amount;
	int		k;

	k = -1;
	new = NULL;
	if ((int)ft_strlen(str) < flags->width)
	{
		new = ft_strnew(flags->width);
		padd_amount = flags->width - ft_strlen(str);
		if (flags->zero == 1)
			ft_memset(new, '0', padd_amount);
		else
			ft_memset(new, ' ', flags->width);
		if (flags->minus == 1)
			padd_amount = 0;
		while (str[++k])
			new[padd_amount + k] = str[k];
	}
	return (new);
}

char	*specifier_padding(char *str, char type, t_flags *flags)
{
	char	*new;
	int		padd_amount;
	int		k;
	int		len;

	k = -1;
	new = NULL;
	len = ft_strlen(str);
	if (len < flags->precision)
	{
		new = ft_strnew(flags->precision);
		padd_amount = flags->precision - ft_strlen(str);
		ft_memset(new, '0', padd_amount);
		while (str[++k])
			new[padd_amount + k] = str[k];
	}
	return (new);
}

void	flag_filter(t_flags *flags)
{
	if (flags->zero == 1 && flags->minus == 1)
		flags->minus = -1;
}
