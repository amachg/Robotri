// Αρχείο Triliza.ino με το ΑΙ του παιχνιδιού και το Ι/Ο με τους χρήστες

//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
// Επιτραπέζιο παιχνίδι Τρίλιζας για ρομποτικό βραχίονα Arduino Braccio
// Γλώσσα προγραμματισμού C++11 (χωρίς STL και streams)
//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

#include "Braxionas.h"      // Οι κινήσεις (άπλωμα-μάζεμα) πουλιών από τον βραχίονα
#include "Pliktrologio.h"   // Ανάγνωση κινήσεων από το Πληκτρολόγιο Μεμβράνης
#include "8x8LED.h"

//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
// Παιχνίδι Τρίλιζας
//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

using Thetikos = uint8_t;         // θετικός ακέραιος
constexpr Thetikos megethos{ 3 }; // Το μέγεθος της πλευράς της τετράγωνης τρίλιζας
constexpr Thetikos plithosKoutakiaPistas{ megethos * megethos };

//+++++Thesi+++++++Symbolo+++++Paiksimo++++++++++Koutaki++++++++++++++++++

struct Thesi {  // Η θέση στη πίστα της τρίλιζας
  Thetikos grammi, stili;   // πραγματικοί αριθμοί θέσης, δηλ. 1 έως 3
  Thesi() : grammi{ 0 }, stili{ 0 } {}
  Thesi(const Thetikos g, const Thetikos s) : grammi{ g }, stili{ s } {}
	bool operator!=(const Thesi th) const {
		return grammi != th.grammi || stili != th.stili; }

	// Το σύμβολο πέφτει στη διαγώνιο της πίστας;
	bool stiDiagonio() const { return grammi == stili; }
	// Το σύμβολο πέφτει στην αντιδιαγώνιο της πίστας;
	bool stinAntidiagonio() const { return grammi + stili == megethos + 1; }
};

// Τα σύμβολα της τρίλιζας

enum struct Symbolo : char {
  Keno    = ' ',
  Omikron = 'O',
  Xi      = 'X'
};

Symbolo antipaloSymbolo(const Symbolo symbolo) {
	return symbolo == Symbolo::Xi ? Symbolo::Omikron : Symbolo::Xi;
}

// Παίξιμο είναι η τοποθέτηση ενός συμβόλου στην πίστα.

struct Paiksimo {
  Thesi thesi;
  Symbolo symbolo;
};

// Κουτάκι της πίστας. Χρειάζεται μόνο σε arduino λόγω της callback του βραχίονα.

struct Koutaki {
  Symbolo symbolo;  
  // Συνάρτηση ανάκλησης (callback) με την οποία ο βραχίονας φέρνει το πούλι στο κουτάκι της πίστας.
  void (*valePouli)(int taxutita);
};

//+++++++++++++++++++++++++++++Pista+++++++++++++++++++++++++++++++++++++++++

// Η πίστα της τρίλιζας σε γραμμές και στήλες με εσωτερικούς αριθμούς θέσης, δηλ. 0 έως 2.
// Σε κάθε πρόσβαση αφαιρείται μια μονάδα από τους πραγματικούς αριθμούς θέσης.

class Pista {
  Koutaki koutakia[megethos][megethos] {
    { {Symbolo::Keno, &valePouliSto_1A}, {Symbolo::Keno, &valePouliSto_1B}, {Symbolo::Keno, &valePouliSto_1G} },
    { {Symbolo::Keno, &valePouliSto_2A}, {Symbolo::Keno, &valePouliSto_2B}, {Symbolo::Keno, &valePouliSto_2G} },
    { {Symbolo::Keno, &valePouliSto_3A}, {Symbolo::Keno, &valePouliSto_3B}, {Symbolo::Keno, &valePouliSto_3G} }};
public:
	Thetikos ypoloipaKena{ plithosKoutakiaPistas };
	void paikse(const Paiksimo paiksimo);			      	// παίξε το παίξιμο
	void ksepaikse(const Thesi thesi);					      // ακύρωσε το παίξιμο
	bool gemise() const { return ypoloipaKena == 0; }	// Αποφάσισε αν γέμισε η πίστα.	
	bool einaiKeniThesi(const Thesi thesi) const;     // Αποφάσισε αν υπάρχει κενό κουτάκι στη θέση.
  
  bool exeiToSymboloStiThesi(const Symbolo symbolo, const Thesi thesi) const;

