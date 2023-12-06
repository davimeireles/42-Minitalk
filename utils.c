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

#include "minitalk.h"

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

unsigned char *ft_str_join(unsigned char *str1, unsigned char *str2)
{
    size_t  i;
    size_t  size;
    unsigned char *ret_string;

    i = 0;
    size = 0;
    if (str1)
        size = ft_strlen((char *)str1);
    size = size + ft_strlen((char *)str2) + 1;
    ret_string = malloc(sizeof(char *) * size);
    if (!ret_string)
        return (NULL);
    if (str1) {
        while (str1[i])
            *(ret_string++) = str1[i++];
        ret_string = ret_string - ft_strlen((char *) str1);
    }
    while (*str2)
        ret_string[i++] = *(str2++);
    ret_string[i] = '\0';
    if (str1)
        free(str1);
    return ret_string;
}