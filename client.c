/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aysozen <42kocaeli.com.tr>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/13 12:31:03 by aysozen           #+#    #+#             */
/*   Updated: 2023/04/13 12:31:20 by aysozen          ###   ########.tr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

static void	send_char(t_pid pid, char c)
{
	int	i;

	i = 7;
	while (i >= 0)
	{
		if ((c >> i) & 1)
			kill(pid, SIGUSR1);
		else
			kill(pid, SIGUSR2);
		usleep(150);
		i--;
	}
}

int	main(int argc, char **argv)
{
	t_pid	pid;
	int		i;

	if (argc != 3)
		write(1, "Error: wrong number of arguments\n", 33);
	else
	{
		pid = ft_atoi(argv[1]);
		i = 0;
		while (argv[2][i])
		{
			send_char(pid, argv[2][i]);
			i++;
		}
	}
}
