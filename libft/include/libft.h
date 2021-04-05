/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aroque <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/20 11:24:25 by aroque            #+#    #+#             */
/*   Updated: 2021/04/04 22:30:51 by aroque           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <stdlib.h>
# include <stdbool.h>

/*
**	----------------------
**	--- Libc Functions ---
**	----------------------
*/

void				ft_bzero(void *s, size_t n);
void				*ft_memset(void *b, int c, size_t len);
int					ft_atoi(const char *str);
void				*ft_memcpy(void *dst, const void *src, size_t n);
void				*ft_memccpy(void *dst, const void *src, int c, size_t n);
void				*ft_memmove(void *dst, const void *src, size_t len);
void				*ft_memchr(const void *s, int c, size_t n);
int					ft_memcmp(const void *s1, const void *s2, size_t n);
int					ft_strncmp(const char *s1, const char *s2, size_t n);
size_t				ft_strlen(const char *s);
size_t				ft_strlcpy(char *dst, const char *src, size_t dstsize);
size_t				ft_strlcat(char *dst, const char *src, size_t dstsize);
char				*ft_strchr(const char *s, int c);
char				*ft_strrchr(const char *s, int c);
char				*ft_strnstr(const char *haystack,
						const char *needle, size_t len);
char				*ft_strdup(const char *s1);
void				*ft_calloc(size_t count, size_t size);
int					ft_isalpha(int c);
int					ft_isdigit(int c);
int					ft_isalnum(int c);
int					ft_isascii(int c);
int					ft_isprint(int c);
int					ft_toupper(int c);
int					ft_tolower(int c);
int					ft_atoi(const char *str);

/*
**	----------------------------
**	--- Additional Functions ---
**	----------------------------
*/

char				*ft_itoa(int n);
char				*ft_substr(char const *s, unsigned int start, size_t len);
char				*ft_strjoin(char const *s1, char const *s2);
char				*ft_strtrim(char const *s1, char const *set);
char				*ft_strmapi(char const *s, char (*f)(unsigned int, char));
char				**ft_split(char const *s, char c);
void				ft_putchar_fd(char const c, int fd);
void				ft_putstr_fd(char const *s, int fd);
void				ft_putendl_fd(char *s, int fd);
void				ft_putnbr_fd(int n, int fd);

/*
**	-----------------------------
**	--- Linked List Functions ---
**	-----------------------------
*/

typedef struct s_list
{
	void			*content;
	struct s_list	*previous;
	struct s_list	*next;
}					t_list;

t_list				*ft_lstnew(void *content);
void				ft_lstadd_front(t_list **lst, t_list *new);
void				ft_lstadd_back(t_list **lst, t_list *new);
int					ft_lstsize(t_list *lst);
t_list				*ft_lstfirst(t_list *lst);
t_list				*ft_lstlast(t_list *lst);
void				ft_lstdelone(t_list *lst, void (*del)(void*));
void				ft_lstclear(t_list **lst, void (*del)(void*));
void				ft_lstiter(t_list *lst, void (*f)(void *));
t_list				*ft_lstmap(t_list *lst, void *(*f)(void *),
						void (*del)(void *));

/*
**	-----------------------
**	--- Other Functions ---
**	-----------------------
*/

int					ft_isspace(char str);
size_t				ft_strspn(const char *s, const char *accept);
size_t				ft_strcspn(const char *s, const char *reject);
char				*ft_strtok(char *str, const char *delim);
char				*ft_strtok_r(char *str, const char *delim, char **ptr);
char				*ft_strreplace(char **str, const char *s, const char *r);
int					ft_isalnum_or_uscore(int c);
bool				ft_streq(const char *s1, const char *s2);

/*
**	░░░░░░░█▐▓▓░████▄▄▄█▀▄▓▓▓▌█
**	░░░░░▄█▌▀▄▓▓▄▄▄▄▀▀▀▄▓▓▓▓▓▌█
**	░░░▄█▀▀▄▓█▓▓▓▓▓▓▓▓▓▓▓▓▀░▓▌█
**	░░█▀▄▓▓▓███▓▓▓███▓▓▓▄░░▄▓▐█▌
**	░█▌▓▓▓▀▀▓▓▓▓███▓▓▓▓▓▓▓▄▀▓▓▐█
**	▐█▐██▐░▄▓▓▓▓▓▀▄░▀▓▓▓▓▓▓▓▓▓▌█▌
**	█▌███▓▓▓▓▓▓▓▓▐░░▄▓▓███▓▓▓▄▀▐█
**	█▐█▓▀░░▀▓▓▓▓▓▓▓▓▓██████▓▓▓▓▐█
**	▌▓▄▌▀░▀░▐▀█▄▓▓██████████▓▓▓▌█▌
**	▌▓▓▓▄▄▀▀▓▓▓▀▓▓▓▓▓▓▓▓█▓█▓█▓▓▌█▌
**	█▐▓▓▓▓▓▓▄▄▄▓▓▓▓▓▓█▓█▓█▓█▓▓▓▐█
*/

#endif
