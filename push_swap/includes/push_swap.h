/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bhumeau <bhumeau@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/26 17:49:30 by bhumeau           #+#    #+#             */
/*   Updated: 2024/01/26 17:49:32 by bhumeau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include "../Libft/libft.h"
# include <stdbool.h>

typedef struct s_info
{
	int		splitted;
	int		argc;
	int		num;
	int		rank_max;
	int		next_rank;
	int		chunk;
	int		top;
	int		error;
	bool	first_push;
	char	**argv;
	t_list	*list_a;
	t_list	*list_b;
}				t_info;

t_list	*list_get_first(t_list *list);
t_list	*initialize_list(t_info *info, char **argv, int i);
t_list	*initialize_list_split(t_info *info, char **argv);
t_list	*push_first(t_list *l_src, t_list *l_dest, t_info *info);
t_list	*push(t_list *l_src, t_list *l_dest, char c, t_info *info);
void	swap(t_list *list, char c, t_info *info);
void	rotate(t_list *list, char c, t_info *info);
void	reverse_rotate(t_list *list, char c, t_info *info);
bool	check_duplicate(t_list *list_a);
bool	check_number(char **argv);
bool	check_minus(char **argv);
bool	check_atoi(char **argv, int splitted);
bool	ft_isspace(char c);
bool	ft_isnumber(char c);
bool	ft_issorted(t_list *list);
void	rank_list(t_list *list, int argc);
void	sort_all(t_info *info);
void	sort_two(t_info *info);
void	sort_three(t_info *info, int a, int b, int c);
void	push_back_to_a(t_info *info);
void	free_list(t_list *list);
void	free_split(char **str, int i);
void	handle_error(t_info *info);

#endif