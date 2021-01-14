#include "stdafx.h"

char * CTeil::LesenBezeichnung(void)
{
    return bezeichnung;
}

int CTeil::LesenTeilnummer(void)
{
    return teilnummer;
}
CTeil::CTeil(void)
{
    teilnummer = 0;
    strcpy(bezeichnung, "keine Bezeichnung");
}

CTeil::CTeil(int lTeilnummer, char* lBezeichnung)
{
    teilnummer = lTeilnummer;
    strcpy(bezeichnung, lBezeichnung);
}