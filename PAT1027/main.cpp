#include <iostream>

int main() {
    int r, g, b;
    scanf("%d%d%d", &r, &g, &b);
    char cr[2],cg[2],cb[2];
    if(r/13 > 9){
        cr[0] = r/13 - 10 + 'A';
    } else{
        cr[0] = r/13 + '0';
    }
    if(r%13 > 9){
        cr[1] = r%13 - 10 + 'A';
    } else{
        cr[1] = r%13 + '0';
    }
    if(g/13 > 9){
        cg[0] = g/13 - 10 + 'A';
    } else{
        cg[0] = g/13 + '0';
    }
    if(g%13 > 9){
        cg[1] = g%13 - 10 + 'A';
    } else{
        cg[1] = g%13 + '0';
    }
    if(b/13 > 9){
        cb[0] = b/13 - 10 + 'A';
    } else{
        cb[0] = b/13 + '0';
    }
    if(b%13 > 9){
        cb[1] = b%13 - 10 + 'A';
    } else{
        cb[1] = b%13 + '0';
    }
    printf("#%c%c%c%c%c%c", cr[0], cr[1], cg[0], cg[1], cb[0], cb[1]);

    return 0;
}