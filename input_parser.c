/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_parser.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsalmi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/19 13:13:51 by jsalmi            #+#    #+#             */
/*   Updated: 2020/09/20 12:47:16 by jsalmi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*output_type(char type, va_list ap, t_flags flags);
void	flag_parser(t_flags *flags, const char *format);
char	*put_char(char d);
char	*put_int(int d);
char	*put_str(char *d);
char	*put_hex(unsigned int d, int upper);
char	*put_float(double d, t_flags flags);

void	input_parser(t_info *info)
{
	int	i;
	char *new;
	char new_char;
	char *temp;

	i = 0;
	info->output = ft_strdup("");
	info->flags.specifiers = ft_strdup("csxfd");
	while (info->input[i] != '\0')
	{
		if (info->input[i] == '%')
		{
			flag_parser(&info->flags, info->input + i);
			if (info->flags.specifier != 0 &&
				ft_strchr(info->flags.specifiers, info->flags.specifier))
			{
				while (info->input[i] != info->flags.specifier)
					i++;
				new = output_type(info->flags.specifier, info->ap, info->flags);
				temp = ft_strdup(info->output);
				ft_strdel(&info->output);
				info->output = ft_strjoin(temp, new);
				ft_strdel(&temp);
				ft_strdel(&new);
			}
		}
		else
		{
			new_char = info->input[i];
			temp = ft_strdup(info->output);
			ft_strdel(&info->output);
			info->output = ft_strjoin(temp, &new_char);
			ft_strdel(&temp);
		}
		i++;
	}	
}

void	reset_flags(t_flags *flags)
{
	flags->minus = -1;
	flags->plus = -1;
	flags->space = -1;
	flags->hash = -1;
	flags->width = -1;
	flags->precision = 6;
	flags->hh = -1;
	flags->h = -1;
	flags->ll = -1;
	flags->l = -1;
	flags->big_l = -1;
	flags->specifier = 0;
}

void	flag_parser(t_flags *flags, const char *format)
{
	int i;

	i = 0;
	reset_flags(flags);
	// flags
	while (format[i] && ft_strchr("#0- +", format[i]))
	{
		if (format[i] == '-')
			flags->minus = 1;
		if (format[i] == '+')
			flags->plus = 1;
		if (format[i] == '#')
			flags->hash = 1;
		if (format[i] == '0')
			flags->zero = 1;
		if (format[i] == ' ')
			flags->space = 1;
		i++;
	}
	while (format[i] && !ft_strchr(flags->specifiers, format[i]))
	{
		if (format[i] == '*')
			flags->asterix = 1;
		else if (format[i] == '.')
		{
			flags->precision = 0;
			if (ft_isdigit(format[i + 1]))
			{
				flags->precision = ft_atoi(&format[i + 1]);
				i += ft_nbrlen(flags->precision);
			}
		}
		else if (ft_isdigit(format[i]))
		{
			flags->width = ft_atoi(&format[i]);
			i += ft_nbrlen(flags->width) - 1;
		}
		i++;
	}
	if (ft_strchr(flags->specifiers, format[i]))
		flags->specifier = format[i];
}

char	*output_type(char type, va_list ap, t_flags flags)
{
	char *new;

	if (type == 'c')
		new = put_char(va_arg(ap, int));
	else if (type == 'd')
		new = put_int(va_arg(ap, int));
	else if (type == 's')
		new = put_str(va_arg(ap, char *));
	else if (type == 'x')
		new = put_hex(va_arg(ap, unsigned int), 0);
	else if (type == 'f')
		new = put_float(va_arg(ap, double), flags);
	return (new);
}

char	*put_char(char d)
{
	char *new;

	new = (char *)malloc(sizeof(char) + 1);
	new[0] = d;
	new[1] = '\0';
	return (new);
}

char	*put_int(int d)
{
	char *new;

	new = ft_itoa(d);
	return (new);
}

char	*put_str(char *d)
{
	char *new;

	new = ft_strdup(d);
	return (new);
}

char	*put_hex(unsigned int d, int upper)
{
	char *new;
	int	i;

	i = 0;
	new = ft_itoa_base(d, 16);
	if (!upper)
	{
		while (new[i])
		{
			new[i] = ft_tolower(new[i]);
			i++;
		}
	}
	return (new);
}

char	*put_float(double d, t_flags flags)
{
	char *new;
	
	new = ft_ftoa(d, flags.precision);
	return (new);
}
