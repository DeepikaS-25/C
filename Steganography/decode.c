#include <stdio.h>
#include "decode.h"
#include "types.h"
#include <string.h>
#include "common.h"
#include <stdlib.h>

// Function definition for read and validate decode args
D_status read_and_validate_decode_args(char *argv[], DecodeInfo *decInfo)
{
    if ((argv[2] != NULL) && (strcmp(strstr(argv[2], "."), ".bmp") == 0))
    {
        decInfo->stego_image_fname = argv[2];
    }
    else
    {
        return d_failure;
    }
    if (argv[3] != NULL)
    {
        decInfo->decode_fname = argv[3];
    }
    else
    {
        decInfo->decode_fname = "decode.txt";
    }
    return d_success;
}

// Function definition for opening files for decoding
D_status open_dec_files(DecodeInfo *decInfo)
{
    //Stego Image file
    decInfo->fptr_stego_image = fopen(decInfo->stego_image_fname, "r");

    //Doing Error handling
    if (decInfo->fptr_stego_image == NULL)
    {
        perror("fopen");
        fprintf(stderr, "ERROR: Unable to open file %s\n", decInfo->stego_image_fname);
        return d_failure;
    }
    //Decoded file
    decInfo->fptr_decode_file = fopen(decInfo->decode_fname, "w");

    //Doing Error handling
    if (decInfo->decode_fname == NULL)
    {
        perror("fopen");
        fprintf(stderr, "ERROR: Unable to open file %s\n", decInfo->decode_fname);
        return d_failure;
    }

    // If not failure then return d_success
    return d_success;
}

// Function definition for decode magic string
D_status decode_magic_string(DecodeInfo *decInfo)
{
    fseek(decInfo->fptr_stego_image, 54, SEEK_SET);
    int i = strlen(MAGIC_STRING);

    decInfo->magic_data = malloc(strlen(MAGIC_STRING) + 1);
    decode_data_from_image(strlen(MAGIC_STRING), decInfo->fptr_stego_image, decInfo);

    decInfo->magic_data[i] = '\0';

    if (strcmp(decInfo->magic_data, MAGIC_STRING) == 0)
    {
        return d_success;
    }
    else
    {
            return d_failure;
    }
}

// Function definition for decoding data fom image
D_status decode_data_from_image(int size, FILE *fptr_stego_image, DecodeInfo *decInfo)
{
    int i;
    char str[8];
    for (i = 0; i < size; i++)
    {
        fread(str, 8, sizeof(char), fptr_stego_image);
        decode_byte_from_lsb(&decInfo->magic_data[i], str);
    }
    return d_success;
}

// Function definition for decoding byte from lsb
D_status decode_byte_from_lsb(char *data, char *image_buffer)
{
    int bit = 7;
    unsigned char ch = 0x00;
    for (int i = 0; i < 8; i++)
    {
        ch = ((image_buffer[i] & 0x01) << bit--) | ch;
    }
    *data = ch;
    return d_success;
}

// Function definition for decoding file extension size
D_status decode_file_extn_size(int size, FILE *fptr_stego_image)
{
    char str[32];
    int length;

    fread(str, 32, sizeof(char), fptr_stego_image);
    decode_size_from_lsb(str, &length);

    if (length == size)
    {
        return d_success;
    }
    else
    {
        return d_failure;
    }
}

// Function definition for decoding size from lsb
D_status decode_size_from_lsb(char *buffer, int *size)
{
    int num = 0x00;
    for (int i = 0; i < 32; i++)
    {
        num = ((buffer[i] & 0x01) << (31 - i)) | num;
    }
    *size = num;
}

// Function definition for decoding secret file extension
D_status decode_secret_file_extn(char *file_ext, DecodeInfo *decInfo)
{
    file_ext = ".txt";
    int i = strlen(file_ext);
    decInfo->d_extn_secret_file = malloc(i + 1);
    decode_extension_data_from_image(strlen(file_ext), decInfo->fptr_stego_image, decInfo);

    decInfo->d_extn_secret_file[i] = '\0';

    if (strcmp(decInfo->d_extn_secret_file, file_ext) == 0)
    {
        return d_success;
    }
    else
    {
        return d_failure;
    }
}

// Function definition for decoding extension data from image
D_status decode_extension_data_from_image(int size, FILE *fptr_stego_image, DecodeInfo *decInfo)
{
    for (int i = 0; i < size; i++)
    {
        fread(decInfo->stego_image_fname, 8, 1, fptr_stego_image);
        decode_byte_from_lsb(&decInfo->d_extn_secret_file[i], decInfo->stego_image_fname);
    }
    return d_success;
}

// Function definition for decoding secret file size
D_status decode_secret_file_size(int file_size, DecodeInfo *decInfo)
{
    char str[32];
    fread(str, 32, sizeof(char), decInfo->fptr_stego_image);
    decode_size_from_lsb(str, &file_size);
    decInfo->size_secret_file = file_size;
    //printf("%d\n", file_size);

    return d_success;
}

// Function definition for decoding secret file data
D_status decode_secret_file_data(DecodeInfo *decInfo)
{
    char ch;
    for (int i = 0; i < decInfo->size_secret_file; i++)
    {
        fread (decInfo->stego_image_fname, 8, sizeof(char), decInfo->fptr_stego_image);
        decode_byte_from_lsb(&ch, decInfo->stego_image_fname);
        fputc(ch, decInfo->fptr_decode_file);
    }
    return d_success;
}

// Function definition for decoding
D_status do_decoding(DecodeInfo *decInfo)
{
    if (open_dec_files(decInfo) == d_success)
    {
        printf("Opened required files is successfully\n");
        if (decode_magic_string(decInfo) == d_success)
        {
            printf("Successfully decoded magic string\n");
            if (decode_file_extn_size(strlen(".txt"), decInfo->fptr_stego_image) == d_success)
            {
                printf("Succesfully decoded file extension size\n");
                if (decode_secret_file_extn(decInfo->d_extn_secret_file, decInfo) == d_success)
                {
                    printf("Succesfully decoded Secret File Extension\n");
                    if (decode_secret_file_size(decInfo->size_secret_file, decInfo) == d_success)
                    {
                        printf("Successfully decoded secret file size\n");
                        if (decode_secret_file_data(decInfo) == d_success)
                        {
                            printf("Successfully Decoded secret file data\n");
                        }
                        else
                        {
                            printf("Decoding of secret file data is a failure\n");
                        }
                    }
                    else
                    {
                        printf("Decode of secret file size is a failure\n");
                        return d_failure;
                    }
                }
                else
                {
                    printf("Decode of Secret file extension is a failure\n");
                    return d_failure;
                }
            }
            else
            {
                printf("Decoded of file extension size is a failure\n");
                return d_failure;
            }
        }
        else
        {
            printf("Decoding of magic string is a failure\n");
            return d_failure;
        }
    }
    else
    {
        printf("Open files is a failure\n");
        return d_failure;
    }
    return d_success;
}
