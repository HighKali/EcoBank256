# EcoBank256
Una criptovaluta bancaria basata su Forknote, con crittografia AES-256, mixing delle transazioni, conti bancari con interessi e un'interfaccia CLI.

## Caratteristiche
- Crittografia avanzata con AES-256 per le transazioni
- Conti bancari con interessi sulla blockchain
- Mixing delle transazioni per la privacy
- Interfaccia CLI per gestione semplice
- Sistema di logging per tracciare le operazioni
- Visualizzazione della blockchain tramite CLI
- Proof of Work (PoW) per il consenso
- Valore reale della moneta: 1 EBK = 0.40 centesimi di euro (fisso, con meccanismo di pegging)
- Mappa live dei tentativi di attacco (visualizzabile in `ui/map.html`)
- Blocco crittografico estremo per 48 ore al primo tentativo di accesso esterno

## Prerequisiti
- Sistema operativo: Linux (Ubuntu, Termux su Android, ecc.)
- Dipendenze:
- CMake
- Boost (1.55 o superiore)
- OpenSSL
- Clang o GCC
- Per la mappa live: un browser web moderno (es. Chrome, Firefox)
- Su Ubuntu:
```bash
sudo apt-get update
sudo apt-get install cmake libboost-all-dev libssl-dev clang git
