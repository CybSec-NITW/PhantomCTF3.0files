#include <stdio.h>
#include <string.h>
#include <stdlib.h>

//gcc cctv.c -o cctv

unsigned int dosomemagic(char *message) {
   int i, j;
   unsigned int ccc, aaa, bbb;

   i = 0;
   aaa = 0xFFFFFFFF;
   while (message[i] != 0) {
      ccc = message[i];            // Get next ccc.
      aaa = aaa ^ ccc;
      for (j = 7; j >= 0; j--) {    // Do eight times.
         bbb = -(aaa & 1);
         aaa = (aaa >> 1) ^ (0xEDB88320 & bbb);
      }
      i = i + 1;
   }
   return ~aaa;
}

void pet(char *in, char *out) {
    int i, n;
    n = strlen(in);
    char ccc[5];
    unsigned int crypted;
    for (i=0;i<160 && i<n;i+=4) {
        strncpy(ccc, (in+i), 4);
        ccc[4] = '\0';
        crypted = dosomemagic(ccc);
        strncpy((out+i), (char *)&crypted, 4);
    }
}

int main(int argc, char* argv[]) {

    char flag[] = "\xec\x30\xcf\x79\xe4\xe4\xfe\x88\x26\xe8\x1d\x67\x91\xe9\xc6\xd9\x1b\xed\xcf\x55\x1f\x29\x45\x68\xc6\xb5\xa0\xd0";

    if (argc != 2) {
        printf("Usage: %s <password>\n", argv[0]);
        return 0;
    }
    char buffer[200];
    memset(buffer, '\0', 200);
    pet(argv[1], buffer);

    if (strlen(buffer) == strlen(flag) && memcmp(buffer, flag, strlen(flag)) == 0) {
        printf("You are controlling CCTVs!\n");
    }
    else {
        printf("The CCTVs are strong enough!\n");
    }

    return 0;
}

