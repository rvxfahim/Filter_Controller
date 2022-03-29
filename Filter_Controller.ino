//<App !Start!>
// FILE: [Filter_Controller.ino]
// Created by GUIslice Builder version: [0.17.b11]
//
// GUIslice Builder Generated File
//
// For the latest guides, updates and support view:
// https://github.com/ImpulseAdventure/GUIslice
//
//<App !End!>
//<App !End!>


// ------------------------------------------------
// Headers to include
// ------------------------------------------------
#include <Arduino.h>
#include <EEPROM.h>
#include "Filter_Controller_GSLC.h"


// ------------------------------------------------
// Program Globals
// ------------------------------------------------
uint8_t on_time_global;     
uint8_t gap_time_global;   
uint8_t play_status_global;
uint8_t relay=22; 
bool gap_timer_started = false;
bool box=false;
bool on_t_flag=false;
bool gap_t_flag=true;
bool relay_text_updated=false;
char              acTxt[4];
unsigned long int t1, t2;

void on_time() {
  uint8_t on_time_l = gslc_ElemXSpinnerGetCounter(&m_gui, &m_sXSpinner1);
  //Serial.println("On Time: " + String(on_time_l));
  on_time_global = on_time_l;
  EEPROM.update(0, on_time_l);
}
void gap_time() {
  uint8_t gap_time_l = gslc_ElemXSpinnerGetCounter(&m_gui, &m_sXSpinner2);
  //Serial.println("Gap Time: " + String(gap_time_l));
  gap_time_global=gap_time_l;
  EEPROM.update(1, gap_time_l);
}
void start_switch() {
  if (gslc_ElemXTogglebtnGetState(&m_gui, m_pElemToggle1)) {
    //Serial.println("turned on");
    play_status_global = 1;
    EEPROM.update(2, 1);
  }
  else
  {
    //Serial.println("turned off");
    play_status_global = 0;
    EEPROM.update(2, 0);
  }
}
// Save some element references for direct access
//<Save_References !Start!>
gslc_tsElemRef* m_pElemProgress1  = NULL;
gslc_tsElemRef* m_pElemSpinner1   = NULL;
gslc_tsElemRef* m_pElemSpinner2   = NULL;
gslc_tsElemRef* m_pElemToggle1    = NULL;
gslc_tsElemRef* m_status          = NULL;
gslc_tsElemRef* relay_text        = NULL;
//<Save_References !End!>

// Define debug message function
static int16_t DebugOut(char ch) { if (ch == (char)'\n') Serial.println(""); else Serial.write(ch); return 0; }

// ------------------------------------------------
// Callback Methods
// ------------------------------------------------
// Common Button callback
bool CbBtnCommon(void* pvGui,void *pvElemRef,gslc_teTouch eTouch,int16_t nX,int16_t nY)
{
  // Typecast the parameters to match the GUI and element types
  gslc_tsGui*     pGui     = (gslc_tsGui*)(pvGui);
  gslc_tsElemRef* pElemRef = (gslc_tsElemRef*)(pvElemRef);
  gslc_tsElem*    pElem    = gslc_GetElemFromRef(pGui,pElemRef);

  if ( eTouch == GSLC_TOUCH_UP_IN ) {
    // From the element's ID we can determine which button was pressed.
    switch (pElem->nId) {
//<Button Enums !Start!>
      case E_ELEM_TOGGLE1:
        // TODO Add code for Toggle button ON/OFF state
        start_switch();
        break;
//<Button Enums !End!>
      default:
        break;
    }
  }
  return true;
}

//<Checkbox Callback !Start!>
//<Checkbox Callback !End!>
//<Keypad Callback !Start!>
//<Keypad Callback !End!>
//<Listbox Callback !Start!>
//<Listbox Callback !End!>
//<Checkbox Callback !Start!>
//<Checkbox Callback !End!>
//<Keypad Callback !Start!>
//<Keypad Callback !End!>
// Spinner Input Ready callback
bool CbSpinner(void* pvGui, void *pvElemRef, int16_t nState, void* pvData)
{
  gslc_tsGui*     pGui = (gslc_tsGui*)pvGui;
  gslc_tsElemRef* pElemRef = (gslc_tsElemRef*)(pvElemRef);
  gslc_tsElem*    pElem = gslc_GetElemFromRef(pGui,pElemRef);

  // NOTE: pvData is NULL
  if (nState == XSPINNER_CB_STATE_UPDATE) {
    // From the element's ID we can determine which input field is ready.
    switch (pElem->nId) {
//<Spinner Enums !Start!>
      case E_ELEM_SPINNER1:
        //TODO- Add Spinner handling code
        // using gslc_ElemXSpinnerGetCounter(&m_gui, &m_sXSpinner1);
        on_time();
        break;
      case E_ELEM_SPINNER2:
        //TODO- Add Spinner handling code
        // using gslc_ElemXSpinnerGetCounter(&m_gui, &m_sXSpinner2);
        gap_time();
        break;

//<Spinner Enums !End!>
      default:
        break;
    }
  }
}
//<Draw Callback !Start!>
//<Draw Callback !End!>
//<Slider Callback !Start!>
//<Slider Callback !End!>
//<Tick Callback !Start!>
//<Tick Callback !End!>

