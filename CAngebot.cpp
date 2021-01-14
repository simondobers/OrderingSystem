#include "stdafx.h"

CAngebot::CAngebot(void) : CTeil()
{
    lieferantenNummer = 0;
    anzahlAngeboteneTeile = 0;
    anzahlBestellteTeile = 0;
    preisProStueck = 0;
    next = 0;
}

CAngebot::CAngebot(int lTeilnummer, char* lBezeichnung, int lLieferantenNummer, int lAnzahlAngeboteneTeile, float lPreisProStueck) : CTeil(lTeilnummer, lBezeichnung)
{
    lieferantenNummer = lLieferantenNummer;
    anzahlAngeboteneTeile = lAnzahlAngeboteneTeile;
    anzahlBestellteTeile = 0;
    preisProStueck = lPreisProStueck;
    next = 0;
}

int CAngebot::LesenLieferantenNummmer(void)
{
    return lieferantenNummer;
}

int CAngebot::LesenAngebotAnzahl(void)
{
    return anzahlAngeboteneTeile;
}

int CAngebot::LesenBestellt(void)
{
    return anzahlBestellteTeile;
}

void CAngebot::SetzenBestellt(int lBestellt)
{
    anzahlBestellteTeile = lBestellt;
}

float CAngebot::LesenPreis(void)
{
    return preisProStueck;
}

float CAngebot::AngebotsPreis(void)
{   
    return preisProStueck * (float)anzahlAngeboteneTeile;
}

char * CAngebot::LesenLieferantenName(void)
{
    for (int i = 0; i < 6; i++)
    {
        if (lieferanten[i].LesenLieferantNummer() == lieferantenNummer)
            return lieferanten[i].LesenLieferantName();
    }
}