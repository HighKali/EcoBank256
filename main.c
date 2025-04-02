#include <stdio.h>
#include <openssl/aes.h>

int main(void) {  // Aggiunto "void" per il prototipo
    printf("EcoBank256 - Primo avvio\n");
    AES_KEY aes_key;  // Dichiarazione
    AES_set_encrypt_key("chiave_di_prova_32_bytes_long!!", 256, &aes_key);  // Uso della variabile
    printf("AES-256 inizializzato\n");
    return 0;
}
