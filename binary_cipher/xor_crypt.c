#include "binary_cipher.h"

void my_xor_crypt(void *data, size_t data_len, const void *key, size_t key_len)
{
    unsigned char *val_data = data;
    const unsigned char *val_key = key;
    size_t j = 0;

    for (size_t i = 0; i < data_len; i++)
    {
        if (j == key_len)
        {
            j = 0;
        }

        val_data[i] = val_data[i] ^ val_key[j];
        j++;
    }
}
