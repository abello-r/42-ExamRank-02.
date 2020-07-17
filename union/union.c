
#include <unistd.h>

int main (int argc, char **argv)
{
	int flag[255] = {0};
	int x;
	int y;

	if (argc == 3)
	{
		x = 1;
		while (x < 3)
		{
			y = 0;
			while(argv[x][y])
			{
				if (!flag[(unsigned char)argv[x][y]])
				{
					flag[(unsigned char)argv[x][y]] = 1;
					write(1, &argv[x][y], 1);
				}
				y++;
			}
			x++;
		}
	}
	write(1, "\n", 1);
	return (0);
}

// Para este ejercicio creamos una Array con un total de 255 caracteres (Tabla ascii extendida), 
// la rellenamos de '0' para trabajar con binarios, 1 = existe 0 = no existe.
// creamos dos contadores, para poder movernos por el Argc y el Argv.
// con el (x) nos movemos de argumento, y con el (y) nos movemos sobre el argumento.
// creamos una condición para trabajar solo con 3 argumentos, en caso de haber màs devolvemos "\n" y retornamos.
// posicionamos el contador (x) sobre el primer argumento que es el siguiente al (./a.out).
// creamos un bucle de dos vueltas porque solo trabajaremos sobre 2 argumentos.
// igualamos el contador que recorrerá los arrays a 0
// mientras exista argv
// si en la tabla que hemos llenado de '0' no existe ningun dato ( 0 != [x] ).
// lo igualamos a 1, y lo escribimos, asi cuando volvamos a pasar el bucle pero con el otro argumento, reconocerá que ya existe un dato
// asi evitamos que lo vuelva a escribir.
// aumentamos los contadores..
// escribimos el salto de linea.
// fin.
// PD: Es importante castear el argv a unsigned char, si no cuando compiles con flag te dara error.