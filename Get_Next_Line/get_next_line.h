/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bhumeau <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/30 15:36:15 by bhumeau           #+#    #+#             */
/*   Updated: 2023/11/30 16:23:49 by bhumeau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 5
# endif
# include <stdlib.h>
# include <unistd.h>

char	*get_next_line(int fd);
char	*ft_strjoin(char const *s1, char const *s2);
char	*ft_strjoin_n(char const *s1, char const *s2, int is_n, size_t i);
char	*ft_strdup_n(const char *s, int is_n);
int		ft_is_n(char *str);
void	ft_clean(char *buffer, int is_n);
size_t	ft_strlen(const char *s);
int		ft_buffer_0(char *buffer, int fd, int *is_n);
int		ft_while_is_n(int fd, char *buffer, int *is_n);

#endif
