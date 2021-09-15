#include "ex00.h"

int main ()
{
    koala_t * _lkoala = new_koala ("Legend", 1) ;
    koala_t * _nlkoala = new_koala ("NotLegend", 0) ;
    cthulhu_t * _cthulhu = new_cthulhu () ;
    printf ("----Start----\n") ;
    print_power ( _cthulhu ) ;
    print_power (&_lkoala->m_parent) ;
    print_power (&_nlkoala->m_parent) ;
    attack ( _cthulhu ) ;
    attack (&_lkoala->m_parent) ;
    attack (&_nlkoala->m_parent) ;
    eat ( _nlkoala ) ;
    attack ( _cthulhu ) ;
    sleeping ( _cthulhu ) ;
    print_power ( _cthulhu ) ;
    attack (&_nlkoala->m_parent) ;
    return 0;
}