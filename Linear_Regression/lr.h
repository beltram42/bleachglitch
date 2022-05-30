/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lr.h                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alambert <alambert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/09 11:04:32 by alambert          #+#    #+#             */
/*   Updated: 2022/05/30 11:49:58 by alambert         ###   ########.fr       */
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


void	ft_splitandconvert(char *str, long ldb[7][24]);
void	ft_getdata(long ldb[7][24]);
void	ft_setzero(float fdb[2][24], float fv[5], long ldb[7][24], long lv[19]);
void	ft_dataset(float fdb[2][24], float fv[5], long ldb[7][24], long lv[19]);
void	ft_userprice(long lv[19]);
void	ft_grad_dsc(float fdb[2], float fv[5], long lv[19]);
void	ft_regr(float fdb[2][24], float fv[5], long lv[19], long ldb[7][24]);
void	ft_predict(float fdb[2], long lv[18]);
void	ft_landmark(void *id[2]);

#endif
