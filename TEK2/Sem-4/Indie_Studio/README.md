# Documentation Technique : Projet B-YEP-400 Indie Studio

## Epitech

## Année 2021

> Membres : Corentin Petrau, Lyvia Mallereau, Raphael Risser, Alec Ferrari, Paul Narchal, Florian Chanson

## Sommaire

> I- Introduction
>
> II- Présentation du projet
>
> III- Organisation/Architecture du projet
>
> IV- Entity-Component-System
>
> V- Partie Raylib
>
> VI- Partie Jeu
>
> VII- Description technique du code
>
> VIII- Difficultés rencontrées
>
> IX- Conclusion
>
> X- Sources

## I- Introduction

Le présent document est une documentation technique du projet B-400-YEP Indie Studio destinée aux futurs utilisateurs et examinateurs dudit projet.

La documentation décompose le programme en différentes parties afin de mieux le décrire. Il n'est qu'une explication partielle du code du programme et ne sera pas une démonstration complète du projet. Le but est de discuter de son implémentation et de quoi celle-ci découle.

Les rédacteurs et programmeurs ne seront pas tenus responsables des différents bugs qui peuvent résulter de l'utilisation du programme. Les utilisateurs doivent le prendre dans son intégralité et l'adapter dans le cadre de leurs besoins, en tant que démonstration ou simplement pour jouer.

## II- Présentation du projet

Le projet B-400-YEP Indie Studio est un projet pour les étudiants de deuxième année (ici, la promotion 2024) au sein de l'école Epitech.

Ce projet a pour but de recréer le jeu Bomberman (sorti en 1983 sur plusieurs machines, notamment la MSX et la ZX Spectrum). Le but du jeu est de déposer des bombes sur une grille afin de détruire ses adversaires. La réalisation du jeu en lui-même n'est pas très compliquée. Le gameplay est relativement simple, facile à implémenter. L'intérêt du projet vient dans la manière dont il sera implémenté. Cette implémentation peut compliquer le projet en le rendant par la même occasion plus intéressant.

D'un point de vue pédagogique, le projet s'effectue en groupe de 6 personnes. Chaque personne ayant sa propre façon de travailler, il faut trouver la bonne méthode de travail. Cette méthode devrait permettre aux membres du groupe de travailler sans craindre de mettre en péril le travail des autres. Dans cet esprit, la maîtrise d'un logiciel de gestion de version comme Github est primordiale.

De prime abord, recréer un Bomberman semble simple. Cependant, les conditions de réalisation complexifient la chose. En effet, la prise en compte du lancement sur différents systèmes d'exploitation (Linux-based/Windows) est la clé pour permettre la distribution du jeu. Par ailleurs, il faut réfléchir à une architecture extensible, optimisée et stable permettant un développement rapide. Bien entendu, recréer un jeu Bomberman ne veut pas dire reprendre le même design, il faut réfléchir à un thème et l'adapter au projet.

## III- Organisation/Architecture du projet

Dans un premier temps et comme dit précédemment, il a fallu discuter du thème choisi pour le jeu. Le gameplay à réaliser a guidé notre réflexion autour du thème : il nous fallait des explosions, des éléments destructibles et une opposition. Pour notre projet, nous avons le théme Godzilla vs King Kong, qui nous semblait assez amusant pour les joueurs, sans être ennuyant.

Lorsque le projet nous a été présenté, le responsable du projet a encouragé le développement d'une architecture complexe basée sur un design pattern moderne : l'Entity-Component-System. Réaliser un jeu en prenant avantage de ce design pattern peut s'avérer difficile et nécessite beaucoup de réflexion. Nous sommes le seul groupe ayant choisi cette difficulté supplémentaire. Il nous a semblé important de toujours travailler à se mettre à jour et s'améliorer.

Une fois que le thème a été choisi et que le design pattern a été décidé, le projet à été découpé en plusieurs parties distinctes : l'ECS (Entity-Component-System), l'engine basé sur la Raylib (librairie obligatoire) et le jeu en lui-même.

