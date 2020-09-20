/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ftoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsalmi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/19 15:54:23 by jsalmi            #+#    #+#             */
/*   Updated: 2020/09/20 13:06:05 by jsalmi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*special_itoa(int nbr, int n)
{
	int i;
	char *str;

	str = (char *)malloc(sizeof(char) * n + 1);
	str[n] = '\0';
	i = 0;
	while (nbr)
	{
		str[i++] = (nbr % 10) + '0';
		nbr = nbr / 10;
	}
	while (i < n)
		str[i++] = '0';
	ft_reverse(str);
	return (str);
}

char	*ft_ftoa(double d, int precision)
{
	int		i;
	int		ipart;
	double	fpart;
	char	*str;
	char	*temp;

	ipart = (int)d;
	fpart = d - (double)ipart;
	temp = ft_itoa(ipart);
	i = ft_strlen(temp);
	str = (char *)malloc(sizeof(char) * i + precision + 1);
	ft_strcpy(str, temp);
	if (precision > 0)
	{
		str[i] = '.';
		ft_strdel(&temp);
		temp = special_itoa(fpart * ft_pow(10, precision), precision);
		ft_strncpy(str + i + 1, temp, precision);
	}
	ft_strdel(&temp);
	return (str);
}
