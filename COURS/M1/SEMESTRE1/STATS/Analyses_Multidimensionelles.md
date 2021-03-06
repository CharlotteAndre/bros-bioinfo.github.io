# Analyses Multidimensionnelles (Multivariées) Exploratrices (Descriptives)
**Antoine Grémare**
Il y a équivalence avec les termes entre parenthèses et le titre.


## I. Généralités

L'analyse **multidimensionnelle** (multivariée / multifactorielle) concerne **des groupes d'objets** (individus) dont chacun est décrit par les valeurs d'un ensemble de **descripteurs** (variables) (nombre > 1) **que l'on veut** analyser simultanément

- Exemple: les tableaux espèces ~ abondances
    - Stations = objets
    - Abondance des espèces = variables = descripteur

- L'**Analyse exploratrice** (descriptive) **reflète l'absence d'idée préconçue sur les données en question**
- **S'oppose à** inférentielle

- Le plus souvent, la quantité d'information contenu dans de tels tableaux est trop grande pour que l'on puisse mettre en évidence les relations entre objet et/ou descripteurs à partir de leur seul examen (**nombre de dimension >> 3**)
- Cette information doit donc être réduite pour devenir interprétable par le cerveau humain
- Cette réduction est le plus souvent assimilable à une **réduction du nombre de dimensions** par rapport à l'espace originel
- Dans les cas des analyses multidimensionnelles, cette réduction se fait en deux temps
    1. Le calcul d'une **matrice d'association**
    2. L'utilisation d'une méthode de **groupement** et/ou d'**ordination**
- L'ensemble du processus doit induire **une déformation minimale de l'information originelle** 

- Les analyses multifactorielles se différencient par les méthodes de détermination des espaces réduits décrivant le mieux l'information originelle (i.e. celle contenue dans l'espace multivarié originel puis résumée dans la matrice d'association)

- Les différents modes d'analyses:
    - Mode Q : Relations entre objets (Mode direct)
    - Mode R : Relations entre descripteurs (Mode indirect)

- Enchainment des éléments constitutifs d'une analyse multivariée:
    1. Données brutes
    2. Données transformées
        - Optionnelle selon l'analyse utilisée 
    3. Matrice d'association
    4. Analyse de la matrice
        - Nombreuses méthodes das ces deux catégories
        - **Classification**
            - Dendrogramme
        - **Ordination**
    5. "Indicator species"
   
## II. Les tableaux de données et leur transformation

- Grand nombre d'objets et de descripteurs
    - Chaque objet est positionnable dans un espace à $N _{variables}$ dimensions
    - L'ensemble des objets y délimite un nuage des objets
    - 
    - Chaque descripteur est positionnable dans un espace à $N _{objets}$ dimensions
    - L'ensemble des descripteurs y délimite un nuage de descripteurs
    - 
    - On peut aborder l'analyse d'un tableau selon l'un ou l'autre des angles (ou les deux)
    - Dans tous les cas, lorsque le nombre de dimensions est > 3 il est impossible de visualiser ces nuages directement
  
- Les deux types de descripteurs constitutifs d'un jeu de données écologiques
    - Écosystème = Biocénose + Biotope (Tansley)
    - En écologie, les tableaux de données contiennent souvent deux types de descripteurs:
        - Biologiques
            - Tableaux espèces ~ abondances
            - Unicité d'unités
            - Double 0 sans significations
        - Environnementaux
            - Multiplicité d'unités
            - Double 0 indicateur de ressemblance
    - Ces descripteurs sont de natures différentes 
    - Est t'il possible de les traiter simultanément ?


- Parfois certains descripteurs ont des valeurs moyennes et/ou des gammes de variation beaucoup plus important ce qui leur confère un impact très fort l'ensemble du processus d'analyse. Il convient alors de réduire l'importance de ces descripteurs dominants et pour cela transformer les données
    - Transformations:
        1. $\sqrt{x}$
        2. $\sqrt{\sqrt{x}}$
        3. $log(x+1)$
        4. Présence / Absence (Binaire)
- Le plus souvent, le données environnementales n'ont pas les même unités. Il est alors nécessaire de les rendre adimensionnelles en les réduisant (division par leur écart type)
- L'opération de centrage et de réduction (soustraction de la moyenne et division par l'écart type) remplit ces deux fonctions à la fois :
    - Adimensionnel
    - Moyenne = 0
    - Écart type = 1

## III.Les mesures de ressemblance et de dépendance

- La notion de similarité (ressemblance entre objets)
    - Mesure de ressemblances de deux objets (Mode Q)
    - 0 < Similarité < 100 (Parfois 1)
    - Similarité = 0 si les deux objets sont on ne peut plus différents
    - Similarité = 100 si les deux objets sont strictement identiques
    - Dissimilarité = 100 - Similarité
    - Il existe un grand nombre de manière de mesurer la similarité ...
