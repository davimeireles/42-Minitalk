/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmeirele <dmeirele@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/05 13:58:01 by dmeirele          #+#    #+#             */
/*   Updated: 2023/12/07 23:09:46 by dmeirele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	print_pid(int op)
{
	pid_t	pid;

	pid = getpid();
	if (op == 1)
		ft_printf("Server PID: ");
	else
		ft_printf("Client PID: ");
	ft_printf("%d\n", pid);
}

unsigned char	*ft_str_join(unsigned char *global_str, unsigned char c)
{
	size_t			i;
	size_t			size;
	size_t			j;
	unsigned char	*helper_string;

	i = 0;
	j = 0;
	size = 0;
	if (global_str)
		size = ft_strlen((char *)global_str);
	size = size + 1;
	helper_string = malloc(sizeof(char *) * size + 1);
	if (!helper_string)
		return (NULL);
	while (helper_string[j])
		j++;
	if (global_str)
	{
		while (global_str[i])
			helper_string[j++] = global_str[i++];
	}
	helper_string[j] = c;
	j++;
	helper_string[j] = '\0';
	return (helper_string);
}
