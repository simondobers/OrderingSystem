#pragma once
#include "stdafx.h"

CBedarf bedarf[4] = { CBedarf(1001,"Schraube",500),CBedarf(1103,"Halter",50),CBedarf(2032,"Motor",20),CBedarf(2075,"Anzeige",15) };

void CVerwaltung::StartProjekt(void)
{
    int wahl = 1;
    while (wahl)
    {
        cout << "1. Neues Angebot"
            << "\n2. Angebot loeschen"
            << "\n3. Uebersicht Bedarf"
            << "\n4. Uebersicht aller Angebote"
            << "\n5. Uebersicht Angebote pro Teil"
            << "\n6. Uebersicht Angebote pro Lieferant"
            << "\n7. Bestellung"
            << "\n0. Programmende"
            << "\nIhre Wahl :";
        cin >> wahl;
        switch(wahl)
        {
        case 0:
            break;
        case 1:
            int  lTeilNummer, lLieferantenNummer, lAnzahlAngebotenerTeile;
            float lPreisProStueck;
            cout << "Teile:\n";
            ListeTeile();
            cout << "\nLieferanten:\n";
            ListeLieferanten();
            cout << "Teilnummer:";
            cin >> lTeilNummer;
            cout << "Lieferantennummer:";
            cin >> lLieferantenNummer;
            cout << "Anzahl angebotener Teile:";
            cin >> lAnzahlAngebotenerTeile;
            cout << "Preis pro Teil:";
            cin >> lPreisProStueck;
            angebote.NeuesAngebot(lTeilNummer,lLieferantenNummer,lAnzahlAngebotenerTeile,lPreisProStueck);
            break;
        case 2:
            angebote.AlleAngeboteAusgeben();
            cout << "Teilnummer:";
            cin >> lTeilNummer;
            cout << "\nLieferantennummer:";
            cin >> lLieferantenNummer;
            angebote.AngebotLoeschen(lTeilNummer, lLieferantenNummer);
            break;
        case 3:
            cout << "Teilnummer Bezeichnung Bedarf\n";
            ListeBedarfe();
            break;
        case 4:
            cout << "Teilnummer Bezeichnung Anzahl Preis Lieferantennummer\n";
            angebote.AlleAngeboteAusgeben();
            break;
        case 5:
            ListeTeile();
            cout << "Teilnummer:";
            cin >> lTeilNummer;
            cout << "lief.Nr.     Lieferant     Anzahl Preis Gesamt\n";
            angebote.AngeboteNachTeil(lTeilNummer);
            break;
        case 6:
            ListeLieferanten();
            cout << "\nLieferantennummer:";
            cin >> lLieferantenNummer;
            cout << "Teil Bezeichnung Anzahl Preis \n";
            angebote.AngeboteNachLieferant(lLieferantenNummer);
            break;
        case 7:
            BestellMenue();
            break;
        }
    }
}

void CVerwaltung::ListeBedarfe(void)
{
    for (int i = 0; i < 4; i++)
    {
        cout <<setw(10)<< bedarf[i].LesenTeilnummer() << " ";
        cout << setw(11)<<bedarf[i].LesenBezeichnung() << " ";
        cout <<setw(6)<< bedarf[i].LesenBedarf() << "\n";

    }
}

void CVerwaltung::ListeLieferanten(void)
{
    for (int i = 0; i < 6; i++)
    {
        cout << lieferanten[i].LesenLieferantNummer() << " ";
        cout << lieferanten[i].LesenLieferantName() << "\n";
    }
}

void CVerwaltung::ListeTeile(void)
{
    for (int i = 0; i < 4; i++)
    {
        cout << teile[i].LesenTeilnummer() << " ";
        cout << teile[i].LesenBezeichnung() << "\n";
    }
}

void CVerwaltung::BestellMenue(void)
{
    int bWahl = 1;
    
      while (bWahl)
    {
        cout << "1. Einzelbestellung"
            << "\n2. Bestellung pro Teil"
            << "\n3. Gesamtbestellung"
            << "\n4. Einzelbestellung loeschen"
            << "\n5. Bestellungen pro Teil loeschen"
            << "\n6. Alle Bestellungen loeschen"
            << "\n7. Uebersicht Bestellungen"
            << "\n0. Zurueck"
            << "\nIhre Wahl :";
        cin >> bWahl;
        switch (bWahl)
        {
        case 1:
            int lTeilNummer,lLieferantenNummer,lAnzahlBestellteTeile;
            ListeTeile();
            cout << "Teilnummer:";
            cin >> lTeilNummer;
            angebote.AngeboteNachTeil(lTeilNummer);
            cout << "Lieferantennummer: ";
            cin >> lLieferantenNummer;
            cout << "Anzahl der zu bestellenden Teile: ";
            cin >> lAnzahlBestellteTeile;
            angebote.EinzelBestellung(lTeilNummer, lLieferantenNummer, lAnzahlBestellteTeile);
            cout << "\nDaten zur Kontrolle: Es werden " << lAnzahlBestellteTeile << " mit der Teilnummer " << lTeilNummer << " bei Lieferant " << lLieferantenNummer << " bestellt. \n";
            break;
        case 2:
            ListeTeile();
            cout << "Teilnummer:";
            cin >> lTeilNummer;
            angebote.BestellungProTeil(lTeilNummer);
            break;
        case 3:
            cout << "Noch keine Funktion!\n";
            break;
        case 4:
            cout << "Noch keine Funktion!\n";
            break;
        case 5:
            cout << "Noch keine Funktion!\n";
            break;
        case 6:
            angebote.AlleBestellungenLoeschen();
            break;
        case 7:
            ListeTeile();
            cout << "Teilnummer:";
            cin >> lTeilNummer;
            angebote.BestellUebersicht(lTeilNummer);
            break;

        }
    }
    
}
