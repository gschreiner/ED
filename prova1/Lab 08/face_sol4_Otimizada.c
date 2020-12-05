/* A solução de Davair 100 -> https://www.clubedohardware.com.br/topic/1330623-uri-1944-c%C3%B3digo-em-c/

	Essa uma solução interessante e possui um desempenho superior as demais. De maneira geral o vetor arr é utilizado com uma pilha, cada letra é adiconada a ele, e o topo é controlado pela variável
	t.
	A variável T sempre anda de 4 em 4 elementos, e por isso trabalha como se fosse a pilha em si. Para alguns pode parecer que não esta usando uma pilha, mas o comportamento emulado no vetor é o de uma pilha.
	Perceba que a pilha arr tem 99999 elemento, no caso é exagero, apenas 4004 já seriam suficentes já que o máximo de elementos que poderiamos ter na pilha, segundo o problema, é 1000.
	T anda de 4 em 4 elementos para que os t-4 sejá o primeiro elemento do topo da pilha e t-1 seja o último, assim quando empilhamos sempre adicionamos elementos a arr e somamos a t. E para desemplilhar apenas decrementamos t em 4 posições.

*/

#include <stdio.h>


int main(int argc, char const *argv[]) {
	int n, s = 0, t = 4;
	char arr[99999] = { 'F', 'A', 'C', 'E' }; //inicializa a pilha
	char r1[2], r2[2], r3[2], r4[2];
	
	scanf("%d", &n);
	for (int i = 0; i < n; ++i) {
		scanf("%s%s%s%s", r1, r2, r3, r4); //lendo com %s ele se utiliza do fato de o scanf ler apenas até o proximo espaço ou \n assim evita o problema do \n do %c
		if (r1[0] == arr[t-1] && r2[0] == arr[t-2] && r3[0] == arr[t-3] && r4[0] == arr[t-4]) { //compara a leitura com o contrario do topo da pilha (por isso começa com t-1)
			t -= 4; //desempilha um elemento
			if (t == 0) //se a pilha esta vazia aciciona FACE
				arr[0] = 'F', arr[1] = 'A', arr[2] = 'C', arr[3] = 'E', t = 4;
			s++; //conta o número de premiados
		} else { //se o valor não for o contrario do topo da pilha, empilha o valor lido na pilha.
			arr[t] = r1[0], t++, arr[t] = r2[0], t++, arr[t] = r3[0], t++, arr[t] = r4[0], t++;
		}
	}
	
	printf("%d\n", s);
	return 0;
}