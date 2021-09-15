#include "string.h"

int main ( void )
{
    string_t s;
    string_init(&s, "");
    string_t str;
    string_t src;
    src.str = "Zebi";
    str.str = "Hey ça marche";
    string_init(&s , " Hello World ") ;
    printf ("%s\n", s.str) ;
    assign_s(&s, &str);
    printf ("%s\n", s.str) ;
    assign_c(&s, "soy un carotte");
    printf ("%s\n", s.str) ;
    string_destroy(&s);
    s.str = NULL;
    assign_c(&s, "je fais un test");
    printf ("%s\n", s.str) ;
    append_c(&s, "soy un carotte");
    printf ("%s\n", s.str) ;
    append_s(&s, &src);
    printf ("%s\n", s.str) ;
    string_destroy(&s);
    s.str = "0123456789";
    char c = at(&s, 2);
    printf("%c\n", c);
    printf("%d\n", at(&s, 10));
    printf("%d\n", size(&s));
    s.str = NULL;
    printf("%d\n", size(&s));
    printf("%d\n", size(NULL));
    clear(NULL);
    s.str = "pomme";
    char *str_to_cpy = strdup("pom");
    printf("%d\n", s.copy(&s, str_to_cpy, 3, 0));
    printf("%s\n", str_to_cpy);
    printf("%d\n", empty(&s));
    //free(str_to_cpy);
    //string_destroy(&s);
    return(0);
}