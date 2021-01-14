// stdafx.h : include file for standard system include files,
// or project specific include files that are used frequently, but
// are changed infrequently
//

#pragma once
#define _CRT_SECURE_NO_WARNINGS   
#include "targetver.h"

#include <stdio.h>
#include <tchar.h>
#include <iostream>
#include <iomanip>
using namespace std;
#include <string.h>
#include "CTeil.h"
#include "CBedarf.h"
#include "CLieferant.h"
#include "CAngebot.h"
#include "CListe.h"
#include "CVerwaltung.h"

static CTeil teile[4] = { CTeil(1001,"Schraube"),CTeil(1103,"Halter"),CTeil(2032,"Motor"),CTeil(2075,"Anzeige") };
 


 
static CLieferant lieferanten[6] = { CLieferant(110,"Maier KG"),CLieferant(210,"Gebr.Klaus"),CLieferant(220,"HUXA AG"),CLieferant(320,"Karl Schmidt"),CLieferant(360,"Krause & Co"),CLieferant(440,"Allo GmbH & Co KG") };





// TODO: reference additional headers your program requires here

