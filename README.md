# EcoBank256
Una criptovaluta bancaria basata su Forknote, con crittografia AES-256, mixing delle transazioni e funzionalità CLI.

## Caratteristiche
- Crittografia avanzata con AES-256 per le transazioni
- Conti bancari con interessi sulla blockchain
- Mixing delle transazioni per la privacy
- Interfaccia CLI per gestione semplice

## Istruzioni per la compilazione
1. Installa le dipendenze: `pkg install cmake boost openssl clang git`
2. Configura: `cd build && cmake ..`
3. Compila: `make`
4. Avvia: `./forknoted --config-file=ecobank256.ini`

## Configurazione
Vedi `ecobank256.ini` per i parametri della moneta.
