NAME				=	so_long

SRCS_DIR			=	sources

OBJS_DIR			=	.objs

HEADER_DIR			=	includes

BONUS_DIR			=	bonus

MLX_DIR				=	minilibx-linux

SRCS				=	check_argc_and_name.c	free_and_error.c	load_sprite_1.c	check_images.c	\
						ft_itoa.c	load_sprite_2.c	check_map_accessibility.c	get_map_elements.c	\
						moove_player.c	check_map_entities.c	get_next_line.c	initialize_struct.c	\
						check_map_rectangle.c	get_next_line_utils.c	deal_key.c	so_long.c

OBJS				=	$(SRCS:%.c=$(OBJS_DIR)/%.o)

HEADERS				=	$(HEADER_DIR)/so_long.h $(HEADER_DIR)/get_next_line.h

CC					=	cc

FLAGS				=	-Wall -Werror -Wextra -g3

MLXFLAGS				=	-L ./minilibx-linux -lmlx -lXext -lX11

ifeq ($(BONUS),true)
	NAME			=	so_long_bonus

    SRCS_DIR        =    sources_bonus

    SRCS            =	check_argc_and_name_bonus.c	free_and_error_bonus.c	load_sprite_1_bonus.c	check_images_bonus.c	\
						ft_itoa_bonus.c	load_sprite_2_bonus.c	check_map_accessibility_bonus.c	get_map_elements_bonus.c	\
						moove_player_bonus.c	check_map_entities_bonus.c	get_next_line_bonus.c	initialize_struct_bonus.c	\
						check_map_rectangle_bonus.c	get_next_line_utils_bonus.c	deal_key_bonus.c	so_long_bonus.c		\
						moove_monster_bonus.c	load_monster_sprites_bonus.c
                    
    OBJS            =    $(SRCS:%.c=$(OBJS_DIR)/%.o)

endif

all:				mlx $(NAME)

$(OBJS_DIR)/%.o:	$(SRCS_DIR)/%.c $(HEADERS)
						$(CC) $(FLAGS) -I/usr/include -Iminilibx-linux -c $< -o $@

$(NAME):			$(OBJS_DIR) $(OBJS) $(HEADERS) $(MLX_DIR)/libmlx.a
						$(CC) $(FLAGS) $(OBJS) $(MLXFLAGS) $(MLX_DIR)/libmlx.a -o $(NAME)

$(OBJS_DIR):
						mkdir -p $(OBJS_DIR)

mlx:
						$(MAKE) -C $(MLX_DIR)

bonus:
						@$(MAKE) all BONUS=true


clean:
						rm -rf $(OBJS_DIR)
						$(MAKE) clean -C $(MLX_DIR)

fclean:
						$(MAKE) clean
						$(MAKE) fclean_bonus BONUS=true
						rm -rf $(NAME)
						$(MAKE) clean -C $(MLX_DIR)

fclean_bonus:
						rm -rf $(NAME)

re:
						$(MAKE) fclean all

.PHONY: all clean fclean re libft
