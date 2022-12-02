/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   2.c                                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xmatute- <xmatute-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/02 15:04:08 by xmatute-          #+#    #+#             */
/*   Updated: 2022/12/02 15:38:33 by xmatute-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <fcntl.h>
#include <stdio.h>

// void	GA1(int fd)
// {
// 	char	elf;
// 	char	me;
// 	char	*c;
// 	ssize_t	r;
// 	unsigned int score = 0;
	
// 	r = read(fd, c, 1);
// 	while (r && *c)
// 	{
// 		elf = *c;
// 		r = read(fd, c, 1);
// 		r = read(fd, c, 1);
// 		me = *c;
// 		r = read(fd, c, 1);
// 		r = read(fd, c, 1);
// 		printf("elf %c me %c ", elf, me);
// 		if (elf == 'A')
// 		{
// 			if (me == 'X')
// 				score+= 1 + 3;
// 			if (me == 'Y')
// 				score+= 2 + 6;
// 			if (me == 'Z')
// 				score+= 3 + 0;
// 		}
// 		if (elf == 'B')
// 		{
// 			if (me == 'X')
// 				score+= 1 + 0;
// 			if (me == 'Y')
// 				score+= 2 + 3;
// 			if (me == 'Z')
// 				score+= 3 + 6;
// 		}
// 		if (elf == 'C')
// 		{
// 			if (me == 'X')
// 				score+= 1 + 6;
// 			if (me == 'Y')
// 				score+= 2 + 0;
// 			if (me == 'Z')
// 				score+= 3 + 3;
// 		}
// 		printf("score = %u\n", score);
// 	}
// 	printf("FINAL score = %u\n", score);

// }

void	GA(int fd)
{
	char	elf;
	char	me;
	char	*c;
	ssize_t	r;
	unsigned int score = 0;
	
	r = read(fd, c, 1);
	while (r && *c)
	{
		elf = *c;
		r = read(fd, c, 1);
		r = read(fd, c, 1);
		me = *c;
		r = read(fd, c, 1);
		r = read(fd, c, 1);
		printf("elf %c me %c ", elf, me);
		if (elf == 'A')
		{
			if (me == 'X')
				score+= 3 + 0;
			if (me == 'Y')
				score+= 1 + 3;
			if (me == 'Z')
				score+= 2 + 6;
		}
		if (elf == 'B')
		{
			if (me == 'X')
				score+= 1 + 0;
			if (me == 'Y')
				score+= 2 + 3;
			if (me == 'Z')
				score+= 3 + 6;
		}
		if (elf == 'C')
		{
			if (me == 'X')
				score+= 2 + 0;
			if (me == 'Y')
				score+= 3 + 3;
			if (me == 'Z')
				score+= 1 + 6;
		}
		printf("score = %u\n", score);
	}
	printf("FINAL score = %u\n", score);

}
int main(int argc, char const *argv[])
{
	int	fd;

	fd = open("test.txt", O_RDONLY);
	GA(fd);
	close(fd);
	return 0;
}
