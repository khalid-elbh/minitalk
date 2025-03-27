/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kel-bahr <kel-bahr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/25 16:14:02 by kel-bahr          #+#    #+#             */
/*   Updated: 2025/03/27 11:25:43 by kel-bahr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_H
# define MINITALK_H

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
