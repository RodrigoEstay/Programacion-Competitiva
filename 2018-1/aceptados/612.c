#include <stdlib.h>
#include <stdio.h>

// Programa hecho sin ayuda.

// Declaramos la informacion del adn como estructura para ordenarlos con qsort posteriormente.

struct dnaInf{
	char chain[51];
	int unsortedness;
};

int cmpf(const void *a, const void *b);

int main(){
	int n, m, i, j, M;
	scanf("%d", &M);
	while(M--){
		scanf("%d%d", &n, &m);
		struct dnaInf dna[m];
		int total=m;

		// 	Simplemente para cada cadena de adn escaneada le contamos las veces de que
		// se cumple que la letra es "mayor" a letras posteriores a esta, cada vez que
		// esto ocurre aumentamos el contador de "unsortedness".

		for(m=0;m<total;++m){
			scanf("%s", dna[m].chain);
			dna[m].unsortedness=0;
			for(i=0;i<n-1;++i){
				for(j=i+1;j<n;++j){
					if(dna[m].chain[i]>dna[m].chain[j]) ++dna[m].unsortedness;
				}
			}
		}

		// 	Una vez que tenemos la informacion de todas las cadenas, las ordenamos con
		// qsort con una funcion personalizada.

		qsort(dna, total, sizeof(struct dnaInf), cmpf);
		for(i=0;i<total;++i) printf("%s\n", dna[i].chain);
		if(M) printf("\n");
	}
	return 0;
}

//  Esta es la funcion "personalizada", con esta simplemente le mandamos la diferencia
// entre los unsortedness del primero y del segundo, de esta manera se ordenan por el
// que tiene menor valor primero, y luego el que tiene mayor.
// 	Cabe notar que hacemos casting de const void a struct dnaInf, ya que qsort manda
// de este tipo de valor, con el cual no podemos trabajar.

int cmpf(const void *a, const void *b){
	struct dnaInf *c, *d;
	c=(struct dnaInf*)a;
	d=(struct dnaInf*)b;
	return c->unsortedness - d->unsortedness;
}