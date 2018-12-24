# Robotri
![Arduino](https://res-1.cloudinary.com/crunchbase-production/image/upload/c_lpad,h_120,w_120,f_auto,b_white,q_auto:eco/v1397183645/50bf4fee6f1194cbd5064a4342c4ab75.png "Logo1") 
![Arduino](http://www.i2clipart.com/cliparts/1/4/8/7/clipart-open-source-harware-logo-1487.png "Logo2")
![Arduino](https://dl.myket.ir/newresizing/resize/medium/png/icon/com.starktech.cpf_arm_fcb4e631-1b58-497c-97ab-d8c80cfe7f9f_.png "Logo3")

### Ρομποτική Τρίλιζα  
Στόχος της ομάδας ρομποτικής του σχολείου μας είναι:
1. Η συναρμολόγηση ενός κιτ **ρομποτικού βραχίονα**, ανοικτού υλικού συμβατού με *arduino*, με πέντε βαθμούς ελευθερίας. Ο βραχίονας θα πρέπει να μπορεί να ανασηκώνει και να μετακινεί ελαφρά αντικείμενα μερικών εκατοντάδων γραμμαρίων σε ακτίνα μερικών δεκάδων εκατοστών. Ο βραχίονας θα είναι αρθρωτός και θα φέρει στο άκρο του μηχανισμό αρπάγης (δαγκάνα) για να μετακινεί πούλια σε τυπωμένη πίστα τρίλιζας.
Εναλλακτικά, να γράφει τα σημεία της τρίλιζας με μαρκαδόρο στο χαρτί.
2. Η κατασκευή από μακετόχαρτο δύο *τροφοδοτών* (γλίστρες) ώστε να μπορεί το ρομπότ να βρίσκει εύκολα τα πούλια και μιας ξύλινης βάσης από μοριοσανίδα στη οποία θα βιδωθεί η βάση του ρομπότ για την εξασφάλιση της σταθερότητας του βραχίονα όταν είναι σε κλίση.
3. Η σύνδεση ενός *μικροελεγκτή arduino* στον ρομποτικό βραχίονα, μέσω ειδικής πλακέτας (motor shield), για τον έλεγχο των σερβοκινητήρων του.
4. Η σύνδεση του μικροελεγκτή σε ένα υπολογιστή PC, ενσύρματα μέσω USB, ώστε να λαμβάνει εντολές και δεδομένα από τον χρήστη-παίκτη μέσω πληκτρολογίου.
5. Η ανάπτυξη *προγράμματος*, σε γλώσσα arduino sketch (C++), ώστε ο μικροελεγκτής να μπορεί να κατευθύνει τον βραχίονα στις σωστές θέσεις της πίστας.
---
#### Επεκτάσεις:
1. Η προσθήκη τεχνητής ευφυΐας (AI) ώστε να μπορεί να εκτιμά την τρέχουσα κατάσταση του παιχνιδιού και να διαλέγει την προσφορότερη κίνηση του ρομπότ και τελικά να μην χάνει ποτέ από έναν άνθρωπο.
2. Αυτονόμηση της κατασκευής από το καλώδιο USB με ασύρματη (bluetooth) σύνδεση με τον υπολογιστή,
3. Αυτονόμηση της κατασκευής από τη τροφοδοσία ρεύματος, με χρήση επαναφορτιζόμενων μπαταριών,
4. Ανεξαρτητοποίηση από το PC και το πληκτρολόγιο για την είσοδο της κατάστασης του παιχνιδιού, με αισθητήρες μαγνητικού πεδίου (hall effect ή reed) ή πιεζοηλεκρικούς επαφής (piezo element, tap, knock) και οθόνης στην οποία θα εμφανίζονται μηνύματα του παιχιδιού,
5. Αναγνώριση εικόνας (προτύπων) πίστας-αντικειμένων του παιχνιδιού, μέσω κάμερας με το λογισμικό OpenCV.
---
#### Υπάρχοντα υλικά & εργαλεία:
Ρομποτικός βραχίονας [Arduino Braccio](https://store.arduino.cc/tinkerkit-braccio) (είχε αγοραστεί πέρσι 155€),
σχολικό PC, πεταμένη κάμερα web, καλώδιο USB, μινι-δράπανο, πιστόλι θερμής κόλλησης, ηλεκτρικό κολλητήρι, επαναφορτιζόμενες μπαταρίες λιθίου (από πεταμένο λάπτοπ), φορτιστής μπαταριών.

#### Υλικά προς αγορά:
* Arduino MEGA ADK Rev3
* Κουτί για Arduino MEGA
* ESP32 ESP-32S Development Board
* Display 1.5" RGB 128x128 OLED Module ή 2.8" TFT LCD Touchscreen w/MicroSD
* Dot Matrix Display MAX7219 Module
* x9 Πιεζοηλεκτρικός Μετατροπέας Ήχου
* x2 Αισθητήρας Αφής (Capacitive)
* Καλώδια Dupont Jumper Wires 20cm
* Μπαταριοθήκη 4x18650, με Καλώδια
* Θερμοσυστελλόμενο 9.5mm Μαύρο, 1 μέτρο
* Ισοπροπυλική Αλκοόλη 
* Μοριοσανίδα 60x60x1 εκ.
* Μακετόχαρτο 60x60 εκ.
* Πολύμετρο Ψηφιακό
* Βάση Στήριξης Πλακετών
* Τρόμπα Αποκόλλησης
* Flux Liquid 25ml Rosin-Free
* Heat-resistant Silicone Soldering Pad
* Σετ Κατσαβίδια Ακριβείας
* Toolcraft 816745 Κοφτάκι 125mm πλάγιο
* Τρυπανάκια 0.4 mm - 1 mm 
* Πλαστικό Κουτί Οργάνωσης
#### Κόστος υλικών: 186€
