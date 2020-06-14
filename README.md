# Indie Studio

Voici notre **Bomberman**.
Vous trouverez dans ce README une aide relative à l'installation, sinon, contactez William GAUDFRIN sur Teams pour une aide d'installation.

# Installer

Un installeur est disponible à la racine de l'OOP_indie_studio_2019 pour Windows ou via [mon site web](http://william-gaudfrin.fr/indie/setup.exe)

Sinon, lancez Git Bash, rendez-vous dans le dossier "build", et effectuez la commande :
> cmake .. && cmake --build . --config Release

Ensuite, le bomberman.exe est généré dans le dossier "**Release**" *(ou dans le dossier "Debug" si vous avez fait --config Debug)*, déplacez le à la **racine du projet**, puis copiez-coller à la **racine du projet** l'ensemble des .lib, .exp et .dll disponible dans chacune des librairies dans les dossier :
-  **OOP_indie_studio_2019/libs/irrlicht/bin**
- **OOP_indie_studio_2019/libs/irrlicht/lib**
- **OOP_indie_studio_2019/libs/irrKlang/bin**
- **OOP_indie_studio_2019/libs/irrKlang/lib**

Dans les deux cas, assurez-vous que le binaire (sur Linux et .exe sur Windows)
se trouve bien à la racine du projet, où se trouve le dossier **assets**.

# A savoir:
Pour toutes modifications du son dans les options, celles-ci seront appliquées une fois retourné au menu principal

# Touches

Il existe différentes touches pour diverses actions :

 - "**Suppr**" pour quitter le jeu
 - "**R**" pour restart le jeu
 - "**B**" pour retourner au menu
 - "**P**" pour sauvegarder dans le jeu
 - "**Échap**" pour faire pause dans le jeu

## Touches pour se déplacer
#### Joueur 1
- "**Z**" pour se déplacer vers le haut
- "**S**" pour se déplacer vers le bas
- "**Q**" pour se déplacer vers le gauche
- "**D**" pour se déplacer vers le droite
- "**ESPACE**" pour placer une bombe
#### Joueur 2
- "**ARROW UP**" pour se déplacer vers le haut
- "**ARROW DOWN**" pour se déplacer vers le bas
- "**ARROW LEFT**" pour se déplacer vers le gauche
- "**ARROW RIGHT**" pour se déplacer vers le droite
- "**RIGHT CTRL**" pour placer une bombe
#### Joueur 3
- "**Y**" pour se déplacer vers le haut
- "**H**" pour se déplacer vers le bas
- "**G**" pour se déplacer vers le gauche
- "**J**" pour se déplacer vers le droite
- "**T**" pour placer une bombe
#### Joueur 4
- "**O**" pour se déplacer vers le haut
- "**L**" pour se déplacer vers le bas
- "**K**" pour se déplacer vers le gauche
- "**M**" pour se déplacer vers le droite
- "**I**" pour placer une bombe