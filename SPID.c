#include <stdio.h>
#include <stdlib.h>
#include <gmp.h>

mpz_t p,b,q,r,m;

int main()
{
printf("Please enter a prime number p : ");
mpz_inp_str(p, stdin, 10);

mpz_init(m);
mpz_mod_ui (m,p,6);

if(mpz_cmp_ui(p,2)==0 || mpz_cmp_ui(p,3)==0)
{
printf("2p+1 is prime\n");
}
else if(mpz_cmp_ui(m,1)==0)
{
printf("2p+1 is composite\n");
}
else
{
mpz_init(b);
mpz_init(r);

mpz_mul_ui(q,p,2);
mpz_add_ui(q,q,1);
mpz_set_ui(b,3);
mpz_powm(r,b,p,q);

mpz_clear(p);
mpz_clear(q);

if(mpz_cmp_ui(r,1)==0)
{
printf("2p+1 is prime\n");
}
else
{
printf("2p+1 is composite\n");
}
mpz_clear(r);
}
return 0;
}