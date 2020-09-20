/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsalmi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/20 11:11:13 by jsalmi            #+#    #+#             */
/*   Updated: 2020/09/20 13:39:21 by jsalmi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	val(int c)
{
	if (c >= 0 && c <= 9)
		return ('0' + c);
	else
		return ('A' - 10 + c);
}

int		ft_nbrlen_base(int nbr, int base)
{
	int	i;

	i = 1;
	while (nbr >= ft_pow(base, i))
		i++;
	return (i);
}

char	*ft_itoa_base(int nbr, int base)
{
	char	*str;
	int		len;

	len = ft_nbrlen_base(nbr, base);
	str = ft_strnew(len);
	if (nbr < 0)
		str[0] = '-';
	else if (nbr == 0)
		str[0] = '0';
	while (nbr != 0)
	{
		len--;
		str[len] = val(nbr % base);
		nbr = nbr / base;
	}
	return (str);
}
