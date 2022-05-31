/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lr.h                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alambert <alambert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/09 11:04:32 by alambert          #+#    #+#             */
/*   Updated: 2022/05/31 17:45:21 by alambert         ###   ########.fr       */
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
# include <fcntl.h>
# include <stdlib.h>
# include <stdio.h>
# include <string.h>
# include <limits.h>
# include <ctype.h>
# include <math.h>
# include <sys/stat.h>

void	ft_splitandconvert(char *str, long ldb[6][24]);
void	ft_getdata(long ldb[6][24]);
void	ft_setzero(float fdb[2][24], float fv[5], long ldb[6][24], long lv[19]);
void	ft_dataset(float fdb[2][24], float fv[5], long ldb[6][24], long lv[19]);
void	ft_userprice(long lv[19]);
void	ft_grad_dsc(float fdb[2][24], float fv[5], long lv[19]);
void	ft_regr(float fdb[2][24], float fv[5], long lv[19], long ldb[6][24]);
void	ft_predict(float fdb[2][24], long lv[19]);
void	ft_originfix(int iv[4]);
void	ft_tr_landmark(void *id[2], int iv[4]);
void	ft_tr_dots(void *id[2], long ldb[6][24], long lv[19], int iv[4]);
void	ft_tr_line(void *id[2], int iv[4], long lv[19]);
void	ft_tr_userparam(void *id[2], int iv[4], long lv[19], int max[2]);
void	ft_display0(void *id[2], long ldb[6][24], long lv[19]);
void	ft_display1(void *id[2], long ldb[6][24], long lv[19]);
int		ft_exit(void *id[2]);
#endif