  // Αποφάσισε αν έχει ήδη γίνει τρίλιζα. Το τελευταίο παίξιμο χρειάζεται για λιγότερους ελέγχους.
  Thetikos exeiGineiTrilizaMeTo(const Paiksimo teleytaioPaiksimo) const;
  void sxediaseStiSeiriaki() const;             // Σχεδίασε την πίστα στο σειριακή θύρα για να την δει ο χρήστης.

  // Δοκίμασε μήπως γίνεται τρίλιζα συμπληρώνοντας κάθε κενό πλαίσιο
  // με το σύμβολο και επίστρεψε το σωστό παίξιμο, αλλιώς μηδενικό παίξιμο.
	Thesi vresPithaniTriliza(const Symbolo symbolo);
	Thesi vresKeniThesi() const;       // Διάλεξε τυχαία μια από τις κενές θέσεις.
	Thesi vresApenanti_H_KeniGonia(const Symbolo symbolo) const;

  // φέρε το παιγμένο πούλι στο ανάλογο πραγματικό πλαίσιο
  void vraxionasPaizeiPouli(const Paiksimo teleytaioPaiksimo) const;
};

void Pista::paikse(const Paiksimo paiksimo) {
  // Βάλε το παιγμένο σύμβολο στο ανάλογο κουτάκι. Προϋπόθεση είναι να είναι η θέση κενή.
  koutakia[paiksimo.thesi.grammi - 1][paiksimo.thesi.stili - 1].symbolo = paiksimo.symbolo;
  --ypoloipaKena;
}

void Pista::ksepaikse(const Thesi thesi) {
	// Κάνε κενό το ανάλογο κουτάκι. Προϋπόθεση είναι να είναι η θέση γεμάτη.
	koutakia[thesi.grammi - 1][thesi.stili - 1].symbolo = Symbolo::Keno;
	++ypoloipaKena;
}

bool Pista::einaiKeniThesi(const Thesi thesi) const {
  return koutakia[thesi.grammi - 1][thesi.stili - 1].symbolo == Symbolo::Keno;
}

bool Pista::exeiToSymboloStiThesi(const Symbolo symbolo, const Thesi thesi) const {
  return koutakia[thesi.grammi - 1][thesi.stili - 1].symbolo == symbolo;
}

Thetikos Pista::exeiGineiTrilizaMeTo(const Paiksimo teleytaioPaiksimo) const {
  const Thetikos grammi{teleytaioPaiksimo.thesi.grammi};
  const Thetikos stili{teleytaioPaiksimo.thesi.stili};
  const Symbolo symbolo{teleytaioPaiksimo.symbolo};

  auto j {0};                              // έλεγξε τη γραμμή του παιξίματος για όμοια σύμβολα
  for (; j < megethos; ++j)
    if (koutakia[grammi - 1][j].symbolo != symbolo)
      break;
  if (j == megethos)
		return grammi;  // τρίλιζα στη γραμμή του παιξίματος, κωδικός: 1, 2, 3

  auto i {0};                              // έλεγξε τη στήλη του παιξίματος για όμοια σύμβολα
  for (; i < megethos; ++i)
    if (koutakia[i][stili - 1].symbolo != symbolo)
      break;
  if (i == megethos)
		return stili + 3;  // τρίλιζα στη στήλη του παιξίματος, κωδικός: 4, 5, 6

  if (teleytaioPaiksimo.thesi.stiDiagonio()) {    // αν πέφτει στη διαγώνιο, έλεγξέ τη για όμοια σύμβολα
    for (i = 0; i < megethos; ++i)
      if (koutakia[i][i].symbolo != symbolo)
        break;
    if (i == megethos)
			return 7;  // τρίλιζα στη διαγώνιο, κωδικός: 7
  }

  if (teleytaioPaiksimo.thesi.stinAntidiagonio()) {// αν πέφτει στην αντιδιαγώνιο, έλεγξέ τη για όμοια σύμβολα
    for (i = 0; i < megethos; ++i)
      if (koutakia[i][(megethos - 1) - i].symbolo != symbolo)
        break;
    if (i == megethos)
			return 8;           // τρίλιζα στην αντιδιαγώνιο, κωδικός: 8
  }

  return false;           // δεν έχει γίνει τρίλιζα
}

