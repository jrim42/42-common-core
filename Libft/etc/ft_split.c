/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrim <jrim@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/21 22:50:41 by haryu             #+#    #+#             */
/*   Updated: 2021/11/27 15:02:39 by jrim             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*ft_strndup(char const *s, size_t n)
{
	size_t	i;
	size_t	limit;
	char	*ret;

	i = 0;
	limit = n;
	if (ft_strlen(s) > n)
		ret = (char *)ft_calloc((n + 1), sizeof(char));
	else
		ret = (char *)ft_calloc((ft_strlen(s) + 1), sizeof(char));
	if (!ret)
		return (NULL);
	while (s[i] && i < limit)
	{
		*(ret + i) = *(s + i);
		i++;
	}
	*(ret + i) = '\0';
	return (ret);
}

static void	ft_free_all(char **target, size_t height)
{
	size_t	i;

	i = 0;
	while (i < height)
		free (target[i++]);
	free (target);
}

int	ft_height_check(char const *s, char c)
{
	int	height;

	height = 0;
	while (*s)
	{
		if ((*s != c && (*(s + 1) == c || *(s + 1) == '\0')))
			height++;
		s++;
	}
	return (height);
}

char	**ft_split_str(char **ret, char const *s, char c)
{
	size_t	start;
	size_t	end;
	size_t	height;
	int		i;

	i = -1;
	height = 0 ;
	while (s[++i] && (int)height < ft_height_check(s, c))
	{
		if (s[i] != c && (i == 0 || s[i - 1] == c))
			start = (size_t)i;
		if (s[i] != c && (s[i + 1] == c || s[i + 1] == '\0'))
		{
			end = (size_t)i;
			ret[height] = ft_strndup((s + start), (end - start + 1));
			if (ret[height] == NULL)
			{
				ft_free_all(ret, ft_height_check(s, c));
				return (NULL);
			}
			height++;
		}
	}
	return (ret);
}

char	**ft_split(char const *s, char c)
{
	char	**ret;

	if (!s)
		return (NULL);
	ret = (char **)ft_calloc((ft_height_check(s, c) + 1), sizeof(char *));
	if (!ret)
		return (NULL);
	ret = ft_split_str(ret, s, c);
	if (!ret)
		return (NULL);
	return (ret);
}
