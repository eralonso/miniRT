# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: omoreno- <omoreno-@student.42barcelona.    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/11/21 10:34:11 by omoreno-          #+#    #+#              #
#    Updated: 2023/09/11 11:46:39 by omoreno-         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME			:= miniRT
NAMEB			:= ${addsuffix _bonus, $(NAME)}

SRCC_R			:= ft_read_map.c\
					events.c\
					ft_take_argument.c\
					ft_draw.c\
					minirt_class/minirt_class.c\
					minirt_class/ft_init_minirt_data.c\
					minirt_class/ft_cast_line_object.c\
					minirt_class/parse_figures.c\
					minirt_class/parse_scene_obj.c\
					minirt_class/parse_material.c\
					minirt_class/ft_free_material.c\
					minirt_class/ft_free_figure.c\
					minirt_class/ft_find_material.c\
					minirt_class/ft_link_figure_material.c\
					minirt_class/ft_link_materials.c\
					minirt_class/ft_create_background.c\
					minirt_class/parse_mat_image.c\
					minirt_class/image_class.c\
					minirt_class/ft_init_material_images.c\
					minirt_class/ft_destroy_mat_images.c\
					graph_ctx/graph_ctx.c \
					graph_ctx/graph_ctx_utils.c \
					utils/ft_matrix_len.c\
					utils/ft_isdouble.c\
					utils/ft_isrgb.c\
					utils/ft_isunsignedchar.c\
					utils/ft_isvector.c\
					utils/ft_isvector2d.c\
					utils/ft_strtod.c\
					utils/ft_isorientation.c\
					utils/ft_isfov.c\
					utils/ft_ispositivedouble.c\
					utils/ft_istheta.c\
					utils/ft_isangle.c\
					utils/ft_isratio.c\
					utils/ft_isname.c\
					utils/ft_ismattype.c\
					utils/ft_isexistingfile.c\
					utils/colors.c\
					utils/ft_free_n_log_error.c\
					geometry/vector_class.c\
					geometry/ft_addition.c\
					geometry/ft_distance_sq.c\
					geometry/ft_distance.c\
					geometry/ft_module.c\
					geometry/ft_normalize.c\
					geometry/ft_scale_vector.c\
					geometry/ft_substraction.c\
					geometry/ft_dot_product.c\
					geometry/ft_cross_product.c\
					geometry/ft_copy_vector.c\
					geometry/ft_get_base_ref.c\
					geometry/ft_tile.c\
					geometry/skin_mapping.c\
					geometry/ft_limit_height.c\
					geometry/camera/camera_rays_v2.c\
					geometry/raytrace/diffuse.c\
					geometry/raytrace/specular.c\
					geometry/raytrace/raytrace.c\
					geometry/raytrace/gen_ray.c\
					geometry/intersections/precomputers.c\
					geometry/intersections/ft_chess_pick_color.c\
					geometry/intersections/ft_quadrat_eq.c\
					geometry/intersections/inter_sphere_line.c\
					geometry/intersections/inter_plane_line.c\
					geometry/intersections/inter_cone_line.c\
					geometry/intersections/inter_cyl_line.c\
					geometry/intersections/best_intersection.c

SRC_R			:= main.c

SRCB_R			:= main_bonus.c

SRCC_PATH 		:= src_common/
SRC_PATH		:= src/
SRCB_PATH		:= src_bonus/
LIBFT_PATH		:= libft/
MLX_PATH		:= mlx/
MLX_MC_PATH		:= mlx_mc/
MLX_LX_PATH		:= mlx_lx/
BUILD_PATH		:= .build/
SRCC			:= ${addprefix $(SRCC_PATH), $(SRCC_R)}
SRC				:= ${addprefix $(SRC_PATH), $(SRC_R)}
SRCB			:= ${addprefix $(SRCB_PATH), $(SRCB_R)}

OBJC			:= $(addprefix $(BUILD_PATH), $(SRCC:.c=.o))
OBJ				:= $(addprefix $(BUILD_PATH), $(SRC:.c=.o))
OBJB			:= $(addprefix $(BUILD_PATH), $(SRCB:.c=.o))
DEPSC			:= $(addprefix $(BUILD_PATH), $(SRCC:.c=.d))
DEPS			:= $(addprefix $(BUILD_PATH), $(SRC:.c=.d))
DEPSB			:= $(addprefix $(BUILD_PATH), $(SRCB:.c=.d))

