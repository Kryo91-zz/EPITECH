#include "Mage.hpp"
using namespace std;

int main ()
{
    Character c("poney", 42);
    Warrior d("Thor", 42, "Hammer");
    Mage m("Lyvia", 84);
    c.Range = Character::RANGE;
    m.Range = Character::CLOSE;
    d.TakeDamage(51);
    c.CloseAttack();
    c.TakeDamage(84);
    c.Heal();
    cout << "Life restored " << c.getPv() << endl;
    d.Heal();
    cout << "Life restored " << d.getPv() << endl;
    d.RangeAttack();
    cout << "------ MAGE ATTACK -------" << endl;
    m.CloseAttack();
    m.RangeAttack();
    m.RangeAttack();
    m.RangeAttack();
    cout << "------ END MAGE ATTACK -------" << endl;
    d.CloseAttack();
    c.Heal();
    cout << "Life restored " << c.getPv() << endl;
    m.RestorePower();
    cout << m.getPower() << endl;
    m.RestorePower();
    cout << m.getPower() << endl;
    c.TakeDamage(200);
    c.TakeDamage(200);
}