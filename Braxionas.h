// Αρχείο Braxionas.h για  για ρομποτικό βραχίονα Arduino Braccio
// με όλες οι κινήσεις (άπλωμα-μάζεμα) πουλιών με το ρομπότ.


// Tροποποιημένη Βιβλιοθήκη "Braccio" ώστε να μην χρησιμοποιεί το SOFT_START
// που δε δουλεύει σωστά. Περιλαμβάνει το "servo.h" από τη βιβλιοθήκη "Servo".
#include <myBraccio.h>

//Τα σέρβο έχουν δηλωθεί στο "servo.h" και εξωτερικά (extern) στο "Braccio.cpp"
Servo base;
Servo shoulder;
Servo elbow;
Servo wrist_rot;
Servo wrist_ver;
Servo gripper;

//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

int taxutita = 30;
int leuko = 180;
int mauro = 0;

//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
// Όρθια θέση βραχίονα (ξεκούρασης!)
//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

void orthiosBraxionas() {
  //Τιμές:             ελάχιστη - μέση - μέγιστη
  //Καθυστέρηση:            010 - 030 - 030 χιλιοστά δευτερόλεπτου
  //Βάση (M1):              000 - 090 - 180 μοίρες στροφής άξονα σερβοκινητήρα
  //Ώμος (M2):              015 - 090 - 165             <<
  //Αγκώνας (M3):           000 - 090 - 180             <<
  //Καρπός Ανύψωση(M4):     000 - 090 - 180             <<
  //Καρπός Περιστροφή(M5):  000 - 090 - 180             <<
  //Δαγκάνα (M6): (κλειστό) 073 - 055 - 010 (ανοιχτό)
  //          Καθυστέρηση,  Βασ, Ώμος, Αγγ, ΚαρΑ, ΚαρΠ, Δαγκ;
  Braccio.ServoMovement(30,  90,   90,  90,   90,   90,  55);
}

//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
// Απλώματα πουλιών στην πίστα
//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

void parePouliApoGlistra(const int taxutita, const int base) {
  orthiosBraxionas();
  Braccio.ServoMovement(taxutita, base,  30,  180,  177,  90, 24);
  Braccio.ServoMovement(taxutita, base,  97,  180,  173,  90, 24);  //πάει στο πούλι
  Braccio.ServoMovement(taxutita, base,  97,  180,  173,  90, 53);  //πιάνει το πούλι
  Braccio.ServoMovement(taxutita, base,  93,  180,  173,  90, 53);  //ανασήκωμα1
  delay(300);
  Braccio.ServoMovement(taxutita, base,  91,  180,  173,  90, 53);  //ανασήκωμα2
  delay(300);
  Braccio.ServoMovement(taxutita, base,  88,  180,  173,  90, 53);  //ανασήκωμα2
  delay(300);
  Braccio.ServoMovement(taxutita, base,  30,  150,  173,  90, 53);  //ανεβάζει το πούλι
}

void valePouliSto_1A(const int taxutita) {
  Braccio.ServoMovement(taxutita, 116,   90, 150, 169,  90, 53); //πάει προς το Α1
  Braccio.ServoMovement(taxutita, 120,  105, 172, 174,  90, 53); //κατεβαζει προς το Α1
  Braccio.ServoMovement(taxutita, 120,  105, 172, 174,  90, 24); //αφηνει στο Α1
  Braccio.ServoMovement(taxutita, 116,   80, 175, 174,  90, 24); //ανεβαίνει
  orthiosBraxionas();
}

void valePouliSto_1B(const int taxutita) {
  Braccio.ServoMovement(taxutita, 91,  80,   90, 171,  90, 53);
  Braccio.ServoMovement(taxutita, 90, 101,  180, 174,  90, 53);
  Braccio.ServoMovement(taxutita, 90, 101,  180, 174,  90, 28);
  Braccio.ServoMovement(taxutita, 91,  80,  180, 171,  90, 28);
  orthiosBraxionas();
}

