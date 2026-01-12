/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yopeng <yopeng@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/02 17:56:11 by yopeng            #+#    #+#             */
/*   Updated: 2025/10/10 16:35:16 by yopeng           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	check_argv_num(char *argv)
{
	int	i;

	i = 0;
	while (argv[i] != '\0')
	{
		if (argv[i] < '0' || argv[i] > '9')
			return (1);
		i++;
	}
	return (0);
}

int	check_argv_valid(char **argv)
{
	if (ft_atoi(argv[1]) < 1 || ft_atoi(argv[1]) > PHILO_MAX
		|| check_argv_num(argv[1]) == 1)
		return (write(2, "invalid number of philosophers\n", 32), 1);
	if (ft_atoi(argv[2]) < 1 || check_argv_num(argv[2]) == 1)
		return (write(2, "invalid time to die\n", 21), 1);
	if (ft_atoi(argv[3]) < 1 || check_argv_num(argv[3]) == 1)
		return (write(2, "invalid time to eat\n", 21), 1);
	if (ft_atoi(argv[4]) < 1 || check_argv_num(argv[4]) == 1)
		return (write(2, "invalid time to sleep\n", 23), 1);
	if (argv[5] && (ft_atoi(argv[5]) < 0 || check_argv_num(argv[5]) == 1))
		return (write(2, "invalid number of times each philosopher must eat\n",
				51), 1);
	return (0);
}
