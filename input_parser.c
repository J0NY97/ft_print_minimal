/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_parser.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsalmi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/19 13:13:51 by jsalmi            #+#    #+#             */
/*   Updated: 2020/09/20 16:56:36 by jsalmi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*output_type(char type, va_list ap, t_flags *flags);
int		flag_parser(t_flags *flags, const char *format);
char	*put_char(char d);
char	*put_int(int d);
char	*put_str(char *d);
char	*put_hex(unsigned int d, int upper);
char	*put_float(double d, t_flags *flags);

void	input_parser(t_info *info)
{
	int	i;
	char *new;
	char *temp;

	i = 0;
	while (info->input[i] != '\0')
	{
		if (info->input[i] == '%' && flag_parser(&info->flags, info->input + i + 1))
		{
			if (info->flags.specifier != 0 &&
				ft_strchr(info->flags.specifiers, info->flags.specifier))
			{
				while (info->input[i] != info->flags.specifier && (++i));
				new = output_type(info->flags.specifier, info->ap, &info->flags);
			}
		}
		else
		{
			new = ft_strnew(1);
			new[0] = info->input[i];
		}
		ft_stradd(&info->output, new);
		ft_strdel(&new);
		i++;
	}	
}

void	reset_flags(t_flags *flags)
{
	flags->minus = -1;
	flags->plus = -1;
	flags->zero = -1;
	flags->space = -1;
	flags->hash = -1;
	flags->width = -1;
	flags->precision_given = -1;
	flags->precision = 6;
	flags->hh = -1;
	flags->h = -1;
	flags->ll = -1;
	flags->l = -1;
	flags->big_l = -1;
	flags->specifier = 0;
}

int		check_flags(const char *format, t_flags *flags, char *flag_chars)
{
	int i;
	
	i = 0;
	while (format[i] && ft_strchr(flag_chars, format[i]))
	{
		if (format[i] == '-')
			flags->minus = 1;
		else if (format[i] == '+')
			flags->plus = 1;
		else if (format[i] == '#')
			flags->hash = 1;
		else if (format[i] == '0')
			flags->zero = 1;
		else if (format[i] == ' ')
			flags->space = 1;
		i++;
	}
	return (i);
}

int		flag_parser(t_flags *flags, const char *format)
{
	int i;
	int k;

	reset_flags(flags);
	i = check_flags(format, flags, "#0- +");
	while (format[i] && !ft_strchr(flags->specifiers, format[i]))
	{
		if (format[i] == '.')
		{
			flags->precision = 0;
			flags->precision_given = 1;
			if (ft_isdigit(format[i + 1]))
				flags->precision = ft_atoi(&format[i + 1]);
			i += ft_nbrlen(flags->precision) - 1;
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
	return (1);
}

char	*padding(char *str, char type, t_flags *flags)
{
	char *new;
	int	padd_amount;
	int k;
	
	k = -1;
	new = NULL;
//	printf("w: %d, %d %d %d %d %d\n", flags->width, flags->minus, flags->plus, flags->hash, flags->zero, flags->space);
	if (ft_strlen(str) < flags->width)
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

void	flag_filter(t_flags *flags)
{
	if (flags->zero == 1 && flags->minus == 1)
		flags->minus = -1;

}

char	*output_type(char type, va_list ap, t_flags *flags)
{
	char *new;
	char *temp;

	if (type == 'c')
		new = put_char(va_arg(ap, int));
	else if (type == 'd')
		new = put_int(va_arg(ap, int));
	else if (type == 's')
		new = put_str(va_arg(ap, char *));
	else if (type == 'x')
		new = put_hex(va_arg(ap, unsigned int), 0);
	else if (type == 'X')
		new = put_hex(va_arg(ap, unsigned int), 1);
	else if (type == 'f')
		new = put_float(va_arg(ap, double), flags);
	flag_filter(flags);
	if (flags->width != -1)
	{
		temp = padding(new, type, flags);
		if (temp != NULL)
		{
			ft_strdel(&new);
			new = ft_strdup(temp);
			ft_strdel(&temp);
		}
	}
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

char	*put_float(double d, t_flags *flags)
{
	char *new;
	
	new = ft_ftoa(d, flags->precision);
	return (new);
}