- La question des doubles zéros
    - Les descripteurs biologiques
        - Le fait qu'une espèce soit absente de deux stations ne nous apprends rien sur la similarité des compositions biologiques de ces deux stations 
        - Les lémuriens ne sont présent qu'à madagascar, leur absence dans toutes les autres partie du monde ne signifie pas que les faunes s'y ressemblent
        - Les mesures de similarité impliquant des données biologiques doivent donc être insensibles aux double zéro
    - Les descripteurs environnementaux
            - Le fait qu'une espèce soit absente de deux stations ne nous apprends rien sur la similarité des compositions biologiques de ces deux stations 
            - Les mesures de similarité impliquant des données environnementales doivent donc être sensibles aux double zéro
- Les principales mesures de similarité entre objets pour des données présence/absence (1)
    - a espèces présentes dans les objets 1 et 2
    - d espèces absentes dans les objets 1 et 2
    - b + c espèces présentes dans seulement un des deux objets
    - Coefficient de concordance simple (simple matching coefficient):
        - $S _{jk} = 100\times\frac{a + d}{a + b + c + d}$
    - Paradoxe: La similarité entre y1 et y2 dépend de y3:

| Espèce | y1  | y2  | y3  |
| ------ | --- | --- | --- |
| e1     | 1   | 1   | 0   |
| e2     | 1   | 0   | 0   |
| e1     | 0   | 0   | 1   |
-   - Coefficient standard:
        - $S _{y1y2} sans objet y3 = 50$
        - $S _{y1y2} avec objet y3 = 66.7$
    - Coefficient de Jaccard : $S _{jk} = 100\times\frac{a}{a + b + c}$
        - $S _{y1y2} sans objet y3 = 50$
        - $S _{y1y2} avec objet y3 = 50$
    - Coefficient de Sorenson (Dice) : $S _{jk} = 100\times\frac{2a}{2a + b + c}$
        - $S _{y1y2} sans objet y3 = 66.7$
        - $S _{y1y2} avec objet y3 = 66.7$
- Les concepts de dissimilarité et de distance 
    - Dissimilarité = 100 - Similarité
    - Analogue à une distance mais
        - Échelle finie (0-100)
        - Ne respecte pas forcément l'inégalité triangulaire $D _{AC}< D _{AB} + D _{BC}$
    - Il existe une multiplicité de mesure de distances
        - Distance Euclidienne
            - $d_{jk} = \sqrt{\sum\limits _{i=1} ^{p} (y _{ij} - y _{ik})^2}$
        - Distance de Manhattan:
            - $d_{jk} = \sum\limits _{i=1} ^{p} \lvert {y _{ij} - y _{ik}\rvert}$
    - Possibilité de transformer une distance de dissimilarité en la bornant 
    - Division par sa valeur maximale (Celle correspondant à deux objets on ne peut plus différent)
  
|     | Station 1 | Station 2 |
| --- | --------- | --------- |
| sp1 | 0         | a1,2      |
| sp2 | a2,1      | 0         |
| sp3 | a3,1      | 0         |
| sp4 | 0         | a4,2      |

$$MAX = \sum\limits _{i=1} ^{p} \lvert {y _{1,i} - y _{2,i}\rvert} = \sum\limits _{i=1} ^{p} {y _{1,i} + y _{2,i}}$$

-   - Transformation de la distance de manhattan en similarité de Bray-Curtis

$$S _{jk} = 100 \left\{ 1 - \frac{\sum\limits _{i=1} ^{p} \lvert {y _{ij} - y _{ik}\rvert}}{\sum\limits _{i=1} ^{p} {y _{ij} + y _{ik}}}\right\}$$

- La ressemblance entre descripteurs: notion de dépendance
    - Mesure de la ressemblance de deux descripteurs (mode R) 
    - Relation linéaire
        - Covariance
            - Mesure de la dispersion conjointe de deux variables autour du point défini par leur deux moyennes (aire des ellipses)
        - Coefficient de corrélation de Pearson
            - Covariance des deux variables centrées réduites (forme des ellipses)
            - r(A) = r(B)
        - Coefficient de Spearman
            - Equivalent non paramétrique de Pearson (RANG)
            - Fonctionne même avec des fonctions non linéaires 
            - 1 quand la relation est monotone
- La comparaison de profils: distance métrique du $\chi²$
    - Tableau espèce ~ abondance
    - Comparaison du profil de deux stations
        - Transition de 
            - Données Brutes 
            - Abondances absolues de j à i
        - à
            - Profils
            - Abondances relatives de j à i
    - Distance euclidienne entre les profils d'espèces des stations X1 et X2 

 $$ y _{ij} = 
 \begin{bmatrix}
    x_{11} & x_{12} & x_{13} & \dots  & x_{1n} \\
    x_{21} & x_{22} & x_{23} & \dots  & x_{2n} \\
    \vdots & \vdots & \vdots & x _{ij} & \vdots \\
    x_{d1} & x_{d2} & x_{d3} & \dots  & x_{dn}
