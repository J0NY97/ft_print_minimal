/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsalmi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/19 13:03:58 by jsalmi            #+#    #+#             */
/*   Updated: 2020/09/19 16:57:43 by jsalmi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "stdio.h"

int		main(void)
{
	ft_printf("%s\n", "string");
	ft_printf("%c\n", 'c');
	ft_printf("%d\n", 123);
	ft_printf("%x\n", 123);
	ft_printf("%f\n", 123.4567890);
	ft_printf("%4.9f\n", 123.4907890789078909);
	ft_printf("%s %c %d %x\n", "string", 'c', 123, 123);
	ft_printf("%s%c%d%x%f\n", "string", 'c', 123, 123, 123.0987654321);
	ft_printf("%\n", "string");
	while (1);
	return (0);
}
