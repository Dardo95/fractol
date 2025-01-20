# Variables generales
CC = cc
CFLAGS = -Wall -Wextra -Werror
BUILD_DIR = build
SRC_DIR = src
INC_DIR = include
NAME = fractol

# Configuración de MiniLibX
MLX_DIR = minilibx
MLX_LIB = $(MLX_DIR)/libmlx.a
MLX_FLAGS = -L$(MLX_DIR) -lmlx -L/usr/lib -lXext -lX11

# Archivos fuente y objetos
SRCS =  $(SRC_DIR)/fractals.c \
		$(SRC_DIR)/utils.c \
		$(SRC_DIR)/main.c \

OBJS = $(patsubst $(SRC_DIR)/%.c, $(BUILD_DIR)/%.o, $(SRCS))

# Reglas
all: $(NAME)

# Crear el ejecutable
$(NAME): $(OBJS) $(MLX_LIB)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJS) $(MLX_FLAGS)

# Compilación de objetos
$(BUILD_DIR)/%.o: $(SRC_DIR)/%.c
	@mkdir -p $(BUILD_DIR)
	$(CC) $(CFLAGS) -I$(INC_DIR) -I$(MLX_DIR) -c $< -o $@

# Compilar MiniLibX (si es necesario)
$(MLX_LIB):
	make -C $(MLX_DIR)

# Limpieza
clean:
	rm -rf $(BUILD_DIR)
	make -C $(MLX_DIR) clean

fclean: clean
	rm -f $(NAME)

re: fclean all

# Phony
.PHONY: all clean fclean re

