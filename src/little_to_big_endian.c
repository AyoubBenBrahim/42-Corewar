#include <stdio.h>

typedef unsigned int uint32_t;

unsigned int little_to_big_endian(unsigned int x);
uint32_t    swap_uint32(uint32_t d);
uint32_t    other_method(uint32_t a);

// int main( )
// {
// 	int Little_Endian = 0xAABBCCDD ;

// 	printf("\n Little_Endian = %d\n", Little_Endian);

// 	printf("\n Little_Endian = 0x%X\n", Little_Endian);

// 	printf("\n Big_Endian    = 0x%X\n", little_to_big_endian(Little_Endian));

// 	printf("\n Big_Endian    = 0x%X\n", swap_uint32(Little_Endian));

// 	printf("\n Big_Endian    = 0x%X\n", other_method(Little_Endian));
// }

unsigned int little_to_big_endian(unsigned int x)
{
	return (  ((x >> 24) & 0x000000ff)
			| ((x >> 8) & 0x0000ff00)
			| ((x << 8) & 0x00ff0000)
			| ((x << 24) & 0xff000000));
}

uint32_t	swap_uint32(uint32_t d)
{
	return (  (d & 0x000000ff) << 24
			| (d & 0x0000ff00) << 8
			| (d & 0x00ff0000) >> 8
			| (d & 0xff000000) >> 24);
}

uint32_t    other_method(uint32_t a)
{
	a = ((a & (0x0000FFFF)) << 16) | ((a & (0xFFFF0000)) >> 16);
	a = ((a & (0x00FF00FF)) << 8) | ((a & (0xFF00FF00)) >> 8);
	return a;
}
