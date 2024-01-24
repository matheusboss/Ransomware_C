#include <stdio.h>
#include <openssl/conf.h>
#include <openssl/evp.h>
#include <string.h>
#include <unistd.h>
#include <fcntl.h>

#define _LARGEFILE_SOURCE _
#define FILE_OFFSET_BITS 64

unsigned char texto_cifrado[300+1];
void encryptar_dados(unsigned char* dados_limpo, int tamanho_dados_limpo){
        unsigned char *add;
        int add_len;
        unsigned char *key = (unsigned char *)"123456789123456789098765432345";
        unsigned char *iv = (unsigned char *)"1234567890123432";
        int iv_len;
        int len;
        int ciphertext_len = 0;

        EVP_CIPHER_CTX* avp = EVP_CIPHER_CTX_new();

        if(!EVP_EncryptInit_ex(avp, EVP_aes_128_ecb(), NULL, key, NULL)) {
                exit(-1);
        }
        if(!EVP_EncryptUpdate(avp, texto_cifrado, &len, dados_limpo, tamanho_dados_limpo)){
                exit(-1);
        }

        ciphertext_len += len;
        if(!EVP_EncryptFinal_ex(avp, texto_cifrado + len, &len)){
                exit(-1);
        }
        ciphertext_len += len;

        EVP_CIPHER_CTX_free(avp);
}

int tratamento(char *arquivo){

        int arquivo_leitura;
        int arquivo_escrita;
        int dados;
        size_t valor_escrita;
        char buffer[300+1];
        char buffer2[300+1];
        char buffer_final[300+1];
        arquivo_leitura = open(arquivo, O_RDONLY);
        arquivo_escrita = open("temporario.txt", O_WRONLY);
        if(arquivo > 0){
                while(dados = read(arquivo_leitura, buffer, sizeof(buffer)) > 0){
                        sprintf(buffer2, "%s", buffer);
                        encryptar_dados(buffer2, sizeof(buffer2));
                        printf("%s", texto_cifrado);
                        valor_escrita = write(arquivo_escrita, texto_cifrado, sizeof(texto_cifrado));
                }

        }

return 1;
}