void Pista::sxediaseStiSeiriaki() const {
	for (auto i = 1; i <= megethos; ++i)
    Serial.print(String("   ") + i);
  Serial.println("");

  Serial.println(" |");
	for (auto i = 1; i <= megethos; ++i)
    Serial.print("---+");
  Serial.println("");
  
  for (auto i = 0; i < megethos; ++i) {
    Serial.print(i + 1);
    for (auto j = 0; j < megethos; ++j)
      Serial.print(String("| ") + static_cast<char>(koutakia[i][j].symbolo) + " ");
    Serial.println("|");
		for (auto i = 1; i <= megethos; ++i)
      Serial.print("---+");
    Serial.println("");
  }
  Serial.println("");
}

Thesi Pista::vresPithaniTriliza(const Symbolo symbolo) {
	// Σε κάθε κενό κουτάκι δοκίμασε αν γίνεται τρίλιζα με το σύμβολο.
	for (Thetikos grammi{ 1 }; grammi <= megethos; ++grammi)
		for (Thetikos stili{ 1 }; stili <= megethos; ++stili) {
			const Thesi thesi{ grammi, stili };
			if (einaiKeniThesi(thesi)) {
				paikse({thesi, symbolo});		// Προσωρινά παίξε το σύμβολο
				const auto vrethike = exeiGineiTrilizaMeTo({ thesi, symbolo });
				ksepaikse(thesi);				// ξαναβάλε το κενό στη θέση του
				if (vrethike)
					return thesi;               // επιστρέφει την θέση που κάνει τρίλιζα
			}
		}
	return { 0, 0 }; // Το σύμβολο δεν κάνει τρίλιζα σε κανένα κενό κουτάκι, επίστρεψε άκυρη θέση.
}

Thesi Pista::vresKeniThesi() const {
	Thesi kenesTheseis[plithosKoutakiaPistas];    // λίστα των κενών θέσεων της πίστας
	Thetikos plithosKenon{ 0 };
	for (Thetikos grammi{ 1 }; grammi <= megethos; ++grammi)
		for (Thetikos stili{ 1 }; stili <= megethos; ++stili) {
			const Thesi thesi{ grammi, stili };
			if (einaiKeniThesi(thesi))
				kenesTheseis[plithosKenon++] = thesi;     // αποθήκευσε την κενή θέση
		}

	if (plithosKenon > 0)							// υπάρχουν κενές θέσεις διάλεξε μια,
		return kenesTheseis[rand() % plithosKenon];	// τυχαία από 0 έως ypoloipaKena-1, εναλλακτικά random(ypoloipaKena)
	else
		return { 0, 0 };							// Δε βρέθηκε κενή θέση, επίστρεψε άκυρη θέση.
}

Thesi Pista::vresApenanti_H_KeniGonia(const Symbolo symbolo) const {
	// Ψάξε πρώτα για κενή γωνία απέναντι από το δικό σου σύμβολο.
	Thesi thesi{ 1u, 1u };
	if (einaiKeniThesi(thesi) && exeiToSymboloStiThesi(symbolo, thesi))
		return thesi;
	thesi = { 1u, 3u };
	if (einaiKeniThesi(thesi) && exeiToSymboloStiThesi(symbolo, thesi))
		return thesi;
	thesi = { 3u, 1u };
	if (einaiKeniThesi(thesi) && exeiToSymboloStiThesi(symbolo, thesi))
		return thesi;
	thesi = { 3u, 3u };
	if (einaiKeniThesi(thesi) && exeiToSymboloStiThesi(symbolo, thesi))
		return thesi;

	Thesi kenesTheseis[4];				// Σχημάτισε μια λίστα όλων των κενών γωνιών της πίστας.
	auto plithosKenonGonion{ 0 };
	thesi = { 1u, 1u };
	if (einaiKeniThesi(thesi))
		kenesTheseis[plithosKenonGonion++] = thesi;
	thesi = { 1u, 3u };
	if (einaiKeniThesi(thesi))
		kenesTheseis[plithosKenonGonion++] = thesi;
	thesi = { 3u, 1u };
	if (einaiKeniThesi(thesi))
		kenesTheseis[plithosKenonGonion++] = thesi;
	thesi = { 3u, 3u };
	if (einaiKeniThesi(thesi))
		kenesTheseis[plithosKenonGonion++] = thesi;

	if (plithosKenonGonion > 0)							          	// Υπάρχουν κενές γωνίες, διάλεξε μια
		return kenesTheseis[random(plithosKenonGonion)];	// τυχαία από 0 έως plithosKenonGonion-1.
	
	return { 0, 0 };                     // Δε βρέθηκε κενή γωνία, επίστρεψε άκυρη θέση.
}

