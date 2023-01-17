#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Structs/lists for player, pokemon and joint pokedex
typedef struct Player {
  char name[50];
  int PokemonCount;
  struct Player *next;
} Player;

// Used to add new player node
Player *NewPlayerNode(char name[50]) {
  struct Player *node = NULL;
  node = malloc(sizeof(Player));
  if (node != NULL) { // If there is something there, it needs to go next in
                      // line and not take the first spot.
    strcpy(node->name, name);
    node->next = NULL;
  }
  return node;
}
// Adding player to list via function
void AddPlayerToList(Player *ListOfPlayers, char name[50]) {
  Player *node1 = NewPlayerNode(name);
  Player *node2 = ListOfPlayers;
  while (node2->next != NULL) { // If next is NULL then its the last entry
    node2 = node2->next;
  } // Moves to next node in the list, does't reset, just adds
  if (node2->next == NULL) {
    node2->next = node1;
    return;
  }
  return;
}
// Finding players function
Player *FindPlayer(Player *ListOfPlayers, char name[50]) {
  Player *node2 = ListOfPlayers;
  int value;
  while (node2->next != NULL) {
    value = strcmp(name, node2->name);
    if (value == 0) {
      return node2;
    }
    if (node2->next == NULL) {
      value = strcmp(name, node2->name);
      if (value == 0) {
        return node2;
      }
      if (name == node2->name) {
        return node2;
      }
      node2 = node2->next;
    }
    return node2;
  }

  // Struct for pokemon defined
  typedef struct Pokemon {
    char name[50];
    char type[50];
    char ability[50];
    struct Pokemon *next;
  } Pokemon;
  // New pokemon node created
  Pokemon *NewPokemonNode(char name[50], char type[50], char ability[50]) {
    Pokemon *node = NULL;
    node = malloc(sizeof(Pokemon)); // Repeated for all structs for size
    if (node != NULL) {
      strcpy(node->name, name);
      strcpy(node->type, type);
      strcpy(node->ability, ability);
      node->next = NULL;
    }
    return node;
  }
  // Adding a pokemon to the list
  void AddPokemonToList(Player *ListOfPokemon, char name[50], char type[50], char ability[50]) {
    Player *node1 = NewPokemonNode(name, ability, type);
    Player *node2 = ListOfPokemon;
    while (node2->next != NULL) { // If next is NULL then its the last entry
      node2 = node2->next;
    } // Moves to next node in the list, does't reset, just adds
    if (node2->next == NULL) {
      node2->next = node1;
      return;
    }
    return;
  }

  // Listing all players into one
  void ListOfPlayers(Player *ListOfPlayers) {
    printf("The players listed in the pokedex: ");
    Player *node2 = ListOfPlayers;
    while (node2->next != NULL) {
      printf("Name  - %s\n", node2->name);
      node2 = node2->next;
    }
    if (node2->next == NULL) {
      printf("Name: %s\n", node2->name);
      return;
    }
  }
  // Listing all pokemon into one
  void ListOfPokemon(Pokemon *ListOfPokemon) {
    printf("The pokemon listed in the pokedex: ");
    Pokemon *node2 = ListOfPokemon;
    while (node2->next != NULL) {
      printf("Name  - %s\n", node2->name);
      node2 = node2->next;
    }
    if (node2->next == NULL) {
      printf("Name: %s\n", node2->name);
      return;
    }
  }
  // Goes through list and finds all pokemon
  void DisplayPokemonDetails(Pokemon * ListOfPokemon, char name[50]) {
    printf("Pokemon: \n");
    Pokemon *Pokem = Pokem(ListOfPokemon, name);
    printf("Name of Pokemon - %s\n", Pokem->name)
        printf("Type of Pokemon - %s\n", Pokem->Type)
            printf("Ability of Pokemon - %s\n", Pokem->Ability)
  }
  void DisplayPlayerDetails(Player * ListOfPlayers, char name[50]) {
    printf("Players: \n");
    Player *play = Player(ListOfPlayers, name);
    printf("Name of Players - %s\n", Play->name)
  }

  // Pokedex defined as a struct
  typedef struct Pokedex {
    Pokemon ListOfPokemon;
    Player *ListOfPlayers;
  } Pokedex;
  Pokedex *node = NULL;

  int main() {
    // Adding data to lists
    AddPokemon(ListOfPokemon, "Bulbasaur", "Grass", "Overgrow");
    AddPokemon(ListOfPokemon, "Charmander", "Fire", "Blaze");
    AddPlayer(ListOfPlayers, "Ash", "Misty");

    printf(ListOfPokemon);
    printf(ListOfPlayers);
  }