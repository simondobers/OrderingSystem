#pragma once
#include "stdafx.h"

extern CBedarf bedarf[4];





CListe::CListe(void)                            //Konstruktor setzt kopf und ende auf Null, da noch keine Elemente vorhanden
{
    kopf = 0;
    ende = 0;
}

CListe::~CListe(void)                          //Destruktor, löscht die Liste vollständig, um Speicherplatz wieder freizugeben
{
    if (IstLeer())                             //Falls Liste leer ist, muss man auch nichts mehr löschen
        return;

    while (kopf->next != 0)                    //Bis nur noch der Kopf der Liste übrig ist
    {

        CAngebot *vorletztesElement = kopf;                
        while (vorletztesElement->next != ende)
        {
            vorletztesElement = vorletztesElement->next;             //Hilfszeiger solange weiterschieben, bis er auf das vorletze Element zeigt
        }


        delete ende;


        vorletztesElement->next = 0;
        ende = vorletztesElement;
    }

                                                            //als letzes noch den Kopf (letztes verbliebenes Element in der Liste) löschen
    delete kopf;
}

bool CListe::IstLeer(void)
{
    return (kopf == 0) ? true : false;                     //Falls Kopf = 0 ist, dann ist die Liste leer
}

void CListe::NeuesAngebot(int lTeilNummer, int lLieferantenNummer, int lAnzahlAngebotenerTeile, float lPreisProStueck)
{
    char *lName = 0;
    for (int i = 0; i < 4; i++)
    {
        if (teile[i].LesenTeilnummer() == lTeilNummer)                              //Namen des Teils heraussuchen, um den Konstruktor von CAngebot aufrufen zu können
            lName = teile[i].LesenBezeichnung();
    }
    CAngebot * neuesAngebot = new CAngebot(lTeilNummer, lName, lLieferantenNummer,  lAnzahlAngebotenerTeile,  lPreisProStueck);            //Zeiger auf das dynamisch erzeugte Angebot
    CAngebot*p = kopf;                                                                //Hilfszeiger aufs erste Listenelement
    if (IstLeer())                                                                    
        ende = kopf = neuesAngebot;                                                   //Falls Liste noch leer ist, so wird das neue Angebot das erste Element
    /*else
    {
        ende->next = neuesAngebot;
        ende = neuesAngebot;                                                           //Die Liste wird nach dem Preis pro Stück sortiert bzw. die Elemente werden so eingefügt, dass sie bereits sortiert sind
    }  */
    else if (lPreisProStueck<kopf->LesenPreis())                                      //Falls das neue Angebot billiger als das erste Listenelement(kopf) ist, so muss es der neue Kopf werden
    {
        neuesAngebot->next = p;
        kopf = neuesAngebot;
    }
    else
    {
        while (p)                  //Über die komplette Liste gehen
        {
            if (p->next == 0)                          //Falls das neue Angebot das teuerste ist, so muss es das letzte Element werden
            {
                ende->next = neuesAngebot;
                ende = neuesAngebot;
                return;
            }
            if (lPreisProStueck <= p->next->LesenPreis())   //Es wird immer geprüft, ob der Preis des nächsten Elements größer ist, falls ja, so wird das neue Angebot an der Stelle vor dem nächsten Angebot einsortiert
            {
                CAngebot*h = p->next;
                p->next = neuesAngebot;
                neuesAngebot->next = h;
                return;
            }
            p = p->next;
        }

    }
}

void CListe::AngebotLoeschen(int lTeilNummer, int lLieferantenNummer)
{
    CAngebot*p = kopf;
    while (p)
    {
        /*if (kopf == ende && p->LesenTeilnummer()== lTeilNummer && p->LesenLieferantenNummmer() == lLieferantenNummer)
        {
            kopf = 0;
            ende = 0;
            return;
        }*/
        if (p->LesenTeilnummer() == lTeilNummer && p->LesenLieferantenNummmer() == lLieferantenNummer)             //Löschen, falls das zu löschende Angebot das erste Element in der Liste ist
        {
            CAngebot* c = p->next;
            delete p;                       
            kopf = c;
            return;
        }
        if (p->next->LesenTeilnummer() == lTeilNummer && p->next->LesenLieferantenNummmer()==lLieferantenNummer)
        {
            CAngebot*h = p->next->next;
            delete p->next;
            p->next = h;
            return;
        }  
        p = p->next;
    }



    cout << "Es gibt kein solches Angebot!\n";
}

void CListe::AlleAngeboteAusgeben()
{
    
    for (int i = 0; i < 4; i++)                   //Alle Teile durchgehen
    {
        CAngebot*p = kopf;
        while (p)
        {
            if (p->LesenTeilnummer() == teile[i].LesenTeilnummer())                              //Filtern nach der Teilnummer
            {
                cout <<setw(10)<< p->LesenTeilnummer() << " ";         
                cout << setw(11)<<p->LesenBezeichnung() << " ";   
                cout << setw(6)<< p->LesenAngebotAnzahl() << " ";
                cout << setw(5)<<setprecision(3)<< p->LesenPreis() << " ";
                cout << setw(8)<< p->LesenLieferantenNummmer() << " ";
                cout << "\n";
            }
            p = p->next;
        }

    }
    
}

