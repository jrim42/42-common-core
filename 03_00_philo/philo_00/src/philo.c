/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrim <jrim@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/16 20:48:40 by jrim              #+#    #+#             */
/*   Updated: 2022/08/01 18:43:15 by jrim             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int		init_philo(t_philo *philo, t_param *param, pthread_mutex_t *fork);
void	create_philo(t_info *info, t_philo *philo);
void	bye_philo(t_info *info, t_philo *philo);

int	main(int argc, char **argv)
{
	t_info	*info;

	info = (t_info *)malloc(sizeof(t_info));
	if (info == NULL)
		print_error("cannot allocate memory", 12);
	if (parse_param(argc, argv, info->param) == FAILURE)
		return (1);
	if (init_philo(info->philo, info->param, info->fork) == FAILURE)
		return (1);
	create_philo(info, info->philo);
	return (0);
}

int	init_philo(t_philo *philo, t_param *param, pthread_mutex_t *fork)
{
	int	idx;

	philo = (t_philo *)malloc(sizeof(t_philo) * param->num_philo);
	fork = (pthread_mutex_t *)malloc(sizeof(pthread_mutex_t) * param->num_philo);
	if (philo == NULL || fork == NULL)
		print_error("cannot allocate memory", 12);
	idx = -1;
	while (++idx < param->num_philo)
	{
		philo[idx].name = idx;
		pthread_mutex_init(&fork[idx], NULL);
		pthread_mutex_init(&philo[idx].checker, NULL);
		if (idx == 0)
			philo[idx].fork_left = &fork[param->num_philo - 1];
		else
			philo[idx].fork_left = &fork[idx - 1];
		philo[idx].fork_right = &fork[idx];
	}
	return (SUCCESS);
}

void	create_philo(t_info *info, t_philo *philo)
{
	int			idx;
	pthread_t	thread;

	idx = -1;
	gettimeofday(&info->birthday, NULL);
	while (++idx < info->param->num_philo)
	{
		philo[idx].last_eat = info->birthday;
		pthread_create(&philo[idx].thread, NULL, routine, &philo[idx]);
		pthread_create(&thread, NULL, eggshell, &philo[idx]);
		pthread_detach(thread);
	}
	if (info->param->num_eat != 0)
		printf("philo must eat...\n");
}

void	bye_philo(t_info *info, t_philo *philo)
{
	int			idx;
	
	idx = -1;
	while (++idx < info->param->num_philo)
	{
		pthread_join(philo[idx].thread, NULL);
		pthread_mutex_destroy(&philo[idx].checker);
	}
	// free philo
	while (idx-- > 0)
		pthread_mutex_destroy(&info->fork[idx]);		
	// free fork
}