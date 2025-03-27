/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk_bonus.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kel-bahr <kel-bahr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/27 01:26:36 by kel-bahr          #+#    #+#             */
/*   Updated: 2025/03/27 11:21:30 by kel-bahr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_BONUS_H
# define MINITALK_BONUS_H

# include <unistd.h>
# include <stdlib.h>
# include <signal.h>
# include <limits.h>

int		ft_printf(const char *f, ...);
void	ft_exrror(char *error);
int		is_valid_number(char *str);
int		ft_atoi(const char *str);
void	ft_kill(pid_t pid, int signum);

#endif