/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lr.h                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alambert <alambert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/09 11:04:32 by alambert          #+#    #+#             */
/*   Updated: 2022/06/06 18:16:25 by alambert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LR_H
# define LR_H

# include "./mlx/mlx.h"
# include "./lib42/lib42.h"
# include "./myenums.h"
# include <X11/keysym.h>
# include <X11/X.h>
# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <string.h>
# include <ctype.h>
# include <fcntl.h>
# include <limits.h>
# include <float.h>
# include <math.h>
# include <complex.h>
# include <sys/stat.h>
# include <errno.h>

void	ft_set0(float fdb[9][24], float fv[24]);
void	ft_splitandconvert(char *str, float fdb[9][24]);
void	ft_getdata(float fdb[9][24]);
void	ft_dset(float fdb[9][24], float fv[24]);
void	ft_grad_dsc(float fdb[9][24], float fv[24]);
void	ft_regr(float fdb[9][24], float fv[24]);
void	ft_corr_rate(float fv[24], float fdb[9][24]);
void	ft_display0(void *id[2], float fv[24], float fdb[9][24]);
void	ft_originfix(int iv[4]);
void	ft_tr_landmark(void *id[2], int iv[4]);
void	ft_tr_dots(void *id[2], int iv[4], float fdb[9][24]);
void	ft_tr_line(void *id[2], int iv[4], float fv[24]);
int		ft_up_shell(float fv[24]);
void	ft_userprice(float fv[24]);
void	ft_display1(void *id[2], float fv[24]);
void	ft_tr_userparam(void *id[2], int iv[4], int max[2], float fv[24]);
int		ft_exit(void *id[2]);
#endif
