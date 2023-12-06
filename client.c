/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmeirele <dmeirele@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/30 19:00:19 by dmeirele          #+#    #+#             */
/*   Updated: 2023/12/04 18:12:17 by dmeirele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	send_bit_to_server(unsigned char c, pid_t pid)
{
	int	bits;

	bits = 0;
	while (bits < 8)
	{
		if (c & 0b00000001)
        {
            if(kill(pid,SIGUSR1) == -1)
                ft_printf("bit not transmited to server\n");
        }
		else
        {
            if(kill(pid, SIGUSR2 == -1))
                ft_printf("bit not transmited to server\n");
        }
        c = c >> 1;
		bits++;
		usleep(100);
	}
}

void	send_bits(pid_t pid, char *str)
{
	size_t  i;
    size_t  len;

	i = 0;
	len = ft_strlen(str);
    while (i <= len)
	{
		send_bit_to_server(str[i], pid);
		i++;
	}
}

int	main(int argc, char *argv[])
{
	pid_t	pid;

	if (argc != 3) {
        ft_printf("You need to put [PID]&[MSG]\n");
        return (0);
    }
	pid = ft_atoi(argv[1]);
	if (pid == -1)
		return (1);
	send_bits(pid, argv[2]);
    return 0;
}