void Pista::vraxionasPaizeiPouli(const Paiksimo paiksimo) const {
  const auto goniaAfetiriasPoulion = (paiksimo.symbolo == Symbolo::Xi ? leuko : mauro);
  parePouliApoGlistra(taxutita, goniaAfetiriasPoulion);
  
  const auto& koutakiProorismos = koutakia[paiksimo.thesi.grammi - 1][paiksimo.thesi.stili - 1];
  koutakiProorismos.valePouli(taxutita);
}

//+++++++++++++++++++++++++++++Agonas++++++++++++++++++++++++++++++++++++++++++

class Agonas {
public:
  Agonas();
  void paikseMexriTelous();
private:
  Pista pista;
  Paiksimo trexonPaiksimo{};
  Thetikos paikseGyroElegkseTelos();
	void deikseApotelesma(const Thetikos codikosApotelesmatos) const;
	
  Thesi eisagogiThesisXristiApoSeiriaki() const;
  Thesi eisagogiThesisXristiApoPliktrologio() const;
	Thesi thesiEyretiki();
};

Agonas::Agonas() {
  // Ο τυχαίος θόρυβος του ασύνδετου αναλογικού πιν 0 παράγει διαφορετικούς τροφοδότες αριθμούς.
  randomSeed(analogRead(0));  //ή srand(static_cast<unsigned>(time(NULL)));
  trexonPaiksimo.symbolo = random(2) ? Symbolo::Omikron : Symbolo::Xi;   // Ξεκινάει τυχαία
  Serial.println(String(F("NEO PAIXNHDI! (O PROTOS EPILEGETAI TYXAIA).\n")));
}

void Agonas::paikseMexriTelous() {
  emfaniseEikona(eikones[24]); delay(2000);       // AΡΧΗ
  xairetismosEnarksis(10);

	Thetikos teleiose_H_apotelesma{ false };	// δεν τελείωσε (false) ή κωδικός αποτελέσματος (δηλαδή true)
	do {
    pista.sxediaseStiSeiriaki();
		trexonPaiksimo.symbolo = trexonPaiksimo.symbolo == Symbolo::Omikron ?
			Symbolo::Xi : Symbolo::Omikron;		// Αλλαγή σειράς παίκτη
    Serial.println(String("\nPAIZEI TO: ") + static_cast<char>(trexonPaiksimo.symbolo));
    emfaniseEikona(eikones[trexonPaiksimo.symbolo == Symbolo::Xi ? 25 : 26]);   // δείξε βέλος παίκτη
    delay(2000);    
    teleiose_H_apotelesma = paikseGyroElegkseTelos();    
  } while (!teleiose_H_apotelesma);       // Αν δεν τελείωσε ο αγώνας, συνέχισε με τον επόμενο παίκτη.

	deikseApotelesma(teleiose_H_apotelesma);	// Έχει τελειώσει ο αγώνας, δείξε το αποτέλεσμα.
}

Thetikos Agonas::paikseGyroElegkseTelos() {
  if (trexonPaiksimo.symbolo == Symbolo::Omikron) {   // Έχει σειρά να παίξει ο υπολογιστής το "Ο".
    // Ζήτα από τον υπολογιστής τη θέση που θα παίξει, η θέση είναι σίγουρα έγκυρη.
    trexonPaiksimo.thesi = thesiEyretiki();
    
    Serial.println(String(static_cast<char>(trexonPaiksimo.symbolo))
      + ": PAIZEI STH 8ESH: " + trexonPaiksimo.thesi.grammi + ", " + trexonPaiksimo.thesi.stili);
    const Thetikos thesi1eos9 = (trexonPaiksimo.thesi.grammi - 1) * 3 + trexonPaiksimo.thesi.stili;
    emfaniseEikona(eikones[thesi1eos9]);
  }
  else { //trexonPaiksimo.symbolo == Symbolo::Xi) {   // Έχει σειρά να παίξει ο χρήστης το "Χ" 
    // Ζήτα από τον χρήστη τη θέση που θα παίξει, η θέση είναι σίγουρα έγκυρη.
    //trexonPaiksimo.thesi = eisagogiThesisXristiApoSeiriaki();
    trexonPaiksimo.thesi = eisagogiThesisXristiApoPliktrologio();

    Serial.println(String(static_cast<char>(trexonPaiksimo.symbolo))
      + ": PAIZEI STH 8ESH: " + trexonPaiksimo.thesi.grammi + ", " + trexonPaiksimo.thesi.stili);
    const Thetikos thesi1eos9 = (trexonPaiksimo.thesi.grammi - 1) * 3 + trexonPaiksimo.thesi.stili;
    emfaniseEikona(eikones[thesi1eos9 + 10]);   
  }  
  pista.paikse(trexonPaiksimo);
  pista.vraxionasPaizeiPouli(trexonPaiksimo);

	if (const Thetikos codikosTrilizas = pista.exeiGineiTrilizaMeTo(trexonPaiksimo))
		return codikosTrilizas;				// Τέλος αγώνα, υπάρχει νικητής.
	if (pista.gemise())
		return 9;							// Τέλος αγώνα, κωδικός ισοπαλίας.
	return false;							// ο αγώνας συνεχίζεται.
}

