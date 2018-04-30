#include <iostream>

#include "Application.h"
#include "Config.h"

/**
	Ova igra se sastoji od niza organizama koji žive u vlastitim ćelijama u dvodimenzionalnom svijetu. Konfiguracija organizama se mijenja u diskretnim vremenskim trenucima, pri čemu svaka ćelija matrice može biti prazna (mrtva) ili zauzeta (živa). Nova generacija organizama u ćelijama nastaje na osnovu stare generacije organizama ovisno o sadržaju osam susjednih ćelija svake pojedine ćelije (sve izvan matrice smatramo mrtvim organizmima). Pravila za formiranje nove generacije organizama su sljedeća:
	1. Živi organizam u ćeliji preživljava u sljedećoj generaciji ukoliko je broj njegovih susjeda dva ili tri.  2. Živi organizam u ćeliji umire u sljedećoj generaciji ukoliko je broj njegovih susjeda manji od dva (zbog usamljenosti) ili veći od tri (zbog prenaseljenosti). 3. U praznoj ćeliji se rađa novi organizam ukoliko se u točno tri njene susjedne ćelije nalaze živi organizmi.
	Igra života počinje od zadane početne konfiguracije i u diskretnim trenucima se formiraju sljedeće konfiguracije organizama istovremenom primjenom gornjih pravila na sve ćelije prethodne konfiguracije. Ovo znači da se prelazak u sljedeću generaciju sastoji od dva koraka:
	1. Izračunati što će se dogoditi sa svakom ćelijom na osnovu gornjih pravila.  2. Primijeniti izračunato na sve ćelije.
	Igra nema kraja.
 */

int main()
{
    Config config;

    char option;
    std::cout << "Would you like to use default config? [Y/N]: ";
    std::cin >> option;
    option = std::toupper(option,std::locale());

    if (option == 'N')
    {
        std::cout << "Enter window width: ";
        std::cin >> config.windowWidth;

        std::cout << "Enter window height: ";
        std::cin >> config.windowHeight;

        std::cout << "Enter cell size: ";
        std::cin >> config.quadSize;

        //Make it so that the cells fit in the window
        config.windowWidth -= config.windowWidth   % config.quadSize;
        config.windowHeight -= config.windowHeight % config.quadSize;

        config.simWidth  =  config.windowWidth  / config.quadSize;
        config.simHeight =  config.windowHeight / config.quadSize;
    }
    else
    {
        config.quadSize     = 8;
        config.windowWidth  = 1024;
        config.windowHeight = 768;

        config.simWidth     =  config.windowWidth  / config.quadSize;
        config.simHeight    =  config.windowHeight / config.quadSize;
    }

    Application app(config);
    app.run();
}
