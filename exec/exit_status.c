/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit_status.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otmallah <otmallah@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/14 15:43:14 by otmallah          #+#    #+#             */
/*   Updated: 2022/06/16 12:03:12 by otmallah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../shell.h"
void	ft_check_cmd2(t_shell *mini, t_list *lst);
char	*check_path_if_exi2(t_shell *mini);

void    ft_exit_status(t_shell *mini, t_list *lst)
{
	char **temp = NULL;
	char *str = NULL;
	int i;
	int size;

	i = 0;
	if (lst->val[0][0] == '.' || lst->val[0][0] == '/')
		ft_check_cmd2(mini, lst);
	else if (check_path_if_exi2(mini) != NULL)
	{
		str = check_path_if_exi(mini);
		if (str != NULL)
		{
			if (find(str) == 1)
				temp = ft_split(str, ':');
			else
			{
				temp = (char **)malloc(sizeof(char *) * 2);
				temp[i] = str;
				temp[i + 1] = NULL;
			}
			while (temp[i])
			{
				size = ft_strlen(temp[i]);
				temp[i] = ft_strjoin(temp[i], "/");
				str = ft_strjoin(temp[i], lst->val[0]);
				if (access(str, F_OK) == 0)
                {
					status_exec_g = 0;
                    i = -1;
                    break;
                }
                i++;
			}
            if (i != -1 && ft_strcmp(lst->val[0], "exit") != 0)
			    status_exec_g = 127;
        }
	}
	else
        status_exec_g = 127;
}

void	ft_check_cmd2(t_shell *mini, t_list *lst)
{
	DIR *dp;

	dp = opendir(lst->val[0]);
	if ((int)dp == 512)
		status_exec_g = 126;
	if (lst->val[0][0] == '.')
	{
		if (access(lst->val[0], F_OK | X_OK ) == 0)
            status_exec_g = 0;
        else
            status_exec_g = 127;
    }
	else if (lst->val[0][0] == '/')
	{
		if (access(lst->val[0], F_OK) == 0)
            status_exec_g = 0;
        else
            status_exec_g = 127;
	}
}	



char	*check_path_if_exi2(t_shell *mini)
{
	int i;
	char	*temp;

	i = 0;
	while (mini->tab_save_env[i])
	{
		temp = ft_substr(mini->tab_save_env[i], 0, len(mini->tab_save_env[i]));
		if (strcmp(temp, "PATH") == 0)
			return (ft_strchr(mini->tab_save_env[i],'='));
		i++;
	}
	if (mini->tab_save_exp && mini->tab_save_exp[0] != NULL)
	{
		i = 0;
		temp = ft_substr(mini->tab_save_exp[i], 0, len(mini->tab_save_exp[i]));
		if (strcmp(temp, "PATH") == 0)
			return (ft_strchr(mini->tab_save_exp[i],'='));
		i++;
	}
	return NULL;
}