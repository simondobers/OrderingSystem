#include "stdafx.h"

int CBedarf::LesenBedarf(void)
{
    return bedarf;
}

CBedarf::CBedarf(void) :CTeil()
{
    bedarf = 0;
}

CBedarf::CBedarf(int lTeilnummer, char* lBezeichnung, int lBedarf) : CTeil(lTeilnummer, lBezeichnung)
{
    bedarf = lBedarf;
}

void CBedarf::SetzenBedarf(int lBedarf)
{
    bedarf = lBedarf;
}