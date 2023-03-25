NAME = cub3D

CFLAGS = -Wall -Wextra -Werror

SRC = cub3d.c \
      utils/ft_atoi.c \
      utils/ft_putstr_fd.c \
      utils/ft_strlen.c \
      utils/ft_split.c \
      utils/ft_strjoin.c \
      utils/ft_strncmp.c \
      utils/ft_strtrim.c \
      utils/ft_memcpy.c \
      utils/ft_calloc.c \
	  utils/ft_bzero.c \
	  utils/ft_putchar_fd.c \
	  utils/ft_memset.c \
	  utils/ft_strdup.c \
	  get_next_line.c \
	  get_next_line_utils.c \
	  raycasting.c \
	  raycasting_utils.c \
	  init_cub.c \
	  get_path.c \
	  transposed.c \
	  check_file.c \
	  vrf_res_flr_cl.c \
	  parcing_utils.c \
	  map_utils.c \
	  sprit.c \
	  sprit_utils.c \
	  move.c \
	  rotation.c \
	  save.c \
	  trait_error.c \
	  trait_key.c
OBJ = ${SRC:.c=.o}

all:$(LIBFT) $(NAME) 

$(NAME): $(OBJ)
	@gcc $(CFLAGS) $(OBJ) -lmlx -framework OpenGL -framework AppKit  -o $(NAME)

clean:
	@rm -f $(OBJ)

fclean: clean
	@rm -f $(NAME)

re: fclean all