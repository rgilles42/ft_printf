/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgilles <rgilles@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/08 12:49:27 by rgilles           #+#    #+#             */
/*   Updated: 2020/05/08 12:49:31 by rgilles          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printf(const char *to_parse, ...)
{
	t_printf	*myprintf;

	if (!(myprintf = (t_printf*)malloc(sizeof(t_printf))))
		return (-1);
	va_start(myprintf->args, to_parse);
	myprintf->nbwritten = 0;
	while (to_parse[myprintf->nbwritten])
	{
		if (to_parse[myprintf->nbwritten] == '%')
		{
			myprintf->nbwritten++;
			launch_parsing(to_parse, myprintf);
		}
		else
			write(1, to_parse + myprintf->nbwritten, 1);
		(myprintf->nbwritten)++;
	}
	return (myprintf->nbwritten);
}
