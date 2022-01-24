// Αρχείο 8x8LED.h για οδήγηση οθόνης 8x8 LED Matrix συμβατής με MAX7219
// εταιρία: elecrow, μοντέλο :DLM72192R
// εταιρία: elecrow, μοντέλο :DLM72192R

#include <LedControl.h>

const uint64_t eikones[] = {
  0x2424ff2424ff2424, //0 άδεια πίστα

  0x2424ff2424ff2527, 0x2424ff2424ff243c, 0x2424ff2424ffa4e4,
  0x2424ff2525ff2424, 0x2424ff2c34ff2424, 0x2424ffa4a4ff2424,
  0x2725ff2424ff2424, 0x3c24ff2424ff2424, 0xe424ff2424ff2424,
  0x3c66666666663c00, //10 'O'

  0x2424ff2424ff2727, 0x2424ff2424ff3c3c, 0x2424ff2424ffe4e4,
  0x2424ff2727ff2424, 0x2424ff3c3cff2424, 0x2424ffe4e4ff2424,
  0x2727ff2424ff2424, 0x3c3cff2424ff2424, 0xe4e4ff2424ff2424,
  0xc6c66c386cc6c600, //20 'X'

  0x7e1818181c181800, //21 '1'
  0x7e060c3060663c00, //22 '2'
  0x3c66603860663c00, //23 '3'
  
  0x9070509609090906, //24 ΟΚ
  0x081c3e7f1c1c1c1c, //25 κάτω βέλος
  0x1c1c1c1c7f3e1c08, //26 πάνω βέλος
  
  0x040e1b3160c08000, //27 τσεκ
  0x8142241818244281, //28 ΑΚΥΡ , 'Χ'
  
  0x00003c003c000000, //29 '='
  0x003c420000666600, //30 χαμόγελο
  0x00423c0000662400  //31 λύπη
};

const int eikones_mikos = sizeof(eikones) / 8;

LedControl othoni = LedControl(53, 49, 51);   // πινάκια για arduino Mega: DIN, CLK, CS

void enarksiOthonis() {
  othoni.clearDisplay(10);
  othoni.shutdown(0, false);  // αλλάζει τον τρόπο λειτουργίας από σβηστή σε αναμένη
  othoni.setIntensity(0, 10); // θέτει την φωτινότητα σε 16 βήματα, 0..15.
}

void emfaniseEikona(uint64_t eikona) {
  for (int i = 0; i < 8; i++) {
    byte row = (eikona >> i * 8) & 0xFF;
    for (int j = 0; j < 8; j++)
      othoni.setLed(0, i, j, bitRead(row, j));
  }
}

/*
int i = 0;
void loop() {
  emfaniseEikona(eikones[i]);
  if ( ++i >= eikones_mikos ) i = 0;
  delay(500);
}
*/