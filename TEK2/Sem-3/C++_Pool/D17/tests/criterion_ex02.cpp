/*
** EPITECH PROJECT, 2020
** B-CPP-300-MPL-3-1-CPPD17-corentin.petrau
** File description:
** criterion_ex02.cpp
*/

#include "criterion_ex.hpp"

static void encryptString(IEncryptionMethod &encryptionMethod, std::string const & toEncrypt)
{
    size_t len = toEncrypt.size();
    encryptionMethod.reset();
    for(size_t i = 0; i < len ; ++ i) {
        encryptionMethod.encryptChar (toEncrypt [ i ]) ;
    }
    std::cout << std::endl;
}

static void decryptString(IEncryptionMethod &encryptionMethod, std::string const &toDecrypt)
{
    size_t len = toDecrypt.size();
    encryptionMethod.reset();
    for (size_t i = 0; i < len ; ++ i) {
        encryptionMethod.decryptChar(toDecrypt [ i ]);
    }
    std::cout << std::endl;
}

void do_a_test_ex02()
{
    Cesar c;
    OneTime o ("DedeATraversLesBrumes");
    OneTime t ("TheCakeIsALie");

    encryptString(c, "Je clair Luc, ne pas ? Ze woudrai un kekos !");
    decryptString(c, "Mi isirb Xhq, ew jvo ? Zf zszjyir fz ytafk !");
    encryptString(c, "KIKOO");
    encryptString(c, "LULZ XD");
    decryptString(c, "Ziqivun ea Ndcsg.Wji !");

    encryptString (t, "Prend garde Lion, ne te trompes pas de voie !");
    encryptString (o, "De la musique et du bruit !");
    encryptString (t, "Kion li faras? Li studas kaj programas!");

    decryptString (t, "Iyipd kijdp Pbvr, xi le bvhttgs tik om ovmg !");
    decryptString (o, "Gi pa dunmhmp wu xg tuylx !");
    decryptString (t, "Dpsp vm xaciw? Pk cxcvad otq rrykzsmla!");
}

Test(check_crypt_and_decrypt, crypt_and_decrypt_with_cesar_and_OneTime_method, .init=redirect_all_std)
{
    do_a_test_ex02();
    cr_assert_stdout_eq_str("Mi isirb Xhq, ew jvo ? Zf zszjyir fz ytafk !\nJe clair Luc, ne pas ? Ze woudrai un kekos !\nNMPUV\nOYQF FM\nWelcome to Zombo.Com !\nIyipd kijdp Pbvr, xi le bvhttgs tik om ovmg !\nGi pa dunmhmp wu xg tuylx !\nDpsp vm xaciw? Pk cxcvad otq rrykzsmla!\nPrend garde Lion, ne te trompes pas de voie !\nDe la musique et du bruit !\nKion li faras? Li studas kaj programas!\n", "");
}