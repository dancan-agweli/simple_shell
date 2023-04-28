#ifndef _SHEL_H_
#define _SHEL_H_

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <errno.h>
#include <fcntl.h>
#include <signal.h>
#include <limits.h>

#define BUFSIZE 1024
/* tokenizing */
#define TOK_BUFSIZE 128
#define TOK_DELM " \t\r\n\a"

/* Points to an array of pointers to environment */
extern char **environ;


/**
 * struct info - struct that contains all relevant data on runtime
 * @aav: argument vector
 * @inp: command line written by the user
 * @args: tokens of the command line
 * @status: last status of the shell
 * @count: linesof the counter
 * @_environn: environment variable
 * @pid: process ID of the shell
 */
typedef struct info
{
	char **aav;
	char *inp;
	char **args;
	int status;
	int count;
	char **_environn;
	char *pid;
} info2;

/**
 * struct sep_list_s - single linked list
 * @sep: ; | &
 * @next: next node
 * Description: single linked list to store separators
 */
typedef struct sep_list_s
{
	char sep;
	struct sep_list_s *next;
} sep_list;

/**
 * struct line_list_s - single linked list
 * @line: commands of the line
 * @next: next node of the program
 * Description: single linked list to store command lines
 */
typedef struct line_list_s
{
	char *line;
	struct line_list_s *next;
} line_list;

/**
 * struct r_var_list - single linked list in program
 * @lenvar: length of the variable list
 * @valuee: value of the variable list
 * @lenval: length of the value list
 * @next: next node of program
 * Description: single linked list to stored variables.
 */
typedef struct r_var_list
{
	int lenvar;
	char *valuee;
	int lenval;
	struct r_var_list *next;
} r_var;

/**
 * struct builtin_s - Builtin struct of cmd args.
 * @name: The namee of the command builtin i.e cd, exit, env
 * @f: data type pointer function.
 */
typedef struct builtin_s
{
	char *name;
	int (*f)(info2 *info3);
} builtin_t;

/* ddlists.c */
sep_list *add_sep_node_end(sep_list **headd, char sep);
void free_sep_list(sep_list **headd);
line_list *add_line_node_end(line_list **headd, char *line);
void free_line_list(line_list **headd);

/* ddlists2.c */
r_var *add_rvar_node(r_var **headd, int lenvar, char *valuee, int lenval);
void free_rvar_list(r_var **headd);

/* ddstr functions */
char *_strcat(char *dt, const char *sc);
char *_strcpy(char *dt, char *sc);
int _strcmp(char *s11, char *s22);
char *_strchr(char *ss, char cc);
int _strspn(char *ss, char *acceps);

/* ddmem.c */
void _memcpy(void *nptr, const void *pr, unsigned int sz);
void *_reallocc(void *pr, unsigned int oldsz, unsigned int newsz);
char **_reallocc2(char **pr, unsigned int oldsz, unsigned int newsz);

/* ddstr2.c */
char *_strdup(const char *ss);
int _strlen(const char *ss);
int cmp_charss(char strs[], const char *delm);
char *_strtoks(char strs[], const char *delm);
int _isdigits(const char *ss);

/* ddstr3.c */
void rev_strings(char *ss);

/* check_syntax_error.c */
int repchar(char *inp, int x);
int error_sep(char *inp, int x, char end);
int start_char(char *inp, int *x);
void print_synt_err(info2 *info3, char *inp, int x, int bool);
int check_s_error(info2 *info3, char *inp);

/* shell_loop.c */
char *witho_comm(char *ni);
void s_loop(info2 *info3);

/* read_line.c */
char *readline1(int *x_eof);

/* split.c */
char *swpch(char *inp, int bool);
void add_node1(sep_list **head_ss, line_list **head_ll, char *inp);
void go_next(sep_list **list_ss, line_list **list_ll, info2 *info3);
int spltcmd(info2 *info3, char *inp);
char **spltlne(char *inp);

/* rep_var.c */
void check_environment(r_var **h, char *n, info2 *info3);
int checkvars(r_var **h, char *n, char *s, info2 *info3);
char *rep__input(r_var **headd, char *inp, char *nwinp, int lenn);
char *replace_var(char *inp, info2 *info3);

/* getline.c */
void get_line3(char **lptr, size_t *m, char *buff, size_t i);
ssize_t get_line(char **lptr, size_t *m, FILE *stream);

/* ddexecline */
int executeline1(info2 *info3);

/* ddcmdexec.c */
int isdir(char *path, int *j);
char *_wh(char *cmd, char **_environn);
int is_executable(info2 *info3);
int checkerrcmd(char *dir, info2 *info3);
int cmexec(info2 *info3);

/* ddenv1.c */
char *getenv1(const char *namee, char **_environn);
int env1(info2 *info3);

/* ddenv2.c */
char *copyinff(char *namee, char *vlue);
void setenvv(char *namee, char *vlue, info2 *info3);
int setenv1(info2 *info3);
int unsetenvv2(info2 *info3);

/* ddcd.c */
void cddott(info2 *info3);
void cdto2(info2 *info3);
void cdprev(info2 *info3);
void cdhome(info2 *info3);

/* ddcdshell.c */
int cdshel(info2 *info3);

/*ddgetbuiltin */
int (*get_builtin(char *cmd))(info2 *);

/* dd_exit.c */
int exit_shell(info2 *info3);

/* dd_stdlib.c */
int get_length(int m);
char *a_ito(int m);
int _atoiii(char *r);

/* dd_error1.c */
char *strctCd(info2 *, char *, char *, char *);
char *err_cd(info2 *info3);
char *err_unfound(info2 *info3);
char *err_exitshell(info2 *info3);

/* dd_error2.c */
char *er_alias(char **args);
char *er2_envir(info2 *info3);
char *er_synt(char **args);
char *er2_perm(char **args);
char *error_path(info2 *info3);


/* ddget_error.c */
int get1_err(info2 *info3, int val);

/*dd getsigint.c */
void ge2_sigint(int g);

/* ddhelp.c */
void help1_envv(void);
void help2_setenvv(void);
void help2_unsetenvv(void);
void help2_general(void);
void help_exitt(void);

/* ddhelp2.c */
void _help(void);
void _help1_alias(void);
void _help_cdd(void);

/* ddgethelp.c */
int gett_helpp(info2 *info3);

#endif
