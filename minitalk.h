/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adegl-in <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/11 12:05:34 by adegl-in          #+#    #+#             */
/*   Updated: 2025/03/12 18:37:18 by adegl-in         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// default source was inserted so that the function usleep could've been used
// properly
// usleep is not a function that exists in the newer versions of glibc
// xopen source is used to not print unwanted errors made by the compiler
#ifndef MINITALK_H
# define MINITALK_H

# define _DEFAULT_SOURCE
# define _XOPEN_SOURCE 700

# include <signal.h>
# include <errno.h>
# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>
# include "./libft/libft.h"

#endif