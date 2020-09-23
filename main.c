#include <stdio.h>
#include "ft_printf.h"

int main(void)
{
	char *asd = "Hello World!";
	int x = 12359;
	char a = 'a';
	unsigned int t = 96;
	unsigned short int tt = 948;
	long double dd = 11112312.123123123;
	unsigned char xx = 22;

	printf("---------Start--------\n");
	ft_printf("User s: %s\n", asd);
	printf("Real s: %s\n", asd);

	printf("----------------------\n");
	ft_printf("User c: %c\n", a);
	printf("Real c: %c\n", a);

	printf("----------------------\n");
	ft_printf("User d: %.d\n", x);	
	printf("Real d: %.d\n", x);

	printf("----------------------\n");
	ft_printf("User i: %i %i %i\n", 12, 012, 0x12);
	printf("Real i: %i %i %i\n", 12, 012, 0x12);

	printf("----------------------\n");
	ft_printf("User u: %u\n", t);
	printf("Real u: %u\n", t);

	printf("----------------------\n");
	ft_printf("User o: %20.10o\n", x);
	printf("Real o: %20.10o\n", x);

	printf("----------------------\n");
	ft_printf("User x: %x\n", x);
	printf("Real x: %x\n", x);

	printf("----------------------\n");
	ft_printf("User X: %20.10X\n", x);
	printf("Real X: %20.10X\n", x);

	printf("----------------------\n");
	ft_printf("User d: %+7.5d\n", -123);
	ft_printf("User d: %+7.3d\n", 12345);
	ft_printf("User d: %+5.3d\n", 1234567);
	ft_printf("User d: %+5.7d\n", 123);
	ft_printf("User d: %+3.7d\n", 12345);
	ft_printf("User d: %+3.5d\n", 1234567);

	
	printf("Real d: %+7.5d\n", -123);
	printf("Real d: %+7.3d\n", 12345);
	printf("Real d: %+5.3d\n", 1234567);
	printf("Real d: %+5.7d\n", 123);
	printf("Real d: %+3.7d\n", 12345);
	printf("Real d: %+3.5d\n", 1234567);

		printf("----------------------\n");
	long double asd1 = -3123.82312;
	double d = -11.1;
	ft_printf("User f: %f\n", d);//
	printf("Real f: %f\n", d);//

	ft_printf("User 20f: %20f\n", d);//
	printf("Real 20f: %20f\n", d);//
	ft_printf("User .14f: %.18f\n", d);
	printf("Real .14f: %.18f\n", d);
	ft_printf("User +f: %+f\n", d);//
	printf("Real +f: %+f\n", d);//
	ft_printf("User +30.20f: %+30.19f\n", d);
	printf("Real +30.20f: %+30.19f\n", d);
	ft_printf("User 020f: %020f\n", d);//
	printf("Real 020f: %020f\n", d);//
	ft_printf("User #f: %#20f\n", d);//
	printf("Real #f: %#20f\n", d);//
	ft_printf("User -20f: %-20f%f\n", d, d);//
	printf("Real -20f: %-20f%f\n", d, d);//
	ft_printf("User f: %.3f\n", d);//
	printf("Real f: %.3f\n", d);//

	ft_printf("User o: %#o\n", x);
	printf("Real o: %#o\n", x);
	ft_printf("User x: %#x\n", x);
	printf("Real x: %#x\n", x);
	ft_printf("User X: %#X\n", x);
	printf("Real X: %#X\n", x);
	ft_printf("User o: %#20o\n", x);
	printf("Real o: %#20o\n", x);
	ft_printf("User x: %#20x\n", x);
	printf("Real x: %#20x\n", x);
	ft_printf("User X: %#20X\n", x);
	printf("Real X: %#20X\n", x);
	ft_printf("User o: %#20.10o\n", x);
	printf("Real o: %#20.10o\n", x);
	ft_printf("User x: %#20.10x\n", x);
	printf("Real x: %#20.10x\n", x);
	ft_printf("User X: %#20.10X\n", x);
	printf("Real X: %#20.10X\n", x);
	while (1);
	return (0);
}
