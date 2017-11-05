/* ------------------------------
   $Id: dump.c,v 0.0 2003/10/13 13:38:21 marquet Exp $
   ------------------------------------------------------------

   Dump a buffer.
   Philippe Marquet, october 2003

*/

#include <stdio.h>
#include <ctype.h>

/* dump buff to stdout,
   and octal dump if octal_dump; an ascii dump if ascii_dump! */
void dump(unsigned char *buff, unsigned int buff_size, int ascii_dump, int octal_dump) {
    int i,j;

    for (i=0; i < buff_size; i+=16) {
        /* offset */
        printf("%.8o",i);

        /* octal dump */
        if (octal_dump) {
            for(j=0; j<8; j++)
                printf(" %.2x", buff[i+j]);
            printf(" - ");

            for(; j<16; j++)
                printf(" %.2x", buff[i+j]);

            printf("\n");
        }

        /* ascii dump */
        if (ascii_dump) {
            printf("%8c", ' ');

            for(j=0; j<8; j++)
                printf(" %1c ", isprint(buff[i+j])?buff[i+j]:' ');
            printf(" - ");

            for(; j<16; j++)
                printf(" %1c ", isprint(buff[i+j])?buff[i+j]:' ');

            printf("\n");
        }
    }
}
