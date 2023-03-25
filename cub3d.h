/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moharras <moharras@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/24 13:25:01 by moharras          #+#    #+#             */
/*   Updated: 2020/11/25 11:14:31 by moharras         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
# include <mlx.h>
# include <math.h>

# define FD 8192

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 100
# endif

# define ARG_NOT_FOUND 101
# define ERROR_FILE -1
# define EXT_ERROR -2
# define MAP_ERROR -3
# define ERROR_GNL -4
# define EXEC_ERROR -5
# define ERROR_DUPL -6
# define ERROR_RESOL -7
# define ERROR_FLOOR -8
# define ERROR_CEIL -9
# define ERROR_NORTH -10
# define ERROR_SOUTH -11
# define ERROR_WEST -12
# define ERROR_EAST -13
# define ERROR_SPRITE -14
# define ERROR_SAVE -15
# define ERROR_COLOR -16
# define ERROR_ARG -17
# define SP_NUMBER 20

typedef struct		s_axe
{
	int				x;
	int				y;
}					t_axe;

typedef struct		s_coord
{
	int				x;
	int				y;
}					t_coord;

typedef struct		s_sprite
{
	int				val_sp;
	t_coord			coord[4096];
	int				count;
}					t_sprite;

typedef struct		s_pos
{
	int				x;
	int				y;
}					t_pos;

typedef struct		s_mp
{
	char			*tmp_mp;
	char			**tb;
	t_axe			axe;
	int				cardinal;
	char			card_dir;
	int				val_dir;
	t_pos			pos;
	int				flag;
}					t_mp;
typedef struct		s_rgb
{
	int				r;
	int				g;
	int				b;
	int				a;
}					t_rgb;

typedef struct		s_sprit
{
	double			*z_buffer;
	int				spr_w;
	int				spr_h;
	int				spr_s_l;
	int				spr_end;
	int				spr_bbp;
	int				*spr_data;
	void			*spr_img;
	int				sp_ord[SP_NUMBER];
	double			sp_dst[SP_NUMBER];
	double			sp_x;
	double			sp_y;
	double			inv_det;
	double			tsf_x;
	double			tsf_y;
	int				sp_scrn_x;
	int				sp_h;
	int				dr_st_y;
	int				dr_en_y;
	int				sp_wdth;
	int				dr_st_x;
	int				dr_en_x;
	int				tex_x;
	int				d;
	int				tex_y;
	int				color;
}					t_sprit;

typedef struct		s_var
{
	void			*mlx_ptr;
	void			*win_ptr;
	int				tw;
	int				th;
	int				*texture;
	double			pos_x;
	double			pos_y;
	double			dir_x;
	double			dir_y;
	double			p_x;
	double			p_y;
	int				x;
	double			c_x;
	double			rd_x;
	double			rd_y;
	int				mp_x;
	int				mp_y;
	double			s_dstx;
	double			s_dsty;
	double			d_dstx;
	double			d_dsty;
	double			pw_dst;
	int				step_x;
	int				step_y;
	int				hit;
	int				side;
	int				l_h;
	int				ds;
	int				d_end;
	int				color;
	double			old_dir_x;
	double			old_p_x;
	void			*xpm_file_img;
	void			*xfi_no;
	void			*xfi_so;
	void			*xfi_we;
	void			*xfi_ea;
	void			*xfi_s;
	void			*mlx_img;
	int				*mlx_data;
	int				*data_fl_cl;
	int				*data_no;
	int				*data_so;
	int				*data_ea;
	int				*data_we;
	int				*data_s;
	int				*mlx_data3;
	int				bits_per_pixel;
	int				size_line;
	int				endian;
	int				tex_num;
	int				tex_x;
	int				tex_y;
	double			walx;
	double			step;
	double			tex_pos;
	int				tex_width;
	int				tex_height;
	double			m_sp;
	double			rt_sp;
	int				key_up;
	int				key_down;
	int				key_right;
	int				key_left;
	int				rt_lft;
	int				rt_rgt;
	long long		rs_w;
	long long		rs_h;
	char			*p_no;
	char			*p_so;
	char			*p_we;
	char			*p_ea;
	char			*p_sp;
	char			**buff;
	int				tw_no;
	int				tw_so;
	int				tw_we;
	int				tw_ea;
	int				th_no;
	int				th_so;
	int				th_we;
	int				th_ea;
	int				check;
	int				check1;
	t_rgb			flr;
	t_rgb			cl;
	t_mp			mp;
	t_sprite		sprite;
	t_sprit			sprit;
	int				save;
}					t_var;

typedef	struct		s_bmp
{
	int				save;
	int				width;
	int				height;
	int				bit_count;
	int				width_in_bytes;
	int				img_size;
	int				bi_size;
	int				bmf_offbits;
	int				filesize;
	int				bit_planes;
	unsigned char	*header;
	unsigned char	*buf;
	int				row;
	int				col;
	long			color;
	int				r;
	int				g;
	int				b;
}					t_bmp;

void				trait_error(int ops);
char				*free_cub_exit(t_var *v, int ops);
char				**free_tab2d(char **tab, int size);
int					tab_len(char **tab);
int					key_release(int key, t_var *v);
int					key_press(int key, t_var *v);
void				trait_key(t_var *v);
void				move_up(t_var *v);
void				move_down(t_var *v);
void				move_right(t_var *v);
void				move_left(t_var *v);
void				rot_right(t_var *v);
void				rot_left(t_var *v);
void				draw_line_ceilling(t_var *v);
void				draw_line_floor(t_var *v);
void				dda(t_var *v);
void				step_init_dist(t_var *v);
void				sp_side(t_var *v);
void				coord_tex(t_var *v);
void				start_draw_end(t_var *v);
void				init_raycast(t_var *v);
int					draw_walls(t_var *v);
void				draw_line_ceilling(t_var *v);
void				draw_line_floor(t_var *v);
void				dda(t_var *v);
void				step_init_dist(t_var *v);
void				count_sprite(t_var *v, int i);
void				sort_sprite(t_var *v);
void				sprite_3(t_var *v, int stripe);
void				count_sprite_1(t_var *v);
void				sprite_2(t_var *v);
int					close_window(t_var *v);
void				sprite_1(t_var *v);
void				draw_in_file(t_var *v);
void				save_bmp(unsigned char *buf, t_bmp *bmp, t_var *v);
void				init_fh_fih(t_bmp *bmp, t_var *v);
void				start_game(t_var *v);
void				initial_tex(t_var *v);
void				player_initial(t_var *v);
void				rc_initial(t_var *v);
void				resolution(char *data, t_var *v);
void				cardinal_dir_path(char *line, t_var *v);
void				get_path_no_so(char *line, t_var *v, char *path);
void				get_path_we_ea(char *line, t_var *v, char *path);
void				sprite_path(char *line, t_var *v);
void				check_file_map(t_var *v, char *file_map);
void				rc_initial(t_var *v);
int					vrf_line_map(t_var *v, char *line, int idx);
void				vrf_cub(t_var *v);
int					check_line(t_var *v, char *line, int fd);
void				check_file_map(t_var *v, char *file_map);
int					dir_coord_sp(t_var *v, char *line, int idx);
int					transposed(t_var *v);
void				cub_initial(t_var *v);
int					is_color(int color_code);
void				color_init(t_rgb *color);
int					vrf_arg_dg(char *tab, char *set);
void				trait_space(t_var *v, char *line);
int					directions(char x);
void				check_res_card(char *line, t_var *v);
void				check_stuc_flr_cl(char *line, t_var *v);
int					vrf_color_flr_ceil(char **tab);
void				val_flr_ceil_color(t_var *v, char c, t_rgb color);
void				flr_cel_color(char *line, t_var *v);
int					trait_ext(char *file_name, char *extension);
int					mx_hl(char **tab);
int					vrf_map(t_var *v);
void				stock_map(int fd, char *line, t_var *v);
int					eof_vrf(int fd, char *line, t_var *v);
long long			ft_atoi(const char *str);
char				*ft_strdup(const char *s1);
void				*ft_calloc(size_t count, size_t size);
void				ft_bzero(void *s, size_t n);
void				*ft_memset(void *b, int c, size_t len);
char				*ft_strtrim(char const *s1, char const *set);
char				*ft_strjoin(char const *s1, char const *s2);
size_t				ft_strlen(const char *s);
int					ft_strncmp(const char *s1, const char *s2, size_t n);
void				*ft_memcpy(void *dst, const void *src, size_t n);
char				**ft_split(char const *s, char c);
void				ft_putchar_fd(char c, int fd);
void				ft_putstr_fd(char *s, int fd);
int					get_next_line(int fd, char **line);
char				*ft_strdup1(const char *s1);
char				*ft_strjoin1(char const *s1, char const *s2);
#endif
