/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aroque <aroque@student.42sp.org.br>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/05 20:27:24 by aroque            #+#    #+#             */
/*   Updated: 2021/04/10 15:39:26 by aroque           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include <fcntl.h>
#include "libft.h"
#include "stack.h"
#include "minunit.h"
#include "general.h"

MU_TEST(test_swap)
{
	t_stack	*a;

	a = initialize(5);
	a->array[0] = 4;
	a->array[1] = 1;
	a->array[2] = 2;
	a->array[3] = 9;
	a->top = 3;
	mu_assert_int_eq(9, a->array[3]);
	mu_assert_int_eq(2, a->array[2]);
	swap(a);
	mu_assert_int_eq(2, a->array[3]);
	mu_assert_int_eq(9, a->array[2]);
}

MU_TEST(test_swap_null)
{
	t_stack	*a;

	a = initialize(1);
	a->array[0] = 4;
	swap(a);
	mu_assert_int_eq(4, a->array[0]);
}

MU_TEST(test_push)
{
	t_stack	*a;
	t_stack	*b;

	a = initialize(5);
	b = initialize(5);
	a->array[0] = 4;
	a->array[1] = 1;
	a->array[2] = 2;
	a->array[3] = 9;
	a->top = 3;
	b->array[0] = 1;
	b->array[1] = 2;
	b->array[2] = 0;
	b->array[3] = 7;
	b->top = 3;
	push(a, b);
	mu_assert_int_eq(2, a->array[2]);
	mu_assert_int_eq(9, b->array[4]);
	mu_assert_int_eq(7, b->array[3]);
	mu_assert_int_eq(2, a->top);
	mu_assert_int_eq(4, b->top);
}

MU_TEST(test_rotate)
{
	t_stack	*a;

	a = initialize(5);
	a->array[0] = 4;
	a->array[1] = 1;
	a->array[2] = 2;
	a->array[3] = 9;
	a->top = 3;
	rotate(a);
	mu_assert_int_eq(9, a->array[0]);
	mu_assert_int_eq(4, a->array[1]);
	mu_assert_int_eq(1, a->array[2]);
	mu_assert_int_eq(2, a->array[3]);
}

MU_TEST(test_rotate_null)
{
	t_stack	*a;

	a = initialize(2);
	a->array[0] = 4;
	a->top = 0;
	rotate(a);
	mu_assert_int_eq(4, a->array[0]);
}

MU_TEST(test_reverse_rotate)
{
	t_stack	*a;

	a = initialize(5);
	a->array[0] = 4;
	a->array[1] = 1;
	a->array[2] = 2;
	a->array[3] = 9;
	a->top = 3;
	reverse_rotate(a);
	mu_assert_int_eq(1, a->array[0]);
	mu_assert_int_eq(2, a->array[1]);
	mu_assert_int_eq(9, a->array[2]);
	mu_assert_int_eq(4, a->array[3]);
}

MU_TEST(test_reverse_rotate_null)
{
	t_stack	*a;

	a = initialize(2);
	a->array[0] = 4;
	a->top = 0;
	reverse_rotate(a);
	mu_assert_int_eq(4, a->array[0]);
}

MU_TEST_SUITE(test_suite_stack)
{
	MU_RUN_TEST(test_swap);
	MU_RUN_TEST(test_swap_null);
	MU_RUN_TEST(test_push);
	MU_RUN_TEST(test_rotate);
	MU_RUN_TEST(test_rotate_null);
	MU_RUN_TEST(test_reverse_rotate);
	MU_RUN_TEST(test_reverse_rotate_null);
}

/*
** ---------------------
** --- General Tests ---
** ---------------------
*/

#include "checker.h"

MU_TEST(test_binary_search)
{
	int array[] = {1, 2, 4, 7, 19, 23};
	int array_size = 6;

	mu_assert_int_eq(true, binary_search(4, array, array_size));
	mu_assert_int_eq(true, binary_search(1, array, array_size));
	mu_assert_int_eq(false, binary_search(42, array, array_size));
}

MU_TEST(test_atoiv)
{
	int		n;
	bool	overflow;

	overflow = atoiv("472", &n);
	mu_assert_int_eq(472, n);
	mu_assert_int_eq(false, overflow);
	overflow = atoiv("2147483647", &n);
	mu_assert_int_eq(2147483647, n);
	mu_assert_int_eq(false, overflow);
	overflow = atoiv("-2147483648", &n);
	mu_assert_int_eq(-2147483648, n);
	mu_assert_int_eq(false, overflow);
	overflow = atoiv("2147483648", &n);
	mu_assert_int_eq(true, overflow);
	overflow = atoiv("10000000000000", &n);
	mu_assert_int_eq(true, overflow);
	overflow = atoiv("21474836480000000", &n);
	mu_assert_int_eq(true, overflow);
	overflow = atoiv("-2147483649", &n);
	mu_assert_int_eq(true, overflow);
	overflow = atoiv("-21474836490000", &n);
	mu_assert_int_eq(true, overflow);
}


MU_TEST_SUITE(test_suite_general)
{
	MU_RUN_TEST(test_binary_search);
	MU_RUN_TEST(test_atoiv);
}

int	main(void)
{
	MU_RUN_SUITE(test_suite_stack);
	MU_RUN_SUITE(test_suite_general);
	MU_REPORT();
	return (MU_EXIT_CODE);
}
