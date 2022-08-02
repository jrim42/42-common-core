/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   _print.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrim <jrim@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/18 17:21:27 by jrim              #+#    #+#             */
/*   Updated: 2022/08/02 17:11:12 by jrim             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

long long	get_time_interval(struct timeval t1, struct timeval t2);
void		print_error(char *err_msg, int exit_state);
void		print_routine(t_philo *philo, char *msg);
void		print_param(t_param *param);

long long	get_time_interval(struct timeval t1, struct timeval t2)
{
	long long		t1_ms;
	long long		t2_ms;
	long long		interval;

	t1_ms = t1.tv_sec * 1000 + t1.tv_usec / 1000;
	t2_ms = t2.tv_sec * 1000 + t2.tv_usec / 1000;
	interval = t1_ms - t2_ms;
	return (interval);
}

void	print_error(char *err_msg, int exit_state)
{
	printf("error: %s\n", err_msg);
	// exit 사용 불가함수라서 수정해야함
	exit (exit_state);
}

void	print_routine(t_philo *philo, char *msg)
{
	long long		ms;
	struct timeval	now;

	// pthread_mutex_lock();
	gettimeofday(&now, NULL);
	ms = now.tv_sec * 1000 + now.tv_usec / 1000;
	// print
	// pthread_mutex_unlock();
}

void	print_param(t_param *param)
{
	printf("---------------------\n");
	printf("  philo  :  %d\n", param->num_philo);
	printf("   die   :  %d\n", param->ms_to_die);
	printf("   eat   :  %d\n", param->ms_to_eat);
	printf("  sleep  :  %d\n", param->ms_to_sleep);
	if (param->num_eat != -1)
		printf(" num eat :  %d\n", param->num_eat);
	printf("---------------------\n");
}
