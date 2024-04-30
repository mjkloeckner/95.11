/* guia07/ej08.c 
 * por Martin J. Klöckner
 * github.com/klewer-martin
 */

#include <stdio.h>

#define MASK_RED	0xFF0000
#define MASK_GREEN	0x00FF00
#define MASK_BLUE	0x0000FF

#define SHIFT_RED	16
#define SHIFT_GREEN	8
#define SHIFT_BLUE	0

typedef unsigned int uint;
typedef unsigned char uchar;
typedef enum { OK, ERROR_BRIGHTNESS_OUT_OF_RANGE, ERROR_NULL_POINTER } status_t;

uchar get_red(uint color);
uchar get_green(uint color);
uchar get_blue(uint color);

status_t rgb_components(uint color, uchar *red, uchar *green, uchar *blue);
status_t rgb_components2(uint color, uchar *red, uchar *green, uchar *blue);

uint mix_colors(uint color1, uint color2);
uint change_brightness(uint *color, float brightness);
uint complementary_color(uint color);

int main (void)
{
	uint color1 = 0xFF6464;
	uint color2 = 0x0100FF;

	printf("color1: %06X\n", color1);
	printf("color2: %06X\n", color2);
	printf("color2: %06X\n", complementary_color(color1));
	
	printf("%X\n", mix_colors(color1, color2));

	change_brightness(&color1, 1);

	printf("%d red\n", get_red(color1));
	printf("%d green\n", get_green(color1));
	printf("%d blue\n", get_blue(color1));

	return OK;
}

uchar get_red(uint color)
{
	return (uchar)((color & MASK_RED) >> SHIFT_RED);
}

uchar get_green(uint color)
{
	return (uchar)((color & MASK_GREEN) >> SHIFT_GREEN);
}

uchar get_blue(uint color)
{
	return (uchar)((color & MASK_BLUE) >> SHIFT_BLUE);
}

/* This implementation its independendent from other functions */
status_t rgb_components(uint color, uchar *red, uchar *green, uchar *blue)
{
	if(!red || !green || !blue) return ERROR_NULL_POINTER;

	*red = (uchar)((color & MASK_RED) >> SHIFT_RED);
	*green = (uchar)((color & MASK_GREEN) >> SHIFT_GREEN);
	*blue = (uchar)((color & MASK_BLUE) >> SHIFT_BLUE);

	return OK;
}

/* This implementation insted depends from other functions */
status_t rgb_components2(uint color, uchar *red, uchar *green, uchar *blue)
{
	if(!red || !green || !blue) return ERROR_NULL_POINTER;

	*red = get_red(color);
	*green = get_green(color);
	*blue = get_blue(color);

	return OK;
}

uint mix_colors(uint color1, uint color2)
{
	uint aux, res;

	/* Suma color con color, y lo va asignando en res, en caso de ser mayor al maximo 255, asigna 255 al color que corresponda */
	res = ((aux = ((color1 & MASK_RED) + (color2 & MASK_RED))) > MASK_RED) ? MASK_RED : aux;
	res += ((aux = ((color1 & MASK_GREEN) + (color2 & MASK_GREEN))) > MASK_GREEN) ? MASK_GREEN : aux;
	res += ((aux = ((color1 & MASK_BLUE) + (color2 & MASK_BLUE))) > MASK_BLUE) ? MASK_BLUE : aux;

	return res;
}

status_t change_brightness(uint *color, float brightness)
{
	if(!color) return ERROR_NULL_POINTER;
	else if(brightness < 0 || brightness > 100) return ERROR_BRIGHTNESS_OUT_OF_RANGE;

	/* Convierte el valor de brillo en porcentual */
	brightness *= .01;

	/* Multiplica cada color con brightness */
	*color = ((int)(((*color & MASK_RED) >> SHIFT_RED) * brightness) << SHIFT_RED) + (*color & ~MASK_RED);
	*color = ((int)(((*color & MASK_GREEN) >> SHIFT_GREEN) * brightness) << SHIFT_GREEN) + (*color & ~MASK_GREEN);
	*color = ((int)(((*color & MASK_BLUE) >> SHIFT_BLUE) * brightness) << SHIFT_BLUE) + (*color & ~MASK_BLUE);

	return OK;
}

uint complementary_color(uint color)
{
	return (MASK_RED - (color & MASK_RED)) + (MASK_GREEN - (color & MASK_GREEN)) + (MASK_BLUE - (color & MASK_BLUE));
}
