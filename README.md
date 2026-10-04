# Jogo de Adivinhação

Jogo de adivinhação em C para terminal. O código foi escrito acompanhando o livro [Introdução à programação em C: Os primeiros passos de um desenvolvedor](https://www.casadocodigo.com.br/products/livro-introducao-c), de [Maurício Aniche](https://www.linkedin.com/in/mauricioaniche/), publicado pela [Casa do Código](https://www.casadocodigo.com.br/), que ensina programação por meio da construção de jogos.

## Sumário

- [Sobre o projeto](#sobre-o-projeto)
- [Como jogar](#como-jogar)
- [Melhorias implementadas](#melhorias-implementadas)
- [Pré-requisitos](#pré-requisitos)
- [Como compilar e executar](#como-compilar-e-executar)
  - [Terminal (GCC)](#terminal-gcc)
  - [Code::Blocks](#codeblocks)
  - [Eclipse CDT](#eclipse-cdt)
  - [Visual Studio Code](#visual-studio-code)
  - [Dev-C++](#dev-c)
  - [Visual Studio](#visual-studio)
- [Problemas comuns](#problemas-comuns)
- [Conceitos praticados](#conceitos-praticados)
- [Referências](#referências)
- [Créditos](#créditos)

## Sobre o projeto

Este repositório registra meus estudos da linguagem C. O jogo é o primeiro dos três projetos propostos no livro e foi implementado seguindo os capítulos passo a passo. O projeto e o código original são de autoria de Maurício Aniche. Sobre essa base, acrescentei algumas funcionalidades próprias, descritas em [Melhorias implementadas](#melhorias-implementadas).

O programa sorteia um número secreto dentro de um intervalo definido pelo jogador, que precisa descobri-lo dentro de um número limitado de tentativas. A cada chute, o jogo informa se o valor foi maior ou menor que o número secreto.

## Como jogar

1. Informe o início e o fim do intervalo em que o número secreto será sorteado.
2. Escolha o nível de dificuldade.
3. Digite um chute a cada tentativa.
4. Use as dicas para se aproximar do número secreto.
5. Ao final da partida, escolha se deseja jogar novamente ou encerrar o jogo.

O intervalo deve usar números não negativos, e o fim deve ser maior ou igual ao início.

| Nível   | Tentativas |
|---------|------------|
| Fácil   | 20         |
| Médio   | 15         |
| Difícil | 6          |

### Pontuação

O jogador começa cada partida com 1000 pontos. A cada chute, perde metade da diferença entre o chute e o número secreto. Quanto mais próximos os chutes, maior a pontuação final.

Chutes negativos e chutes iguais ao imediatamente anterior são rejeitados: o jogo exibe um aviso e a tentativa não é consumida.

## Melhorias implementadas

As funcionalidades abaixo não fazem parte do código do livro e foram acrescentadas como exercício:

- **Intervalo personalizado:** o jogador define o início e o fim do intervalo em que o número secreto é sorteado. Na versão original, o intervalo era fixo, de 0 a 99.
- **Jogar novamente:** ao final de cada partida, o jogador escolhe entre iniciar outra ou encerrar o jogo, sem precisar executar o programa de novo. Cada nova partida recomeça com a pontuação inicial e um novo número secreto.
- **Bloqueio de chute repetido:** o mesmo número não pode ser chutado duas vezes seguidas. O jogo guarda apenas o último chute, avisa o jogador e não contabiliza a tentativa.
- **Constantes para as regras do jogo:** a pontuação inicial e o número de tentativas de cada nível de dificuldade são definidos com `#define`, em vez de valores soltos no código.

## Pré-requisitos

O projeto usa apenas a biblioteca padrão do C e precisa de um compilador com suporte a C99 ou superior. A tabela resume o que cada ambiente exige:

| Ambiente           | Compilador incluído          | O que instalar                                                     | Sistemas              |
|--------------------|------------------------------|--------------------------------------------------------------------|-----------------------|
| Terminal (GCC)     | Não se aplica                | GCC (MinGW-w64 no Windows)                                         | Windows, Linux, macOS |
| Code::Blocks       | Sim, no instalador com MinGW | Apenas a IDE                                                       | Windows, Linux, macOS |
| Eclipse CDT        | Não                          | IDE e GCC                                                          | Windows, Linux, macOS |
| Visual Studio Code | Não                          | Editor, extensão C/C++ e GCC                                       | Windows, Linux, macOS |
| Dev-C++            | Sim (TDM-GCC)                | Apenas a IDE                                                       | Windows               |
| Visual Studio      | Sim (MSVC)                   | IDE com a carga de trabalho "Desenvolvimento para desktop com C++" | Windows               |

### Instalando o GCC

Necessário para o terminal, o Eclipse CDT e o Visual Studio Code.

**Windows**

1. Instale o [MSYS2](https://www.msys2.org/).
2. No terminal do MSYS2, execute:

```bash
   pacman -S mingw-w64-ucrt-x86_64-gcc
```

3. Adicione `C:\msys64\ucrt64\bin` à variável de ambiente `PATH`.

**Linux (Debian/Ubuntu)**

```bash
sudo apt update
sudo apt install build-essential
```

**macOS**

```bash
xcode-select --install
```

Para confirmar a instalação em qualquer sistema:

```bash
gcc --version
```

## Como compilar e executar

Primeiro, obtenha o código:

```bash
git clone https://github.com/RafaelRodriguesMagdaleno/Jogo_Advinhacao.git
cd Jogo_Advinhacao
```

### Terminal (GCC)

```bash
gcc Jogo_Adivinhacao.c -o jogo_adivinhacao
```

Para executar no Linux ou macOS:

```bash
./jogo_adivinhacao
```

Para executar no Windows:

```bash
.\jogo_adivinhacao.exe
```

### Code::Blocks

**Requisitos:** [Code::Blocks](https://www.codeblocks.org/downloads/). No Windows, baixe o instalador que tem `mingw` no nome, pois ele já inclui o compilador. No Linux e no macOS, instale o GCC separadamente.

1. Abra o Code::Blocks.
2. Acesse `File > Open` e selecione `Jogo_Adivinhacao.c`.
3. Pressione `F9` ou acesse `Build > Build and run`.

O jogo abre em uma janela de console própria.

Para trabalhar com um projeto em vez de um arquivo avulso:

1. Acesse `File > New > Project > Console application`.
2. Selecione a linguagem `C` e defina nome e pasta do projeto.
3. Substitua o `main.c` gerado pelo conteúdo de `Jogo_Adivinhacao.c`.
4. Pressione `F9`.

### Eclipse CDT

**Requisitos:** [Eclipse IDE for C/C++ Developers](https://www.eclipse.org/downloads/packages/) e GCC instalado e disponível no `PATH`. O Eclipse não inclui compilador.

1. Acesse `File > New > C/C++ Project`.
2. Selecione `C Managed Build` e avance.
3. Informe o nome do projeto e escolha `Executable > Empty Project`.
4. Em `Toolchains`, selecione `MinGW GCC` (Windows), `Linux GCC` ou `MacOSX GCC`.
5. Copie `Jogo_Adivinhacao.c` para a pasta do projeto, ou use `File > Import > General > File System`.
6. Compile com `Project > Build All` (`Ctrl+B`).
7. Execute com `Run > Run As > Local C/C++ Application`.

Os nomes dos menus podem variar um pouco entre versões do Eclipse.

### Visual Studio Code

**Requisitos:** [Visual Studio Code](https://code.visualstudio.com/), a extensão **C/C++** da Microsoft e GCC instalado e disponível no `PATH`.

1. Acesse `File > Open Folder` e abra a pasta do projeto.
2. Instale a extensão C/C++ pela aba de extensões (`Ctrl+Shift+X`).
3. Abra `Jogo_Adivinhacao.c`.
4. Clique na seta de execução no canto superior direito e escolha `Run C/C++ File`.
5. Selecione o compilador `gcc` quando solicitado.

Como alternativa, abra o terminal integrado (`` Ctrl+` ``) e use os comandos da seção [Terminal (GCC)](#terminal-gcc).

### Dev-C++

**Requisitos:** [Embarcadero Dev-C++](https://www.embarcadero.com/free-tools/dev-cpp), que já inclui o compilador TDM-GCC. Disponível apenas para Windows.

1. Acesse `Arquivo > Abrir` e selecione `Jogo_Adivinhacao.c`.
2. Pressione `F11` ou acesse `Executar > Compilar & Executar`.

Versões antigas, como o Orwell Dev-C++ 5.11, compilam em C90 por padrão. Nesse caso, acesse `Ferramentas > Opções do Compilador` e adicione `-std=c99` aos comandos de compilação.

### Visual Studio

**Requisitos:** [Visual Studio Community](https://visualstudio.microsoft.com/) com a carga de trabalho **Desenvolvimento para desktop com C++**. Disponível apenas para Windows.

1. Acesse `Arquivo > Novo > Projeto` e escolha `Projeto Vazio`.
2. No Gerenciador de Soluções, clique com o botão direito em `Arquivos de Origem` e escolha `Adicionar > Item Existente`.
3. Selecione `Jogo_Adivinhacao.c`. A extensão `.c` faz o arquivo ser compilado como C.
4. Acesse `Projeto > Propriedades > C/C++ > Pré-processador > Definições do Pré-processador` e adicione `_CRT_SECURE_NO_WARNINGS`. Sem isso, o compilador da Microsoft rejeita o uso de `scanf`.
5. Pressione `Ctrl+F5` para compilar e executar.

## Problemas comuns

**`gcc` não é reconhecido como comando**
O compilador não está no `PATH`. Revise a seção [Instalando o GCC](#instalando-o-gcc) e reabra o terminal ou a IDE.

**`'for' loop initial declarations are only allowed in C99 mode`**
O compilador está em modo C90. Adicione a opção `-std=c99` na compilação.

**Acentos aparecem como caracteres estranhos**
A codificação do arquivo não corresponde à do terminal. Verifique em qual codificação o arquivo está salvo (UTF-8 ou ANSI) e ajuste a do terminal ou a do editor para a mesma.

**Eclipse: `Launch failed. Binary not found`**
O projeto ainda não foi compilado ou o Eclipse não encontrou o compilador. Compile com `Ctrl+B` e confira os erros na aba `Console`.

**Eclipse no Windows: as perguntas só aparecem depois de digitar**
O console interno do Eclipse armazena a saída em buffer. Execute o programa em um terminal externo ou adicione `setvbuf(stdout, NULL, _IONBF, 0);` no início da função `main`.

**Visual Studio: erro C4996 em `scanf`**
Adicione `_CRT_SECURE_NO_WARNINGS` às definições do pré-processador, conforme a seção [Visual Studio](#visual-studio).

## Conceitos praticados

- Entrada e saída de dados (`scanf` e `printf`)
- Variáveis e tipos de dados (`int` e `double`)
- Operações matemáticas
- Estruturas condicionais (`if`, `else` e `switch`)
- Laços de repetição (`for`, `while`, `break` e `continue`)
- Geração de números aleatórios (`rand`, `srand` e `time`)
- Constantes com `#define`

## Referências

ANICHE, Maurício. [Introdução à programação em C: Os primeiros passos de um desenvolvedor](https://www.casadocodigo.com.br/products/livro-introducao-c). São Paulo: [Casa do Código](https://www.casadocodigo.com.br/), 2015. ISBN 978-85-5519-088-9.

## Créditos

- Projeto e código original: [Maurício Aniche](https://www.linkedin.com/in/mauricioaniche/), no livro [Introdução à programação em C](https://www.casadocodigo.com.br/products/livro-introducao-c)
- Implementação para estudo e melhorias: [Rafael Rodrigues Magdaleno](https://github.com/RafaelRodriguesMagdaleno) ([LinkedIn](https://linkedin.com/in/rafael-rodrigues-magdaleno-5476a0271))
