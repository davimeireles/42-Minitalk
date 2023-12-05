/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmeirele <dmeirele@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/05 13:58:01 by dmeirele          #+#    #+#             */
/*   Updated: 2023/12/05 14:13:08 by dmeirele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalkbonus.h"

void	print_pid(int op)
{
	pid_t	pid;

	pid = getpid();
	if (op == 1)
		ft_printf("Server PID: ");
	else
		ft_printf("Client PID: ");
	ft_printf("%d\n",pid);
}