void valePouliSto_1G(const int taxutita) {
  Braccio.ServoMovement(taxutita,  60,  80,  90, 169,  90, 53);
  Braccio.ServoMovement(taxutita,  68, 108, 174, 174,  90, 53);
  Braccio.ServoMovement(taxutita,  68, 108, 174, 174,  90, 24);
  Braccio.ServoMovement(taxutita,  68,  80, 174, 169,  90, 24);
  orthiosBraxionas();
}

void valePouliSto_2A(const int taxutita) {
  Braccio.ServoMovement(taxutita, 110,  80,  90, 176,  90, 53);
  Braccio.ServoMovement(taxutita, 114, 123, 152, 170,  90, 53);
  Braccio.ServoMovement(taxutita, 114, 123, 152, 170,  90, 24);
  Braccio.ServoMovement(taxutita, 110,  84, 155, 167,  90, 24);
  orthiosBraxionas();
}

void valePouliSto_2B(const int taxutita) {
  Braccio.ServoMovement(taxutita,  92,  60,   90, 176,  90, 53);
  Braccio.ServoMovement(taxutita,  93, 120,  160, 167,  90, 53);
  Braccio.ServoMovement(taxutita,  93, 120,  160, 167,  90, 33);
  Braccio.ServoMovement(taxutita,  92,  80,  158, 169,  90, 33);
  orthiosBraxionas();
}

void valePouliSto_2G(const int taxutita) {
  Braccio.ServoMovement(taxutita,  70, 105,   90, 177,  90, 53);
  Braccio.ServoMovement(taxutita,  78, 125,  160, 168,  90, 53);
  Braccio.ServoMovement(taxutita,  78, 125,  160, 168,  90, 35);
  Braccio.ServoMovement(taxutita,  70,  60,  158, 167,  90, 28);
  orthiosBraxionas();
}

void valePouliSto_3A(const int taxutita) {
  Braccio.ServoMovement(taxutita, 105, 105,  90, 177,  90, 53);
  Braccio.ServoMovement(taxutita, 111, 130, 150, 153,  90, 53);
  Braccio.ServoMovement(taxutita, 111, 130, 150, 153,  90, 28);
  Braccio.ServoMovement(taxutita, 105,  80, 115, 160,  90, 28);
  orthiosBraxionas();
}

void valePouliSto_3B(const int taxutita) {
  Braccio.ServoMovement(taxutita,  90, 105,  90, 176,  90, 53);
  Braccio.ServoMovement(taxutita,  95, 140, 130, 168,  90, 53);
  Braccio.ServoMovement(taxutita,  95, 140, 130, 168,  90, 24);
  Braccio.ServoMovement(taxutita,  90,  80, 130, 171,  90, 24);
  orthiosBraxionas();
}

void valePouliSto_3G(const int taxutita) {
  Braccio.ServoMovement(taxutita,  75, 105,  90, 176,  90, 53);
  Braccio.ServoMovement(taxutita,  83, 141, 138, 163,  90, 53);
  Braccio.ServoMovement(taxutita,  83, 141, 138, 163,  90, 30);
  Braccio.ServoMovement(taxutita,  75,  80, 130, 169,  90, 30);
  orthiosBraxionas();
}

//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
// Μαζέματα πουλιών από πίστα
//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

void mazepseLeukoPouliApo_1A(const int taxutita) {
  Braccio.ServoMovement(taxutita, 118,   90, 150, 171,  90, 23); //πάει προς το Α1
  Braccio.ServoMovement(taxutita, 120,  106, 172, 173,  90, 24); //κατεβαζει προς το Α1
  Braccio.ServoMovement(taxutita, 120,  106, 172, 173,  90, 53); //αφηνει στο Α1
  Braccio.ServoMovement(taxutita, 118,   60, 175, 172,  90, 53);
  Braccio.ServoMovement(taxutita, 118,   90,  90,  90,  90, 53); //ανεβαίνει
  Braccio.ServoMovement(taxutita, 179,   90,  90,  90,  90, 53); //πάει στη βάσ
  Braccio.ServoMovement(taxutita, 179,  114, 130, 154,  90, 53);
  Braccio.ServoMovement(taxutita, 179,  114, 130, 154,  90, 35);
  orthiosBraxionas();
}