\end{bmatrix}    
\begin{bmatrix}
    \sum x_{1}\\
    \sum x_{2} \\
    \vdots \\
    \sum x_{n} 
\end{bmatrix} = y _{i+}  
 $$

 $$ y _{j+} = 
 \begin{bmatrix}
    \sum x_{1} & \sum x_{2} & \sum x_{3} & \dots & \sum x_{d}
\end{bmatrix}
 $$
Distance Euclidienne
$$D _{15} (x _1, x _2) = \sqrt{\sum\limits _{j = 1} ^{p} \left ( \frac{y _{1,j}}{y _{1+}} - \frac{y _{2,j}}{y _{2+}} \right ) }$$
Métrique: Pondérée par le total des station afin d'éviter la surinterprétation des espèces dominantes
$$D _{15} (x _1, x _2) = \sqrt{\sum\limits _{j = 1} ^{p} \frac{1}{y _{+j}}\left ( \frac{y _{1,j}}{y _{1+}} - \frac{y _{2,j}}{y _{2+}} \right ) }$$


 Distance chi2:
 $$D _{16} (x _1, x _2) = \sqrt{\sum\limits _{j = 1} ^{p} \frac{1}{y _{+j} / y _{++}}\left ( \frac{y _{1,j}}{y _{1+}} - \frac{y _{2,j}}{y _{2+}} \right ) }$$
 
- La matrice d'association est une matrice symétrique qui rassemble des mesures de similarité (ressemblance/dépendance) ou de dissimilarité (difference/indépendance) de tous les couples possibles d'objets ou de descripteurs
    - Matrice carrée symétrique / Diagonale
    - Similarité d'une station avec elle même = 100
    - $\frac{N(N-1)}{2}$ couples de stations composées de 2 éléments différents
    - Mode Q = Objets x Objets
        - Ressemblance
    - Mode R: Variables x Variables
        - Dépendance
## IV. Les analyses de groupement
- Réaliser des partitions d'ensemble d'objets (mode Q) ou de descripteurs (mode R) sur la base de leur ressemblance (ou dépendance)
- Il existe un grand nombre de méthodes de groupement
    - Fuzzy vs **Hard**
        - Possibilité pour une entité d'appartenir à plusieurs groupes ou **non**
    - Ascendante vs **Descendante**
        - Point de départ un élément ou **un groupe unique**
    - Hiérarchique ou **non**
        - Les membres des groupes inférieurs deviennent automatiquement membres de groupes "supérieurs" ou **non**
- Analyse de groupement hiérarchique ascendante
    - Base : Matrice de similarité
    - Sélection de la plus forte similarité (A1:A3)
    - Définition d'un groupe A1:A3 
    - Calcul d'une nouvelle matrice de similarité incluant ce groupe
        - **Lien moyen**
            - "Group average linking"
                - Valeur moyenne des similarité
        - Lien complet
            - "Farthest Neighbor"
                - Valeur minimale des similarités
        - Lien simple 
            - "Nearest Neighbor"
                - Valeur maximale des similarités
    - Représentation:
        - Dendrogramme
            - Attention : Multitude de représentations équivalentes suite à des rotations de chaque articulation
            - Conclusion: Seul le niveau auquel les stations se rejoignent comptent 
        - Lien simple
            - Favorise l'aggregation à des groupes existants
        - Lien complet 
            - Favorise la création de nouveaux groupes
        - Lien moyen
            - Intermédiaire (Plus proche du complet)
    - Mieux vaut utiliser le lien moyen
