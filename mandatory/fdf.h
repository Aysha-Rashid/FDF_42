/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayal-ras <ayal-ras@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/03 12:45:35 by ayal-ras          #+#    #+#             */
/*   Updated: 2023/12/23 16:11:46 by ayal-ras         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#define BUFFER_SIZE 500
#define W_WIDTH 1000
#define W_LENGTH 1000
#define BACKGROUND	0x1E1E1E
#include <stdlib.h>
#include <math.h>
#include <unistd.h>
#include "../minilibx/mlx.h"
#include <fcntl.h>
#define RED 0xfc0345
#define NEON_BLUE 0x83EEFF
#define NEON_ORANGE 0xFF5F1F
#define GREEN 0x98FF98
#define BLUE 0x0000FF
#define COLOR_DISCO	0x9A1F6A
#define TEXT_COLOR	0xEAEAEA
#define COLOR_FLAMINGO 0xEC4B27
#define COLOR_SAFFRON 0xF3AF3D
//-----project-----
typedef struct s_point
{
	float	z;
	float	x;
	float	y;
	int		color;
}			t_point;

typedef struct t_fdf
{
	void	*mlx_win;
	char	*img_add;
	void	*img;
	int		bpp;
	int		size_line;
	int		endian;
	void	*mlx_ptr;
	int		yes_isometric;
	int		z_scale;
	int		scale;
	int		x1;
	int		y1;
	int		is_end;
	double	angle_x;
	double	angle_y;
	double	angle_z;
	t_point	matrix;
}			t_fdf;

t_fdf	**read_map(char *file);
t_fdf	**memory_allocated(char *file);
void	put_pixel(int x, int y, int color, t_fdf *data);
int		ft_color(t_fdf *current, t_fdf *next);
int		deal_key(int key, t_fdf **matrix);
void	ft_init(t_fdf *data);
void	zoom(t_fdf *current, t_fdf *next, t_fdf *data);
void	ft_set(t_fdf *current, t_fdf *next, t_fdf *data);
void	draw(t_fdf **matrix);
void	isometric(t_fdf *dots);
void	print_menu(t_fdf param);
void	get_dots_from_line(char *line, t_fdf **matrix_of_dots, int y);
void	ft_error(t_fdf *data);
void	image_menu(t_fdf *data);
int		esc_key(int key, t_fdf **matrix);
int		clear(void *data);
void	handle_color(char **dots, t_fdf **matrix_of_dots, int y, int x);

//-----libft-----
void	*ft_memset(void	*b, int c, size_t	len);
char	*read_lines(int fd, char *store);
char	*new_line(char *buffer);
char	*remaining(char *buffer);
char	**ft_split(char const *s, char c);
int		count_substrings(char const *s, char c);
char	*ft_strncpy(char *dest, const char *src, unsigned int n);
void	split_into_substrings(char	**str, char const	*s, char c);
char	*get_next_line(int fd);
int		ft_atoi(const char	*str);
char	*ft_strchr(char *s, int c);
char	*ft_strdup(char	*s1);
char	*ft_strjoin(char *s1, char *s2);
int		ft_putchar(int c);
int		ft_string(char *str);
int		ft_strncmp(const char	*s1, const char	*s2, unsigned int n);
int		ft_atoi_base(const char *str, int str_base);
void	ft_bzero(void	*s, size_t n);
void	draw_background(t_fdf *fdf);
size_t	ft_strlen(const char *str);
