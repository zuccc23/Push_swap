/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dahmane <dahmane@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/20 15:21:27 by dahmane           #+#    #+#             */
/*   Updated: 2025/01/20 15:22:34 by dahmane          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int main(int argc, char **argv)
{
	// FUNCTIONS TO FIX //////////////////////////////////////////////////
	// cost_of_push
	
	// PARSING //////////////////////////////////////////////////////////////
	// if (argc < 2)
	// 	return (0);
	// printf("%d", valid_param(argv));
	
	// INIT //////////////////////////////////////////////////////////////////
	int	tab[] = {410, 372, 363, 107, -2147483648, 413, 411, 432, 5, 479, 44, 158, 457, 403, 471, 162, 170, 138, 301, 161, 417, 395, 132, 224, 450, 397, 256, 184, 356, 419, 10, 51, 435, 477, 340, 137, 143, 31, 442, 236, 370, 210, 114, 371, 147, 428, 362, 216, 34, 234, 284, 360, 328, 493, 58, 329, 16, 145, 39, 13, 336, 486, 152, 82, 125, 469, 141, 172, 120, 275, 385, 238, 75, 449, 42, 260, 189, 209, 214, 494, 254, 386, 430, 232, 296, 187, 312, 87, 461, 318, 17, 230, 133, 24, 433, 95, 280, 225, 359, 352, 253, 462, 382, 274, 383, 314, 135, 211, 109, 166, 366, 289, 436, 239, 240, 341, 346, 464, 381, 425, 345, 354, 204, 124, 121, 134, 241, 384, 273, 399, 111, 334, 136, 86, 320, 190, 168, 463, 438, 157, 365, 176, 248, 207, 304, 243, 178, 406, 295, 81, 453, 70, 297, 242, 287, 57, 415, 269, 358, 165, 252, 495, 69, 348, 367, 186, 278, 302, 440, 78, 402, 23, 223, 203, 80, 52, 205, 101, 439, 244, 291, 90, 249, 443, 325, 198, 258, 305, 177, 45, 118, 451, 327, 191, 122, 259, 32, 9, 330, 478, 446, 104, 353, 421, 414, 180, 202, 487, 396, 300, 129, 30, 35, 183, 148, 213, 117, 460, 27, 424, 11, 171, 40, 437, 100, 128, 343, 285, 119, 257, 492, 483, 351, 255, 173, 47, 441, 116, 127, 93, 407, 473, 322, 250, 364, 22, 264, 401, 444, 418, 201, 88, 192, 317, 361, 20, 123, 368, 206, 231, 188, 55, 416, 389, 307, 245, 144, 298, 292, 226, 286, 262, 324, 61, 458, 25, 154, 85, 140, 333, 321, 310, 261, 489, 38, 74, 106, 380, 3, 200, 149, 110, 412, 405, 228, 347, 77, 37, 68, 167, 445, 290, 390, 182, 18, 319, 21, 332, 251, 160, 36, 420, 448, 142, 222, 218, 8, 344, 108, 43, 56, 12, 217, 79, 29, 326, 247, 466, 484, 459, 331, 197, 355, 498, 175, 376, 342, 151, 62, 54, 391, 271, 59, 146, 96, 26, 139, 434, 339, 373, 99, 454, 277, 306, 196, 293, 103, 7, 485, 337, 427, 208, 2, 500, 33, 496, 221, 155, 470, 164, 15, 233, 131, 73, 455, 153, 335, 276, 490, 499, 150, 72, 272, 303, 14, 50, 220, 400, 299, 456, 465, 102, 194, 267, 357, 227, 279, 392, 282, 387, 246, 115, 6, 315, 309, 283, 97, 472, 48, 388, 476, 185, 377, 76, 41, 349, 467, 67, 89, 83, 404, 112, 219, 266, 474, 497, 163, 323, 169, 409, 63, 447, 1, 338, 105, 311, 408, 235, 288, 49, 195, 215, 265, 281, 91, 422, 66, 491, 64, 431, 65, 294, 174, 313, 375, 19, 270, 156, 482, 94, 71, 92, 350, 452, 480, 229, 130, 308, 423, 488, 126, 481, 379, 316, 268, 84, 393, 369, 199, 181, 4, 429, 46, 394, 60, 263, 53, 378, 468, 28, 98, 475, 179, 159, 398, 212, 193, 426, 113, 237};
	s_list	*stack_a = NULL;
	s_list	*stack_b = NULL;
	s_list	*temp = NULL;
	stack_a = assign_list(tab, 500);
	// stack_b = assign_list(tab2, 6);

	// TESTS ///////////////////////////////////////////////////////////////////////////
	
	push_swap(&stack_a, &stack_b);
	
	// SORT_A_TO_B /////////////////////////////////////////////////////////////////////

	// push_swap(&stack_a, &stack_b);
	// sort_a_to_b(&stack_a, &stack_b);
	// assign_all(&stack_a, &stack_b);
	
	// assign_target_b(&stack_a, &stack_b);
	// index_assign(&stack_a, &stack_b);
	// median_assign(&stack_a, &stack_b);
	// cost_of_push(&stack_b, &stack_a);
	// individual_cost(&stack_a);
	// individual_cost(&stack_b);
	
	
	
	// push_cheapest_to_b(&stack_a, &stack_b);
	// push_cheapest_to_b(&stack_a, &stack_b);
	// push_cheapest_to_b(&stack_a, &stack_b);
	// push_cheapest_to_b(&stack_a, &stack_b);
	// push_cheapest_to_b(&stack_a, &stack_b);
	// push_cheapest_to_b(&stack_a, &stack_b);
	// push_cheapest_to_b(&stack_a, &stack_b);
	// push_cheapest_to_b(&stack_a, &stack_b);
	// push_cheapest_to_b(&stack_a, &stack_b);
	// push_cheapest_to_b(&stack_a, &stack_b);
	// push_cheapest_to_b(&stack_a, &stack_b);
	// push_cheapest_to_b(&stack_a, &stack_b);
	// push_cheapest_to_b(&stack_a, &stack_b);
	// push_cheapest_to_b(&stack_a, &stack_b);
	// push_cheapest_to_b(&stack_a, &stack_b);
	// push_cheapest_to_b(&stack_a, &stack_b);
	// push_cheapest_to_b(&stack_a, &stack_b);
	// push_cheapest_to_b(&stack_a, &stack_b);
	// push_cheapest_to_b(&stack_a, &stack_b);
	// push_cheapest_to_b(&stack_a, &stack_b);
	// push_cheapest_to_b(&stack_a, &stack_b);
	// push_cheapest_to_b(&stack_a, &stack_b);

	// assign_target_b(&stack_a, &stack_b);
	
	// move_b(stack_a, &stack_b);
	// move_a(&stack_a, stack_b);
	// push(&stack_a, &stack_b);
	
	// SORT_B_TO_A /////////////////////////////////////////////////////////////////////
	
	// push_swap(&stack_a, &stack_b);
	// assign_all2(&stack_a, &stack_b);
	
	// push_cheapest_to_a(&stack_a, &stack_b);
	// push_cheapest_to_a(&stack_a, &stack_b);
	// push_cheapest_to_a(&stack_a, &stack_b);
	// push_cheapest_to_a(&stack_a, &stack_b);
	// push_cheapest_to_a(&stack_a, &stack_b);
	// push_cheapest_to_a(&stack_a, &stack_b);
	// push_cheapest_to_a(&stack_a, &stack_b);
	// push_cheapest_to_a(&stack_a, &stack_b);
	// push_cheapest_to_a(&stack_a, &stack_b);
	
	// sort_b_to_a(&stack_a, &stack_b);
	// move_b3(&stack_b, stack_a);
	// move_a3(stack_b, &stack_a);
	// push(&stack_b, &stack_a);
	
	// assign_target_a(&stack_a, &stack_b);
	// index_assign(&stack_a, &stack_b);
	// median_assign(&stack_a, &stack_b);
	// cost_of_push(&stack_b, &stack_a);
	// individual_cost(&stack_a);
	// individual_cost(&stack_b);
	// rotate_down(&stack_a);
	// push(&stack_b, &stack_a);
	
	// TEST OF ALL VARIABLES ////////////////////////////////////////////////////
	
	// assign_all(&stack_a, &stack_b);
	// assign_all2(&stack_a, &stack_b);
	// while (stack_a != NULL)
	// {
	// 	printf("|| index : %d || value : %d || target(value) : %d || cost : %d || cheapest : %d || median : %d ||\n", stack_a->index, stack_a->data, stack_a->target->data, stack_a->cost, stack_a->cheapest, stack_a->above_median);
	// 	stack_a = stack_a->next;
	// }
	// while (stack_b != NULL)
	// {
	// 	printf("|| index : %d || value : %d || target(value) : %d || cost : %d || cheapest : %d || median : %d ||\n", stack_b->index, stack_b->data, stack_b->target->data, stack_b->cost, stack_b->cheapest, stack_b->above_median);
	// 	stack_b = stack_b->next;
	// }
	
	// TEST OF 1 VARIABLE /////////////////////////////////////////////////////////
	
	// assign_target_a(&stack_a, &stack_b);
	// while (stack_b != NULL)
	// {
	// 	// find_targetv2(stack_a, &stack_b);
	// 	printf("%d target : %d\n", stack_b->data, stack_b->target->data);
	// 	stack_b = stack_b->next;
	// }
	// printf("\n");

	// PRINT LISTS ///////////////////////////////////////////////////////////////////
	
	// printf("\nStack A :\n");
	// print_list(stack_a);
	// printf("\nStack B :\n");
	// print_list(stack_b);
}