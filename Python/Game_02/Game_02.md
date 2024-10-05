# Projeto de Jogo em Python com PyGame

## _Funcionalidades_

- **Movimentação pelo Mapa**: Permite ao jogador se deslocar em todas as direções do plano cartesiano (X, -X, Y, -Y).
- **Sistema de Colisões**: Implementa detecções de colisão para interações realistas entre o jogador e objetos do ambiente.
- **Portal de Teleporte**: Facilita o transporte instantâneo entre diferentes áreas do jogo.

## _O que eu implementei?_

### Sistema de Sprites com Sprite Sheet

- **Movimentação Básica**: Habilita o movimento do jogador nas quatro direções (cima, baixo, esquerda e direita).
- **Sprite Sheet**: Utiliza uma única imagem para representar várias animações de personagem.
- **Troca de Sprites**: Atualiza o sprite exibido conforme a direção pressionada pelo jogador.
- **Adição de NPC**: Introduzido um NPC chamado May, que está jogando Nintendo.

## _Tecnologias Utilizadas_

- **Visual Studio Code**: Ambiente de desenvolvimento integrado (IDE) para codificação.
- **Biblioteca PyGame**: Ferramenta essencial para a criação de jogos em Python.
- **Linguagem Python**: Linguagem de programação utilizada para desenvolvimento do jogo.
- **ChatGPT**: Auxiliou na formatação e organização do texto em Markdown.
- **GitHub**: Plataforma para versionamento e colaboração no desenvolvimento do projeto.
- **Remove.bg**: Site utilizado para remover o fundo das sprites, facilitando a criação de personagens e objetos.


## Bugs/Problemas Conhecidos

- **Colisão**: Faltam colisões para as paredes, e as colisões existentes estão com problemas.

## Como clonar apenas a pasta Python do repositório

Para clonar apenas a pasta `Python/Game_02` do repositório `Meus-Estudos`, use o comando `git sparse-checkout`. Isso permitirá que você baixe somente o conteúdo dessa pasta, economizando espaço e tempo.

Siga os comandos abaixo:

```bash
# Clone o repositório sem baixar o conteúdo completo
git clone --no-checkout https://github.com/alexschimitz/Meus-Estudos.git

# Entre no diretório do repositório
cd Meus-Estudos

# Habilite o sparse checkout
git sparse-checkout init --cone

# Defina para baixar apenas a pasta Python/Game_02
git sparse-checkout set Python/Game_02

# Baixe o conteúdo da pasta
git checkout
```

Agora você tem um markdown completo, direto ao ponto, sem divisões explicativas, apenas com as instruções e o código necessário.


