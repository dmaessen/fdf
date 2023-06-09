/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmaessen <dmaessen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/10 13:49:26 by dmaessen          #+#    #+#             */
/*   Updated: 2023/01/10 12:45:26 by dmaessen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_bzero(void *s, size_t n)
{
	size_t	i;
	char	*x;

	x = s;
	i = 0;
	while (n > 0)
	{
		x[i] = '\0';
		n--;
		i++;
	}
}

// int	main(void)
// {
// 	char	s[9] = "123456789";

// 	ft_bzero(s, 5);
// 	printf("%s \n", s);
// 	return (0);
// }
