/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pointh.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dquartin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/07 10:08:13 by dquartin          #+#    #+#             */
/*   Updated: 2018/04/13 15:14:44 by dquartin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <string.h>
# include <stdlib.h>
# include <unistd.h>

# define BUFF_SIZE 1000
# define BLACK "\033[22;31m"
# define GREEN "\033[22;32m"
# define BROWN "\033[22;33m"
# define BLUE "\033[22;34m"
# define MAGENTA "\033[22;35m"
# define CYAN "\033[22;36m"
# define GRAY "\033[22;37m"
# define DARK_GRAY "\033[01;30m"
# define LIGHT_RED "\033[01;31m"
# define LIGHT_GREEN "\033[01;32m"
# define YELLOW "\033[01;33m"
# define LIGHT_BLUE "\033[01;34m"
# define LIGHT_MAGENTA "\033[01;35m"
# define LIGHT_CYAN "\033[01;36m"
# define WHITE "\033[01;37m"

typedef struct		s_list
{
	void			*content;
	size_t			content_size;
	struct s_list	*next;
}					t_list;

void				delete_tab(char ***stock);
void				ft_bzero(void *s, size_t n);
void				ft_strdel(char **as);
void				ft_strclr(char *s);
void				ft_striter(char *s, void (*f)(char *));
void				ft_striteri(char *s, void (*f)(unsigned int, char *));
void				ft_memdel(void **ap);
void				ft_putchar(char c);
void				ft_putchar_fd(char c, int fd);
void				ft_putstr(char const *s);
void				ft_putstr_fd(char const *s, int fd);
void				ft_putendl(char const *s);
void				ft_putendl_fd(char const *s, int fd);
void				ft_puterror(char *s);
void				ft_putnbr(int n);
void				ft_putnbr_fd(int n, int fd);
void				ft_putcolor(char *str, char *color);
void				ft_putnbrcolor(int nb, char *color);
void				ft_lstdelone(t_list **alst, void (*del)(void *, size_t));
void				ft_lstdel(t_list **alst, void (*del)(void *, size_t));
void				ft_lstadd(t_list **alst, t_list *new);
void				ft_lstiter(t_list *lst, void (*f)(t_list *elem));
void				ft_putnbr_base(unsigned int nb, char *base);
void				ft_padding(int nb, int space);
void				ft_putstrerror(char *s);
void				*ft_realloc(void *ptr, int old_size, int nez_size);
void				*ft_memset(void *str, int c, size_t n);
void				*ft_memcpy(void *dest, const void *src, size_t n);
void				*ft_memccpy(void *dest, const void *src, int c, size_t n);
void				*ft_memmove(void *dest, const void *src, size_t n);
void				*ft_memchr(const void *str, int c, size_t n);
void				*ft_memalloc(size_t size);

int					get_next_line(const int fd, char **line);
int					ft_countstr(char *s1, char *s2);
int					ft_memcmp(const void *s1, const void *s2, size_t n);
int					ft_strcmp(const char *s1, const char *s2);
int					ft_strncmp(const char *s1, const char *s2, size_t n);
int					ft_atoi(const char *str);
int					ft_isalpha(int c);
int					ft_isdigit(int c);
int					ft_isalnum(int c);
int					ft_isascii(int c);
int					ft_isprint(int c);
int					ft_puterrorint(char *s);
int					ft_toupper(int c);
int					ft_tolower(int c);
int					ft_sqrt(int nb);
int					ft_nbdigit(int value, int base);
int					ft_pow(int n, unsigned int pow);
int					ft_strequ(char const *s1, char const *s2);
int					ft_strnequ(char const *s1, char const *s2, size_t n);
int					tab_len(char **tab);

size_t				ft_strlen(const char *str);
size_t				ft_strlcat(char *dest, const char *src, size_t size);

char				*ft_delinstr(char *src, char *del);
char				*ft_strnew(size_t size);
char				*ft_strdup(const char *str);
char				*ft_strndup(const char *str, char c);
char				*ft_strcpy(char *dest, const char *src);
char				*ft_strintab(char *str, char **stock);
char				*ft_strncpy(char *dest, const char *src, size_t len);
char				*ft_strcat(char *s1, const char *s2);
char				*ft_strncat(char *dest, const char *src, size_t n);
char				*ft_strchr(const char *str, int c);
char				*ft_strrchr(const char *str, int c);
char				*ft_strreplace(char *src, char *new, int size);
char				*ft_strstr(const char *s1, const char *s2);
char				*ft_strnrstr(const char *s1, const char *s2, int size);
char				*ft_strnstr(const char *s1, const char *s2, size_t len);
char				*ft_strmap(char const *s, char (*f)(char));
char				*ft_strmapi(char const *s, char (*f)(unsigned int, char));
char				*ft_strsub(char const *s, unsigned int start, size_t len);
char				*ft_strsubdel(char *s, int start, size_t len);
char				*ft_strjoin(char const *s1, char const *s2);
char				*ft_strjoindel(char *s1, const char *s2);
char				*ft_strjoindeldel(char *s1, char *s2);
char				*ft_strtrim(char const *s);
char				*ft_itoa(int n);
char				**ft_strsplit(char const *s, char c);
char				*ft_touppercase(char *str);
char				*ft_tolowercase(char *str);

t_list				*ft_lstnew(void const *content, size_t content_size);
t_list				*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem));

#endif
