/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_main.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkasongo <jkasongo@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/06 02:23:09 by jkasongo          #+#    #+#             */
/*   Updated: 2021/05/08 20:26:29 by jkasongo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void test_ft_split(void)
{
	char	**splitted1 = ft_split(" Rolling in the Deep ", ' ');
	char	**splitted2 = ft_split("ddddertreerd", 0);

		if ((splitted1[3][0] == 'D') && (splitted2[0][1] == 'd'))
		ft_print_success("ft_split passed");
	else
		ft_print_error("ft_split failed");
	ft_free_array((void **)splitted1);
	ft_free_array((void **)splitted2);
}

void test_ft_strtrim(void)
{
	char *cpy = 0;

	cpy = ft_strtrim("       Hello World!        ", " ");
	if (cpy[0] == 'H')
		ft_print_success("ft_strtrim passed");
	else
		ft_print_error("ft_strtrim failed");
	free(cpy);
}

void test_ft_strjoin(void)
{
	char *cpy = 0;
	char *cpy2 = 0;

	cpy = ft_strjoin("harry", "potter");
	cpy2 = ft_strjoin(0, 0);
	if ((cpy[0] == 'h') && (cpy[5] == 'p') && (cpy2[0] == 0))
		ft_print_success("ft_strjoin passed");
	else
		ft_print_error("ft_strjoin failed");
	free(cpy);
	free(cpy2);
}

void	test_ft_substr(void)
{
	char src[] = "loisirpointpoint";
	char *cpy = 0;
	char *cpy2 = 0;

	cpy = ft_substr(src, 6, 5);
	cpy2 = ft_substr(src, 17, 5);
	if ((cpy[0] == 'p') && (cpy[5] == 0) && (cpy2[0] == 0))
		ft_print_success("ft_strndup passed");
	else
		ft_print_error("ft_strndup failed");
	free(cpy);
	free(cpy2);
}

void	test_ft_strndup(void)
{
	char src[] = "panda";
	char *cpy = 0;

	cpy = (char *)ft_strndup(src,3);
	if ((cpy[0] == 'p') && (cpy[3] == 0))
		ft_print_success("ft_strndup passed");
	else
		ft_print_error("ft_strndup failed");
	free(cpy);
}

void	test_ft_strdup(void)
{
	char src[] = "panda";
	char *cpy = 0;

	cpy = (char *)ft_strdup(src);
	if ((cpy[0] == 'p') && (cpy[5] == 0))
		ft_print_success("ft_srtdup passed");
	else
		ft_print_error("ft_srtdup failed");
	free(cpy);
}

void	test_ft_calloc(void)
{
	char	*tab1;
	int		*tab2;

	tab1 = (char *)ft_calloc(2, sizeof(char));
	tab2 = (int *)ft_calloc(2, sizeof(int));
	if (((tab2[0] + tab2[1]) == 0) && (tab1[1] == 0))
		ft_print_success("ft_calloc passed");
	else
		ft_print_error("ft_calloc failed");
	free(tab1);
	free(tab2);
}

void	test_ft_memcmp(void)
{
	int test1;
	int test2;
	int test3;
	int test4;

	test1 = (ft_memcmp("ABC", "ABC", 3) == 0);
	test2 = (ft_memcmp("ABC", "AB", 3) == 67);
	test3 = (ft_memcmp("ABA", "ABZ", 3) == -25);
	test4 = (ft_memcmp("LBA", "ABC", 0) == 0);

	if (test1 && test2 && test3 && test4)
		ft_print_success("ft_memcmp passed");
	else
		ft_print_error("ft_memcmp failed");
}

void	test_ft_memmove(void)
{
	char *found;
	char *found2;
	char str[] = "superman";
	char str2[] = "superman";

	found = (char *)ft_memmove((str + 4), str, 3);
	found2 = (char *)ft_memmove(str2, str2 + 5, 3);
	if ((*(found - 4) == 's') && (*(found2 + 5) == 'm'))
		ft_print_success("ft_memmove passed");
	else
		ft_print_error("ft_memmove failed");
}

void	test_ft_memchr(void)
{
	int test;
	char src[] = "Bruce wayne";
	char *found = 0;

	found = (char *)ft_memchr(src, 'w', 13);
	test = (src[6] == *found);
	if (test)
		ft_print_success("ft_memchr passed");
	else
		ft_print_error("ft_memchr failed");
}

void	test_ft_memccpy(void)
{
	int test1;
	int test2;
	char src[] = "onepiece";
	char *found = 0;
	char dst[] = "piraterie";

	found = (char *)ft_memccpy(dst, src, 'p', 5);
	test1 = (dst[3] == 'p');
	test2 = (dst[4] == *found);
	if (test1 && test2)
		ft_print_success("ft_memccpy passed");
	else
		ft_print_error("ft_memccpy failed");
}

void	test_ft_memcpy(void)
{
	int	test1;
	char	src[] = "onepiece";
	char	dst[] = "piraterie";

	ft_memcpy(dst,src, 3);
	test1 = (dst[2] == 'e');
	if (test1)
		ft_print_success("ft_memcpy passed");
	else
		ft_print_error("ft_memcpy failed");
}

void	test_ft_bzero(void)
{
	int test1;
	char tab[3];

	ft_bzero(tab, 3);
	test1 = (tab[2] == 0);
	if (test1)
		ft_print_success("ft_bzero passed");
	else
		ft_print_error("ft_bzero failed");
}

void	test_ft_memset(void)
{
	int		test1;
	int		test2;
	char	tab[3];

	ft_memset(tab, 'a', 2);
	ft_memset(tab + 2, 'b', 1);
	test1 = (tab[1] == 'a');
	test2 = (tab[2] == 'b');
	if (test1 && test2)
		ft_print_success("ft_memset passed");
	else
		ft_print_error("ft_memset failed");
}

void	test_ft_atoi(void)
{
	int	test1;
	int	test2;
	int	test3;

	test1 = (ft_atoi("   214748364gfsj") == 214748364);
	test2 = (ft_atoi("   -2147483648gfsj") == -2147483648);
	test3 = (ft_atoi("   -gfsj") == 0);
	if (test1 && test2 && test3)
		ft_print_success("ft_atoi passed");
	else
		ft_print_error("ft_atoi failed");
}

void	test_ft_strnstr(void)
{
	int		test1;
	int		test2;
	char	boite[] = "sdfgiamlordvoldemorthska";
	char	s[] = "voldemort";

	test1 = (ft_strnstr(boite, s, 40) == (&boite[11]));
	test2 = (ft_strnstr(boite, s, 3) == 0);
	if (test1 && test2)
		ft_print_success("ft_strnstr passed");
	else
		ft_print_error("ft_strnstr failed");
}

void	test_ft_strrchr(void)
{
	int test1;
	int test2;
	char src[] = "aaaeaxx";

	test1 = (ft_strrchr(src, src[3]) == (&src[3]));
	test2 = (ft_strrchr(src, 97) == (&src[4]));
	if (test1 && test2)
		ft_print_success("ft_strrchr passed");
	else
		ft_print_error("ft_strrchr failed");
}

void	test_ft_strchr(void)
{
	int test1;
	int test2;
	char src[] = "aaaeaxx";

	test1 = (ft_strchr(src, src[3]) == &src[3]);
	test2 = (ft_strchr(src, 97) == src);
	if (test1 && test2)
		ft_print_success("ft_strchr passed");
	else
		ft_print_error("ft_strchr failed");
}

void	test_ft_strlcat(void)
{
	int		test1;
	int		test2;
	char	dst[5] = {'b', 'b', 'b', '\0', '\0'};
	char	src[] = "aaaaxx";

	test1 = (ft_strlcat(dst, src, 5) == 9);
	test2 = (ft_strlcat(dst, src, 2) == 8);
	if (test1 && test2)
		ft_print_success("ft_strlcat passed");
	else
		ft_print_error("ft_strlcat failed");
}

void	test_ft_strlcpy(void)
{
	char	tab1[] = "aaaa";
	char	tab2[] = "bbbb";
	char	tab3[5] = {'b','b','b','\0','e'};

	int		test1 = (ft_strlcpy(tab1,tab2, 5) == 4);
	int		test2 = (ft_strlcpy(tab1,tab3, 5) == 3);
	int		test3 = (ft_strlcpy(tab1, tab3, 2) == 3);
	int		test4 = (ft_strlcpy(tab1,tab2, 0) == 4);

	if (test1 && test2 && test3 && test4)
		ft_print_success("ft_strlcpy passed");
	else
		ft_print_error("ft_strlcpy failed");
}

void	test_ft_strncmp(void)
{
	int	test1;
	int	test2;
	int	test3;
	int	test4;

	test1 = (ft_strncmp("ABC","ABC", 3) == 0);
	test2 = (ft_strncmp("ABC","AB", 3) == 67);
	test3 = (ft_strncmp("ABA","ABZ",3) == -25);
	test4 = (ft_strncmp("LBA","ABC",0) == 0);

	if (test1 && test2 && test3 && test4)
		ft_print_success("ft_strncmp passed");
	else
		ft_print_error("ft_strncmp failed");
}

void	test_to_up_and_low(void)
{
	int	test1;
	int	test2;
	int	test3;
	int	test4;

	test1 = ft_toupper(97) == 65;
	test2 = ft_tolower(65) == 97;
	test3 = ft_toupper(67) == 67;
	test4 = ft_tolower(9) == 9;

	if (test1 && test2 && test3 && test4)
		ft_print_success("lower and upper passed");
	else
		ft_print_error("lower and upper failed");
}

void	test_ft_isspace(void)
{
	int	test1;
	int	test2;
	int	test3;
	int	test4;

	test1 = (ft_isspace(10) == 1);
	test2 = (ft_isspace(32) == 1);
	test3 = (ft_isspace(9) == 1);
	test4 = (ft_isspace(0) == 0);

	if (test1 && test2 && test3 && test4)
		ft_print_success("ft_isspace passed");
	else
		ft_print_error("ft_isspace failed");
}

void	test_ft_isprint(void)
{
	int	test1;
	int	test2;
	int	test3;
	int	test4;

	test1 = ft_isprint(10) == 0;
	test2 = ft_isprint(65) == 1;
	test3 = ft_isprint(32) == 1;
	test4 = ft_isprint(127) == 0;

	if (test1 && test2 && test3 && test4)
		ft_print_success("ft_isprint passed");
	else
		ft_print_error("ft_isprint failed");
}

void	test_ft_isalnum(void)
{
	int	test1;
	int	test2;
	int	test3;
	int	test4;

	test1 = (ft_isalnum(0) == 0);
	test2 = (ft_isalnum(55) == 1);
	test3 = (ft_isalnum(65) == 1);
	test4 = (ft_isalnum(1) == 0);

	if (test1 && test2 && test3 && test4)
		ft_print_success("ft_isalnum passed");
	else
		ft_print_error("ft_isalnum failed");
}

void	test_ft_isdigit(void)
{
	int	test1;
	int	test2;
	int	test3;
	int	test4;

	test1 = ft_isdigit(0) == 0;
	test2 = ft_isdigit(48) == 1;
	test3 = ft_isdigit(57) == 1;
	test4 = ft_isdigit(65) == 0;

	if (test1 && test2 && test3 && test4)
		ft_print_success("ft_isdigit passed");
	else
		ft_print_error("ft_isdigit failed");
}

void	test_ft_isalpha(void)
{
	int	test1;
	int	test2;
	int	test3;
	int	test4;

	test1 = ft_isalpha(0) == 0;
	test2 = ft_isalpha(97) == 1;
	test3 = ft_isalpha(90) == 1;
	test4 = ft_isalpha(100) == 1;

	if (test1 && test2 && test3 && test4)
		ft_print_success("ft_isalpha passed");
	else
		ft_print_error("ft_isalpha failed");
}

void	test_ft_isascii(void)
{
	int	test1;
	int	test2;
	int	test3;
	int	test4;

	test1 = ft_isascii(2 ) == 1;
	test2 = ft_isascii(0) == 1;
	test3 = ft_isascii(-127) == 0;
	test4 = ft_isascii(128) == 0;

	if (test1 && test2 && test3 && test4)
		ft_print_success("ft_isascii passed");
	else
		ft_print_error("ft_isascii failed");
}

void	test_ft_strlen(void)
{
	int	test1;
	int	test2;
	int	test3;

	test1 = ft_strlen("test") == 4;
	test2 = ft_strlen("") == 0;
	test3 = ft_strlen(0) == 0;

	if (test1 && test2 && test3)
		ft_print_success("ft_strlen passed");
	else
		ft_print_error("ft_strlen failed");
}

void	part_one_test(){
	ft_putstr("> Memory fucntions\n", STDOUT_FILENO);
	test_ft_memset();
	test_ft_bzero();
	test_ft_memcpy();
	test_ft_memccpy();
	test_ft_memmove();
	test_ft_memchr();
	test_ft_memcmp();
	ft_putstr("> string fucntions\n", STDOUT_FILENO);
	test_ft_strlen();
	test_ft_isalpha();
	test_ft_isdigit();
	test_ft_isalnum();
	test_ft_isascii();
	test_ft_isprint();
	test_to_up_and_low();
	test_ft_strchr();
	test_ft_strrchr();
	test_ft_strncmp();
	test_ft_strlcpy();
	test_ft_strlcat();
	test_ft_strnstr();
	test_ft_atoi();
	ft_putstr("> malloc\n", STDOUT_FILENO);
	test_ft_calloc();
	test_ft_strdup();
}

int		main(void)
{
	ft_print_error("NB: this is not the norminette");
	ft_putstr("==========TESTING==========\n", STDOUT_FILENO);
	part_one_test();
	ft_putstr("> Part 2 functions\n", STDOUT_FILENO);
	test_ft_substr();
	test_ft_strjoin();
	test_ft_strtrim();
	test_ft_split();
	ft_putstr("==========PERSONAL==========\n", STDOUT_FILENO);
	test_ft_isspace();
	test_ft_strndup();
	return (0);
}
