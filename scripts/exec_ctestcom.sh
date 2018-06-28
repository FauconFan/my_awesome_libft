#!/usr/bin/env bash

LIBFT_SRC="libft/src/"
CTESTCOM_FOLDER="ctestcom"
PATH_CTESTCOM="ctestcom/ctestcom"
FLAGS_COMP_CTESTCOM="-L ctestcom/libtestcom -l ctestcom -I ctestcom/libtestcom/includes"
OUTPUT_CTESTCOM=$(mktemp)
OUTPUT_POST_BUILD=$(mktemp)

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

for FILE in ${FILES}; do
    NB_FILES=$((${NB_FILES} + 1))
    printf "Handling %s\\n" "${FILE}"
    ./${PATH_CTESTCOM} ${FILE} ${OUTPUT_CTESTCOM}.c
    gcc ${OUTPUT_CTESTCOM}.c ${FLAGS_COMP_CTESTCOM} -o ${OUTPUT_POST_BUILD}
    RET_OUTPUT=$(${OUTPUT_POST_BUILD})
    OUTPUT_RC=$?
    echo ${RET_OUTPUT}
    if ! [[ ${OUTPUT_RC} = 0 ]]; then
        echo "Tests not passed"
        RC=1
        break
    fi
    if echo ${RET_OUTPUT} | grep 'enough tests' > /dev/null 2>&1; then
        FILES_WITH_NO_TESTS=$((${FILES_WITH_NO_TESTS} + 1))
    else
        FILES_WITH_TESTS=$((${FILES_WITH_TESTS} + 1))
    fi
done

printf "Files in total :         %s\\n" "${NB_FILES}"
printf "Files with no tests :    %s\\n" "${FILES_WITH_NO_TESTS}"
printf "Files with tests :       %s\\n" "${FILES_WITH_TESTS}"


rm -rf ${OUTPUT_CTESTCOM} ${OUTPUT_CTESTCOM}.c ${OUTPUT_POST_BUILD}

exit ${RC}
