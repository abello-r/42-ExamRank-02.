
#include <unistd.h>

int main (int argc, char **argv)
{
	int flag[255] = {0};
	int x;
	int y;

	if (argc == 3)
	{
		x = 2;
		while (x > 0)
		{
			y = 0;
			while (argv[x][y])
			{
				if (x == 2 && !flag[(unsigned char)argv[x][y]])
					flag[(unsigned char)argv[x][y]] = 1;
				else if (x == 1 && flag[(unsigned char)argv[x][y]] == 1)
				{
					write(1, &argv[x][y], 1);
					flag[(unsigned char)argv[x][y]] = 2;
				}
				y++;
			}
			x--;
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
// condicionamos con un bucle para trabajar solo con los dos argumentos siguientes al ./a.out.
// igualamos el contador que se movera sobre las cadenas a (0).
// trabajamos sobre un bucle que diga "mientras exista argv hago lo siguiente".
// Sí estamos en el segundo argumento, ejemplo ( ./a.out = 0 hola = 1 > pepe = 2) y en la tabla de 255 no existe dato, la igualamos a 1.
// Luego, si no, sí estamos en el argumento 1 (explicado en la linea de arriba), y en nuestra tabla de 255 ya existe un dato, lo escribimos.
// y luego lo igualamos a 2, que quiere decir que ya no entra en nuestra cuenta binaria y asi no se volverá a escribir.
// aumentamos contadores.
// escribimos el salto de linea y retornamos (0).
// fin. 
// PD : Es importante castear dentro del flag el argv, en caso de no hacerlo, al compilar con flags (Wall Werror Wextra), mostrará un error.