#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define NUM_POKEMON 151
#define MAX_NOME 20
#define MAX_TIPO 20

// Estrutura para armazenar o Pokemon com o Indice original
typedef struct {
    char nome[MAX_NOME];
    char tipo[MAX_TIPO];
    int indice_original;
} Pokemon;

// Função de comparação para qsort e bsearch
int comparar(const void *a, const void *b) {
    const Pokemon *pokemonA = (const Pokemon *)a;
    const Pokemon *pokemonB = (const Pokemon *)b;
    return strcmp(pokemonA->nome, pokemonB->nome);
}

// Função para converter uma string para minúsculas
void toLowerCase(char *str) {
    for (int i = 0; str[i]; i++) {
        str[i] = tolower(str[i]);
    }
}

// Função para buscar Pokemon por nome ou listar os que contêm uma substring
void buscarPorNomeOuSubstring(Pokemon Pokedex[], int tamanho, const char *query) {
    char queryLower[MAX_NOME];
    strncpy(queryLower, query, sizeof(queryLower));
    queryLower[sizeof(queryLower) - 1] = '\0'; // Garante que a string esteja terminada
    toLowerCase(queryLower);

    int encontrado = 0;
    for (int i = 0; i < tamanho; i++) {
        char nomeLower[MAX_NOME];
        strncpy(nomeLower, Pokedex[i].nome, sizeof(nomeLower));
        nomeLower[sizeof(nomeLower) - 1] = '\0'; // Garante que a string esteja terminada
        toLowerCase(nomeLower);

        if (strstr(nomeLower, queryLower) != NULL) {
            printf("Pokemon encontrado: %s, Tipo: %s, Indice Original: %d\n",
                   Pokedex[i].nome, Pokedex[i].tipo, Pokedex[i].indice_original);
            encontrado = 1;
        }
    }
    if (!encontrado) {
        printf("Nenhum Pokemon encontrado com a substring '%s'.\n", query);
    }
}

