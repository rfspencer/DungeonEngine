# Project Two: Design Document
This will be a dungeon crawling adventure game that runs on Windows Terminal. The player can adventure as one of three classes: fighter, rogue, or mage. Each class has their own special abilities and advantages to aid them in their quest for the MacGuffin. 

## Design
#### Minimum Viable Product
Ok, so we both know this is going to be a fuck-ton of work to do what I have in mind, so I need to define the minimum that we would need build to make this game. I think there's two roads here, 1) the ideal version where the player can use the arrow keys to move around the dungeon, and 2) the version where they don't. On the version where they don't, it's either going to be a first-person click-to-move (singe screen redrawn after every action), or purely text based/menu-driven. But all of that is really separate from the core game logic. So I can design the rest of the game while I figure out the interface.

#### Requirements
- Interface: Arrows to move player or not.
- Game
    - Turn Based: The player goes, then the computer-enemies-environment goes
      - If arrow key interface, free roaming until encounter. If not, then it's turn based all the time.
      - If arrow key interface, exit turn-based mode.
    - Do damage
    - Take damage
    - Heal
    - Pick ups
    - Inventory
- Map: Dungeon layout
    - Functionality to translate map file into game object
    - Functionality to place game objects at a location in-game
    - Query the location for game objects or state (environment, area of effect, etc)
    - *Fog of war
    - Hardcode map, *Map from file, or *randomly generated
    - Update map
- User Interface
  - Main Menu
  - HUD
    - Health / HealthMax
    - Mana / ManaMax
    - Stats
    - Legend
    - Text Feedback Box: Dialog, Combat readout, Pickup readout
- Hero
    - Bare minimum, a hero character. Ideally, three classes.
    - Actions: Attack. Use item. Cast spell
    - Movement
    - Inventory
    - *Legend
    - *Stats: Str, Dex, Con, Int, Wis, Cha
    - *XP
    - *Level Up
- Enemy
    - Attack
    - Movement
  
*Not MVP

### Implementation Notes
#### Core
Isolate Core systems from the Game system. Core systems as a static library that the game loads.

EntryPoint::Main creates the Application

#### Menu
Menu system. Main menu: new game, load game, quit.

#### Map
The map tiles are linked lists, but can have multiple pathways. Generate a map file for each dungeon that you can read in to make the nodes. Each node holds loot, if any, and monsters, if any.

Make a 2D vector array for the total map, each holding a pointer to their map node. This is all handled by the Map class, building the 2D vector array from data sent to it from the map creator.

File format: file lines represent map rows, and tab seperated columns for map columns. Each tab encapsulated map tile will have a series of comma seperated values that hold the map tile's information. Initial column layout may be:
```angular2html
string TILE_ID, bool HAS_TRAP, TrapType TRAP, bool HAS_ENEMY, vector<EnemyType> EnemyList,
    bool HAS_LOOT, vector<LootItem> LootList

- TrapType: Struct of trap parameters.
- vector<EnemyType>: Vector of Enemy pointers.
- vector<LootItem>: Vector of LootItem's.
```

The **TILE_ID** parameter is what is used to track the player's location. The Map can pass that location off to the GameState or World, not sure which yet.

Use Windows Console API to draw to the screen. Consider making supporting Mac console.

#### Hero Classes
- Rogue: Chance to see traps, monsters, loot within a radius. Sneak attack.
- Warrior: Attack and damage bonus. Armor boost. Physical traits enhanced.
- Mage: Cast spells, high damage. Squishy. 

#### Enemy Classes
Enemy class. Archer. Fighter. Shaman. Boss.
