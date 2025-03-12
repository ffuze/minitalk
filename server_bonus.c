/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adegl-in <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/11 12:04:42 by adegl-in          #+#    #+#             */
/*   Updated: 2025/03/12 16:31:21 by adegl-in         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void signal_handler(int sig, siginfo_t *info, void *context)
{
    static int bit_index = 0;
    static char character = 0;

    (void)context;
    character |= (sig == SIGUSR2) << (7 - bit_index);
    bit_index++;

    if (bit_index == 8)
	{
        write(1, &character, 1);
        bit_index = 0;
        character = 0;
    }
    kill(info->si_pid, SIGUSR1); // ack to client
}

int main(void)
{	
    struct sigaction sa;
	
    ft_printf("Server PID: %d\n", getpid());
    sa.sa_sigaction = signal_handler;  // function to call when signal is received
	sa.sa_flags = SA_SIGINFO;      // provides extra info (like sender PID)
	sigemptyset(&sa.sa_mask);      // function that clears any blocked signals (like a free)
	sigaction(SIGUSR1, &sa, NULL); // function to handle SIGUSR1
	sigaction(SIGUSR2, &sa, NULL); // function to handle SIGUSR2
    while (1)
        pause();
    return 0;
}
