#pragma once

class CTeil {
protected:
    int teilnummer;
    char bezeichnung[40] ;
public:
    char * LesenBezeichnung(void);
    int LesenTeilnummer(void);
    CTeil(void);
    CTeil(int lTeilnummer, char* lBezeichnung);
};