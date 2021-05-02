/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aroque <aroque@student.42sp.org.br>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/05 20:27:24 by aroque            #+#    #+#             */
/*   Updated: 2021/05/01 18:19:16 by aroque           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include <fcntl.h>
#include "libft.h"
#include "stack.h"
#include "minunit.h"
#include "general.h"
#include "checker.h"
#include "push_swap.h"

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

MU_TEST(test_max)
{
	t_stack	*a;

	a = initialize(5);
	a->array[0] = 4;
	a->array[1] = 1;
	a->array[2] = 2;
	a->array[3] = 9;
	a->top = 3;
	mu_assert_int_eq(9, max(a));
	a->top = 2;
	mu_assert_int_eq(4, max(a));
	free_stack(a);
}

MU_TEST(test_min)
{
	t_stack	*a;

	a = initialize(5);
	a->array[0] = 4;
	a->array[1] = 1;
	a->array[2] = 2;
	a->array[3] = -2;
	a->top = 3;
	mu_assert_int_eq(-2, min(a));
	a->top = 2;
	mu_assert_int_eq(1, min(a));
	free_stack(a);
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
	MU_RUN_TEST(test_max);
	MU_RUN_TEST(test_min);
}

/*
** ---------------------
** --- General Tests ---
** ---------------------
*/

MU_TEST(test_abs)
{
	mu_assert_int_eq(42, abs(42));
	mu_assert_int_eq(42, abs(-42));
	mu_assert_int_eq(2147483647, abs(2147483647));
	mu_assert_int_eq(0, abs(0));
	mu_assert_int_eq(23, abs(-23));
}

MU_TEST(test_binary_search)
{
	int array[] = { 1, 2, 4, 7, 19, 23 };
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

MU_TEST(test_reverse_array)
{
	int array1[] = { 0, 1, 2, 3, 4 };
	int array2[] = { 0, 1, 2, 3, 4, 5 };

	reverse_array(array1, 5);
	mu_assert_int_eq(4, array1[0]);
	mu_assert_int_eq(3, array1[1]);
	mu_assert_int_eq(2, array1[2]);
	mu_assert_int_eq(1, array1[3]);
	mu_assert_int_eq(0, array1[4]);
	reverse_array(array2, 6);
	mu_assert_int_eq(5, array2[0]);
	mu_assert_int_eq(4, array2[1]);
	mu_assert_int_eq(3, array2[2]);
	mu_assert_int_eq(2, array2[3]);
	mu_assert_int_eq(1, array2[4]);
	mu_assert_int_eq(0, array2[5]);
}

MU_TEST_SUITE(test_suite_general)
{
	MU_RUN_TEST(test_abs);
	MU_RUN_TEST(test_binary_search);
	MU_RUN_TEST(test_atoiv);
	MU_RUN_TEST(test_reverse_array);
}

/*
** ------------------
** --- Sort Tests ---
** ------------------
*/

MU_TEST(test_index)
{
	int size = 12;
	int list[] = { 11, 8, 1, 4, 7, 9, 6, 10, 12, 5, 3, 2 };

	t_stack	*a;

	a = initialize(64);
	memcpy(a->array, list, size * sizeof(*list));
	a->top = 11;
	index_stack(&a);
	mu_assert_int_eq(10, a->array[0]);
	mu_assert_int_eq(7, a->array[1]);
	mu_assert_int_eq(0, a->array[2]);
	mu_assert_int_eq(3, a->array[3]);
	mu_assert_int_eq(6, a->array[4]);
	mu_assert_int_eq(8, a->array[5]);
	mu_assert_int_eq(1, a->array[11]);
	free_stack(a);

	size = 7;
	int list2[] = { -2147483648, 2100, 220010, -1, 7, 210815, 121 };

	a = initialize(64);
	memcpy(a->array, list2, size * sizeof(*list));
	a->top = 6;
	index_stack(&a);
	mu_assert_int_eq(0, a->array[0]);
	mu_assert_int_eq(4, a->array[1]);
	mu_assert_int_eq(6, a->array[2]);
	mu_assert_int_eq(1, a->array[3]);
}

//MU_TEST(test_push_closest)
//{
//	int size = 12;
//	int list[] = { 11, 8, 1, 4, 7, 9, 6, 10, 12, 5, 3, 2 };
//
//	t_stack	*a;
//	t_stack	*b;
//
//	a = initialize(64);
//	b = initialize(64);
//	memcpy(a->array, list, size * sizeof(*list));
//	a->top = 11;
//	push_closest(7, a, b);
//	mu_assert_int_eq(2, b->array[0]);
//	push_closest(7, a, b);
//	mu_assert_int_eq(3, b->array[1]);
//	push_closest(7, a, b);
//	mu_assert_int_eq(5, b->array[2]);
//	push_closest(7, a, b);
//	mu_assert_int_eq(6, b->array[3]);
//	push_closest(7, a, b);
//	mu_assert_int_eq(6, b->array[0]);
//	mu_assert_int_eq(5, b->array[1]);
//	mu_assert_int_eq(2, b->array[2]);
//	mu_assert_int_eq(3, b->array[3]);
//}
//
//
//MU_TEST(test_push_chunk)
//{
//	int size = 12;
//	int list[] = { 11, 8, 1, 4, 7, 9, 6, 10, 12, 5, 3, 2 };
//
//	t_stack	*a;
//	t_stack	*b;
//
//	a = initialize(64);
//	b = initialize(64);
//	memcpy(a->array, list, size * sizeof(*list));
//	a->top = 11;
//	push_chunk(a, b);
//	mu_assert_int_eq(-1, a->top);
//	mu_assert_int_eq(1, b->array[0]);
//	mu_assert_int_eq(2, b->array[1]);
//	mu_assert_int_eq(3, b->array[2]);
//	mu_assert_int_eq(4, b->array[3]);
//	mu_assert_int_eq(5, b->array[4]);
//	mu_assert_int_eq(6, b->array[5]);
//}

MU_TEST_SUITE(test_suite_sort)
{
	//int	fd;

	//fd = dup(STDOUT_FILENO);
	//close(STDOUT_FILENO);
	MU_RUN_TEST(test_index);
	//MU_RUN_TEST(test_push_closest);
	//MU_RUN_TEST(test_push_chunk);
	//dup2(fd, STDOUT_FILENO);
}

/*
** -------------------------
** --- Integration Tests ---
** -------------------------
*/

#include <sys/types.h>
#include <sys/wait.h>

//MU_TEST(test_already_sorted)
//{
//	int	child;
//
//	if ((child = fork()) < 0)
//		return ;
//	else if (child == 0)
//	{
//		execlp("./push_swap", "")
//
//	}
//	else
//	{
//		wait(NULL);
//	}
//
//
//}


//MU_TEST_SUITE(test_suite_integrated)
//{
//	//int	fd;
//
//	//fd = dup(STDOUT_FILENO);
//	//close(STDOUT_FILENO);
//	MU_RUN_TEST(test_already_sorted);
//	//dup2(fd, STDOUT_FILENO);
//
//}



int	main(void)
{
	MU_RUN_SUITE(test_suite_stack);
	MU_RUN_SUITE(test_suite_general);
	MU_RUN_SUITE(test_suite_sort);
	//MU_RUN_SUITE(test_suite_integrated);
	MU_REPORT();
	return (MU_EXIT_CODE);
}