void setup()
{
  // ------------------------------------------------
  // Initialize
  // ------------------------------------------------
  Serial.begin(9600);
  // Wait for USB Serial 
  //delay(1000);  // NOTE: Some devices require a delay after Serial.begin() before serial port can be used
  on_time_global     = EEPROM.read(0);
  gap_time_global    = EEPROM.read(1);
  play_status_global = EEPROM.read(2);
  if (on_time_global > 99) {
    on_time_global = 1;
  }
  if (gap_time_global > 99) {
    gap_time_global = 1;
  }
  if (play_status_global > 1) {
    play_status_global = 0;
  }  
  //set pins 22 to 39 as outputs
  for (int i = 22; i < 40; i++) {
    pinMode(i, OUTPUT);
  }
  // set all pins to LOW
  for (int i = 22; i < 40; i++) {
    digitalWrite(i, LOW);
  }
  gslc_InitDebug(&DebugOut);

  // ------------------------------------------------
  // Create graphic elements
  // ------------------------------------------------
  InitGUIslice_gen();

  gslc_ElemXSpinnerSetCounter(&m_gui, &m_sXSpinner1, on_time_global);
  gslc_ElemXSpinnerSetCounter(&m_gui, &m_sXSpinner2, gap_time_global);
  if (play_status_global==1)
  gslc_ElemXTogglebtnSetState(&m_gui, m_pElemToggle1, true);
  else
  gslc_ElemXTogglebtnSetState(&m_gui, m_pElemToggle1, false);
  int relay_readable = map (relay, 22, 39, 1, 18);
  snprintf(acTxt, 4, "%u", relay_readable);
  gslc_ElemSetTxtStr(&m_gui,relay_text,acTxt);
  t1 = millis();
  t2 = millis();
}

// -----------------------------------
// Main event loop
// -----------------------------------
void loop()
{

  // ------------------------------------------------
  // Update GUI Elements
  // ------------------------------------------------
  
  //TODO - Add update code for any text, gauges, or sliders
  
  // ------------------------------------------------
  // Periodically call GUIslice update function
  // ------------------------------------------------
  gslc_Update(&m_gui);

  if(play_status_global)
  { 
    if(millis() - t1 > (on_time_global*1000))
    {
      digitalWrite(relay, LOW);
      gslc_ElemXCheckboxSetState(&m_gui, m_status, false);
      //Serial.println("Relay: " + String(relay) + " OFF");
      float progress_percent = (millis() - t2);
      progress_percent = progress_percent/ (gap_time_global*1000);
      progress_percent=progress_percent*100;
      //Serial.println("Progress: " + String(progress_percent) + "%");
      gslc_ElemXProgressSetVal(&m_gui,m_pElemProgress1, int16_t(100-progress_percent));
    }
    else{
      t2 = millis();
      digitalWrite(relay, HIGH);
      gslc_ElemXCheckboxSetState(&m_gui, m_status, true);
      //Serial.println("Relay: " + String(relay) + " ON");
      float progress_percent = (millis() - t1);
      progress_percent = progress_percent/ (on_time_global*1000);
      progress_percent=progress_percent*100;
      //Serial.println("Progress: " + String(progress_percent) + "%");
      gslc_ElemXProgressSetVal(&m_gui,m_pElemProgress1, int16_t(progress_percent));
    }
    if(millis() - t2 > (gap_time_global*1000))
    {
        t1 = millis();
        relay++;
        relay_text_updated = true;
        if(relay > 39)
        {
          relay = 22;
        }
    }
    
    if (relay_text_updated)
    {
      relay_text_updated = false;
      int relay_readable = map (relay, 22, 39, 1, 18);
      Serial.println("Relay: " + String(relay_readable));
      snprintf(acTxt, 4, "%u", relay_readable);
      gslc_ElemSetTxtStr(&m_gui,relay_text,acTxt);
    }
        
  }
  else
  {
    digitalWrite(relay, LOW);
    gslc_ElemXCheckboxSetState(&m_gui, m_status, false);
  }
    
}

