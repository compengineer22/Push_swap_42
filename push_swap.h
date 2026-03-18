/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsrour <hsrour@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/17 16:44:04 by hsrour            #+#    #+#             */
/*   Updated: 2026/03/17 17:13:53 by hsrour           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stddef.h>
# include <stdarg.h>
# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>

typedef struct s_stack {
	int				val;
	int				rank;
	struct s_stack	*next;
}	t_stack;

int		ft_printf(int fd, const char *format, ...);
int		ft_format(char c, va_list args);
int		ft_putchar(char c);
int		ft_putstr(char *str);
int		ft_puthex(unsigned long l, char c);
int		ft_putnbr(int n);
int		ft_putnbru(unsigned int n);

void	handler(t_stack **a, int *tab);
void	handle_3(t_stack **a, int *tab);
void	handle_3_2(t_stack **a, int *tab);
void	handle_2(t_stack **stack_a, int *tab);

int		ft_strlen_arr(char **s);
int		nb_flags(int argc, char *argv[]);
int		ft_lstlen(t_stack *s);
t_stack	*tail(t_stack	*a);
t_stack	*prev(t_stack	*a,	t_stack	*b);
t_stack	*initialize(t_stack *a, t_stack **cur, int *index, int *index2);
void	advance(t_stack **cur, t_stack **cur2, int *index, int *index2);
float	compute_disorder(t_stack *a);
int		check_dup(char **numbers);
int		check_dup_sep(char **numbers);
t_stack	*fill_stack_a(char *s, t_stack *stack);
int		num_of_words(char const *str, char c);
int		ft_strcmp(char *s1, char *s2);
int		ft_atoi(const char *nptr, char **numbers, t_stack *s);
char	**ft_split(char const *str, char c);
t_stack	*insert_stack(t_stack *s, int n);
t_stack	*separate_numbers(int argc, char *argv[], t_stack *s, int n_flags);
t_stack	*check_sequence(int argc, char *argv[], t_stack *stack_a);
int		comp_flag(char *s);
t_stack	*handle_no_flags(int argc, char *argv[], int n_flags, t_stack *stack_a);
int		is_numeric(char *s);
void	delete(char **numbers);
int		is_zero(char *s);
int		ft_isdigit(int c);

int		sa(t_stack **stack_a);
int		sb(t_stack **stack_b);
int		ss(t_stack **stack_a, t_stack **stack_b);
void	swap(t_stack **stack_a, t_stack **stack_b, char choice);
int		pa(t_stack **stack_a, t_stack **stack_b);
int		pb(t_stack **stack_a, t_stack **stack_b);
int		ra(t_stack **stack_a);
int		rb(t_stack **stack_b);
int		rr(t_stack **stack_a, t_stack **stack_b);
void	rotate(t_stack **stack_a, t_stack **stack_b, char choice);
int		rra(t_stack **stack_a);
int		rrb(t_stack **stack_b);
int		rrr(t_stack **stack_a, t_stack **stack_b);
void	rev_rotate(t_stack **a, t_stack **b, char choice);

void	simple(t_stack **stack_a, t_stack **stack_b, int *tab);
int		find_min_index(t_stack *stack_a);

void	assign_ranks(t_stack **stack_a, int chunk_size);
void	move_chunks(t_stack **stack_a, t_stack **stack_b, int *tab);
void	extract_minimum(t_stack **stack_a, t_stack **stack_b, int *tab);
void	extract_maximum(t_stack **stack_a, t_stack **stack_b, int *tab);
int		find_max_index(t_stack *stack_a);
int		radical(int length);
int		ft_min(t_stack *stack_a);
int		ft_max(t_stack *stack_a);
void	move_to_top(t_stack **stack_a, int index, int *tab);
void	normalize_not_perfect(t_stack **a, t_stack **b, int length, int *tab);
void	normalize_perfect(t_stack **a, t_stack **b, int length, int *tab);
void	bucker_sort(t_stack **a, t_stack **b, int length, int *tab);

int		ft_log(int n);
int		ft_pow(int power);
void	burcker_sort(t_stack **a, t_stack **b, int length, int *tab);
void	burcker_no_log(t_stack **a, t_stack **b, int length, int *tab);
void	perfect_burcker(t_stack **a, t_stack **b, int length, int *tab);
void	burcker_chunks(t_stack **a, t_stack **b, int chunk_size, int *tab);

void	free_stack(t_stack *s);
void	print_bench(double disorder, char *flag, int *t);

void	ft_end(void);

#endif
