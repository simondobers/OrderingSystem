#pragma once
#include "stdafx.h"


class CListe
{


    CAngebot * kopf, *ende;

public:
    CListe(void);
    ~CListe(void);
    void NeuesAngebot(int lTeilNummer,int lLieferantenNummer,int lAnzahlAngebotenerTeile, float lPreisProStueck );          //Jedes neue Angebot wird mit Teilnummer, Lieferantennumer, Preis pro Einzelteil und Anzahl der angebotenen Teile eingegeben.
    void AngebotLoeschen(int lTeilNummer, int lLieferantenNummer);
    void AlleAngeboteAusgeben(void);
    void AngeboteNachTeil(int lTeilNummer);
    void AngeboteNachLieferant(int lLieferantenNummer);
    void EinzelBestellung(int lTeilNummer, int lLieferantenNummer,int lAnzahlBestellterTeile);
    void BestellungProTeil(int lTeilNummer);
    void AlleBestellungenLoeschen(void);
    void BestellUebersicht(int lTeilNummer);
    bool IstLeer(void);

};
