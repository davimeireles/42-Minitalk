/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmeirele <dmeirele@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/05 12:41:34 by dmeirele          #+#    #+#             */
/*   Updated: 2023/12/05 16:00:22 by dmeirele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalkbonus.h"

void	print_byte(int *bits)
{
	int				i;
	unsigned char	c;

	i = 7;
	c = 0;
	while (i >= 0)
	{
		c = c * 2 + bits[i];
		i--;
	}
	ft_printf("%c", c);
}

void	signal_handler(int signal)
{
	static int	byte[8];
	static int	bits = 0;

	if (signal == SIGUSR1)
	{
		byte[bits] = 0;
		bits++;
	}
	else if (signal == SIGUSR2)
	{
		byte[bits] = 1;
		bits++;
	}
	else
		exit(1);
	if (bits == 8)
	{
		print_byte(byte);
		bits = 0;
	}
}

int	main(void)
{
	print_pid(1);
	signal(SIGUSR1,signal_handler);
	signal(SIGUSR2,signal_handler);
	while(1)
		pause();
	return (EXIT_SUCCESS);
}
