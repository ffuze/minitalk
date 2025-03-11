/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adegl-in <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/11 12:05:03 by adegl-in          #+#    #+#             */
/*   Updated: 2025/03/11 14:43:57 by adegl-in         ###   ########.fr       */
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
}

void ack_handler(int sig) {
    (void)sig;
}

int main(int argc, char **argv) {
    if (argc != 3) {
        ft_printf("Usage: %s <server_pid> <message>\n", argv[0]);
        return 1;
    }

    pid_t server_pid = atoi(argv[1]);
    struct sigaction sa;
    
    sa.sa_handler = ack_handler;
    sigemptyset(&sa.sa_mask);
    sa.sa_flags = 0;
    sigaction(SIGUSR1, &sa, NULL);

    for (int i = 0; argv[2][i] != '\0'; i++) {
        send_bit(server_pid, argv[2][i]);
        pause();  // Wait for acknowledgment
    }
    send_bit(server_pid, '\n');  // Send newline to indicate end

    return 0;
}
