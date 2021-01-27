/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   budurezat.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grinko <grinko@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/27 19:07:35 by grinko            #+#    #+#             */
/*   Updated: 2019/11/27 19:52:01 by grinko           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

char	**split(char *s)
{
	char	**res;
	int		i;

	if ((res = (char **)malloc(sizeof(char *) * (4))) == NULL)
		return (NULL);
	i = 0;
	while (*s)
	{
		while (*s && (*s == '\n'))
			s++;
		if (*s && *s != '\n')
		{
			res[i] = word(s);
			i++;
			while (*s && *s != '\n')
				s++;
		}
	}
	return (res);
}

char	*word(char *s)
{
	char	*word;
	int		i;

	word = (char *)malloc(sizeof(char) * 5);
	i = 0;
	while (s[i] && s[i] != '\n')
	{
		word[i] = s[i];
		i++;
	}
	word[i] = '\0';
	return (word);
}

void	strclean(char **s)
{
	int i;

	i = 0;
	while (i < 4)
	{
		free(s[i]);
		i++;
	}
	free(s);
}

int		mapclean(int **s, int a)
{
	int i;

	i = 0;
	while (i < a)
	{
		free(s[i]);
		i++;
	}
	free(s);
	return (0);
}
