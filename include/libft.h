/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlins <rlins@student.42sp.org.br>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/03 18:36:17 by rlins             #+#    #+#             */
/*   Updated: 2023/03/08 08:05:53 by rlins            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <string.h>
# include <stdlib.h>
# include <unistd.h>
# include <limits.h>
# include <stdarg.h> // All the macros to use variable args (va_list)

# ifndef BUFFER_SIZE
# define BUFFER_SIZE 128

# define HEX_BASE_LOWER	"0123456789abcdef"
# define HEX_BASE_UPPER	"0123456789ABCDEF"
# define DEC_BASE		"0123456789"
# define STR_NULL		"(null)"
# define PTR_NULL		"(nil)"
# define INI_PTR		"0x"
# define NEG_PTR		"FFFFFFFF"
# endif

void	ft_free(char* ptr);
char	*ft_strdup(const char *s);
char	*ft_strjoin(char const *s1, char const *s2);
size_t	ft_strlen(const char *str);
char	*ft_substr(char const *s, unsigned int start, size_t len);
char	*get_next_line(int fd);
char	**ft_split(char const *s, char c);
int		ft_printf(const char* str, ...);
int		ft_print_char(char c);
int		ft_print_string(char* str);
int		ft_print_dec_int(long nbr);
int		ft_print_pointer(void* ptr);
int		ft_print_hexa(unsigned int nbr, char spec);
void	ft_putchar(char c);
int		ft_putstr(char* str);
char*	ft_itoa_base(unsigned long long nbr, char* base);

void	ft_putchar_fd(char c, int fd);
void	ft_putstr_fd(char *s, int fd);
void	ft_putendl_fd(char *s, int fd);

/**
* @brief Searches for the first occurrence of the character c
* (an unsigned char) in the string pointed to by the argument str.
* @param s - This is the C string to be scanned.
* @param c This is the character to be searched in str
* @return This returns a pointer to the first occurrence of the
* character c in the string str, or NULL if the character is not found
*/
char	*ft_strchr(const char *s, int c);

/**
* @brief isascii in c checks the passed value is ascii character or not.
* @param argument to check
* @return This function returns non-zero value if passed value is ascii character
* otherwise zero.
*/
int		ft_isascii(int argument);

/**
* @brief Compares the first n bytes of memory area str1 and memory area str2
* @param str1 − This is the pointer to a block of memory.
* @param str2 − This is the pointer to a block of memory.
* @param len − This is the number of bytes to be compared.
* @return if Return value < 0 then it indicates str1 is less than str2.
*if Return value > 0 then it indicates str2 is less than str1.
*if Return value = 0 then it indicates str1 is equal to str2.
*/
int		ft_memcmp(const void *str1, const void *str2, size_t len);

void	*ft_calloc(size_t count, size_t size);
void	ft_bzero(void *s, size_t n);

#endif
