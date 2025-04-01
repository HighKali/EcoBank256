# EcoBank256: Guida Completa

## Introduzione
EcoBank256 (EBK) è una criptovaluta bancaria basata su Forknote, progettata per offrire funzionalità avanzate come crittografia AES-256, mixing delle transazioni, conti bancari con interessi e un'interfaccia CLI. Una delle caratteristiche principali è il prezzo fisso di 1 EBK = 0.40 centesimi di euro, mantenuto tramite un meccanismo di pegging simulato. Include anche una mappa live dei tentativi di attacco e un sistema di blocco crittografico per la sicurezza.

### Obiettivi del progetto
- Fornire una criptovaluta stabile con un valore ancorato all'euro.
- Garantire privacy tramite il mixing delle transazioni.
- Offrire un sistema bancario con interessi sulla blockchain.
- Facilitare l'uso tramite un'interfaccia CLI.
- Migliorare la sicurezza con un sistema di rilevamento degli attacchi e blocco crittografico.

## Architettura del Sistema

### Struttura dei file
- **ecobank256.ini**: File di configurazione con parametri come il tasso di cambio e la riserva.
- **include/Blockchain.h**: Header della classe Blockchain.
- **src/Blockchain.cpp**: Implementazione della blockchain con il meccanismo di pegging e blocco crittografico.
- **src/Daemon/DaemonCommandsHandler.cpp**: Gestione dei comandi CLI.
- **src/main.cpp**: Punto di ingresso del programma.
- **ui/map.html**: Interfaccia grafica per la mappa live dei tentativi di attacco.
- **README.md**: Documentazione del progetto.

### Parametri di configurazione
- **Nome della moneta**: EcoBank256
- **Simbolo**: EBK
- **Totale monete**: 1,000,000,000 EBK
- **Tasso di cambio**: 1 EBK = 0.40 centesimi di euro
- **Riserva iniziale**: 400,000,000 EUR
- **Ricompensa genesis**: 50,000 EBK
- **Difficoltà target**: 60
- **Tempo per blocco**: 60 secondi
- **Intervallo di dimezzamento**: 210,000 blocchi
- **Algoritmo di mining**: SHA-256
- **Tasso di interesse**: 0.1% al giorno

## Funzionalità Principali

### Prezzo fisso (Pegging)
EcoBank256 utilizza un meccanismo di pegging simulato per mantenere il prezzo di 1 EBK = 0.40 centesimi di euro. Questo è realizzato tramite:
- Una riserva simulata in euro (400,000,000 EUR).
- Un sistema di regolazione delle ricompense di mining per bilanciare l'emissione di nuove monete.

### Crittografia e Privacy
- Le transazioni sono crittografate con AES-256.
- Il mixing delle transazioni è supportato per garantire la privacy.

### Conti bancari con interessi
- Ogni indirizzo ha un conto bancario associato.
- Gli interessi (0.1% al giorno) vengono applicati automaticamente con il comando `interest`.

### Mappa live dei tentativi di attacco
- Una mappa live (accessibile tramite `ui/map.html`) mostra i tentativi di attacco simulati in tempo reale.
- Utilizza Leaflet.js per visualizzare i tentativi su una mappa globale.

### Blocco crittografico estremo
- Al primo tentativo di accesso esterno, l'account viene bloccato per 48 ore.
- Durante il blocco, tutte le operazioni (es. invio di fondi, applicazione degli interessi) sono disabilitate.
- Un messaggio di avviso ricorda all'utente di mantenere la chiave privata al sicuro.

### Interfaccia CLI
- Comandi disponibili:
  - `balance`: Mostra il saldo in EBK e EUR.
  - `send <amount> <address>`: Invia EBK a un indirizzo.
  - `mix`: Attiva il mixing per la prossima transazione.
  - `interest`: Applica gli interessi.
  - `showchain`: Visualizza la blockchain.
  - `reserve`: Mostra la riserva in euro.
  - `lockstatus`: Verifica lo stato del blocco crittografico.

## Installazione e Configurazione

### Prerequisiti
- Sistema operativo: Linux (Ubuntu, Termux, ecc.).
- Dipendenze:
  - CMake
  - Boost (1.55 o superiore)
  - OpenSSL
  - Clang o GCC
- Per la mappa live: un browser web moderno (es. Chrome, Firefox)

### Installazione delle dipendenze
- Su Ubuntu:
  ```bash
  sudo apt-get update
  sudo apt-get install cmake libboost-all-dev libssl-dev clang git
