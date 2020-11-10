/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hwoodwri <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/05 13:04:04 by hwoodwri          #+#    #+#             */
/*   Updated: 2020/11/10 15:27:55 by hwoodwri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		num_of_words(char const *s, char c)
{
	unsigned int	i;
	int				num;

	i = 0;
	num = 0;
	while (s[i])
	{
		while (s[i] == c)
			i++;
		if (s[i] != '\0')
			num++;
		while (s[i] != c && s[i])
			i++;
	}
	return (num);
}

static char		*ft_strndup(const char *s1, size_t n)
{
	char	*copy;

	copy = (char *)malloc(sizeof(char) * (n + 1));
	if (!copy)
		return (NULL);
	ft_strlcpy(copy, s1, n + 1);
	return (copy);
}

static char		**ft_free_arr(char **arr, int j)
{
	while (j > 0)
	{
		free(arr[j]);
		j--;
	}
	free(arr);
	return (NULL);
}

char			**ft_split(char const *s, char c)
{
	int		i;
	int		j;
	int		x;
	char	**arr;

	i = 0;
	j = 0;
	if (!s)
		return (NULL);
	arr = (char **)malloc(sizeof(char *) * (num_of_words(s, c) + 1));
	if (!arr)
		return (NULL);
	while (s[i])
	{
		while (s[i] == c)
			i++;
		x = i;
		while (s[i] != c && s[i])
			i++;
		if (!(arr[j] = ft_strndup(s + x, i - x)))
			return (ft_free_arr(arr, j));
		j++;
	}
	arr[num_of_words(s, c)] = 0;
	return (arr);
}