void mazepseMauroPouliApo_1A(const int taxutita) {
  Braccio.ServoMovement(taxutita, 118,   90, 150, 171,  90, 23); //πάει προς το Α1
  Braccio.ServoMovement(taxutita, 120,  106, 172, 173,  90, 24); //κατεβαζει προς το Α1
  Braccio.ServoMovement(taxutita, 120,  106, 172, 173,  90, 53); //αφηνει στο Α1
  Braccio.ServoMovement(taxutita, 118,   60, 175, 172,  90, 53);
  Braccio.ServoMovement(taxutita, 118,   90,  90,  90,  90, 53);
  Braccio.ServoMovement(taxutita,   1,   90,  90,  90,  90, 53);
  Braccio.ServoMovement(taxutita,   1,  114, 130, 150,  90, 53);
  Braccio.ServoMovement(taxutita,   1,  114, 130, 150,  90, 24);
  orthiosBraxionas();
}

void mazepseLeukoPouliApo_1B(const int taxutita) {
  Braccio.ServoMovement(taxutita,  94,  80,  90, 171,  90, 10);
  Braccio.ServoMovement(taxutita,  91, 101, 180, 173,  90, 28);
  Braccio.ServoMovement(taxutita,  91, 101, 180, 173,  90, 53);
  Braccio.ServoMovement(taxutita,  91,  80, 180, 170,  90, 53);
  Braccio.ServoMovement(taxutita,  91,  90,  90,  90,  90, 53);
  Braccio.ServoMovement(taxutita, 179,  90,  90,  90,  90, 53); //πάει στη βάσ
  Braccio.ServoMovement(taxutita, 179, 114, 130, 154,  90, 53);
  Braccio.ServoMovement(taxutita, 179, 114, 130, 154,  90, 35);
  orthiosBraxionas();
}

void mazepseMauroPouliApo_1B(const int taxutita) {
  Braccio.ServoMovement(taxutita,  94,  80,  90, 171,  90, 10);
  Braccio.ServoMovement(taxutita,  91, 101, 180, 173,  90, 28);
  Braccio.ServoMovement(taxutita,  91, 101, 180, 173,  90, 53);
  Braccio.ServoMovement(taxutita,  91,  80, 180, 170,  90, 53);
  Braccio.ServoMovement(taxutita,  91,  90,  90,  90,  90, 53);
  Braccio.ServoMovement(taxutita,   1,  90,  90,  90,  90, 53);
  Braccio.ServoMovement(taxutita,   1, 114, 130, 150,  90, 53);
  Braccio.ServoMovement(taxutita,   1, 114, 130, 150,  90, 24);
  orthiosBraxionas();
}

void mazepseLeukoPouliApo_1G(const int taxutita) {
  Braccio.ServoMovement(taxutita,  68, 108, 174, 174,  90, 24);
  Braccio.ServoMovement(taxutita,  68, 108, 174, 174,  90, 53);
  Braccio.ServoMovement(taxutita,  67,  90,  90,  90,  90, 53);
  Braccio.ServoMovement(taxutita, 179,  90,  90,  90,  90, 53); //πάει στη βάσ
  Braccio.ServoMovement(taxutita, 179, 114, 130, 154,  90, 53);
  Braccio.ServoMovement(taxutita, 179, 114, 130, 154,  90, 35);
  orthiosBraxionas();
}

void mazepseMauroPouliApo_1G(const int taxutita) {
  Braccio.ServoMovement(taxutita,  68, 108, 174, 174,  90, 24);
  Braccio.ServoMovement(taxutita,  68, 108, 174, 174,  90, 53);
  Braccio.ServoMovement(taxutita,  67,  90,  90,  90,  90, 53);
  Braccio.ServoMovement(taxutita,   1,   90,  90,  90,  90, 53);
  Braccio.ServoMovement(taxutita,   1,  114, 130, 150,  90, 53);
  Braccio.ServoMovement(taxutita,   1,  117, 130, 150,  90, 24);
  orthiosBraxionas();
}

