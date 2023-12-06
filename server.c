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

unsigned char *global_string = NULL;

void	signal_handler(int signal)
{
    static int	count;
    static unsigned char c;
    unsigned char   bit;

    count = 0;
    c = 0;
    bit = (signal == SIGUSR1);
    c = c | (bit << count++);
    if (count == 8) // ja tenho os 8 bits que compoe o byte do caractere em questao
    {
        global_string = ft_str_join(global_string,&c);
        if (!global_string)
            exit (EXIT_FAILURE);
        if(c == '\0')
        {
            ft_printf("%s",global_string);
            free(global_string);
            global_string = NULL;
        }
        count = 0;
        c = 0;
    }
}

void define_handler(void)
{
    struct sigaction    act1;
    struct sigaction    act2;

    act1.sa_handler = &signal_handler;
    act2.sa_handler = &signal_handler;
    sigemptyset(&act1.sa_mask);
    sigaddset(&act1.sa_mask, SIGUSR2);
    sigemptyset(&act2.sa_mask);
    sigaddset(&act2.sa_mask , SIGUSR1);
    if (sigaction(SIGUSR1,  &act1, NULL) == -1)
        ft_printf("failed handler\n");
    if(sigaction(SIGUSR2, &act2, NULL) == -1)
        ft_printf("failed handler\n");
}

int	main(void)
{
    print_pid(1);
    define_handler();
    while(1)
        pause();
}
