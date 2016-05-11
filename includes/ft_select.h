/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_select.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbaran <rbaran@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/09 14:45:08 by rbaran            #+#    #+#             */
/*   Updated: 2016/05/11 16:04:59 by rbaran           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_SELECT_H
# define FT_SELECT_H
# include <libft.h>
# include <termcap.h>
# include <term.h>
# include <curses.h>
# include <termios.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <signal.h>
# include <fcntl.h>
# include <sys/ioctl.h>
# define LEF 0x445B1B
# define RIG 0x435B1B
# define UP 0x415B1B
# define DO 0x425B1B
# define UNDER_ON 1
# define UNDER_OFF 0


typedef struct	s_output
{
	int	o_lines;
	int	o_cols;
	int	len_max;
}				t_output;

typedef struct	s_elems
{
	char			*data;
	short int		selected;
	int				posX;
	int				posY;
	struct s_elems	*next;
	struct s_elems	*prev;
}				t_elems;

int		ft_open(void);
t_elems	*ft_fillselect(int ac, char **av);
int		ft_termios(void);
void	ft_managedisplay(t_elems *elems, int fd);
void	ft_printconf(t_elems *elems, int fd);
int		ft_putchar_int(int c);
void	ft_set_positions(t_elems *elems, t_output *size_conf);
void	ft_movecursor(t_elems *elem);
void	ft_underlinemode(int mode);
void	ft_clearscreen(void);
void	ft_savecursor(void);
void	ft_restorecursor(void);

#endif
