# Variables generales
CC = cc
CFLAGS = -Wall -Wextra -Werror -g -fsanitize=address
BUILD_DIR = build
SRC_DIR = src
INC_DIR = include
HEADERS = -I ./MLX42/include/ -I$(INC_DIR)
NAME = fractol

# Configuración de MiniLibX
MLX_DIR = MLX42
MLX_BUILD_DIR = $(MLX_DIR)/build
MLX_LIB = $(MLX_BUILD_DIR)/libmlx42.a
MLX_FLAGS = -L$(MLX_BUILD_DIR) -ldl -pthread -lm -lglfw

# Configuración de Libft
LIBFT_DIR = ./Libft
LIBFT = $(LIBFT_DIR)/libft.a

# Archivos fuente y objetos
SRCS =  $(SRC_DIR)/fractals.c \
		$(SRC_DIR)/utils.c \
		$(SRC_DIR)/draw.c \
		$(SRC_DIR)/events.c \
		$(SRC_DIR)/hsv_map.c \
		$(SRC_DIR)/main.c

OBJS = $(patsubst $(SRC_DIR)/%.c, $(BUILD_DIR)/%.o, $(SRCS))

# Reglas principales
all: libmlx libft $(NAME)

# Compilar MLX42 usando CMake
libmlx:
	@cmake -DDEBUG=1 $(MLX_DIR) -B $(MLX_BUILD_DIR) && cmake --build $(MLX_BUILD_DIR) -j4

# Compilar libft
libft:
	$(MAKE) -C $(LIBFT_DIR)

# Crear el ejecutable
$(NAME): $(OBJS)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJS) $(MLX_LIB) $(LIBFT) -L$(MLX_BUILD_DIR) -lglfw -ldl -pthread -lm


# Compilación de objetos
$(BUILD_DIR)/%.o: $(SRC_DIR)/%.c
	@mkdir -p $(BUILD_DIR)
	$(CC) $(CFLAGS) $(HEADERS) -c $< -o $@

# Limpieza
clean:
	rm -rf $(BUILD_DIR)
	$(MAKE) -C $(LIBFT_DIR) clean

fclean: clean
	rm -rf $(NAME)
	rm -rf $(MLX_BUILD_DIR)
	$(MAKE) -C $(LIBFT_DIR) fclean

re: fclean all

# Phony
.PHONY: all clean fclean re libmlx libft

