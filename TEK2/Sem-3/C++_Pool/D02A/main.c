
#include "double_list.h"
#include "generic_list.h"
#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>

static void populate_list ( double_list_t * list_head )
{
    double_list_add_elem_at_back ( list_head , 1.2) ;
    double_list_add_elem_at_position (list_head , 1.3, 0) ;
    double_list_add_elem_at_position (list_head , 88.9, 1);
    double_list_add_elem_at_position (list_head , 4.3, 2);
}
static void test_size ( double_list_t list_head )
{
    printf (" There are %u elements in the list \n", double_list_get_size ( list_head ) ) ;
    double_list_dump ( list_head ) ;
}
static void test_del ( double_list_t * list_head )
{
    if (double_list_is_empty(list_head) == 0)
        printf("List is not empty\n");
}

static void test_get_value(double_list_t list_head)
{
    printf("La value est : %f\n", double_list_get_elem_at_front(list_head));
    printf("La value est : %f\n", double_list_get_elem_at_back(list_head));
    printf("La value est : %f\n", double_list_get_elem_at_position(list_head, 2));
}

int main ( void )
{
    double_list_t list_head = NULL ;
    populate_list (& list_head ) ;
    test_size ( list_head ) ;
    test_del (& list_head ) ;
    test_get_value(list_head);
    return 0;
}

// static void int_displayer ( void * data )
// {
//     int value = *(( int *) data ) ;
//     printf ("%d\n", value ) ;
// }

// static void test_size ( list_t list_head )
// {
//     printf (" There are %u elements in the list \n", list_get_size ( list_head ) ) ;
//     list_dump ( list_head , & int_displayer ) ;
// }
// static void test_del ( list_t * list_head )
// {
//     list_del_elem_at_back ( list_head ) ;
//     printf (" There are %u elements in the list \n", list_get_size (* list_head ) ) ;
//     list_dump (* list_head , & int_displayer ) ;
// }
// int main ( void )
// {
//     list_t list_head = NULL ;
//     int i = 5;
//     int j = 42;
//     int k = 3;
//     list_add_elem_at_back (& list_head , & i ) ;
//     list_add_elem_at_back (& list_head , & j ) ;
//     list_add_elem_at_back (& list_head , & k ) ;
//     test_size ( list_head ) ;
//     test_del (& list_head ) ;
//     return 0;
// }