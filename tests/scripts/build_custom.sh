#/bin/sh

verify_build_custom()
{
	path="../build_custom/$1"
	make -C ${path}libft
	gcc ${path}main.c -I ${path}libft/ -o ${path}a.out -L ${path}libft -l ft
	${path}a.out
	rm -rf ${path}a.out
	res=$(find ${path}libft/src -name "*.c" | wc -l)
	if [ ! $res = 1 ]; then
		printf "more than one file"
		exit 1
	fi
	make fclean -C ${path}libft
}

test_tg()
{
	path="../build_custom/$1"
	make -C ${path}libft
	gcc ${path}main.c -I ${path}libft/ -o ${path}a.out -L ${path}libft -l ft
	${path}a.out
	rm -rf ${path}a.out
	make fclean -C ${path}libft
}

if [ $# = 0 ]; then
	printf "./build_custom.sh [mode] [args]...\n"
	exit 1
fi

G_MODE=$1

case $G_MODE in
	"simple_test") verify_build_custom $2 ;;
	"test_tg") test_tg $2 ;;
	*) printf "this mode is not recognised"; exit 1;;
esac
