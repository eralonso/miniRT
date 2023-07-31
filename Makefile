# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: omoreno- <omoreno-@student.42barcelona.    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/11/21 10:34:11 by omoreno-          #+#    #+#              #
#    Updated: 2023/07/27 18:54:35 by omoreno-         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME			:= miniRT
NAMEB			:= ${addsuffix _bonus, $(NAME)}

SRCC_R			:= ft_read_map.c\
					events.c\
					ft_take_argument.c\
					ft_draw.c\
					minirt_class/minirt_class.c\
					minirt_class/ft_cast_line_object.c\
					minirt_class/parse_figures.c\
					minirt_class/parse_scene_obj.c\
					graph_ctx/graph_ctx.c \
					utils/ft_matrix_len.c\
					utils/ft_isdouble.c\
					utils/ft_isrgb.c\
					utils/ft_isunsignedchar.c\
					utils/ft_isvector.c\
					utils/ft_strtod.c

SRC_R			:= main.c

SRCB_R			:= main_bonus.c

SRCC_PATH 		:= src_common/
SRC_PATH		:= src/
SRCB_PATH		:= src_bonus/
LIBFT_PATH		:= libft/
MLX_PATH		:= mlx/
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

CC				:= 	@gcc
CFLAGS			:= -Wall -Werror -Wextra -g
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
LIBS_FLAGS		:= -lm -Lmlx -lmlx -framework OpenGL -framework AppKit -I ${LIBFT_H} -I ${MLX_H}
LIBFT_D_CONT	:= $(@shell cat ${LIBFT_D} 2> /dev/null)

folder_create 	= $(shell mkdir -p $(1))

.SECONDEXPANSION:

$(BUILD_PATH)%.o: %.c ${HEADER} | $$(call folder_create,$$(dir $$@))
	@echo "Compiling " $@ " ..."
	${CC} ${CFLAGS} ${CFD} -I ${LIBFT_PATH} -I ${MLX_PATH} -c $< -o $@

all : $(NAME)
bonus : $(NAMEB)

-include $(DEPS)
$(NAME) : ${OBJC} ${OBJ} ${LIBFT_A} ${MLX_A}
	@echo "Linking " $@ " ..."
	${CC} ${CFLAGS} \
		${OBJ} ${OBJC} ${LIBFT_A} ${MLX_A} ${LIBS_FLAGS} -o $@

-include $(DEPSB)
$(NAMEB): ${OBJC} ${OBJB} ${LIBFT_A} ${MLX_A}
	@echo "Linking " $@ " ..."
	${CC} ${CFLAGS} \
		${OBJB} ${OBJC} ${LIBFT_A} ${MLX_A} ${LIBS_FLAGS} -o $@

${LIBFT_A} : ${LIBFT_D_CONT}
	@echo "Making " $@ " if necessary.."
	@make -C libft

${MLX_A} :
	@echo "Making " $@ " if nececessary..."
	@make -C mlx 2> /dev/null 1> /dev/null

clean :
	@echo "Cleaning ..."
	@echo "Cleaning $(BUILD_PATH) ..."
	$(RM) -Rf $(BUILD_PATH)
	@echo "Cleaning MLX ..."
	@make clean -C mlx 2> /dev/null 1> /dev/null
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