Cette division des tâches a permis de réaliser un projet moderne, proposant des solutions élégantes et facile à maintenir.

C'est en connaissant les forces et les faiblesses de chacun que le travail a pu se faire rapidement et efficacement. Chacun a travailler sur sa partie de manière optimale, sans s'interdire de collaborer avec ses coéquipiers sur les parties compliquées.

## IV- Entity-Component-System

Dans cette partie, nous décrirons le design pattern que nous avons suivi : l'Entity-Component-System. Il sera appelé ECS dorénavant.

Nous verrons dans un premier temps une explication de l'idée derrière le pattern, son fonctionnement en général, puis son implémentation dans notre cas.

## Sommaire Sous-Partie 1

> 1.Pourquoi un ECS ?
>
> 2.Fonctionnement général
>
> 3.Implémentation
>
> 4.Diagrammes

### 1.Pourquoi un ECS ?

L'ECS est un modèle architectural (appelé aussi design pattern) principalement utilisé dans le développement de jeux vidéo. Il suit le principe de composition plutôt qu'héritage. Ce principe permet une plus grande flexibilité dans la définition des entités où chaque objet dans la scéne d'un jeu est une entité à laquelle on attache des composants qui seront manipulés par des systèmes.

À chaque entité sont rattachés un ou plusieurs composants qui contiennent uniquement des données. Par conséquent, le comportement d'une entité est défini par des systèmes qui ajoutent, suppriment ou modifient des composants ou des entités. Cela permet d'éliminer les problémes d'ambiguité des hiérarchies d'héritage profondes et larges qui sont difficiles à comprendre, maintenir et étendre. Les approches ECS communes sont hautement compatibles et souvent combinées avec des technique de conception orientées objet. Cette optimisation du programme est motivée par une utilisation efficace du cache CPU. Elle est principalemment utilisée dans le développement de jeux vidéo. Par ailleurs, mettre en place de la programmation concurentielle sur un ECS est significativement plus simple que sur une architecture traditionnelle.

Pour faire un bref rappel de l'histoire de l'ECS, c'est en 2007 qu'on entend la première fois parler d'ECS : une équipe travaillant sur un jeu nommé Operation Flashpoint : Dragon Rising expérimente sur ce design pattern. C'est ensuite Adam Martin qui écrit un compte rendu détaillé de la conception ECS, comprenant des définitions de la terminologie et des concepts de base. Son travail à propulsé les idées de "systèmes", "entité en tant qu'identifiant", "composants en tant que données brutes", "logique stockée dans les systèmes, pas dans des composants ou des entités".

Il nous a été conseillé de réaliser le projet en utilisant ce design pattern puisqu'il est relativement récent et populaire. Il est donc important d'en connaître les principes en tant que développeur de jeux vidéos. De plus, l'idée d'une très bonne optimisation sans grands coûts est relativement alléchante pour tout développeur.

### 2.Fonctionnement général

Dans la terminologie de Martin, il y décrit son fonctionnement de manière formelle:

- Entité: il s'agit d'un objet à usage général. Habituellement, il ne s'agit que d'un identifiant unique. Ils "marquent chaque objet de jeu comme un élément séparé". Les implémentations utilisent généralement un integer pour cela.
- Composant: les données brutes pour un aspect de l'objet et comment il interagit avec le monde. "Étiquette l'entité comme possédant cet aspect particulier". Les implémentations utilisent généralement des structures, des classes ou des tableaux associatifs.
- Système: chaque système s'exécute en continu (comme si chaque système avait son propre thread) et exécute des actions globales sur chaque entité qui remplit son/sa contrat/signature (la liste des composants nécessaires).

Un exemple serait peut-être plus parlant. Imaginons que l'on souhaite simuler la chute d'un corps dans un espace tridimensionnel. Pour appliquer une gravité ou un mouvement sur une entité, le système chargé de la physique aura besoin de la position, de la vélocité et de la masse d'une entité par exemple. Par conséquent, on assignera à ce système une signature faite des composants `transform` et `physics`. Lorsqu'on assignera ces deux composants à une entité, celle-ci remplira la signature et le système en traitera les composants.

