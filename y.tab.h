

/* aqui están definidas los tokens utilizados por lex y yacc, que se obtienen llamando a la funcion yylex */

#ifndef YY_YY_Y_TAB_H_INCLUDED
# define YY_YY_Y_TAB_H_INCLUDED
/* Debug traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif
#if YYDEBUG
extern int yydebug;
#endif

/* Token type.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
  enum yytokentype
  {
    IF = 258,
    THEN = 259,
    ELSE = 260,
    END = 261,
    REPEAT = 262,
    UNTIL = 263,
    READ = 264,
    WRITE = 265,
    ID = 266,
    NUM = 267,
    ASSIGN = 268,
    EQ = 269,
    LT = 270,
    PLUS = 271,
    MINUS = 272,
    TIMES = 273,
    OVER = 274,
    LPAREN = 275,
    RPAREN = 276,
    SEMI = 277,
    ERROR = 278
  };
#endif
/* Tokens.  */
#define IF 258
#define THEN 259
#define ELSE 260
#define END 261
#define REPEAT 262
#define UNTIL 263
#define READ 264
#define WRITE 265
#define ID 266
#define NUM 267
#define ASSIGN 268
#define EQ 269
#define LT 270
#define PLUS 271
#define MINUS 272
#define TIMES 273
#define OVER 274
#define LPAREN 275
#define RPAREN 276
#define SEMI 277
#define ERROR 278

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef int YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_Y_TAB_H_INCLUDED  */
