//<File !Start!>
// FILE: [Filter_Controller_GSLC.h]
// Created by GUIslice Builder version: [0.17.b11]
//
// GUIslice Builder Generated GUI Framework File
//
// For the latest guides, updates and support view:
// https://github.com/ImpulseAdventure/GUIslice
//
//<File !End!>

#ifndef _GUISLICE_GEN_H
#define _GUISLICE_GEN_H

// ------------------------------------------------
// Headers to include
// ------------------------------------------------
#include "GUIslice.h"
#include "GUIslice_drv.h"

// Include any extended elements
//<Includes !Start!>
// Include extended elements
#include "elem/XCheckbox.h"
#include "elem/XProgress.h"
#include "elem/XSpinner.h"
#include "elem/XTogglebtn.h"

// Ensure optional features are enabled in the configuration
#if !(GSLC_FEATURE_COMPOUND)
  #error "Config: GSLC_FEATURE_COMPOUND required for this program but not enabled. Please see: https://github.com/ImpulseAdventure/GUIslice/wiki/Configuring-GUIslice"
#endif
//<Includes !End!>

// ------------------------------------------------
// Headers and Defines for fonts
// Note that font files are located within the Adafruit-GFX library folder:
// ------------------------------------------------
//<Fonts !Start!>
#if defined(DRV_DISP_TFT_ESPI)
  #error Project tab->Target Platform should be tft_espi
#endif
#include <Adafruit_GFX.h>
//<Fonts !End!>

// ------------------------------------------------
// Defines for resources
// ------------------------------------------------
//<Resources !Start!>
//<Resources !End!>

// ------------------------------------------------
// Enumerations for pages, elements, fonts, images
// ------------------------------------------------
//<Enum !Start!>
enum {E_PG_MAIN};
enum {E_ELEM_BOX1,E_ELEM_PROGRESS1,E_ELEM_RADIO1,E_ELEM_SPINNER1
      ,E_ELEM_SPINNER2,E_ELEM_TEXT1,E_ELEM_TEXT2,E_ELEM_TEXT3
      ,E_ELEM_TEXT4,E_ELEM_TEXT5,E_ELEM_TEXT6,E_ELEM_TOGGLE1};
// Must use separate enum for fonts with MAX_FONT at end to use gslc_FontSet.
enum {E_BUILTIN10X16,E_BUILTIN20X32,MAX_FONT};
//<Enum !End!>

// ------------------------------------------------
// Instantiate the GUI
// ------------------------------------------------

// ------------------------------------------------
// Define the maximum number of elements and pages
// ------------------------------------------------
//<ElementDefines !Start!>
#define MAX_PAGE                1

#define MAX_ELEM_PG_MAIN 12 // # Elems total on page
#define MAX_ELEM_PG_MAIN_RAM MAX_ELEM_PG_MAIN // # Elems in RAM
//<ElementDefines !End!>

// ------------------------------------------------
// Create element storage
// ------------------------------------------------
gslc_tsGui                      m_gui;
gslc_tsDriver                   m_drv;
gslc_tsFont                     m_asFont[MAX_FONT];
gslc_tsPage                     m_asPage[MAX_PAGE];

//<GUI_Extra_Elements !Start!>
gslc_tsElem                     m_asPage1Elem[MAX_ELEM_PG_MAIN_RAM];
gslc_tsElemRef                  m_asPage1ElemRef[MAX_ELEM_PG_MAIN];
gslc_tsXTogglebtn               m_asXToggle1;
gslc_tsXSpinner                 m_sXSpinner1;
gslc_tsXSpinner                 m_sXSpinner2;
gslc_tsXProgress                m_sXBarGauge1;
gslc_tsXCheckbox                m_asXRadio1;

#define MAX_STR                 100

//<GUI_Extra_Elements !End!>

// ------------------------------------------------
// Program Globals
// ------------------------------------------------

// Element References for direct access
//<Extern_References !Start!>
extern gslc_tsElemRef* m_pElemProgress1;
extern gslc_tsElemRef* m_pElemSpinner1;
extern gslc_tsElemRef* m_pElemSpinner2;
extern gslc_tsElemRef* m_pElemToggle1;
extern gslc_tsElemRef* m_status;
extern gslc_tsElemRef* relay_text;
//<Extern_References !End!>

// Define debug message function
static int16_t DebugOut(char ch);

// ------------------------------------------------
// Callback Methods
// ------------------------------------------------
bool CbBtnCommon(void* pvGui,void *pvElemRef,gslc_teTouch eTouch,int16_t nX,int16_t nY);
bool CbCheckbox(void* pvGui, void* pvElemRef, int16_t nSelId, bool bState);
bool CbDrawScanner(void* pvGui,void* pvElemRef,gslc_teRedrawType eRedraw);
bool CbKeypad(void* pvGui, void *pvElemRef, int16_t nState, void* pvData);
bool CbListbox(void* pvGui, void* pvElemRef, int16_t nSelId);
bool CbSlidePos(void* pvGui,void* pvElemRef,int16_t nPos);
bool CbSpinner(void* pvGui, void *pvElemRef, int16_t nState, void* pvData);
bool CbTickScanner(void* pvGui,void* pvScope);

