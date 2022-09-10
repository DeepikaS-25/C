#ifndef DECODE_H
#define DECODE_H

#include "types.h" // Contains user defined types

/*
 * Structure to store information required for
 * decoding secret file from source Image
 */

#define MAX_SECRET_BUF_SIZE 1
#define MAX_IMAGE_BUF_SIZE (MAX_SECRET_BUF_SIZE * 8)

typedef struct _DecodeInfo
{
    /* Stego image Info */
    char *stego_image_fname;
    FILE *fptr_stego_image;

    char d_image_data[MAX_IMAGE_BUF_SIZE];
    char *magic_data;
    char *d_extn_secret_file;

    int size_secret_file;
    FILE *fptr_d_dest_image;

    char *decode_fname;
    FILE *fptr_decode_file;
} DecodeInfo;


/* Decoding Function Prototypes */

/* Read and validate decode args from argv */
D_status read_and_validate_decode_args(char *argv[], DecodeInfo *decInfo);

/* Perform the decoding */
D_status do_decoding(DecodeInfo *decInfo);

/* Get File pointers for i/p and o/p files */
D_status open_dec_files(DecodeInfo *decInfo);

/* Decode Magic String */
D_status decode_magic_string(DecodeInfo *decInfo);

/* Decode data from image */
D_status decode_data_from_image(int size, FILE *fptr_stego_image, DecodeInfo *decInfo);

/* Decode byte from lsb */
D_status decode_byte_from_lsb(char *data, char *image_buffer);

/* Decode file extn size */
D_status decode_file_extn_size (int size, FILE *fptr_stego_image);

/* Decode size from lsb */
D_status decode_size_from_lsb (char *buffer, int *size);

/* Decode secret file extn */
D_status decode_secret_file_extn (char *file_ext, DecodeInfo *decInfo) ;

/* Decode extension data from image */
D_status decode_extension_data_from_image ( int size, FILE *fptr_stego_image, DecodeInfo *decInfo);

/* Decode secret file size */
D_status decode_secret_file_size (int file_size, DecodeInfo *decInfo);

/* Decode secret file data */
D_status decode_secret_file_data (DecodeInfo *decInfo);

#endif
