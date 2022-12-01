/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   1.c                                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xmatute- <xmatute-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/01 18:54:55 by xmatute-          #+#    #+#             */
/*   Updated: 2022/12/01 21:10:16 by xmatute-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <fcntl.h>
#include <stdio.h>

int	ft_isdigit(int arg)
{
	if (arg >= '0' && arg <= '9')
		return (1);
	return (0);
}

// char	getchar(fd)
// {
// 	char	*s;
	
// 	*s = 0;
// 	read(fd, s, 1);
// 	return(*s);
// }

void	GA(int fd)
{
	char	*c;
	char	*s;
	ssize_t	r;
	int		n;
	int		cal;
	int		anser1 = 0;
	int		anser2 = 0;
	int		anser3 = 0;
	
	n = 0;
	cal = 0;

	r = read(fd, c, 1);
	printf("i c = %c n = %i\n", *c, n);
	while (r && *c)
	{
		n = 0;
		cal = 0;
		while (*c!='\n' && r > 0)
		{
			while (r > 0 && ft_isdigit (*c))
			{
				// printf("a c = %c n = %i\n", *c, n);
				n = n * 10 + (*c - '0');
				r = read(fd, c, 1);
				printf("d c = %c n = %i\n", *c, n);
			}
			printf("num c = %c n = %i\n", *c, n);
			cal += n;
			n = 0;
			printf("cal= %i\n", cal);
			r = read(fd, c, 1);
			printf("%s", c);
		}
		if (cal > anser1)
		{
			anser2 = anser1;
			anser1 = cal;
			
		}
		else if (cal > anser2)
		{
			anser3 = anser2;
			anser2 = cal;
		
		}
		else if (cal > anser3)
			anser3 = cal;


		
		r = read(fd, c, 1);
	}
	printf("la respuesta es %i + %i + %i = %i", anser1, anser2, anser3, anser1 + anser2 + anser3);
		
}

int main(int argc, char const *argv[])
{
	int	fd;

	fd = open("test.txt", O_RDONLY);
	GA(fd);
	close(fd);
	return 0;
}
