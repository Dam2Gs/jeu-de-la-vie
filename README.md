# jeu-de-la-vie

## Utilisation
./jeuDeLaVie <largeur> <hauteur> <probabilité> <nombre de générations>

où <probabilité> représente la probabilité pour une cellule qu'elle soit vivante dans l'état initial.

## Construction de l'image Docker
Utiliser le Dockerfile en lançant "docker build -t damien/jdlv ." dans le même répertoire que le Dockerfile pour construire l'image Docker et "docker run -it damien/jdlv" pour lancer le conteneur qui fera tourner le jeu de la vie.