OS				:= $(shell uname -s | tr '[:upper:]' '[:lower:]')
CC				:= 	@gcc
OPTIM_FLAG		:= -O3
CFLAGS			:= -Wall -Werror -Wextra -g -O3
SANIT_FLAG		:=  -fsanitize=address
CFD				:= -MMD
RM				:= 	@rm -f
LIBC 			:= 	@ar -rcs
HEADERC 		:= ${addprefix $(SRCC_PATH), common.h}
HEADER 			:= ${addprefix $(SRC_PATH), ${addprefix $(NAME), .h}}
HEADERB 		:= ${addprefix $(SRCB_PATH), ${addprefix $(NAMEB), .h}}
LIBFT_H 		:= ${addprefix $(LIBFT_PATH), libft.h}
LIBFT_A 		:= ${addprefix $(LIBFT_PATH), libft.a}
LIBFT_D 		:= ${addprefix $(LIBFT_PATH), libft.d}
MLX_A 			:= ${addprefix $(MLX_PATH), libmlx.a}
MLX_H 			:= ${addprefix $(MLX_PATH), libmlx.h}
LIBS_MC_FLAGS  := -lm -Lmlx -lmlx -framework OpenGL -framework AppKit -I ${LIBFT_H} -I ${MLX_H}
LIBS_LX_FLAGS   := -I/usr/include -Imlx_linux -O1
LIBS_LX_FLAGS_LK:= -Lmlx -lmlx -L/usr/lib -Imlx -lXext -lX11 -lm -lz3
ifeq ($(OS),linux)
	LIBS_FLAGS		:= ${LIBS_LX_FLAGS}
	LIBS_FLAGS_LK	:= ${LIBS_LX_FLAGS_LK}
	MLX_OS_PATH		:= ${MLX_LX_PATH}
else
	LIBS_FLAGS		:=
	LIBS_FLAGS_LK	:= ${LIBS_MC_FLAGS}
	MLX_OS_PATH		:= ${MLX_MC_PATH}
endif
LIBFT_D_CONT	:= $(shell cat ${LIBFT_D} 2> /dev/null)

folder_create 	= $(shell mkdir -p $(1))

.SECONDEXPANSION:

$(BUILD_PATH)%.o: %.c $(MLX_PATH) ${HEADER} Makefile | $$(call folder_create,$$(dir $$@))
	@echo "Compiling " $@ " ..."
	${CC} ${CFLAGS} ${CFD} -I ${LIBFT_PATH} -I ${MLX_PATH} ${LIBS_FLAGS} -c $< -o $@

all : $(NAME)
bonus : $(NAMEB)

-include $(DEPS)
-include $(DEPSC)
$(NAME) : ${OBJC} ${OBJ} ${LIBFT_A} ${MLX_A} Makefile
	@echo "Linking " $@ " ..."
	${CC} ${CFLAGS} \
		${OBJ} ${OBJC} ${LIBFT_A} ${MLX_A} ${LIBS_FLAGS_LK} -o $@

-include $(DEPSB)
$(NAMEB): ${OBJC} ${OBJB} ${LIBFT_A} ${MLX_A} Makefile
	@echo "Linking " $@ " ..."
	${CC} ${CFLAGS} \
		${OBJB} ${OBJC} ${LIBFT_A} ${MLX_A} ${LIBS_FLAGS_LK} -o $@

${LIBFT_A} : ${LIBFT_D_CONT} libft/Makefile
	@echo "Making " $@ " if necessary.."
	@make -C libft

${MLX_A} : $(MLX_PATH)
	@echo "Making " $@ " if nececessary..."
	@echo "Host Operative System: " ${OS}
	@make -C mlx 2> /dev/null 1> /dev/null

$(MLX_PATH) :
	cp -R $(MLX_OS_PATH) $(MLX_PATH)

clean :
	@echo "Cleaning ..."
	@echo "Cleaning $(BUILD_PATH) ..."
	$(RM) -Rf $(BUILD_PATH)
	@echo "Cleaning MLX ..."
	$(RM) -Rf $(MLX_PATH)
#@make clean -C mlx 2> /dev/null 1> /dev/null
	@echo "Cleaning LIBFT ..."
	@make clean -C libft

fclean : clean
	@echo "Full cleaning ..."
	@echo "Cleaning LIBFT ..."
	@make fclean -C libft
	$(RM) $(NAME)
	$(RM) $(NAMEB)

re: fclean all

.PHONY : clean fclean re all bonus