Thesi Agonas::eisagogiThesisXristiApoSeiriaki() const {
  do {
    Serial.println("Parakalo eisagete tin thesi (GrammiStili) stin pista (p.x. 32): ");
    if (Serial.available()) {
      String eiserxomeno {Serial.readStringUntil('\n')};
      eiserxomeno.trim();
      eiserxomeno.toLowerCase();
      const char c1 {eiserxomeno.charAt(0)};
      const char c2 {eiserxomeno.charAt(1)};
      if (eiserxomeno.length() == 2
      && (c1 == '1' || c1 == '2' || c1 == '3')
      && (c2 == '1' || c2 == '2' || c2 == '3')
      && pista.einaiKeniThesi({c1 - '0', c2 - '0'}) ) {
        return  {c1 - '0', c2 - '0'};
      }
      else
        Serial.println(F("Lathos thesi! Ksanaprospathiste..."));
    }
  } while (true);
}

Thesi Agonas::eisagogiThesisXristiApoPliktrologio() const {
  emfaniseEikona(eikones[0]);                         // δείξε κενή τρίλιζα
  
  while (true) {
    const char pliktro = pliktrologio.getKey();
    delay(5);
    if (pliktro != NO_KEY) {
      Serial.println(String("pliktro: ") + pliktro);
      delay(10);
      if (pliktro < '1' || '9' < pliktro)  {
        Serial.println(F("Lathos Pliktro! Ksanaprospathiste..."));
        emfaniseEikona(eikones[28]);                  // πλήκτρο '0' ή * ή #, ΛΑΘΟΣ 
        delay(2000);
        emfaniseEikona(eikones[0]);                   // δείξε κενή τρίλιζα
        continue;
      }
      
      const Thetikos arithmos{pliktro - '0'};
      Serial.println(String("arithmos: ") + arithmos);
      const Thesi thesi { (arithmos - 1) / 3 + 1,
                          (arithmos - 1) % 3 + 1 };
      Serial.println(String("grammi stili: ") + thesi.grammi + ", " + thesi.stili);
      
      if (!pista.einaiKeniThesi(thesi)) {
        Serial.println(F("KATELEIMENNH thesi! Ksanaprospathiste..."));
        emfaniseEikona(eikones[28]);                  // Κατελημμένη θέση, ΛΑΘΟΣ
        delay(2000);
        emfaniseEikona(eikones[0]);                   // δείξε κενή τρίλιζα
        continue;
      }
      
      emfaniseEikona(eikones[27]); 
      delay(2000);
      return thesi;                                   // Άδεια θέση, ΣΩΣΤΗ
    }
  }
}

Thesi Agonas::thesiEyretiki() {
	// Πρώτα προσπάθησε να κάνεις τρίλιζα.
	const Thesi thesiTrilizasMou{ pista.vresPithaniTriliza(trexonPaiksimo.symbolo) };
	if (thesiTrilizasMou != Thesi{ 0, 0 })
		return thesiTrilizasMou;

	// Αλλιώς, προσπάθησε να εμποδίσεις τρίλιζα του αντίπαλου σου.
	const Symbolo antipalos{ antipaloSymbolo(trexonPaiksimo.symbolo) };
	const Thesi thesiTrilizasTou{ pista.vresPithaniTriliza(antipalos) };
	if (thesiTrilizasTou != Thesi{ 0, 0 })
		return thesiTrilizasTou;

	// Αλλιώς, προσπάθησε να δημιουργήσεις διπλή απειλή.
	//const Thesi thesiDiplisMou{ pista.vresPithanoPaiksimoDixalas(trexonPaiksimo.symbolo) };
	//if (thesiDiplisMou != Thesi{ 0, 0 })
	//	return thesiDiplisMou;

	// TODO Αν υπάσχει τρόπος να δημιουργήσει ο αντίπαλος διπλή απειλή, να τον εμποδίσω.

	// Αλλιώς, διάλεξε τυχόν διαθέσιμο κέντρο.
	if (pista.ypoloipaKena <= 7 && pista.einaiKeniThesi({ 2u, 2u })) return { 2u, 2u };

	// Αλλιώς, διάλεξε μια γωνιακή θέση από τις διαθέσιμες, προτιμώντας τις απέναντι αντιπάλου.
	const Thesi thesiGoniaki{ pista.vresApenanti_H_KeniGonia(trexonPaiksimo.symbolo) };
	if (thesiGoniaki != Thesi{ 0, 0 })
		return thesiGoniaki;

	// Αλλιώς, διάλεξε μια τυχαία θέση από τις υπόλοιπες διαθέσιμες. Ουσιαστικά, τις πλευρικές.
	return pista.vresKeniThesi();
}

