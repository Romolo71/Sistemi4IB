// --- PIN DEFINITIONS ---
const int dataPins[4] = {13, 12, 11, 10};  // D3 D2 D1 D0
const int READY = 9;                       // TX → RX
const int TAKEN = 8;                       // RX → TX

void setup() {
  for (int i = 0; i < 4; i++) {
    pinMode(dataPins[i], INPUT);
  }

  pinMode(READY, INPUT);
  pinMode(TAKEN, OUTPUT);

  digitalWrite(TAKEN, LOW);

  Serial.begin(9600);
}

byte receiveNibble() {
  // Aspetta READY = 1 → dato valido
  while (digitalRead(READY) == LOW);

  // Leggi le 4 linee dati
  byte value = 0;
  for (int i = 0; i < 4; i++) {
    value |= (digitalRead(dataPins[i]) << i);
  }

  // TAKEN = 1 → dato ricevuto
  digitalWrite(TAKEN, HIGH);

  // Aspetta che TX abbassi READY
  while (digitalRead(READY) == HIGH);

  // TAKEN = 0
  digitalWrite(TAKEN, LOW);

  return value;
}

void loop() {
  byte highNibble = receiveNibble();
  byte lowNibble  = receiveNibble();

  byte ch = (highNibble << 4) | lowNibble;

  Serial.print("Ricevuto: ");
  Serial.println((char)ch);
}
