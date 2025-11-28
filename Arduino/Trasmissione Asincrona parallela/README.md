# 📘 **Trasmissione Asincrona parallela**
*Trasmissione Asincrona parallela tra due Arduino via seriale*

---

## 👥 Realizzatori

| Realizzatori | 
|--------------|
| [![Nome](https://github.com/Romolo71.png)](https://github.com/Romolo71)  <br> **Riccardo Tonini** |
| [![Nome](https://github.com/ct-0401.png)](https://github.com/ct-0401)  <br> **Tommaso Scattolin** |

---

# 📑 Indice
- [1. Obiettivo](#1-obiettivo)
- [2. Strumenti e Materiale](#2-strumenti-e-materiale)
- [3. Foto](#3-foto)
  - [3.1 Thinkercad](#31-thinkercad)
  - [3.2 Circuito Fisico](#32-circuito-fisico)
- [4. Cenni Teorici](#4-cenni-teorici)
- [5. File Presenti](#5-file-presenti)
- [6. Conclusione](#6-conclusione)

---

## 1. **Obiettivo**
*(descrivere l’obiettivo dell’esperienza)*  

Puoi evidenziare concetti importanti con:  
- **grassetto** → `**testo**`  
- colore → `<span style="color:blue">testo colorato</span>`  
- entrambi → `<span style="color:red"><b>testo in grassetto e rosso</b></span>`

---

## 2. **Strumenti e Materiale**
Per realizzare l’esperimento sono stati utilizzati due Arduino UNO, cavi jumper, LED, resistori, pulsanti, e un PC per la programmazione e la gestione della comunicazione seriale.  
Inoltre è stato usato il software Arduino IDE per scrivere e caricare i programmi sulle schede, e la piattaforma Thinkercad per la simulazione del circuito prima della realizzazione fisica.  
Questo materiale permette di implementare la trasmissione asincrona parallela in modo semplice e sicuro, testando il protocollo di handshake e la gestione dei segnali digitali.

---

## 3. **Foto**

### 3.1 **Tinkercad**
![Tinkercad](images/thinkercad.png)

### 3.2 **Circuito Fisico**
![Circuito Fisico](images/circuit.png)

---

## 4 **Cenni Teorici**

### Arduino
> Arduino è una piattaforma di prototipazione elettronica che `permette di creare facilmente sistemi interattivi collegando sensori e attuatori`. La scheda dispone di `pin digitali e analogici`, che possono essere configurati per leggere dati dal mondo esterno o inviare segnali a dispositivi come LED, motori o relè. Grazie a un `ambiente di sviluppo semplice` e a un `linguaggio simile al C/C++`, Arduino `consente di programmare comportamenti complessi senza dover gestire` direttamente `circuiti elettronici complessi`.

### Segnali digitali
> I segnali digitali sono impulsi elettrici che possono assumere solo due stati distinti, generalmente chiamati `HIGH` e `LOW`, corrispondenti a `5V` e `0V` su Arduino. Questo tipo di segnale permette di rappresentare informazioni in `forma binaria`, cioè 1 e 0, rendendolo ideale per i circuiti logici e i sistemi di controllo. 

> Su Arduino, i segnali digitali vengono utilizzati sia in input, per leggere lo stato di `pulsanti` o `sensori`, sia in output, per comandare `LED`, `motori` o altri dispositivi. La precisione del segnale digitale rende semplice gestire la logica dei programmi e sincronizzare l’interazione con il mondo esterno.

### Input e Output
> Arduino permette di gestire i segnali digitali attraverso i suoi pin, che possono essere configurati come input o output. I pin configurati come output possono inviare tensione al mondo esterno, ad esempio per accendere un LED o attivare un relè. Per fare questo si utilizza il comando `digitalWrite`, che permette di impostare il pin su HIGH (5V) o LOW (0V).

> I pin configurati come input servono invece a leggere segnali provenienti da sensori, pulsanti o interruttori. In questo caso si utilizza il comando `digitalRead`, che restituisce lo stato del pin, HIGH o LOW, a seconda della tensione presente. La configurazione dei pin si fa con `pinMode`, specificando se il pin deve comportarsi come INPUT o OUTPUT.

> Su una scheda Arduino UNO, i pin digitali vanno da `D0` a `D13`, e alcuni di essi hanno funzioni speciali come `PWM` o comunicazione seriale (`TX` e `RX`). L’uso corretto dei pin in input e output permette ad Arduino di interagire con il mondo esterno, ricevendo informazioni dai sensori e controllando dispositivi.

### Protocollo di handshake
> Il protocollo di handshake è un `metodo di comunicazione` che permette a due dispositivi di `sincronizzarsi prima di scambiare dati`. In pratica, un dispositivo segnala quando è `pronto a inviare o ricevere informazioni`, e `l’altro conferma quando è pronto a riceverle o a prenderle in carico`, evitando perdite o errori nei dati.

> Su Arduino, l’handshake digitale può essere implementato con pin configurati come input e output, dove `segnali HIGH e LOW indicano lo stato di “pronto” o “ricevuto”`. Questo tipo di protocollo è molto utile quando si devono trasferire dati tra più Arduino o Arduino e altri dispositivi in modo affidabile.

---

## 5 **FILE PRESENTI**
Elenco dei file inclusi nel progetto (aggiornare in base alla cartella):

/src → codici  
/schematic → schema elettrico mediante KiCAD  
/images → immagini utilizzate nel README  
README.md → file descrittivo

---

## 6. **Conclusione**
*(risultati ottenuti, osservazioni, problemi riscontrati, possibili sviluppi futuri)*
