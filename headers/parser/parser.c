#include "parser.h"

char* readline(char* prompt) {
    /*print an output and get input*/
    fputs(prompt, stdout);
    fgets(buffer, 2048, stdin);
    char* cpy = malloc(strlen(buffer)+1);
    strcpy(cpy, buffer);
    cpy[strlen(cpy)-1] = '\0';
    return cpy;
}

void handler(void) {
    mpc_parser_t *_int = mpc_new("int");
    mpc_parser_t *_operator = mpc_new("operator");
    mpc_parser_t *rePython = mpc_new("rePython");

    mpca_lang(MPCA_LANG_DEFAULT,
    "                                                     \
      int   : /-?[0-9]+/ ;                                \
      operator : '+' | '-' | '*' | '/' ;                  \
      rePython:  /^/ <int>* /$/ ;                           \
    ",
    _int, _operator, rePython);
  

    puts("rePython version 0.0.0.1\n");
    while(1) {
        mpc_result_t result;
        char *input = readline("rePython>");

        if (mpc_parse("<stdin>", input, rePython, &result)) {
            mpc_ast_print(result.output);
            mpc_ast_delete(result.output);
        }

        else {
        mpc_err_print(result.error);
        mpc_err_delete(result.error);
        }
    }
    // undefine and delete parsers
    mpc_cleanup(3, _int, _operator, rePython);
}