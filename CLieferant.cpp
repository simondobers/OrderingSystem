#include "stdafx.h"

char * CLieferant::LesenLieferantName(void)
{
    return name;
}

int CLieferant::LesenLieferantNummer(void)
{
    return identNummer;
}
CLieferant::CLieferant(void)
{
    identNummer = 0;
    strcpy(name, "keine Bezeichnung");
}

CLieferant::CLieferant(int lIdentNummer, char* lName)
{
    identNummer = lIdentNummer;
    strcpy(name, lName);
}