// ------------------------------------------------
// Create page elements
// ------------------------------------------------
void InitGUIslice_gen()
{
  gslc_tsElemRef* pElemRef = NULL;

  if (!gslc_Init(&m_gui,&m_drv,m_asPage,MAX_PAGE,m_asFont,MAX_FONT)) { return; }

  // ------------------------------------------------
  // Load Fonts
  // ------------------------------------------------
//<Load_Fonts !Start!>
    if (!gslc_FontSet(&m_gui,E_BUILTIN10X16,GSLC_FONTREF_PTR,NULL,2)) { return; }
    if (!gslc_FontSet(&m_gui,E_BUILTIN20X32,GSLC_FONTREF_PTR,NULL,4)) { return; }
//<Load_Fonts !End!>

//<InitGUI !Start!>
  gslc_PageAdd(&m_gui,E_PG_MAIN,m_asPage1Elem,MAX_ELEM_PG_MAIN_RAM,m_asPage1ElemRef,MAX_ELEM_PG_MAIN);

  // NOTE: The current page defaults to the first page added. Here we explicitly
  //       ensure that the main page is the correct page no matter the add order.
  gslc_SetPageCur(&m_gui,E_PG_MAIN);
  
  // Set Background to a flat color
  gslc_SetBkgndColor(&m_gui,GSLC_COL_BLACK);

  // -----------------------------------
  // PAGE: E_PG_MAIN
  
  
  // Create toggle button E_ELEM_TOGGLE1
  pElemRef = gslc_ElemXTogglebtnCreate(&m_gui,E_ELEM_TOGGLE1,E_PG_MAIN,&m_asXToggle1,
    (gslc_tsRect){240,10,70,30},GSLC_COL_GRAY,GSLC_COL_GREEN,GSLC_COL_GRAY_LT3,
    true,false,&CbBtnCommon);
  m_pElemToggle1 = pElemRef;
  
  // Create E_ELEM_TEXT1 text label
  pElemRef = gslc_ElemCreateTxt(&m_gui,E_ELEM_TEXT1,E_PG_MAIN,(gslc_tsRect){10,10,121,34},
    (char*)"POWER",0,E_BUILTIN20X32);
   
  // Create E_ELEM_BOX1 box
  pElemRef = gslc_ElemCreateBox(&m_gui,E_ELEM_BOX1,E_PG_MAIN,(gslc_tsRect){10,50,300,175});

  // Add Spinner element
  pElemRef = gslc_ElemXSpinnerCreate(&m_gui,E_ELEM_SPINNER1,E_PG_MAIN,&m_sXSpinner1,
    (gslc_tsRect){20,80,115,40},0,99,0,1,E_BUILTIN10X16,40,&CbSpinner);
  m_pElemSpinner1 = pElemRef;

  // Add Spinner element
  pElemRef = gslc_ElemXSpinnerCreate(&m_gui,E_ELEM_SPINNER2,E_PG_MAIN,&m_sXSpinner2,
    (gslc_tsRect){180,80,115,40},0,99,0,1,E_BUILTIN10X16,40,&CbSpinner);
  m_pElemSpinner2 = pElemRef;
  
  // Create E_ELEM_TEXT2 text label
  pElemRef = gslc_ElemCreateTxt(&m_gui,E_ELEM_TEXT2,E_PG_MAIN,(gslc_tsRect){20,60,97,18},
    (char*)"On Time:",0,E_BUILTIN10X16);
  
  // Create E_ELEM_TEXT3 text label
  pElemRef = gslc_ElemCreateTxt(&m_gui,E_ELEM_TEXT3,E_PG_MAIN,(gslc_tsRect){180,60,109,18},
    (char*)"Off Time:",0,E_BUILTIN10X16);
  
  // Create E_ELEM_TEXT4 text label
  pElemRef = gslc_ElemCreateTxt(&m_gui,E_ELEM_TEXT4,E_PG_MAIN,(gslc_tsRect){20,130,109,18},
    (char*)"Relay # :",0,E_BUILTIN10X16);
  
  // Create E_ELEM_TEXT5 runtime modifiable text
  static char m_sDisplayText5[3] = "1";
  pElemRef = gslc_ElemCreateTxt(&m_gui,E_ELEM_TEXT5,E_PG_MAIN,(gslc_tsRect){140,130,25,18},
    (char*)m_sDisplayText5,3,E_BUILTIN10X16);
  relay_text = pElemRef;

  // Create progress bar E_ELEM_PROGRESS1 
  pElemRef = gslc_ElemXProgressCreate(&m_gui,E_ELEM_PROGRESS1,E_PG_MAIN,&m_sXBarGauge1,
    (gslc_tsRect){220,160,12,50},0,100,0,GSLC_COL_GREEN,true);
  m_pElemProgress1 = pElemRef;
  
  // Create radio button E_ELEM_RADIO1
  pElemRef = gslc_ElemXCheckboxCreate(&m_gui,E_ELEM_RADIO1,E_PG_MAIN,&m_asXRadio1,
    (gslc_tsRect){130,160,50,50},true,GSLCX_CHECKBOX_STYLE_BOX,GSLC_COL_GREEN,false);
  m_status = pElemRef;
  
  // Create E_ELEM_TEXT6 text label
  pElemRef = gslc_ElemCreateTxt(&m_gui,E_ELEM_TEXT6,E_PG_MAIN,(gslc_tsRect){20,180,85,18},
    (char*)"Status:",0,E_BUILTIN10X16);
//<InitGUI !End!>

//<Startup !Start!>
//<Startup !End!>

}

#endif // end _GUISLICE_GEN_H
