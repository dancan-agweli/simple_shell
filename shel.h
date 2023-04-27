#ifndef  _SHEL_H_
#define  _SHEL_H_

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
#define TOK_BUFSIZE 128
#define TOK_DELIM " \t\r\n\a"

/* Points to an array of pointers to strings called the "environment" */
extern char **environ;


/**
 * struct data - struct that contains all relevant data on runtime
 * @av: argument vector
 * @input: command line written by the user
 * @args: tokens of the command line
 * @status: last status of the shell
 * @counter: lines counter
 * @_environ: environment variable
 * @pid: process ID of the shell
 */
typedef struct info
{
	char **va;
	char *in;
	char **args;
	int status;
	int count;
	char **_env;
	char *pid;
} info2;

/**
 * struct sep_list_s - single linked list
 * @separator: ; | &
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
 * @line: command line
 * @next: next node
 * Description: single linked list to store command lines
 */
typedef struct line_list_s
{
	char *line;
	struct line_list_s *next;
} line_list;

/**
 * struct r_var_list - single linked list
 * @len_var: length of the variable
 * @val: value of the variable
 * @len_val: length of the value
 * @next: next node
 * Description: single linked list to store variables
 */
typedef struct r_var_list
{
	int lenvar;
	char *value;
	int lenval;
	struct r_var_list *next;
} r_var;

/**
 * struct builtin_s - Builtin struct for command args.
 * @name: The name of the command builtin i.e cd, exit, env
 * @f: data type pointer function.
 */
typedef struct builtin_s
{
	char *nam;
	int (*f)(data_shell *datash);
} builtin_t;

/* ddlists.c */
sep_list *add_sep_node_end(sep_list **head, char sep);
void free_sep_list(sep_list **head);
line_list *add_line_node_end(line_list **head, char *line);
void free_line_list(line_list **head);

/* ddlists2.c */
r_var *add_rvar_node(r_var **head, int lvar, char *var, int lval);
void free_rvar_list(r_var **head);

/* ddstr functions */
char *_strcat(char *dest, const char *src);
char *_strcpy(char *dest, char *src);
int _strcmp(char *s1, char *s2);
char *_strchr(char *s, char c);
int _strspn(char *s, char *accept);

/* ddmem.c */
void _memcpy(void *newptr, const void *ptr, unsigned int size);
void *_realloc(void *ptr, unsigned int old_size, unsigned int new_size);
char **_reallocdp(char **ptr, unsigned int old_size, unsigned int new_size);

/* ddstr2.c */
char *_strdup(const char *s);
int _strlen(const char *s);
int cmp_chars(char str[], const char *delim);
char *_strtok(char str[], const char *delim);
int _isdigit(const char *s);

/* ddstr3.c */
void rev_string(char *s);

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
void add_node1(sep_list **head_s, line_list **head_l, char *inp);
void go_next(sep_list **list_s, line_list **list_l, info2 *info3);
int spltcmd(info2 *info3, char *inp);
char **spltlne(char *inp);

/* rep_var.c */
void check_environment(r_var **h, char *in, info2 *info3);
int checkvars(r_var **h, char *n, char *s, info2 *info3);
char *rep__input(r_var **head, char *inp, char *nwinp, int lenn);
char *replace_var(char *inp, info2 *info3);

/* get_line.c */
void get_line3(char **lineptr, size_t *m, char *buff, size_t i);
ssize_t get_line(char **lineptr, size_t *m, FILE *stream);

/* exec_line */
int executeline(info2 *info3);

/* cmd_exec.c */
int isdir(char *paTh, int *j);
char *_wh(char *cmd, char **_environ);
int is_executable(info2 *info3);
int checkerrcmd(char *dir, info2 *info3);
int cmexec(info2 *info3);

/* env1.c */
char *getenv1(const char *nam, char **_environ);
int env1(info3 *info3);

/* env2.c */
char *copyinff(char *nam, char *vlue);
void setenvv(char *nam, char *vlue, info2 *info3);
int setenv1(data_shell *datash);
int unsetenvv2(info2 *info3);

/* cd.c */
void cddott(info2 *info3);
void cdto2(info2 *info3);
void cdprev(info2 *info3);
void cdhome(info2 *info3);

/* cd_shell.c */
int cdshel(info2 *info3);

/* get_builtin */
int (*get_builtin(char *cmd))(info2 *info3);

/* _exit.c */
int exit_shell(info2 *info3);

/* aux_stdlib.c */
int getlength(int m);
char *a_ito(int m);
int _atoiii(char *r);

/* aux_error1.c */
char *strctCd(info2 *, char *, char *, char *);
char *err_cd(info2 *info3);
char *err_unfound(data_shell *datash);
char *err_exitshell(info2 *info3);

/* aux_error2.c */
char *er_alias(char **args);
char *er2_envir(info2 *info3);
char *er_synt(char **args);
char *er2_perm(char **args);
char *error_path(info2 *info3);


/* get_error.c */
int get1_err(info2 *info3, int val);

/* get_sigint.c */
void ge2_sigint(int g);

/* aux_help.c */
void help1_envv(void);
void help2_setenvv(void);
void help2_unsetenvv(void);
void help2_gen(void);
void help_exitt(void);

/* aux_help2.c */
void _help(void);
void _help1_alias(void);
void _help_cdd(void);

/* get_help.c */
int gett_helpp(info2 *info3);

#endif
