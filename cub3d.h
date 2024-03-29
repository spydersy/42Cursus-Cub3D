/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abelarif <abelarif@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/14 20:14:32 by abelarif          #+#    #+#             */
/*   Updated: 2021/02/18 16:46:04 by abelarif         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include <unistd.h>
# include <string.h>
# include <stdlib.h>
# include <errno.h>
# include <fcntl.h>
# include <math.h>
# include "./link.h"
# include "./GNL/get_next_line.h"
# include "./libft_utils/libft.h"
# include <mlx.h>

# define PI			3.14159265359
# define A_KEY		0
# define D_KEY		2
# define W_KEY		13
# define S_KEY		1
# define L_KEY		123
# define R_KEY		124
# define E_KEY		53
# define SP			g_sprite
# define DATA		g_data
# define P			g_player
# define TXTS		g_txts
# define TXT1		g_txt1
# define TXT2		g_txt2
# define TXT3		g_txt3
# define TXT4		g_txt4

typedef struct			s_data
{
	int					resolution[2];
	int					nb[8];
	char				*no_txt;
	char				*so_txt;
	char				*we_txt;
	char				*ea_txt;
	char				*sp_txt;
	int					ce_color[3];
	int					fl_color[3];
	int					save;
}						t_data;

typedef	struct			s_player
{
	float				x;
	float				y;
	float				crt;
	float				angle;
	int					col;
}						t_player;

typedef struct			s_mlx
{
	void				*mlx;
	void				*win;
	void				*nmlx;
	void				*nwin;

}						t_mlx;

typedef struct			s_img
{
	void				*img;
	char				*addr;
	int					bpp;
	int					len;
	int					endian;
	int					resl[2];
}						t_img;

typedef struct			s_sprite
{
	int					x_map;
	int					y_map;
	float				x;
	float				y;
	float				distance;
	float				angle;
	float				size;
	float				xof;
	float				yof;
	int					index;
}						t_sprite;

typedef	struct			s_mem
{
	void				*mem;
	struct s_mem		*next;
}						t_mem;

typedef struct			s_bmp
{
	int					width_in_bytes;
	char				header[54];
	unsigned int		bitcount;
	unsigned int		imagesize;
	unsigned int		bi_size;
	unsigned int		bf_off_bits;
	unsigned int		filesize;
	unsigned int		bi_planes;
	unsigned char		*buf;
}						t_bmp;

int						g_nb_line;
int						g_max_len;
int						g_nb_sprite;
char					**g_map;
float					g_dist;
float					*g_wall_distances;
float					*g_wall_pix;
t_mlx					g_mlx;
t_img					g_img;
t_img					g_txt1;
t_img					g_txt2;
t_img					g_txt3;
t_img					g_txt4;
t_img					g_txts;
t_bmp					g_bmp;
t_mem					*g_memory;
t_data					g_data;
t_list					*g_list;
t_player				g_player;
t_sprite				*g_sprite;

int						max_of(int i, int j);
int						min_of(int i, int j);
int						check_sprite(float x, float y);
int						all_digit(const char *str);
int						skip_line(const char *line);
int						manip_line(const char *line);
int						get_txt(char **content);
int						sprite(float x, float y);
int						skip_line(const char *line);
int						get_rgb(int index, const char *str);
int						get_path(int index, const char *str);
int						ft_iswall(int x, int y);
int						get_resolution(char **content);
int						ft_key(int key, void *args);
int						ft_cast_rays(void);
int						calc_x(float x);
int						ft_iswall_space(float *xy);
int						calc_y(float h, float i);
int						ft_islimits(float *xy);
int						ft_exit(int key, void *args);
long					calc_rgb(int r, int g, int b);
void					ft_error (char *str);
void					free_list(t_mem *list);
void					*my_malloc(size_t size);
void					list_push_back(t_mem **list, void *ptr);
void					dda(float x1, float y1, int col);
void					init_text(void);
void					my_mlx_pixel_put(t_img *data, int x, int y, int color);
void					ft_data(int fd);
void					ft_map(int fd);
void					get_cl(int r, int g, int b);
void					malloc_sprite(void);
void					get_new_position(float x1, float y1, int nb_steps);
void					get_fl(int r, int g, int b);
void					ft_init(void);
void					check_line(const char *line, int g_nb_line);
void					ft_save(void);
void					get_position(int y_max, int x_max);
void					get_player_angle(char orientation, int x, int y);
void					horizontal_map(int y_max);
void					cub3d(int g_nb_line, int g_max_len);
void					to_sprite(void);
void					save_frame(void);
float					deg(float x);
float					dst(float x0, float y0, float x1, float y1);
float					vabs(float i);
float					normalize(float angle);

#endif
