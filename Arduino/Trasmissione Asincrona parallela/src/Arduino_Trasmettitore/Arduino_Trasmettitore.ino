// --- PIN DEFINITIONS ---
const int dataPins[4] = {13, 12, 11, 10};  // D3 D2 D1 D0
const int READY = 9;                       // TX → RX
const int TAKEN = 8;                       // RX → TX

void setup() {
  for (int i = 0; i < 4; i++) {
    pinMode(dataPins[i], OUTPUT);
  }

  pinMode(READY, OUTPUT);
  pinMode(TAKEN, INPUT);

  digitalWrite(READY, LOW);
}

void sendNibble(byte val) {
  // Metto il dato sulle 4 linee
  for (int i = 0; i < 4; i++) {
    digitalWrite(dataPins[i], (val >> i) & 1);
  }

  // READY = 1 → dato pronto
  digitalWrite(READY, HIGH);

  // Aspetta RX che alzi TAKEN
  while (digitalRead(TAKEN) == LOW);

  // READY = 0 → operazione finita
  digitalWrite(READY, LOW);

  // Aspetta che TAKEN torni a 0
  while (digitalRead(TAKEN) == HIGH);
}

void loop() {
  // Esempio: invio il carattere 'A' (0x41 → 0100 0001)
  byte ch = 'A';

  // Invio nibble alto (0100)
  sendNibble((ch >> 4) & 0x0F);

  delay(20);

  // Invio nibble basso (0001)
  sendNibble(ch & 0x0F);

  delay(1000); // 1 secondo tra invii
}
