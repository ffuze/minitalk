/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adegl-in <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/11 12:05:03 by adegl-in          #+#    #+#             */
/*   Updated: 2025/03/12 16:02:43 by adegl-in         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void send_bit(pid_t server_pid, char character)
{
	int	i;
	int	bit;

	i = 7;
	bit = 0;
    while (i >= 0)
	{
        bit = (character >> i) & 1;
        if (bit)
            kill(server_pid, SIGUSR2);
        else
            kill(server_pid, SIGUSR1);
		usleep(100);
		i--;
    }
	ft_printf("\n");
}

void ack_handler(int sig)
{
    ft_printf("Segnale ricevuto: %d\n", sig);
}

int main(int argc, char **argv)
{
	int	i;

	i = 0;
    if (argc != 3)
        return (1);
    pid_t server_pid = ft_atoi(argv[1]);
	if (server_pid <= 0)
		return (ft_printf("nice try bastardo\n"), 0);
	if (kill(server_pid, 0) == -1 && errno == ESRCH)
		return (0);
    struct sigaction sa;
    sa.sa_handler = ack_handler;
    sigemptyset(&sa.sa_mask);
    sa.sa_flags = 0;
    sigaction(SIGUSR1, &sa, NULL);
    while (argv[2][i] != '\0')
	{
        send_bit(server_pid, argv[2][i]);
		i++;
    }
    return (0);
}