void CListe::AngeboteNachTeil(int lTeilNummer)
{
    CAngebot *p = kopf;

    while (p)
    {
        if (p->LesenTeilnummer() == lTeilNummer)                                         //Alle Angebote mit Teilnummer=lTeilnummer ausgeben
        {
            cout <<setw(8)<< p->LesenLieferantenNummmer() << " ";
            cout <<setw(17)<< p->LesenLieferantenName() << " ";
            cout <<setw(6)<< p->LesenAngebotAnzahl() << " ";
            cout <<setw(5)<<setprecision(3)<< p->LesenPreis() << " ";
            cout <<setw(6)<<setprecision(3)<< p->AngebotsPreis() << "\n";
        }
        p = p->next;
    }
    

}

void CListe::AngeboteNachLieferant(int lLieferantenNummer)
{
    CAngebot *p = kopf;
    float gesamtPreis = 0.0;

    while (p)
    {
        if (p->LesenLieferantenNummmer() == lLieferantenNummer)
        {
            cout << setw(4)<<p->LesenTeilnummer() << " ";
            cout << setw(10)<<p->LesenBezeichnung() << " ";
            cout << setw(6)<<p->LesenAngebotAnzahl() << " ";
            cout << setw(5)<<setprecision(3)<<p->LesenPreis() << " ";
            cout << "\n";
            gesamtPreis += p->AngebotsPreis();
        }
        p = p->next;
    }
    cout << "\nGesamtpreis: " << setprecision(3)<<gesamtPreis << "\n";
}

void CListe::EinzelBestellung(int lTeilNummer, int lLieferantenNummer, int lAnzahlBestellterTeile)
{
    CAngebot*p = kopf;
    while (p)
    {
        if (p->LesenTeilnummer() == lTeilNummer && p->LesenLieferantenNummmer() == lLieferantenNummer)
        {
            p->SetzenBestellt(lAnzahlBestellterTeile);
        }
        p = p->next;
    }
    for (int i = 0; i < 4; i++)
    {
        if (bedarf[i].LesenTeilnummer() == lTeilNummer)
            bedarf[i].SetzenBedarf(bedarf[i].LesenBedarf() - lAnzahlBestellterTeile);
    }
}

void CListe::AlleBestellungenLoeschen(void)
{
    CAngebot*p = kopf;
    while (p)
    {
        p->SetzenBestellt(0);                            //Über die komplette Liste gehen und alle Bestellungen auf Null setzen
        p = p->next;
    }
    bedarf[0].SetzenBedarf(500);                              //Bedarf wieder auf default-Werte setzen
    bedarf[1].SetzenBedarf(50);
    bedarf[2].SetzenBedarf(20);
    bedarf[3].SetzenBedarf(15);
}

void CListe::BestellUebersicht(int lTeilNummer)
{
    CAngebot*p = kopf;
    int bestellteTeileGesamt = 0;
    float gesamtpreis = 0.0;
    while (p)
    {
        if (p->LesenBestellt() != 0 && p->LesenTeilnummer() == lTeilNummer)
        {
            cout << p->LesenTeilnummer() << " ";
            cout << p->LesenBezeichnung() << " ";
            cout << p->LesenLieferantenNummmer() << " ";
            cout << p->LesenLieferantenName() << " ";
            cout << p->LesenPreis() << " ";
            cout << p->LesenBestellt() ;
            cout << "\n";
            bestellteTeileGesamt += p->LesenBestellt();
            gesamtpreis += (p->LesenBestellt()*p->LesenPreis());
        }
        p = p->next;
    }
    cout << "Anzahl bestellter Teile: " << bestellteTeileGesamt << "\nGesamtpreis: " << gesamtpreis<<"\n";

}

void CListe::BestellungProTeil(int lTeilNummer)
{
    int benoetigteTeile,i=0;
    CAngebot*p = kopf;
    for (i ; i < 4; i++)
    {
        if (bedarf[i].LesenTeilnummer() == lTeilNummer)
        {
            benoetigteTeile = bedarf[i].LesenBedarf();                               //Den Bedarf des gewünschten Teiles ermmitteln
            break;
        }
            
    }
    while (p && benoetigteTeile)                                     //solange es noch nicht "benutze" Angebote gibt und die noch benötigten Teile > 0 sind
    {
        if (p->LesenTeilnummer() == lTeilNummer )                                     //Prüfen, ob das aktuelle Listenelement die benötigten Teile "anbietet"
        {
            if (benoetigteTeile >= p->LesenAngebotAnzahl())                           //Wenn ich mehr Teile benötige, als im aktuellen Angebot ausgeschrieben sind
            {
                p->SetzenBestellt(p->LesenAngebotAnzahl());                                     //Bestellung aller angebotenen Teile dieses Listenelements
                benoetigteTeile -= p->LesenAngebotAnzahl();                                     //benötigte Teile werden um Anzahl der bestellten Teile reduziert
                bedarf[i].SetzenBedarf(bedarf[i].LesenBedarf() - p->LesenAngebotAnzahl());      //Bedarf um bestellte Teile reduzieren
            }
            else
            {
                p->SetzenBestellt(benoetigteTeile);                                   //Falls das Angebot mehr Teile umfasst, als ich benötige, bestellt man alle benötigten
                benoetigteTeile = 0;                                                  //Jetzt werden keine weiteren Teile benötigt...
                bedarf[i].SetzenBedarf(0);                                            //... bzw. der Bedarf ist 0
            }
            
           
        }
        p = p->next;
    }
}