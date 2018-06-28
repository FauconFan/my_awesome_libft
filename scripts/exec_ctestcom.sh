#!/usr/bin/env bash

LIBFT_FOLDER="libft"
CTESTCOM_FOLDER="ctestcom"
BUILD_CUSTOM_FOLDER="build_custom"

LIBFT_SRC="libft/src/"
PATH_CTESTCOM="ctestcom/ctestcom"
FLAGS_COMP_LIBFT="-L rendu -l ft -I rendu"
FLAGS_COMP_CTESTCOM="-L ctestcom/libtestcom -l ctestcom -I ctestcom/libtestcom/includes"
TMP_FOLDER=$(mktemp -d)
OUTPUT_CTESTCOM=${TMP_FOLDER}/ctestcom_output.c
OUTPUT_POST_BUILD=${TMP_FOLDER}/post_build_ctestcom.c

NB_FILES=0
FILES_WITH_TESTS=0
FILES_WITH_NO_TESTS=0

RC=0

if [[ $# = 1 ]]; then
    LIBFT_SRC=libft/src/$1
fi

if ! [[ -d ${LIBFT_SRC} ]]; then
    echo "I can't found the src folder..."
    exit 1;
fi

FILES=$(find ${LIBFT_SRC} -name "*.c" -type f)

printf "Building ctestcom... "
make -C ${CTESTCOM_FOLDER} > /dev/null 2>&1
printf "built\\n"

printf "Building build_custom... "
make -C ${BUILD_CUSTOM_FOLDER} > /dev/null 2>&1
printf "built\\n"

for FILE in ${FILES}; do
    NB_FILES=$((${NB_FILES} + 1))
    printf "Handling %s\\n" "${FILE}"
    ./${PATH_CTESTCOM} ${FILE} ${OUTPUT_CTESTCOM}
    make -C ${BUILD_CUSTOM_FOLDER} run PARAM=${OUTPUT_CTESTCOM}
    make -C rendu
    gcc ${OUTPUT_CTESTCOM} ${FLAGS_COMP_CTESTCOM} ${FLAGS_COMP_LIBFT} -o ${OUTPUT_POST_BUILD}
    RET_OUTPUT=$(${OUTPUT_POST_BUILD})
    OUTPUT_RC=$?
    echo "${RET_OUTPUT}"
    if ! [[ ${OUTPUT_RC} = 0 ]]; then
        echo "Tests not passed"
        RC=1
    fi
    if echo ${RET_OUTPUT} | grep 'enough tests' > /dev/null 2>&1; then
        FILES_WITH_NO_TESTS=$((${FILES_WITH_NO_TESTS} + 1))
    else
        FILES_WITH_TESTS=$((${FILES_WITH_TESTS} + 1))
    fi
    rm -rf rendu
done

printf "Files in total :         %s\\n" "${NB_FILES}"
printf "Files with no tests :    %s\\n" "${FILES_WITH_NO_TESTS}"
printf "Files with tests :       %s\\n" "${FILES_WITH_TESTS}"


rm -rf ${TMP_FOLDER}

exit ${RC}