int main() {
    Pokemon Pokedex[151] = {
        {"Bulbasaur", "Grama", 1}, {"Ivysaur", "Grama", 2}, {"Venusaur", "Grama", 3},
        {"Charmander", "Fogo", 4}, {"Charmeleon", "Fogo", 5}, {"Charizard", "Fogo/Voador", 6},
        {"Squirtle", "Agua", 7}, {"Wartortle", "Agua", 8}, {"Blastoise", "Agua", 9},
        {"Caterpie", "Inseto", 10}, {"Metapod", "Inseto", 11}, {"Butterfree", "Inseto/Voador", 12},
        {"Weedle", "Inseto/Veneno", 13}, {"Kakuna", "Inseto/Veneno", 14}, {"Beedrill", "Inseto/Veneno", 15},
        {"Pidgey", "Normal/Voador", 16}, {"Pidgeotto", "Normal/Voador", 17}, {"Pidgeot", "Normal/Voador", 18},
        {"Rattata", "Normal", 19}, {"Raticate", "Normal", 20}, {"Spearow", "Normal/Voador", 21},
        {"Fearow", "Normal/Voador", 22}, {"Ekans", "Veneno", 23}, {"Arbok", "Veneno", 24},
        {"Pikachu", "Eletrico", 25}, {"Raichu", "Eletrico", 26}, {"Sandshrew", "Terra", 27},
        {"Sandslash", "Terra", 28}, {"Nidoran♀", "Veneno", 29}, {"Nidorina", "Veneno", 30},
        {"Nidoqueen", "Veneno/Terra", 31}, {"Nidoran♂", "Veneno", 32}, {"Nidorino", "Veneno", 33},
        {"Nidoking", "Veneno/Terra", 34}, {"Clefairy", "Fada", 35}, {"Clefable", "Fada", 36},
        {"Vulpix", "Fogo", 37}, {"Ninetales", "Fogo", 38}, {"Jigglypuff", "Normal/Fada", 39},
        {"Wigglytuff", "Normal/Fada", 40}, {"Zubat", "Veneno/Voador", 41}, {"Golbat", "Veneno/Voador", 42},
        {"Oddish", "Grama/Veneno", 43}, {"Gloom", "Grama/Veneno", 44}, {"Vileplume", "Grama/Veneno", 45},
        {"Paras", "Inseto/Grama", 46}, {"Parasect", "Inseto/Grama", 47}, {"Venonat", "Inseto/Veneno", 48},
        {"Venomoth", "Inseto/Veneno", 49}, {"Diglett", "Terra", 50}, {"Dugtrio", "Terra", 51},
        {"Meowth", "Normal", 52}, {"Persian", "Normal", 53}, {"Psyduck", "Agua", 54},
        {"Golduck", "Agua", 55}, {"Mankey", "Lutador", 56}, {"Primeape", "Lutador", 57},
        {"Growlithe", "Fogo", 58}, {"Arcanine", "Fogo", 59}, {"Poliwag", "Agua", 60},
        {"Poliwhirl", "Agua", 61}, {"Poliwrath", "Agua/Lutador", 62}, {"Abra", "Psiquico", 63},
        {"Kadabra", "Psiquico", 64}, {"Alakazam", "Psiquico", 65}, {"Machop", "Lutador", 66},
        {"Machoke", "Lutador", 67}, {"Machamp", "Lutador", 68}, {"Bellsprout", "Grama/Veneno", 69},
        {"Weepinbell", "Grama/Veneno", 70}, {"Victreebel", "Grama/Veneno", 71},
        {"Tentacool", "Agua/Veneno", 72}, {"Tentacruel", "Agua/Veneno", 73}, {"Geodude", "Pedra/Terra", 74},
        {"Graveler", "Pedra/Terra", 75}, {"Golem", "Pedra/Terra", 76}, {"Ponyta", "Fogo", 77},
        {"Rapidash", "Fogo", 78}, {"Slowpoke", "Agua/Psiquico", 79}, {"Slowbro", "Agua/Psiquico", 80},
        {"Magnemite", "Eletrico/Aço", 81}, {"Magneton", "Eletrico/Aço", 82},
        {"Farfetch'd", "Normal/Voador", 83}, {"Doduo", "Normal/Voador", 84}, {"Dodrio", "Normal/Voador", 85},
        {"Seel", "Agua", 86}, {"Dewgong", "Agua/Gelo", 87}, {"Grimer", "Veneno", 88},
        {"Muk", "Veneno", 89}, {"Shellder", "Agua", 90}, {"Cloyster", "Agua/Gelo", 91},
        {"Gastly", "Fantasma/Veneno", 92}, {"Haunter", "Fantasma/Veneno", 93}, {"Gengar", "Fantasma/Veneno", 94},
        {"Onix", "Pedra/Terra", 95}, {"Drowzee", "Psiquico", 96}, {"Hypno", "Psiquico", 97},
        {"Krabby", "Agua", 98}, {"Kingler", "Agua", 99}, {"Voltorb", "Eletrico", 100},
        {"Electrode", "Eletrico", 101}, {"Exeggcute", "Grama/Psiquico", 102}, {"Exeggutor", "Grama/Psiquico", 103},
        {"Cubone", "Terra", 104}, {"Marowak", "Terra", 105}, {"Hitmonlee", "Lutador", 106},
        {"Hitmonchan", "Lutador", 107}, {"Lickitung", "Normal", 108}, {"Koffing", "Veneno", 109},
        {"Weezing", "Veneno", 110}, {"Rhyhorn", "Terra/Pedra", 111}, {"Rhydon", "Terra/Pedra", 112},
        {"Chansey", "Normal", 113}, {"Tangela", "Grama", 114}, {"Kangaskhan", "Normal", 115},
        {"Horsea", "Agua", 116}, {"Seadra", "Agua", 117}, {"Goldeen", "Agua", 118},
        {"Seaking", "Agua", 119}, {"Staryu", "Agua", 120}, {"Starmie", "Agua/Psiquico", 121},
        {"Mr. Mime", "Psiquico/Fada", 122}, {"Scyther", "Inseto/Voador", 123}, {"Jynx", "Gelo/Psiquico", 124},
        {"Electabuzz", "Eletrico", 125}, {"Magmar", "Fogo", 126}, {"Pinsir", "Inseto", 127},
        {"Tauros", "Normal", 128}, {"Magikarp", "Agua", 129}, {"Gyarados", "Agua/Voador", 130},
        {"Lapras", "Agua/Gelo", 131}, {"Ditto", "Normal", 132}, {"Eevee", "Normal", 133},
        {"Vaporeon", "Agua", 134}, {"Jolteon", "Eletrico", 135}, {"Flareon", "Fogo", 136},
        {"Porygon", "Normal", 137}, {"Omanyte", "Pedra/Agua", 138}, {"Omastar", "Pedra/Agua", 139},
        {"Kabuto", "Pedra/Agua", 140}, {"Kabutops", "Pedra/Agua", 141}, {"Aerodactyl", "Pedra/Voador", 142},
        {"Snorlax", "Normal", 143}, {"Articuno", "Gelo/Voador", 144}, {"Zapdos", "Eletrico/Voador", 145},
        {"Moltres", "Fogo/Voador", 146}, {"Dratini", "Dragão", 147}, {"Dragonair", "Dragão", 148},
        {"Dragonite", "Dragão/Voador", 149}, {"Mewtwo", "Psiquico", 150}, {"Mew", "Psiquico", 151}
    };

    char input[50];
    printf("Digite o nome ou o numero do Pokemon: ");
    fgets(input, sizeof(input), stdin);

    // Remove o newline do input
    input[strcspn(input, "\n")] = '\0';

    // Verifica se o input é um numero ou uma string
    if (isdigit(input[0])) {
        int numero = atoi(input);
        if (numero > 0 && numero <= NUM_POKEMON) {
            // Busca pelo numero do Pokemon
            printf("Pokemon encontrado: %s, Tipo: %s, Indice Original: %d\n",
                   Pokedex[numero - 1].nome, Pokedex[numero - 1].tipo, Pokedex[numero - 1].indice_original);
        } else {
            printf("numero de Pokemon invalido.\n");
        }
    } else {
        // Pesquisa por nome ou substring
        buscarPorNomeOuSubstring(Pokedex, NUM_POKEMON, input);
    }
    return 0;
}
