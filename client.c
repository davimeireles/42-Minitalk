/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmeirele <dmeirele@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/30 19:00:19 by dmeirele          #+#    #+#             */
/*   Updated: 2023/12/04 13:36:07 by dmeirele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"
#include <stdio.h>

int main(pid_t PID, char **str)
{
	PID = 10;
	str[1] = "prupru";

	printf("%d\n %s\n",PID,str[1]);

	
}