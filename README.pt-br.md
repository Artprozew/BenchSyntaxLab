# BenchSyntaxLab

[![en](https://img.shields.io/badge/lang-en-blue
)](https://github.com/Artprozew/BenchSyntaxLab/blob/main/README.md)

Esse é um projeto experimental que avalia a performance de diversas linguagens de programação que eu tenho usado e estudado ativamente ultimamente. Ele também inclui alguns **superconjuntos** um tanto quanto interessantes, como o Cython (um superset Python "semelhante" ao C).

Você não apenas pode comparar a performance dessas linguagens, mas também é incentivado a explorar sua **sintaxe**, **composição**, processo de **building** e outros aspectos. Sinta-se à vontade para dar uma olhada no código-fonte! 😊

Tenho tentado manter uma estrutura similar para cada código ao mesmo tempo em que aproveito seus recursos únicos, e também garantindo que eles irão entregar o desempenho ideal para cada cenário específico.

## Índice

- [BenchSyntaxLab](#benchsyntaxlab)
  - [Índice](#índice)
  - [Benchmarks](#benchmarks)
    - [Especificações do PC](#especificações-do-pc)
    - [Números primos](#números-primos)
  - [Compilando e Executando](#compilando-e-executando)
    - [Recomendado](#recomendado)
    - [Configuração Rápida](#configuração-rápida)
  - [Contribuindo](#contribuindo)
    - [Estilo de Código](#estilo-de-código)
  - [Licença](#licença)

## Benchmarks

### Especificações do PC

> - CPU: AMD Ryzen 5 3600
> - RAM: 2x16GB DDR4 ~2666MHz

### Números primos

Teste obtendo 20.000 números primos em 10 execuções, usando a mesma estrutura de código e algoritmo ("divisão por tentativa").

| Linguagem     | Tempo médio (s)  | Notas          |
|:------------: | :--------------: | :-------------:|
| C             | 0.825s           | gcc -O2        |
| C++           | 0.826s           | g++ -O2        |
| Cython        | 0.827s           | MSVC /O2       |
| Python        | 10.790s          | CPython 3.11.3 |

## Compilando e Executando

Você irá precisar:

- Compilador C/C++ ([MSVC](https://visualstudio.microsoft.com/downloads/) é recomendado, ou [MinGW](https://sourceforge.net/projects/mingw/))
- [Python 3.11](https://www.python.org/downloads/release/python-3119/)

### Recomendado

- [Git](https://git-scm.com/downloads)
- Make (para Windows: <sup>[[1]](https://gnuwin32.sourceforge.net/packages/make.htm)[[2]](https://nerdyelectronics.com/install-mingw-on-windows-for-make/)</sup>)

Não se esqueça de definir suas variáveis de ambiente [PATH](https://superuser.com/questions/284342/what-are-path-and-other-environment-variables-and-how-can-i-set-or-use-them) adequadamente (se necessário).

### Configuração Rápida

Esses comandos irão clonar o repositório do projeto, instalar as dependências Python necessárias e compilar/executar o projeto.

```shell
git clone https://github.com/Artprozew/BenchSyntaxLab.git
cd BenchSyntaxLab
python -m pip install -r requirements.txt
make
```

O comando `make` por padrão irá compilar e executar cada linguagem no projeto. Você pode alterar esse comportamento usando `make <linguagem/target>`. Por exemplo: `make python` executará apenas o código Python.

## Contribuindo

Se você quiser contribuir com esse projeto, dê um fork no repositório e crie uma branch separada com suas mudanças. Quando terminar, você pode abrir um pull request! 🤝

### Estilo de Código

Esse projeto geralmente segue estas diretrizes de estilo:

- [PEP8](https://peps.python.org/pep-0008/)
- [Linux Kernel](https://www.kernel.org/doc/html/v4.10/process/coding-style.html)

No entanto, atualmente somos flexíveis com detalhes menores (ex., tabs ainda têm 4 espaços de largura em vez de 8).

## Licença

Este projeto é licenciado sob a licença MIT;
Consulte: [LICENSE](https://github.com/Artprozew/BenchSyntaxLab/blob/main/LICENSE)
