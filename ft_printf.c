/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsalmi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/19 13:03:37 by jsalmi            #+#    #+#             */
/*   Updated: 2020/09/19 16:55:36 by jsalmi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_printf(const char *restrict format, ...)
{
	t_info	*info;
	int		result;

	if (!(info = (t_info *)malloc(sizeof(t_info))))
		ft_putstr("couldnt malloc info\n");
	info->input = ft_strdup(format);
	va_start(info->ap, format);
	input_parser(info);
	va_end(info->ap);
	result = ft_strlen(info->output);
	ft_putstr(info->output);
	ft_strdel(&info->input);
	ft_strdel(&info->output);
	ft_strdel(&info->flags.specifiers);
	free(info);
	return (result);
}
