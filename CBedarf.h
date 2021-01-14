#pragma once
#include "stdafx.h"

class CBedarf :public CTeil {
protected:
    int bedarf;
public:
    int LesenBedarf(void);
    CBedarf(void);
    CBedarf(int lTeilnummer, char* lBezeichnung,int lBedarf);
    void SetzenBedarf(int lBedarf);
};
