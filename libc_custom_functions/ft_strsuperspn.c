/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsuperspn.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alambert <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/21 18:51:11 by alambert          #+#    #+#             */
/*   Updated: 2022/01/21 18:51:19 by alambert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


int ft_strsuperspn(const char *str, const char *set, int gear)
{
  const char  *p;
  const char  *s;

  p = str;
  while (*p)
  {
      s = set;
      s = ft_strchr(s, *p);
      if (s == 0 && gear == 1)
          break;
      if (s != 0 && gear == -1)
          break;
      else
          p++;
  }
  return (p - str);
}