## V- Partie Raylib

Dans cette partie, nous allons décrire de manière simple la Raylib, la librairie graphique que nous avons utilisée ; ainsi que notre utilisation de celle-ci.

Pour ce faire, nous allons voir dans un premier temps une description de la Raylib elle-même et sa mise en place dans le programme.

## Sommaire Sous-Partie 2

> 1.Description de la Raylib
>
> 2.Mise en place de la Raylib

### 1.Description de la Raylib

La Raylib est une bibliothèque logicielle multiplateforme (Android, FreeBSD, HTML5, Linux, MacOS, Windows, ainsi que différents systèmes embarqués) sous licence zlib/libpng, publié par Ramon Santamaria depuis 2013, orientée vers le développement d'application interactives, telles que les jeux-vidéos.

Elle est developpé en langage C et son API qui se veut simple et légère comporte des bindings dans plus de 50 langages (C, Lua, C++, C#, PHP, Rust,Python, etc).

Cette librairie est incroyablement complète et dispose de beaucoup de fonctionnalités allant de modèles 3D, aux shaders en passant par de l'UI. Cette polyvalence est un réel atout et a rendu le développement relativement facile.

### 2.Mise en place de la Raylib

La Raylib nous a servi de moteur de rendu. Toute la logique et les données étaient contenues dans l'ECS, cependant les données étaient traitées et affichées grâce aux fonctions de la Raylib. Dans l'ensemble, nous avons utilisé les fonctionnalités suivantes :

- Affichage et chargement de modèles 3D
- Affichage et chargement de Cubemaps
- Gestion des sons
- Gestion des Shaders
- Gestion des inputs

## VI- Partie Jeu

Le jeu Bomberman est relativement simple : 4 joueurs dans les coins d'une zone carrée remplie de cases à détruire. Les joueurs se frayent un passage dans la zone à coups de bombe tout en récupérant les bonus lachés par les cases détruites. Leur but est de piéger leur adversaire avec leurs bombes pour les éliminer. Le dernier joueur restant est le vainqueur.

Nous avons choisi le thème "Gozilla vs Kong" inspiré du film éponyme. Avec des modèles 3D low poly et des effets inspirés cartoon, on obtient un jeu goofy et énergétique. Jouable jusqu'à 4 en utilisant claviers et souris, il faut utiliser les touches ZQSD du clavier pour déplacer le joueur 1, F pour poser une bombe et les flèches directionelles et K pour le joueur 2. Les deux autres joueurs sont contrôlés au travers des gamepad connectés. La touche echap permet de quitter le jeu.

Si vous choisissez moins de 4P, des IA prendront la place des autres joueurs. Attention, celles-ci sont expérimentales et assez difficiles à battre ! Si vous souhaitez éviter les interruptions créées par les IA, choisissez le nombre de joueurs maximum, utilisez les commandes que vous voulez et tuez les joueurs non utilisés.

## VII- Description technique du code

L'implémentation de l'ECS a été complexe. Dans notre cas, Alec Ferrari, s'est chargé de la réalisation de l'ECS. L'ECS étant quelque chose de nouveau pour notre équipe, nous avons naïvement pensé que sa réalisation serait triviale. Grâce à de nombreux tutoriels et aux références fournies par l'équipe pédagogique, il a été mis en place en 1-2 semaines.

Son implémentation se base sur la séparation de la gestion des entités, des composants et des systèmes. Le but était de permettre une interface naturelle et adaptée au C++ tout en privilégiant l'optimisation. La classe World est la porte d'entrée de l'ECS. Elle sert d'interface opaque. Elle contient les managers d'entités, de composants et de systèmes et expose des méthodes permettant de les manipuler facilement.

Le manager d'entités est relativement simple. Il contient une queue de toutes les entités disponibles. Cette queue permet de gérer la création et le recyclage d'entités en limitant le nombre maximum. les méthodes createEntity du World sont directement tirées de ce manager.

Le manager de systèmes est relativement plus compliqué. Il utilise la RTTI du C++ pour permettre une identification simple des types de systèmes à partir de pointeurs. Il associe ces systèmes à leur signature et réagit à la destruction ou la modification d'entités en remplissant les tableaux des systèmes d'entités compatibles avec leur signature.

Le manager de composant est le plus intéressant. Pour pouvoir cacher un maximum de choses sur le CPU et ainsi optimiser le code, il est requis que tous les composants soient des aggrégats de données (de simples structures C). Le manager se charge de garder ces composants dans des tableaux contiguës à tout moment. De cette manière les données sont mises en cache par le CPU et sont plus rapides d'accès. Il est donc rapide de parcourir toutes les entités et d'accéder à leur composants.

Par dessus ces managers se trouve donc la classe World qui les manipule. Pour permettre de réaliser différents niveaux, différentes scènes etc, un GameManager a été créé. Celui-ci permet de charger des scènes. Simplement, celles-ci sont une représentation d'une configuration de l'ECS. Ce sont des fonctions qui prennent en paramètres le World et le GameManager. Elles vont ensuite ajouter systèmes, entités et composants au World et appeler les fonctions des systèmes dans l'ordre souhaité. Cette organisation est très flexibles et permet d'enfreindre certaines règles d'un ECS classiques en insérant de la logique à l'extérieur de celui-ci. De prime abord, enfreindre les règles semble problématique. Cependant, dans un programme tout est question de budget. Avec une si grande optimisation des accès de composants, on peut se permettre quelque chose de plus lent autre part. De cette manière, nous avons évité certains problèmes épineux.

Pour plus de détails sur l'architecture, un document UML.pdf a été fourni.

## VIII- Difficultés rencontrées

Plusieurs difficultés ont été rencontrées dans la construction et la réalisation du projet.

Dans un premier temps ce fut la décision de l'architecture : ne pas choisir la facilité a mis le groupe dans une situation délicate. Le projet se réalisant en quatres semaines avec de nombreux membres et se révélant assez complexe, c'est avec les commentaires et les remarques des encadrants que le groupe a décidé de prendre des risques et de passer par l'ECS pour porter le projet.

Par la suite il a fallu appréhender la programmation orienté data en développant directement via l'ECS. Comprendre le fonctionnement du design pattern fut aussi une difficulté supplémentaire. Il a fallu changer la manière dont nous réfléchissions jusque là. Ce changement a fait survenir de nombreux problèmes liés à nos habitudes de programmation mais sortir de celle-ci n'est que bénéfique pour le futur.

Enfin, réaliser toutes les features souhaitées à temps s'est avéré compliqué. Il y avait beaucoup de travail à abattre pour réaliser un projet ambitieux.

## IX- Conclusion

Nous tenons à préciser que la démonstration de ce projet n'a pas pour but de permettre la tricherie. Le projet peut cependant vous servir d'aide dans d'éventuelles réflexions concernant l'ECS ou la Raylib. En outre, nous nous dédouanons de toute responsabilité si vous tentez d'adapter votre code sur ce projet.

La dernière partie de ce document pourra vous servir puisqu'elle contient les références qui nous ont servies à comprendre le fonctionnement d'un ECS et de la Raylib.

Pour conclure, nous tenous à remercier nos encadrants pour leurs conseils sur l'ensemble du projet. Ce projet est l'un des plus importants de la fin de la deuxième année et nous avons pris beaucoups de plaisir à le réalisé.

## X- Sources

- Wikipédia ECS
- [Raylib](raylib.com)
- [Explications ECS](https://www.youtube.com/watch?v=Z-CILn2w9K0)
- [Implémentation ECS](https://austinmorlan.com/posts/entity_component_system/)
- [Exemples ECS](https://www.youtube.com/watch?v=W3aieHjyNvw)
- Source interne Epitech
