#pragma once
#include "stdafx.h"



class CVerwaltung {
protected:
    CListe angebote;
public:
    void StartProjekt(void);
    void BestellMenue(void);
    void ListeBedarfe(void);
    void ListeLieferanten(void);
    void ListeTeile(void); 
};