void mazepseLeukoPouliApo_2A(const int taxutita) {
  Braccio.ServoMovement(taxutita, 115, 122, 155, 171,  90, 24);
  Braccio.ServoMovement(taxutita, 115, 122, 155, 171,  90, 50);
  Braccio.ServoMovement(taxutita, 115,  90,  90,  90,  90, 53);
  Braccio.ServoMovement(taxutita, 179,  90,  90,  90,  90, 53); //πάει στη βάσ
  Braccio.ServoMovement(taxutita, 179, 114, 130, 154,  90, 53);
  Braccio.ServoMovement(taxutita, 179, 114, 130, 154,  90, 35);
  orthiosBraxionas();
}

void mazepseMauroPouliApo_2A(const int taxutita) {
  orthiosBraxionas();
}

void mazepseLeukoPouliApo_2B(const int taxutita) {
  Braccio.ServoMovement(taxutita,  93, 120,  158, 171, 65, 24);
  Braccio.ServoMovement(taxutita,  93, 120,  158, 171, 65, 50);
  Braccio.ServoMovement(taxutita,  91,  90,  90,  90,  90, 50);
  Braccio.ServoMovement(taxutita, 179,  90,  90,  90,  90, 50); //πάει στη βάσ
  Braccio.ServoMovement(taxutita, 179, 114, 130, 154,  90, 50);
  Braccio.ServoMovement(taxutita, 179, 114, 130, 154,  90, 35);
  orthiosBraxionas();
}

void mazepseMauroPouliApo_2B(const int taxutita) {
  orthiosBraxionas();
}

void mazepseLeukoPouliApo_2G(const int taxutita) {
  Braccio.ServoMovement(taxutita,  75,  80, 140, 120,  90, 30);
  Braccio.ServoMovement(taxutita,  75, 125, 160, 174,  90, 30);
  Braccio.ServoMovement(taxutita,  75, 125, 160, 174,  90, 53);
  Braccio.ServoMovement(taxutita,  75, 100, 160, 160,  90, 53);
  Braccio.ServoMovement(taxutita, 179,  90,  90,  90,  90, 53); //πάει στη βάσ
  Braccio.ServoMovement(taxutita, 179, 114, 130, 154,  90, 53);
  Braccio.ServoMovement(taxutita, 179, 114, 130, 154,  90, 35);
  orthiosBraxionas();
}

void mazepseMauroPouliApo_2G(const int taxutita) {
  Braccio.ServoMovement(taxutita,  70, 120, 158, 170,  70, 24);
  Braccio.ServoMovement(taxutita,  70, 120, 158, 170,  70, 50);
  Braccio.ServoMovement(taxutita,  70,  90,  90,  90,  90, 53);
  Braccio.ServoMovement(taxutita,   1,  90,  90,  90,  90, 53);
  Braccio.ServoMovement(taxutita,   1, 117, 130, 150,  90, 53);
  Braccio.ServoMovement(taxutita,   1, 117, 130, 150,  90, 24);
  orthiosBraxionas();
}

void mazepseLeukoPouliApo_3A(const int taxutita) {
  Braccio.ServoMovement(taxutita, 111, 140, 134, 167,  90, 24);
  Braccio.ServoMovement(taxutita, 111, 140, 134, 167,  90, 50);
  Braccio.ServoMovement(taxutita, 179,  90,  90,  90,  90, 53); //πάει στη βάσ
  Braccio.ServoMovement(taxutita, 179, 114, 130, 154,  90, 53);
  Braccio.ServoMovement(taxutita, 179, 114, 130, 154,  90, 35);
  orthiosBraxionas();
}

void mazepseMauroPouliApo_3A(const int taxutita) {
  Braccio.ServoMovement(taxutita, 111, 140, 134, 170,  90, 24);
  Braccio.ServoMovement(taxutita, 111, 140, 134, 170,  90, 50);
  Braccio.ServoMovement(taxutita,   1,  90,  90,  90,  90, 53);
  Braccio.ServoMovement(taxutita,   1, 117, 130, 150,  90, 53);
  Braccio.ServoMovement(taxutita,   1, 117, 130, 150,  90, 24);
  orthiosBraxionas();
}

