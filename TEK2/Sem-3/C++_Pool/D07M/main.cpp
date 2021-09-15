#include "Federation.hpp"
#include "WarpSystem.hpp"
#include "Borg.hpp"

int  main()
{
    Federation::Starfleet::Ship UssKreog(289, 132, "Kreog", 6);
    Federation::Ship Independent(150, 230, "Greok");
    WarpSystem::QuantumReactor QR;
    WarpSystem::QuantumReactor QR2;
    WarpSystem::QuantumReactor QR3;
    WarpSystem::Core core(&QR);
    WarpSystem::Core core2(&QR2);
    WarpSystem::Core core3(&QR3);
    Federation::Starfleet::Captain James("James T. Kirk");
    Federation::Starfleet::Ensign Ensign("Pavel  Chekov");
    UssKreog.promote(&James);
    UssKreog.setupCore(&core);
    UssKreog.checkCore();
    Independent.setupCore(&core2);
    Independent.checkCore();
    QR.setStability(false);
    QR2.setStability(false);
    UssKreog.checkCore();
    Independent.checkCore();
    Borg::Ship Cube;
    Cube.setupCore(&core3);
    Cube.checkCore();
    return  0;
}
