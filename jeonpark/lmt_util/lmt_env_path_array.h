/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lmt_env_path_array.h                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeonpark <jeonpark@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/03 16:05:44 by jeonpark          #+#    #+#             */
/*   Updated: 2021/07/03 16:05:52 by jeonpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LMT_ENV_PATH_ARRAY_H
# define LMT_ENV_PATH_ARRAY_H

char	**lmt_env_path_array_new(void);
void	lmt_env_path_array_free(char **array);

#endif