void mazepseLeukoPouliApo_3B(const int taxutita) {
  Braccio.ServoMovement(taxutita,  94, 142, 133, 171,  90, 24);
  Braccio.ServoMovement(taxutita,  94, 142, 133, 171,  90, 50);
  Braccio.ServoMovement(taxutita,  94, 130, 135, 160,  90, 50);
  Braccio.ServoMovement(taxutita, 179,  90,  90,  90,  90, 53); //πάει στη βάσ
  Braccio.ServoMovement(taxutita, 179, 114, 130, 154,  90, 53);
  Braccio.ServoMovement(taxutita, 179, 114, 130, 154,  90, 35);
  orthiosBraxionas();
}

void mazepseMauroPouliApo_3B(const int taxutita) {
  Braccio.ServoMovement(taxutita,  94, 142, 133, 171,  90, 24);
  Braccio.ServoMovement(taxutita,  94, 142, 133, 171,  90, 50);
  Braccio.ServoMovement(taxutita,  94, 130, 135, 160,  90, 50);
  Braccio.ServoMovement(taxutita,   1,  90,  90,  90,  90, 53);
  Braccio.ServoMovement(taxutita,   1, 117, 130, 150,  90, 53);
  Braccio.ServoMovement(taxutita,   1, 117, 130, 150,  90, 24);
  orthiosBraxionas();
}

void mazepseLeukoPouliApo_3G(const int taxutita) {
  Braccio.ServoMovement(taxutita,  78, 140, 133, 168,  90, 24);
  Braccio.ServoMovement(taxutita,  78, 140, 135, 168,  90, 50);
  Braccio.ServoMovement(taxutita,  78,  90,  90,  90,  90, 53);
  Braccio.ServoMovement(taxutita, 179,  90,  90,  90,  90, 53); //πάει στη βάσ
  Braccio.ServoMovement(taxutita, 179, 114, 130, 154,  90, 53);
  Braccio.ServoMovement(taxutita, 179, 114, 130, 154,  90, 35);
  orthiosBraxionas();
}

void mazepseMauroPouliApo_3G(const int taxutita) {
  Braccio.ServoMovement(taxutita,  78, 140, 133, 172,  90, 24);
  Braccio.ServoMovement(taxutita,  78, 140, 135, 169,  90, 50);
  Braccio.ServoMovement(taxutita,  78,  90,  90,  90,  90, 53);
  Braccio.ServoMovement(taxutita,   1,  90,  90,  90,  90, 53);
  Braccio.ServoMovement(taxutita,   1, 117, 130, 150,  90, 53);
  Braccio.ServoMovement(taxutita,   1, 117, 130, 150,  90, 50);
  orthiosBraxionas();
}

//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
// Υπόδειξη νικητήριας στήλης κινήσεις
//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

void ypodiksiTrilizasGrammi1(const int taxutita) {
  Braccio.ServoMovement(taxutita, 120,  90, 175, 180,  90, 53);
  Braccio.ServoMovement(taxutita,  91,  90, 170, 180,  90, 53);
  Braccio.ServoMovement(taxutita,  60,  80, 180, 170,  90, 53);
  delay(1000);
  orthiosBraxionas();
}

void ypodiksiTrilizasGrammi2(const int taxutita) {
  Braccio.ServoMovement(taxutita, 109, 120, 140, 180,  90, 53);
  Braccio.ServoMovement(taxutita,  91, 115, 140, 180,  90, 53);
  Braccio.ServoMovement(taxutita,  70, 120, 140, 180,  90, 53);
  delay(1000);
  orthiosBraxionas();
}

void ypodiksiTrilizasGrammi3(const int taxutita) {
  Braccio.ServoMovement(taxutita, 108, 140, 120, 170,  90, 53);
  Braccio.ServoMovement(taxutita,  91, 130, 130, 170,  90, 53);
  Braccio.ServoMovement(taxutita,  74, 132, 130, 165,  90, 53);
  delay(1000);
  orthiosBraxionas();
}

