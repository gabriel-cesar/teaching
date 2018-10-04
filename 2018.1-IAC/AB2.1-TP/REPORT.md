# Identificação

* Página do repositório do trabalho do <a href="https://github.com/gabriel-cesar/teaching"> GitHub</a>

* Discente 1
	* Nome: Gabriel César Olimpio Alves
	* Matrícula: 18110467
* Discente 2
	* Nome: Marcos Ivan de Almeida Melo
	* Matrícula: 18110498
* Discente 3
	* Nome: Yan Pires Siqueira Pequeno
	* Matrícula: 18111784
* Obs.: Distribuição igualitária da nota.

# Resultados

## Compilação e execução:

* Para a compilação do programa, sugerimos que seja feito com a seguinte estrutura.
	<p><ul>
			<li>gcc main.c -o main</li>
		</ul>
	</p>
* Para a execução do mesmo, a estrutura será da seguinte maneira.
	<p>
		<ul>
			<li>./main ucp</li>
			<li>./main ucp-mem</li>
		</ul>
	</p>

## Utilização intensa da UCP

* Para podermos realizar a verificação da utilização da UCP, adicionamos uma função que gerará uma repetição na execução do seu escopo, como exemplificado abaixo.

	* for ( ; ; ){
	}

* Quando executada, a UCP realizou o loop continuamente até o momento em que o computador matou o processo pai, pois atingiu o limite de execução da máquina. Como o uso da UCP estava elevado (Figura 1) resolvemos adicionar a função “usleep()”, para que a UCP interrompa o processo por um certo intervalo de tempo, definido entre os parênteses do comando, na escala de milissegundos (em UNIX). Feito isso, a função ficou com a seguinte formatação:

	* for ( ; ; ) {
		usleep(100);
	}

* Com as mudanças já efetuadas, pudemos notar uma diminuição absurda na utilização da UCP. Lembrando que, para quaisquer que sejam os valores de parâmetro da função “usleep()”, a constância dos resultados se mantém, ou seja, a alteração do valor apenas altera o tempo em que o programa será pausado, alterando, assim, o valor de utilização da UCP, sendo essa relação inversamente proporcional.
	
	<img src="images/high_cpu.jpg"> <img src="images/low_cpu.jpg">

* Analisando o gráfico presente na figura 2, é fácil ver que a UCP sofreu de uma ligeira alteração na utilização ao longo do tempo, sendo essa alteração de forma quase que constante, assemelhando-se ao gráfico de uma função afim. Lembrando também que a utilização da UCP reduziu-se bastante com a introdução do comando “usleep()”.

## Utilização intensa da UCP e memória

* Já para verificar a utilização da UCP e da memória RAM de forma concomitante, foi adicionada, primeiramente, a função da seguinte forma.
	* for ( ; ; ){
		malloc (sizeof (int) );
	}

* Assim como no experimento anterior, percebemos dificuldade por parte do computador, porém, agora, ocorreu um travamento, precisando forçar o desligamento, pois agora, além da utilização da UCP, estava ocorrendo de forma simultânea um alocamento de memória de forma elevada, gerado pela função “malloc()”. Após isso, resolvemos tomar a mesma medida e adicionar o comando “usleep()”, ficando com a seguinte face.
	
	* for ( ; ; ){
		malloc (sizeof (int) );
		usleep (100);
	}

* Os valores obtidos com a medição da utilização da UCP e da memória estão representados no gráfico da figura 3.

<img src="images/cpu_mem.jpg">

* TODO: Plotar um gráfico com os resultados das medições das seguintes métricas utilizadas para avaliar o comportamento do **processo filho**:
	*  **UCP**: consumo da UCP em porcentagem.
	*  **UCP-MEM**: consumo da memória principal em Kilobytes.
* TODO: Cada métrica deve ser plotada em duas curvas separadas.
* TODO: o eixo das abscissas deve representar o tempo medido a cada segundo e o eixo das coordenadas deve representar a métrica medida.

# Discussão
	
## Utilização intensa da UCP

TODO: explicar se o comportamento da curva **UCP** foi o esperado, sempre justificando sua resposta, referenciando o código fonte do programa e o gráfico do experimento realizado.

## Utilização intensa da UCP e memória

TODO: explicar se o comportamento da curva **UCP-MEM** foi o esperado, sempre justificando sua resposta, referenciando o código fonte do programa e o gráfico do experimento realizado.