- Analyse de groupement hiérarchique ascendante en mode R
    - On cherche à regrouper les espèces (descripteurs)
        - Beaucoup d'espèces sont très peu abondantes et vont obscurcir l'analyse. Il est nécessaire de les éliminer et donc de réduire le jeu des données
            - La base la plus employée pour cela est un critère d'abondance relative maximale (i.e. L'espèce doit représenter au minimum 5% de l'abondance totale à une station donnée)
            - Les espèces les plus abondantes vont avoir tendance à être similaires même si leurs profils de distribution sont différents.
            - A contrario deux espèces peuvent avoir exactement le même profil mais des abondances très différentes. Ils conviendraient alors qu'elles soient regroupées  lors d'une analyse en mode indirect. 
        - Pour régler ce problème, on va standardiser
            - Diviser chaque abondance par la somme des abondances de l'espèce considérée dans le jeu de données ("profils")
            - Peut être remplacé par un centrage des données (pour d'autres descripteurs)
    - La matrice de similarité entre espèces (descripteurs)
    - Reste de l'analyse similaire au mode direct
    - Calcul de la matrice de similarité entre espèces (descripteurs)
    - Analyses de groupement hiérarchique ascendant des espèces

## V. L'Analyse de proximité (Multi Dimensional Scaling MDS)
- La méthode s'applique surtout à la comparaison d'objets (Q)
- La méthode est basée sur la comparaison des dissimilarités d'une matrice d'association et les distances entre stations positionnées dans un espace réduit (le plus souvent un plan)
- La première étape consiste à choisir le nombre de dimensions de l'espace réduit (en général 2, parfois 3)
- L'objectif consiste ensuite à déterminer le positionnement des stations dans l'espace réduit qui permet d'obtenir la meilleur corrélation possible entre les dissimilarités $\delta _{jk}$ et les distances $d _{jk}$
- Ceci nécessite de développer une méthode pour estimer cette corrélation
- Le Diagramme de Shepard représente la relation liant les dissimilarités dans la matrice d'association et les distances dans l'espace réduit de l'analyse de proximité
    - Le stress est un indice qui permet de mesurer la manière dont les distances dans l'espace réduit de l'analyse de proximité reflète les dissimilarités avec les dissimilarités de la matrice d'association
    - Existe également une MDS non métrique (nMDS) ==> Modèle non linéaire mais monotone
- Clef d'interprétation des valeurs du stress:
    - s = 0
        - Ajustement parfait, en général quand n est faible. Rare. Faire attention à l'existence possible de plusieurs solutions
    - s < 0.05
        - Excellente représentation
    - 0.05 < s < 0.1
        - Bonne représentation
    - 0.1 < s < 0.2
        - Bonne représentation mais attention au structures locales
    - 0.2 < s < 0.3
        - Difficilement utilisable
    - 0.3 < s < 1
        - Un peu mieux que le hasard
## VI. L'Analyse en Composante Principale (ACP)
 - Nature des données 
    - Ensemble d'objets (individus) décrits par des descripteurs (variables) quantitatifs
- Nuage des individus
    - Espace à $p$ dimensions
    - $p$ est le nombre de variables
    - G : centre de gravité du nuage
        - Ses coordonnées sont les moyennes des $p$ variables
    - Si $p>3$, nuage non visualisable mais ...
        - La distance euclidienne peut toujours être utilisée pour mesurer la ressemblance entre les individus
            - $d _{jk} = \sqrt{\sum\limits _{i=1} ^{p} (y _{ij} - y _{ik}) ^2}$
- Le centrage et réduction des données
    - $x _{ij} \rightarrow \frac{x _{ij} - \bar x _{j}}{\sigma(X _j)}$
    - Le centrage fait coïncider l'origine du repère avec le centre de gravité du nuage
        - En effet, les moyennes correspondent à 0 après centrage
    - La réduction résout les questions liées à la déformation du nuage du fait de choix d'unités différents
- Principe: produire une image approchée du nuage des individus dans un espace avec un nombre réduit de dimensions (visualisable) (= Projection)
    - Définir un critère de la minimisation de la déformation
        - Conservation de la plus grande proportion des distances de l'espace originel
    - Application à une réduction dans un espace à une dimension
        - $H _i$ projection orthogonale de l'individu I sur un axe $u$
        - Trouver l'axe $u _1$ tel que la somme des $||OH _{i,u1}|| ^2$
        - Maximiser la somme des $1/P _i \times ||OH _{i,u1}|| ^2$ si des poids différents sont donnés aux individus $i \rightarrow P _i$
        - Notion d'inertie
        - Assimilable à une variable
        - Trouver l'axe $u _1$ présentant la variabilité maximale
        - Trouver l'axe $u _1$ présentant l'élongation maximale
        - Axe $u _1$ est une composante linéaire des axes originels
        - Axe $u _1$ : première composante principale
- Une propriété remarquable de l'ACP: **L'emboîtement des solutions**
    - Propriété liée à l'utilisation d'un critère de maximalisation
    - La première composante principale est incluse dans le premier plan principal
    - La deuxième dimension de ce plan est définie par l'axe $u _2$ qui est orthogonal à $u _1$ 
        - l'axe $u _2$ maximise la somme des $1/P _i \times ||OH _{i,s}|| ^2$ si des poids différents sont donnés aux individus 
- Afin de quantifier un équivalent du stress pour les ACP permettant de déterminer le nombre de dimensions optimal,on calcul le pourcentage de variance expliquée par les CP:
$$\frac{\sum 1 / P _i \times OH _{i} ^2}{\sum 1 / P _i \times OI _{i} ^2} \times 100 $$

## VII. L'analyse factorielle des correspondances 

