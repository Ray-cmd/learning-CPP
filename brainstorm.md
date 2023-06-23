# BrainStorm

## Hello Team

Pour commencer, voici un petit hello world que je vais expliquer ligne par ligne.

```c++
#include <iostream>

int main()
{
    std::cout << "Hello Team !!" << std::endl;
}
```

`#include <iostream>` ajoute à notre programme la bibliothèque `iostream`. Cette bibliothèque nous permet de lire et d'écrire la sortie standard.

`int main()` comme pour `C` notre programme a besoin d'un point d'entrée.

`std::cout << "Hello World !!" << std:endl;` cette ligne est plus compliquée, je vais l'éclater en petit morceaux.
`std::cout` `cout` représente la sortie du terminal (`cout = console out`). Nous devons ajouter `std::` car `cout` est dans `namespace` car il nous est fournit par la bibliothèque `iostream`. **Tous ce qui nous ai fournit par la bibliothèque standard est dans le namespace `std`**.
Ensuite il y a `<<` qui est un opérateur de redirection, il redirige à gauche ce qu'il y à droite. Ici, il redirige tous ce qu'il y a à droite vers la sortie standard.
Nous avons ensuite la stringe `"Hello Team !!"`, elle est donc envoyé sur la sortie standard.
Nous utilions encore l'opérateur de redirection `<<`.
Pour finir, nous utilisons `std::endl` pour ajouter un retour à la ligne.

Cette exemple n'est porbablement pas très claire. Il n'explique pas se qu'est un `namespace` est ne permet pas de comprendre correctement comment fonctionne `cout` et l'opérateur `<<`.
Il n'est qu'une mise en bouche, nous verrons plus loins comment tous cela fonctionne en détail.

## Références

`C++` nous met à disposition un nouveau symbole`&`. Nous le conaissons déjà en `C` il permet de désigné l'adresse d'une variable, `C++` nous permet de l utiliser directement avec les type de variable.

```c++
int main()
{
    int a = 5;
    int& ref = a;
}
```

Ce code est écivalent à :

```c
int main()
{
    int a = 5;
    int *ptr = &a;
    return (0);
}
```

Cette nouvelle notation permet de facilité l'adresse d'une variable à une fontion. Avec `C++`, nous pouvons prototyper un argument comment étant une référance et nous pouvons utiliser ce parametre comme un variable normale dans notre fonction :

```c++
#include <iostream>

void increment(int& val)
{
    val++;
}

int main()
{
    int a = 5;

    increment(a);
    std::cout << a << std::endl;
}
```

```bash
6
```

Pour comparer, voici la version `C` :

```c
#include <stdio.h>

void increment(int *val)
{
    (*val)++;
}

int main()
{
    int a = 5;

    increment(&a);
    printf("%d\n", a);
    return (0);
}
```

```bash
6
```

Nous pouvons constater que la fonction `increment` est beaucoup plus lisible en `C++` car nous n'avons pas besoin de déréférencer le paramêtre, le compilateur fait pour nous le travail.

Nous avons la possibiliter de stoquer une référence dans une variable, ce qui revient au même que de faire un pointeur en `C`

```c++
#include <iostream>

int main()
{
    int a = 5;
    int& ref = a;

    ref++;
    std::cout << a << std::endl;
}
```

```bash
6
```

```c
#include <stdio.h>

int main()
{
    int a = 5;
    int *ptr = &a;

    (*ptr)++;
    printf("%d\n", a);
    return (0);
}
```

```bash
6
```

Les référence ne nous offre pas la même libérté que les pointeurs, et c est sont point faible. Par exemple, Nous ne pouvons pas set la valeur d'une référence à un autre moment que lors de sa création. La raison est simple, une référence n'est pas une variable classique, sa raison d'être et de pointer sur une variable, il est donc impossible d'avoir une référence vide.

```c++
int main()
{
    int a = 42;
    // Cette ligne ne va pas compiler.
    int& ref;

    ref = a;
}
```

```c++
int main()
{
    int a = 42;
    // Cette ligne va compiler.
    int ref = a;
}
```

Une autre chose que nous ne pouvons pas faire avec les références est changé la variable qui est ciblé. Cela va juste changer la valeur de la deuxième variable.

```c++
#include <iostream>

int main()
{
    int a = 5;
    int b = 16;
    int& ref = a;

    // Cette ligne fait que le var pointée par ref vaut b (16)
    ref = b;
    std::cout << a << " " << b << std::endl;
}

```

```bash
16 16
```

Ici, nous pouvons constater que la variable `a` à pris la valeur de `b`.

La manière `C++` de faire les choses est d'utiliser les référence. Celle rend le code plus lisible et plus facile à écire. Il faut les utiliser le plus souvent possible. Il ne faut par contre pas oublier leur limitation.
