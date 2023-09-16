/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lebarbos <lebarbos@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/27 13:18:35 by lebarbos          #+#    #+#             */
/*   Updated: 2023/08/15 21:22:15 by lebarbos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H

# include <stdio.h>
# include <unistd.h>
# include <fcntl.h>
# include <stdlib.h>
# include <stddef.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42

# endif

/*Main Functions*/
char	*get_next_line(int fd);

/*Utilitaries*/
char	*ft_strchr_mod(const char *str, int c);
char	*ft_strjoin_mod(char *s1, char const *s2);
size_t	ft_strlen_mod(const char *str);

#endif
