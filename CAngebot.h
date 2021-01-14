#pragma once
#include "stdafx.h"

class CAngebot :public CTeil 
{
protected:
    int lieferantenNummer, anzahlAngeboteneTeile, anzahlBestellteTeile;
    float preisProStueck;
public:
    int LesenLieferantenNummmer(void);
    int LesenAngebotAnzahl(void);
    int LesenBestellt(void);
    void SetzenBestellt(int lBestellt);
    float LesenPreis(void);
    float AngebotsPreis(void);
    char * LesenLieferantenName(void);
    CAngebot(void);
    CAngebot(int lTeilnummer, char* lBezeichnung, int lLieferantenNummer, int lAnzahlAngeboteneTeile, float lPreisProStueck);
    CAngebot* next;
};