void ypodiksiTrilizasStili1(const int taxutita) {
  Braccio.ServoMovement(taxutita, 120,  90, 175, 180,  90, 53);
  Braccio.ServoMovement(taxutita, 109, 120, 140, 180,  90, 53);
  Braccio.ServoMovement(taxutita, 105, 140, 120, 160,  90, 53);
  delay(1000);
  orthiosBraxionas();
}

void ypodiksiTrilizasStili2(const int taxutita) {
  Braccio.ServoMovement(taxutita,  91,  90, 170, 180,  90, 53);
  Braccio.ServoMovement(taxutita,  91, 115, 140, 180,  90, 53);
  Braccio.ServoMovement(taxutita,  91, 130, 130, 160,  90, 53);
  delay(1000);
  orthiosBraxionas();
}

void ypodiksiTrilizasStili3(const int taxutita) {
  Braccio.ServoMovement(taxutita,  60,  80, 180, 170,  90, 53);
  Braccio.ServoMovement(taxutita,  75, 120, 140, 180,  90, 53);
  Braccio.ServoMovement(taxutita,  78, 130, 130, 160,  90, 53);
  delay(1000);
  orthiosBraxionas();
}

void ypodiksiTrilizasDiagonio(const int taxutita) {
  Braccio.ServoMovement(taxutita, 120,  90, 175, 180,  90, 53);
  Braccio.ServoMovement(taxutita,  91, 115, 140, 180,  90, 53);
  Braccio.ServoMovement(taxutita,  74, 132, 130, 165,  90, 53);
  delay(1000);
  orthiosBraxionas();
}

void ypodiksiTrilizasAntidiagonio(const int taxutita) {
  Braccio.ServoMovement(taxutita,  60,  80, 180, 170,  90, 53);
  Braccio.ServoMovement(taxutita,  91, 115, 140, 180,  90, 53);
  Braccio.ServoMovement(taxutita, 108, 140, 120, 170,  90, 53);
  delay(1000);
  orthiosBraxionas();
}

//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
// Δοκιμές όλων των δυνατών μεταφορών πουλιών προς/από πίστα
//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

void aploseOlaTaLeyka(const int taxutita) {
  parePouliApoGlistra(taxutita, leuko);
  valePouliSto_1A(taxutita);
  parePouliApoGlistra(taxutita, leuko);
  valePouliSto_1B(taxutita);
  parePouliApoGlistra(taxutita, leuko);
  valePouliSto_1G(taxutita);
  parePouliApoGlistra(taxutita, leuko);
  valePouliSto_2A(taxutita);
  parePouliApoGlistra(taxutita, leuko);
  valePouliSto_2B(taxutita);
  parePouliApoGlistra(taxutita, leuko);
  valePouliSto_2G(taxutita);
  parePouliApoGlistra(taxutita, leuko);
  valePouliSto_3A(taxutita);
  parePouliApoGlistra(taxutita, leuko);
  valePouliSto_3B(taxutita);
  parePouliApoGlistra(taxutita, leuko);
  valePouliSto_3G(taxutita);
}

void aploseOlaTaMaura(const int taxutita) {
  parePouliApoGlistra(taxutita, mauro);
  valePouliSto_1A(taxutita);
  parePouliApoGlistra(taxutita, mauro);
  valePouliSto_1B(taxutita);
  parePouliApoGlistra(taxutita, mauro);
  valePouliSto_1G(taxutita);
  parePouliApoGlistra(taxutita, mauro);
  valePouliSto_2A(taxutita);
  parePouliApoGlistra(taxutita, mauro);
  valePouliSto_2B(taxutita);
  parePouliApoGlistra(taxutita, mauro);
  valePouliSto_2G(taxutita);
  parePouliApoGlistra(taxutita, mauro);
  valePouliSto_3A(taxutita);
  parePouliApoGlistra(taxutita, mauro);
  valePouliSto_3B(taxutita);
  parePouliApoGlistra(taxutita, mauro);
  valePouliSto_3G(taxutita);
}