void Agonas::deikseApotelesma(const Thetikos codikosApotelesmatos) const {
  pista.sxediaseStiSeiriaki();          // Δείξε την πίστα
	switch (codikosApotelesmatos) {
	case 9:// Ισοπαλία
    emfaniseEikona(eikones[29]);        // '='
    xairetismosIsopalias(23);
    Serial.println(F("OI PAIKTES HR8AN ISOPALIA!\n\n"));
		return;
	case 1:
    ypodiksiTrilizasGrammi1(taxutita);
		break;
	case 2:
    ypodiksiTrilizasGrammi2(taxutita);
		break;
	case 3:
    ypodiksiTrilizasGrammi3(taxutita);
		break;
	case 4:
    ypodiksiTrilizasStili1(taxutita);
		break;
	case 5:
    ypodiksiTrilizasStili2(taxutita);
		break;
	case 6:
    ypodiksiTrilizasStili3(taxutita);
		break;
	case 7:
    ypodiksiTrilizasDiagonio(taxutita);
		break;
	case 8:
    ypodiksiTrilizasAntidiagonio(taxutita);
	}
	
	if(trexonPaiksimo.symbolo == Symbolo::Omikron) {  // Νίκη Ρομπότ
    emfaniseEikona(eikones[30]);                    // χαμόγελο
    xairetismosNikis(18);
    Serial.println(F("SE NIKHSA, ZHTO!\n\n"));
	}
  else {                                            // Νίκη Ανθρώπου
    emfaniseEikona(eikones[31]);                    // λύπη
    xairetismosHttas(30);
    Serial.println(F("EXASA! SNIF\n\n"));
  }
}

//+++++++++++++++++++++++++++++setup+++++++++++++++++++++++++++++++++++++++++

// Αρχικοποίηση
// Τρέχει μόνο μια φορά, όταν πατηθεί το πλήκτρο reset του ελεγκτή ή τροφοδοτηθεί με ρεύμα.
void setup() {
  
  // Αρχικοποίηση σειριακής θύρας για επικοινωνία με τον χρήστη μέσω monitor.
  // Δυστυχώς, το άνοιγμα/κλείσιμο του monitor προκαλεί reset στον ελεγκτή!
  Serial.begin(9600); delay(4000);
  Serial.println(F("#######  Ksekina seiriaki thyra #######"));

  enarksiOthonis(); delay(500);

  //---------------------------------------------------------------------------
  // Τα παρακάτω αντικαθιστούν την κλήση της "_Braccio::begin"
  // ώστε να αποφύγουμε τις κλήσεις των _Braccio::_softStart & _Braccio::_softwarePWM

  // Αρχικοποίηση των pin των σερβοκινητήρων
  base.attach(11);
  shoulder.attach(10);
  elbow.attach(9);
  wrist_rot.attach(6);
  wrist_ver.attach(5);
  gripper.attach(3);

  // Αφήνει το PIN12 σε υψηλή τάση, αν το άφηνε σε χαμηλή τότε τα σερβό δεν θα ανταποκρίνονταν.
  digitalWrite(SOFT_START_CONTROL_PIN, HIGH);

  // Εδώ τελειώνει η υποκατάσταση της Braccio.begin
  //---------------------------------------------------------------------------
  
  Agonas agonas;
  agonas.paikseMexriTelous();
}

//++++++++++++++++++++++++++++++loop+++++++++++++++++++++++++++++++++++++++

// Τρέχει συνεχώς, μέχρι να πατηθεί το πλήκτρο reset του ελεγκτή ή διακοπεί το ρεύμα.
// Ορίζεται αναγκαστικά επειδή καλείται από την main(). Δεν τη χρησιμοποιούμε.
void loop() {
}
