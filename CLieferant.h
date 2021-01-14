#pragma once

class CLieferant {
protected:
    int identNummer;
    char name[40];
public:
    CLieferant(void);
    CLieferant(int lIdentNummer, char* lName);
    int LesenLieferantNummer(void);
    char* LesenLieferantName(void);
};
