# Robotri
![Arduino](https://res-1.cloudinary.com/crunchbase-production/image/upload/c_lpad,h_120,w_120,f_auto,b_white,q_auto:eco/v1397183645/50bf4fee6f1194cbd5064a4342c4ab75.png "Logo1") 
![Arduino](http://www.i2clipart.com/cliparts/1/4/8/7/clipart-open-source-harware-logo-1487.png "Logo2")
![Arduino](https://dl.myket.ir/newresizing/resize/medium/png/icon/com.starktech.cpf_arm_fcb4e631-1b58-497c-97ab-d8c80cfe7f9f_.png "Logo3")
![Arduino](https://github.com/amachg/Robotri/blob/master/τρίλιζα.png "Logo4")

### Ρομποτική Τρίλιζα  
Στόχος της ομάδας ρομποτικής του σχολείου μας είναι:
1. Η συναρμολόγηση ενός κιτ **ρομποτικού βραχίονα**, ανοικτού υλικού συμβατού με *arduino*, με πέντε βαθμούς ελευθερίας. Ο βραχίονας θα πρέπει να μπορεί να ανασηκώνει και να μετακινεί ελαφρά αντικείμενα μερικών εκατοντάδων γραμμαρίων σε ακτίνα μερικών δεκάδων εκατοστών. Ο βραχίονας θα είναι αρθρωτός και θα φέρει στο άκρο του μηχανισμό αρπάγης (δαγκάνα) για να μετακινεί πούλια σε τυπωμένη πίστα τρίλιζας.
Εναλλακτικά, να γράφει τα σημεία της τρίλιζας με μαρκαδόρο στο χαρτί.
2. Η κατασκευή από μακετόχαρτο δύο *τροφοδοτών* (γλίστρες) ώστε να μπορεί το ρομπότ να βρίσκει εύκολα τα πούλια και μιας ξύλινης βάσης από μοριοσανίδα στη οποία θα βιδωθεί η βάση του ρομπότ για την εξασφάλιση της σταθερότητας του βραχίονα όταν είναι σε κλίση.
3. Η σύνδεση ενός *μικροελεγκτή* arduino στον ρομποτικό βραχίονα, μέσω ειδικής πλακέτας (motor shield), για τον έλεγχο των σερβοκινητήρων του.
4. Η σύνδεση του μικροελεγκτή σε ένα υπολογιστή PC, ενσύρματα μέσω USB, ώστε να λαμβάνει εντολές και δεδομένα από τον χρήστη-παίκτη μέσω πληκτρολογίου.
5. Η ανάπτυξη *προγράμματος* (sketch), σε γλώσσα arduino processing (C++), ώστε ο μικροελεγκτής να μπορεί να κατευθύνει τον βραχίονα στις σωστές θέσεις της πίστας.
---
#### Επεκτάσεις:
1. Ανεξαρτητοποίηση από το PC, για την επικοινωνία με τον χρήστη, με πληκτρολόγιο μεμβράνης ή πιεζοηλεκτρικούς αισθητήρες επαφής (piezo knock sensors) και οθόνη LED στην οποία θα εμφανίζονται τα μηνύματα του παιχνιδιού,
2.  Αυτονόμηση της κατασκευής από τη τροφοδοσία ρεύματος, με χρήση επαναφορτιζόμενων μπαταριών από λάπτοπ,
3. Η προσθήκη τεχνητής ευφυΐας (AI), ώστε να μπορεί να εκτιμά την τρέχουσα κατάσταση του παιχνιδιού και να διαλέγει την προσφορότερη κίνηση του ρομπότ και τελικά να μην χάνει ποτέ από έναν άνθρωπο.
4. Αυτονόμηση της κατασκευής από το καλώδιο USB με ασύρματη (bluetooth) σύνδεση με τον υπολογιστή,
5. Αναγνώριση της εικόνας της πίστας και των αντικειμένων του παιχνιδιού, μέσω κάμερας, με το λογισμικό OpenCV.
---
#### Υπάρχοντα υλικά & εργαλεία:
Ρομποτικός βραχίονας [Arduino Braccio](https://store.arduino.cc/braccio-bundle) (είχε αγοραστεί πέρσι 155€),
σχολικό PC, ανακυκλωμένη κάμερα web, καλώδιο USB, μινι-δράπανο, πιστόλι θερμής κόλλησης, ηλεκτρικό κολλητήρι, ανακυκλωμένη επαναφορτιζόμενες μπαταρίες λιθίου (από πεταμένο λάπτοπ), φορτιστής μπαταριών.

#### Υλικά προς αγορά:
* [Arduino MEGA ADK Rev3](https://grobotronics.com/arduino-mega-2560-adk-rev3.html), €53.90
* [Arduino Box](https://grobotronics.com/arduino-box.html), 7,90€
* [Led Matrix 8x8 Red with MAX7219](https://grobotronics.com/led-matrix-8x8-red-with-max7219.html), 3,90€
* [Bluetooth Module for Arduino - HM10](https://grobotronics.com/bluetooth-module-for-arduino-hm-10.html), €12.90
* [Display 1.5" RGB 128x128 OLED Module](https://grobotronics.com/display-1.5-rgb-128x128-oled-module.html), €18.90
* [x9 Πιεζοηλεκτρικός Μετατροπέας Ήχου](https://grobotronics.com/piezo-without-built-in-generator.html), 9 x 0.80 = 7,20€
* [x2 Αισθητήρας Αφής (Capacitive)](https://grobotronics.com/capacitve-touch-sensor-switch-module.html), 2 x €1.50 = 3€
* [Sealed Membrane 3X4 Button Pad with Sticker](https://grobotronics.com/sealed-membrane-3x4-button-pad-with-sticker.html), €1.50
* [Ribbon 40wire 20cm - Female to Μale](https://grobotronics.com/ribbon-40wire-20cm-female-to-ale.html), 3.60€
* [x3 Μπαταριοθήκη 3x18650 - με Καλώδια](https://grobotronics.com/3x18650-wire-leads.html), 3 x €1.50 = 4,5€
* [Resistor Kit - 1/4W](https://grobotronics.com/resistor-kit-1-4w-500-total.html), €9.50
* [Πλακέτα Δοκιμών Mini - Διαφανής](https://grobotronics.com/breadboard-mini-translucent.html), €1.60
* [Ισοπροπυλική Αλκοόλη 100ml](https://grobotronics.com/100ml-ag-termopasty.html), 2,50€
* [Πολύμετρο Ψηφιακό UNI-T UT132D](https://grobotronics.com/digital-multimeter-ut132d-uni-t.html), €21.90
* [Βάση Στήριξης Πλακετών Universal](https://grobotronics.com/universal-pcb-holder.html), 5.90€
* [Tweezer 165mm - Self-Gripping](https://grobotronics.com/tweezer-165mm-self-gripping-proskit-1pk-108t.html), 3,50€
* [Flux Liquid 25ml Rosin-Free](https://grobotronics.com/flux-liquid-25ml-rosin-free.html), €2.99
* [Κόφτης Μικρός](https://grobotronics.com/pk-21.html), €14.90
* [Κουτί Αποθήκευσης Δύο Στρωμάτων 233x161x58mm](https://grobotronics.com/storage-box-double-layer-233x161x58mm.html), €4.90
* [Χαρτόνι Μακέτας 50Χ70εκ./10mm](https://www.plaisio.gr/zografiki-diy/maketa/xartonia/Neofoam-Paper-Board-50x70cm-10mm-10MM-50X70.htm), 4,99€
* [Μοριοσανίδα-MDF Hardboard 35x50cm](https://www.plaisio.gr/zografiki-diy/sxedio/ylika-sxediasis/White-Box-Hardboard-35-X-50-from-Mdf.htm), 1,89€

Κόστος υλικών: 180€

[Τρόπος κατασκευής με φωτογραφίες και βίντεο λειτουργίας](https://robotics.ellak.gr/robotics_participant/rompotiki-triliza-omada-robotri-7-gimnasio-chaidariou/)

---

##### Άδεια χρήσης

Παρακάλω δείτε το αρχείο [LICENSE](https://github.com/amachg/Robotri/blob/master/LICENSE)

---

##### Επαφή

Instagram: [@robot7gymchai](https://www.instagram.com/robot7gymchai/)

email: amach@sch.gr

Ιστοχώρος 7ου Γυμνάσιο Χαϊδαρίου: http://7gym-chaid.att.sch.gr

##### Robotics Club του σχολείου:

* Πετρουλάκης :smirk:
* Φελέσκουρας :disappointed_relieved:
* Παπαδόπουλος :smiley:
* Νικολακόπουλος :relaxed:
* Ανατόλας :smiley:
* Χριστοπούλου :girl:
* Περγαντής :relieved:
* Ψαρράς :flushed:
