/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aysozen <42kocaeli.com.tr>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/13 12:33:48 by aysozen           #+#    #+#             */
/*   Updated: 2023/04/13 12:33:52 by aysozen          ###   ########.tr       */
/*                                                                            */
/* ************************************************************************** */

#include <signal.h>
#include "Libft/libft.h"

void	signal_process(int signal)
{
	static unsigned char	x;
	static int				i;

	if (signal == SIGUSR1)
		x = x | 1;
	i++;
	if (i == 8)
	{
		write(1, &x, 1);
		i = 0;
		x = 0;
	}
	x = x << 1;
}

int	main(void)
{
	ft_putnbr_fd(getpid(), 1);
	signal (SIGUSR1, signal_process);
	signal (SIGUSR2, signal_process);
	while (1)
		pause();
	return (0);
}
