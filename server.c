/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adegl-in <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/11 12:04:42 by adegl-in          #+#    #+#             */
/*   Updated: 2025/03/12 17:30:01 by adegl-in         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void signal_handler(int sig, siginfo_t *info, void *context)
{
    static int bit_index = 0;
    static char character = 0;

    (void)context;
	(void)info;	
    character |= (sig == SIGUSR2) << (7 - bit_index);
    bit_index++;
    if (bit_index == 8)
	{
        write(1, &character, 1);
        bit_index = 0;
        character = 0;
    }
}

int main(void)
{	
    ft_printf("Server PID: %d\n", getpid());
	struct sigaction sa;
	sa.sa_sigaction = signal_handler;
	sa.sa_flags = SA_SIGINFO;
	sigemptyset(&sa.sa_mask);
	sigaction(SIGUSR1, &sa, NULL);
	sigaction(SIGUSR2, &sa, NULL);
    while (1)
        pause();
    return 0;
}
