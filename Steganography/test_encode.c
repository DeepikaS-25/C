#include <stdio.h>
#include <string.h>
#include "encode.h"
#include "types.h"
#include "common.h"
#include "decode.h"

/* Passing arguments through command line arguments */
int main(int argc, char *argv[])
{

   //checking for the argc
    if (argc >= 3)
   {

        // Function call for check operation type
        if (check_operation_type(argv) == e_encode)
        {
            // Declare structure variable
            EncodeInfo encInfo;
            printf("Selected Encoding...\n");
            // Read and validate encode arguments
            if (read_and_validate_encode_args(argv, &encInfo) == e_success)
            {
                printf("Read and validate encode arguments is successful\n");
                printf(" ###### Encoding procedure started ######\n");

                // Function call for encoding
                if (do_encoding(&encInfo) == e_success)
                {
                    printf(" ###### Encoding procedure completed ######\n");
                }
                else
                {
                    printf("Failed Encoding the data\n");
                    return e_failure;
                }
            }
            else
            {
                printf("Read and validate encode arguments is a failure\n");
                return e_failure;
            }
        }
        // Function call for check operation type
        else if (check_operation_type(argv) == e_decode)
        {
            // Declare structure variables
            DecodeInfo decInfo;
            printf("Selected decoding...\n");
            if (read_and_validate_decode_args(argv, &decInfo) == d_success)
            {
                printf("Read and validate decode arguments is successful\n");
            printf(" ###### Decoding procedure started ######\n");
                if (do_decoding(&decInfo) == d_success)
                {
                    printf(" ###### Decoding procedure completed ######\n");
                }
                else
                {
                    printf("Failed decoding the data\n");
                    return d_failure;
                }
            }
        }
        else
        {
            printf("Invalid Operation type, please use as mentioned below\nUsage:\nEncoding: ./a.out -e beautiful.bmp secret.txt stego.bmp\nDecoding: ./a.out -d stego.bmp decode.txt\n");
        }
    }
    else
    {
        printf("Invalid Operation type, please use as mentioned below\nUsage:\nEncoding: ./a.out -e beautiful.bmp secret.txt stego.bmp\nDecoding: ./a.out -d stego.bmp decode.txt\n");
    }
    return 0;
}