void mazepseOlaTaLeyka(const int taxutita) {
  mazepseLeukoPouliApo_1A(taxutita);
  mazepseLeukoPouliApo_1B(taxutita);
  mazepseLeukoPouliApo_1G(taxutita);
  mazepseLeukoPouliApo_2A(taxutita);
  mazepseLeukoPouliApo_2B(taxutita);
  mazepseLeukoPouliApo_2G(taxutita);
  mazepseLeukoPouliApo_3A(taxutita);
  mazepseLeukoPouliApo_3B(taxutita);
  mazepseLeukoPouliApo_3G(taxutita);
}

void mazepseOlaTaMaura(const int taxutita) {
  mazepseMauroPouliApo_1A(taxutita);
  mazepseMauroPouliApo_1B(taxutita);
  mazepseMauroPouliApo_1G(taxutita);
  mazepseMauroPouliApo_2A(taxutita);
  mazepseMauroPouliApo_2B(taxutita);
  mazepseMauroPouliApo_2G(taxutita);
  mazepseMauroPouliApo_3A(taxutita);
  mazepseMauroPouliApo_3B(taxutita);
  mazepseMauroPouliApo_3G(taxutita);
}

void YpodiksiNikitriasTrilizas(const int taxutita) {
  ypodiksiTrilizasStili1(taxutita);
  ypodiksiTrilizasStili2(taxutita);
  ypodiksiTrilizasStili3(taxutita);
  ypodiksiTrilizasGrammi1(taxutita);
  ypodiksiTrilizasGrammi2(taxutita);
  ypodiksiTrilizasGrammi3(taxutita);
  ypodiksiTrilizasDiagonio(taxutita);
  ypodiksiTrilizasAntidiagonio(taxutita);
}

//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
// Χαιρετισμοί
//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

void xairetismosEnarksis(const int taxutita) {
  for (auto i = 1; i <= 2; ++i) {
    Braccio.ServoMovement(taxutita,  90, 90, 90, 90, 180, 35);
    Braccio.ServoMovement(taxutita,  90, 90, 90, 90,   0, 35);
  }
  Braccio.ServoMovement(taxutita,  90, 90, 90, 90,  90, 55);
}

void xairetismosNikis(const int taxutita) {
  Braccio.ServoMovement(17,  180,  90,   90,   90, 180, 60);
  Braccio.ServoMovement(17,  180,  90,  120,   90, 180, 60);
  Braccio.ServoMovement(17,  180,  60,  150,   60, 180, 20);
  Braccio.ServoMovement(17,  180,  60,  120,   60, 180, 20);
  Braccio.ServoMovement(17,  180, 120,   30,  130, 180, 60);
  Braccio.ServoMovement(17,  180,  60,  120,   60, 180, 60);
  Braccio.ServoMovement(17,  180, 120,   30,  130, 180, 20);
  orthiosBraxionas();
}

void xairetismosHttas(const int taxutita) {
  Braccio.ServoMovement(taxutita,  90, 90, 140, 90, 90, 50);
  delay(300);
  Braccio.ServoMovement(taxutita,  90, 90, 170, 170, 90, 50);
  delay(4000);
  orthiosBraxionas();
}

void xairetismosIsopalias(const int taxutita) {
  Braccio.ServoMovement(taxutita,  90, 90, 180, 85,  90, 50);
  Braccio.ServoMovement(taxutita,  90, 90, 180, 85, 180, 30);
  Braccio.ServoMovement(taxutita,  90, 90, 170, 85, 180, 30);
  Braccio.ServoMovement(taxutita,  90, 90, 180, 85, 180, 30);
  Braccio.ServoMovement(taxutita,  90, 90, 170, 85, 180, 30);
  Braccio.ServoMovement(taxutita,  90, 90, 180, 85, 180, 30);
  Braccio.ServoMovement(taxutita,  90, 90, 170, 85, 180, 30);
  Braccio.ServoMovement(taxutita,  90, 90, 180, 85, 180, 30);
  Braccio.ServoMovement(taxutita,  90, 90, 170, 85, 180, 30);
  Braccio.ServoMovement(taxutita,  90, 90, 180, 85, 180, 30);
  Braccio.ServoMovement(taxutita,  90, 90, 170, 85, 180, 30);
  Braccio.ServoMovement(taxutita,  90, 90, 180, 85, 180, 30);
  delay(500);
  orthiosBraxionas();
}
