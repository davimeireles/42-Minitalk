/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmeirele <dmeirele@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/30 18:48:02 by dmeirele          #+#    #+#             */
/*   Updated: 2023/12/05 17:13:49 by dmeirele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void fill_global_string(int *byte)
{
    int i = 7;
    unsigned char character = 0;
    static unsigned char *global_string = NULL;

    while(i >= 0)
        character = character * 2 + byte[i--];
    if(character == '\0')
    {
        ft_printf("%s", global_string);
        free(global_string);
    }
    else
        global_string = ft_str_join(global_string, character);
}

void	signal_handler(int signal, siginfo_t *info, void *context)
{
    (void)info;
    (void)context;

    static int byte[8];
    static int bits = 0;

    if (signal == SIGUSR1)
        byte[bits++] = 0;
    else
        byte[bits++] = 1;
    if(bits == 8)
    {
        fill_global_string(byte);
        bits = 0;
    }
}

int	main(void)
{
    struct sigaction act;
    act.sa_sigaction = &signal_handler;
    sigemptyset(&act.sa_mask);
    act.sa_flags = SA_SIGINFO;
    print_pid(1);
    if (sigaction(SIGUSR1,  &act, NULL) == -1)
        ft_printf("failed handler\n");
    if(sigaction(SIGUSR2, &act, NULL) == -1)
        ft_printf("failed handler\n");
    while(1)
    {
        pause();
    }
}
