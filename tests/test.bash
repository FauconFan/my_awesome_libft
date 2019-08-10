#!/bin/bash

set -eu

BASE=$1
FOLDER=tests/${BASE}/

if [ ! -d "${FOLDER}" ]; then
	echo "Not exist"
	exit 1
fi

_AVAILABLES_MODS=$(cd libft; find . -maxdepth 1 -name "libft_*" -type d)
AVAILABLES_MODS=""

for mod in ${_AVAILABLES_MODS}; do
	AVAILABLES_MODS="${AVAILABLES_MODS} ${mod/.\/libft_/}"
done

printf "===== %s =====\\n" "$(echo "${BASE}" | cut -d '_' -f 1)"

DEP=""

for mod in ${AVAILABLES_MODS}; do
	if [ "${mod}" = "$(echo "${BASE}" | cut -d '_' -f 2)" ]; then
		DEP="${mod}"
		break
	fi
done

make -C libft fclean

if [ "$DEP" = "" ]; then
	make -C libft
else
	make -C libft "MODS_SELECTED=libft_${DEP}"
fi

gcc -g -o "$FOLDER/a.out" "$FOLDER/main.c" -I libft/inc/ -Llibft -lft
"./$FOLDER/a.out" > /tmp/abcoui234.txt 2>&1

if [ -f "$FOLDER/out.txt" ]; then
	diff "$FOLDER/out.txt" /tmp/abcoui234.txt
fi

rm -rf "$FOLDER/a.out"
rm -rf /tmp/abcoui234.txt