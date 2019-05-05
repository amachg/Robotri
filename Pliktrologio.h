// Αρχείο Pliktrologio.h για την οδήγηση πληκτρολογίου μεμβράνης 4x3 πλήκτρων

#include <Keypad.h>

const byte grammes{4};
const byte stiles{3};
char pliktra[grammes][stiles] = {
  {'1', '2', '3'},
  {'4', '5', '6'},
  {'7', '8', '9'},
  {'#', '0', '*'}
};

// Αντιστοίχιση Πληκτρολογίου μεμβράνης σε Μικροελεγκτή Arduino
// Καλώδια πληκτρολογίου:(*){ 7,  6,  5,  4} τέσσερις γραμμές,     { 3,  2,  1} τρεις στήλες (#)
byte pinsGrammis[grammes] = {62, 63, 64, 65}, pinsStilis[stiles] = {66, 67,  68}; // Mega ADK
//byte pinsGrammis[grammes] = {14, 15, 16, 17}, pinsStilis[stiles] = {18, 19,  2}; // Uno

Keypad pliktrologio = Keypad( makeKeymap(pliktra), pinsGrammis, pinsStilis, grammes, stiles );
