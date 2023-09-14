# 42-BSQ
Projet BSQ pour la Piscine C de 42

# TODO

- [X] Parsing Map
  - [X] Recuperer 3 dernier chars de la ligne 1 pour la struct: full, empty, obstacle
  - [X] Recuperer ligne 1 de map de i = 0 jusqu'a i = len - 3 pour atoi et verifier nombre de lignes 
- [ ] Map valide:
  - [X] Verifier si nb lignes = l1, sinon - map error\n
  - [X] Si une ligne contient un char qui n'est pas empty, obstacle - map error\n
  - [X] Verifier que toutes les lignes aient la meme taille, sinon - map error\n
  - [X] Si premiere ligne, char full et empty et obstacle sont identiques - map error\n
  - [ ] Nb de lignes >= 2 (1 ere compte pas) et col >= 1, sinon - map error\n
- [ ] Makefile
- [X] Boucle pour resoudre toutes les maps et pas que maps[0]
- [X] Solveur
- [ ] Gestion d'erreur
- [ ] Verifier TOUS les malloc / free
- [ ] Rendre norme les .h et .c
- [ ] Entree standard
