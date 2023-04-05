# Guía sobre Estructuras de datos

Esta es una guía para principiantes, para el uso correcto de estructuras de datos, mencionando las más comunes y sus usos. Para el desarrollo de la guía uso como lenguaje principal C++, pero se puede adaptar a cualquier lenguaje de programación.

## Tabla de contenido

- Qué son estructuras de datos
- Notación asintótica
  - Clases de funciones para notación asintótica
- Breve vistazo al uso y manipulación de memoria
  - Memoria RAM, los registros y los punteros
  - ¿Cómo se reserva memoria?
  - Tipos de datos y sus límites númericos
  - Tipos de datos personalizados
  - ¿Cómo se utilizan los punteros?
  - ¿Por qué usar punteros y cómo son útiles?
  - La notación de punto y flecha (dot and arrow notation)
- Clases de estructuras de datos

## Qué son estructuras de datos

Se utilizan como formas de organizar los datos para que puedan ser utilizados de manera eficiente. Son colecciones de datos que se organizan de una manera particular para que puedan ser utilizados de manera eficiente. Estos clasifican y ordenan los datos de acuerdo a sus características, y de acuerdo a su uso, cambian la manera de acceder a ellos, haciendolos de acuerdo al escenario la solución más eficiente.

## Notación asintótica

Es una forma de describir el tiempo de ejecución de un algoritmo. Más exactamente, da una noción de la cantidad de instrucciones que se ejecutan en difrentes casos, de acuerdo con una función matemática que describe el comportamiento del algoritmo.

### Clases de notación asintótica

- Notación Big O := O(f(n))
  Nos brinda una noción de la cantidad de instrucciones que se ejecutan en el peor de los casos. Una función $f(n)$ es $O(g(n))$ si y solo si existe un número $c > 0$ y un número $n_0 > 0$ tal que para todo $n > n_0$, $f(n) \leq c * g(n)$. En otras palabras, si al multiplicar $g(n)$ por un número $c$, se obtiene un número mayor o igual a $f(n)$ desde un punto hasta el infinito. O sea, la acota superiormente. (O es una función que acota superiormente a $f(n)$).
- Notación Omega := $\Omega$(f(n))
  Nos brinda una noción de la cantidad de instrucciones que se ejecutan en el mejor de los casos. Una función $f(n)$ es $\Omega(g(n))$ si y solo si existe un número $c > 0$ y un número $n_0 > 0$ tal que para todo $n > n_0$, $f(n) \geq c * g(n)$. En otras palabras, si al multiplicar $g(n)$ por un número $c$, se obtiene un número menor o igual a $f(n)$ desde un punto hasta el infinito. O sea, la acota inferiormente. ($\Omega$ es una función que acota inferiormente a $f(n)$).
- Notación Theta := $\Theta$(f(n))
  Es la intersección de las funciones $O$ y $\Omega$. Es decir, es la función que acota superior e inferiormente a $f(n)$.

## Breve vistazo al uso y manipulación de memoria

### Memoria RAM, los registros y los punteros

La memoria RAM es donde se almacenan los datos que se están utilizando en el momento. Es una memoria volátil, es decir, cuando se apaga la computadora se pierden los datos que se encuentran en la memoria RAM. Realmente no tiene propósito conservar los datos en RAM, ya que su único propósito es agilizar el acceso a los datos que se están utilizando en el momento.

Cuando nosotros ejecutamos un programa o instrucción. Cada uno de los espacios que ocupamos en memoria, como lo serían variables, son almacenados de manera aleatoria en la RAM (por eso se llama Random Access Memory) y por tanto, no es predecible la dirección de memoria en que se va a encontrar un dato en particular.

Nuestro programa, al instanciar el dato, puede conocer esta dirección, y la podemos almacenar en lo que llamaremos un puntero. Un puntero es una variable que almacena la dirección de memoria de otro dato. Estos datos se almacenan en los registros de la CPU al momento de ejecutar cualquier operación utilizando dichos datos. (Esto es lo que se conoce como memoria caché, y todos los procesos relacionados al uso y manipulación de la memoria pueden ser estudiados en un curso de arquitectura de computadoras, así que no ahondaremos en este tema, ya que no es el propósito del curso).

### ¿Cómo se reserva memoria?

Cuando se reserva memoria para un dato, se reserva un espacio de memoria de un determinado, que dependerá del tamaño del tipo de dato que sea. Esta reserva se hace de manera dinámica, es decir, en tiempo de ejecución. Podemos conocer el tamaño de un dato con la función sizeof(), que nos devuelve el tamaño en bytes de un dato. Por ejemplo, si queremos conocer el tamaño de un entero, podemos hacer:

```c++
sizeof(int);

// Esto nos devolverá 4, ya que un entero ocupa 4 bytes en memoria.
```

### Tipos de datos y sus límites númericos

Podemos referirnos a la siguiente tabla, con el tamaño de cada tipo de dato en C++ y los límites númericos que puede almacenar cada uno:

| Tipo de dato | Tamaño en bytes | Límites númericos |
|--------------|-----------------|-------------------|
| char         | 1               | -128 a 127        |
| unsigned char| 1               | 0 a 255           |
| short        | 2               | -32768 a 32767    |
| unsigned short| 2              | 0 a 65535         |
| int          | 4               | -2147483648 a 2147483647 |
| unsigned int | 4               | 0 a 4294967295    |
| long         | 4               | -2147483648 a 2147483647 |
| unsigned long| 4               | 0 a 4294967295    |
| long long    | 8               | -9223372036854775808 a 9223372036854775807 |
| unsigned long long| 8          | 0 a 18446744073709551615 |
| float        | 4               | 1.17549e-38 a 3.40282e+38 |
| double       | 8               | 2.22507e-308 a 1.79769e+308 |
| long double  | 16              | 3.3621e-4932 a 1.18973e+4932 |

Como recomendación, al usar datos de punto flotante, siempre usar double, ya que es el tipo de dato que más precisión tiene. Siempre que se pueda, usar enteros, ya que son más eficientes en términos de memoria y velocidad de ejecución.

### Tipos de datos personalizados

En C o C++ podemos crear tipos de datos personalizados, utilizando la palabra reservada typedef. Por ejemplo, podemos crear un tipo de dato llamado entero, que es un alias de int, de la siguiente manera:

```c++
typedef int entero;
```

Ahora podemos usar entero en lugar de int, y el compilador lo interpretará como int. Esto es útil cuando queremos crear tipos de datos personalizados, que nos permitan hacer nuestro código más legible.

Incluso podemos crear tipos de datos personalizados que sean estructuras, como por ejemplo:

```c++
typedef struct {
  int x;
  int y;
} punto;
```

Ahora podemos usar punto en lugar de struct { int x; int y; }, y el compilador lo interpretará como struct { int x; int y; }. Esto es útil cuando queremos crear tipos de datos personalizados, que nos permitan hacer nuestro código más legible.

Podemos estimar el tamaño de una estructura utilizando la función sizeof(), como por ejemplo:

```c++
sizeof(punto);

// Esto nos devolverá 8, ya que un punto ocupa 8 bytes en memoria. (2 enteros de 4 bytes cada uno)
```

Para conocer más sobre [structs](https://stackoverflow.com/questions/1675351/typedef-struct-vs-struct-definitions/) y el uso de sizeof(), pueden consultar el siguiente [link](https://stackoverflow.com/questions/1675351/typedef-struct-vs-struct-definitions/).

### ¿Cómo se utilizan los punteros?

Ahora, ya hemos mencionado que un puntero es una variable que almacena la dirección de memoria de otro dato. Para declarar un puntero, debemos hacer lo siguiente:

```c++
type_of_data *pointer_name;
```

En nuestros ejemplos anteriores, los siguientes son punteros válidos:

```c++
int *puntero_a_entero;
entero *puntero_a_entero;
punto *puntero_a_punto;
```

Para asignar un valor a un puntero, debemos hacer lo siguiente:

```c++
int a = 5;
int *puntero_a_entero = &a;
```

En este caso, estamos asignando la dirección de memoria de la variable a, a la variable puntero_a_entero.

### ¿Por qué utilizar punteros y cómo son útiles?

Sabemos que los punteros nos permiten conocer la dirección de memoria de un dato. Pero, además, nos permiten acceder a los datos de esa dirección de memoria e incluso modificarlos. Por ejemplo, si tenemos el siguiente código:

```c++
int a = 5;
int *puntero_a_entero = &a;
int b = *puntero_a_entero;
*puntero_a_entero = 10;
```

En este ejemplo acabaron de pasar muchas cosas. Entre ellas:

1. Creamos una variable a, de tipo entero, y le asignamos el valor 5.
2. Creamos una variable puntero_a_entero, de tipo puntero a entero, y le asignamos la dirección de memoria de la variable a.
3. Creamos la variable b, de tipo entero, y le asignamos el valor de la variable a, mediante el puntero puntero_a_entero.
4. Modificamos el valor de la variable a, mediante el puntero puntero_a_entero. Sin siquiera conocer el nombre de la variable a, pudimos modificar su valor.

### La notación de punto y la notación de flecha (dot and arrow notation)

Como ya vimos, podemos crear nuevos tipos de datos con structs y clases. La manera de acceder a los miembros de un struct o una clase es mediante la notación de punto. Por ejemplo, si tenemos el siguiente código:

```c++
typedef struct punto {
  int x;
  int y;
}punto;

punto p;
p.x = 5;
p.y = 10;
```

En este ejemplo, estamos creando un struct llamado punto, que tiene dos miembros, x e y. Luego, creamos una variable p, de tipo punto, y le asignamos valores a sus miembros x e y.

(Para aclarar, los miembros de un struct vendrían siendo atributos, que son variables que pertenecen a la clase, y métodos, que son funciones que pertenecen a la clase).

Ahora, si tenemos el siguiente código:

```c++
typedef struct punto {
  int x;
  int y;
}punto;

punto *p = new punto();
p->x = 5;
p->y = 10;
```

Lo que acabó de ocurrir se puede resumir en lo siguiente:

1. Creamos un struct llamado punto, con miembros x e y.
2. Creamos un puntero a punto, y le asignamos la dirección de memoria de un objeto de tipo punto. La palabra reservada `new`, nos permite crear un objeto en el *heap*, y nos devuelve la dirección de memoria de ese objeto.
3. Asignamos valores a los miembros x e y del objeto al que apunta el puntero p, utilizando la notación de flecha.

Es importante destacar, que el objeto al que apunta el puntero p, no es el mismo objeto que creamos con la palabra reservada `new`. El objeto al que apunta el puntero p, es un objeto que se encuentra en el *heap*, y que tiene los mismos miembros que el objeto que creamos con la palabra reservada `new`.

Por tanto, podemos resumir que la notación de flecha es utilizada para acceder a los miembros de un objeto al que apunta un puntero, y la de punto es utilizada para acceder a los miembros de un objeto como tal (sin utilizar punteros, y de manera directa o explícita).

## Clases de estructuras de datos

Una vez conocemos de manera apropiada como se manipula y administra la memoria en C++, podemos comenzar a estudiar las estructuras de datos. En este caso, las clasificamos de las siguientes maneras:

- Estructuras lineales:
  - Arreglos
  - Listas
  - Pilas
  - Colas
- Estucturas no lineales:
  - Estrucutras de arboles
  - Estrucutras de grafos
- Estructuras con acceso directo
  - Tablas hash
  - Arreglos

Las estructuras de datos que veremos durante la guía serán:

- Arreglos
- Listas:
  - Listas simplemente enlazadas:
    - Con cabecera
    - Con cabecera y cola
  - Listas doblemente enlazadas:
    - Con cabecera
    - Con cabecera y cola
- Pilas:
  - Usando listas simplemente enlazadas
  - Usando arreglos circulares
- Colas:
  - Usando listas simplemente enlazadas
  - Usando arreglos circulares

Asimismo, veremos los siguientes algoritmos de ordenamiento:

- Selection sort
- Insertion sort
- Bubble sort
- Merge sort
- Heap sort

Otros algoritmos que veremos son:

- Búsqueda binaria (Binary search)

Por cada estructura de datos, veremos:

- Definición
- Declaración
- Inserción
- Eliminación
- Modificación
- Ordenamiento

## Arreglos

Son estructuras de datos que consisten el la reserva y uso de bloques de memoria contiguos. Estos bloques son del tamaño del tipo de dato almacenado multiplicado por la cantidad de elementos precisados al momento de crearlo. Es una estructura de datos indexada, es decir, cada elemento del arreglo tiene un índice asociado, este por lo general comienza en 0 y termina en el tamaño del arreglo menos 1 (indexado desde 0).

Podríamos visualizarlos así:

| 0 | 1 | 2 | 3 | 4 | 5 | 6 | 7 | 8 | 9 |
|:---:|:---:|:---:|:---:|:---:|:---:|:---:|:---:|:---:|:---:|
|int|int|int|int|int|int|int|int|int|int|
|4 bytes|4 bytes|4 bytes|4 bytes|4 bytes|4 bytes|4 bytes|4 bytes|4 bytes|4 bytes|
|0x00000000|0x00000004|0x00000008|0x0000000C|0x00000010|0x00000014|0x00000018|0x0000001C|0x00000020|0x00000024|
|tamaño total||size\_of(int)\*10|| 40 bytes| | | | | |

Al ser una estructura de datos indexada, podemos acceder y modificar a los elementos del arreglo mediante un índice. Por ejemplo, si tenemos el siguiente arreglo:

```c++
int arreglo[10];
```

Podemos acceder y a los elementos del arreglo mediante el siguiente código:

```c++
arreglo[0] = 5;
arreglo[1] = 10;
```

Esta característica, nos permite acceder a los elementos del arreglo de forma constante, es decir, independientemente del tamaño del arreglo, el tiempo de acceso a los elementos será el mismo. Por tanto, decimos que el acceso y modificación es $O(1)$.
El espacio de memoria que ocupa un arreglo es de $O(n)$, donde $n$ es el tamaño del arreglo.

### Declaración de arreglos

Declaramos a los arreglos de la siguiente manera:

```c++
tipe_de_dato nombre_arreglo[tamaño_arreglo];
```

También podemos hacerlo por extensión:

```c++
tipe_de_dato nombre_arreglo[] = {elemento1, elemento2, ..., elementoN};
```

Lo que hace el compilador es asignar el tamaño del arreglo en base a la cantidad de elementos que le pasamos. Aparta los bytes necesarios para almacenar los elementos. De no instanciar los elementos, la información almacenada en el arreglo será basura.

Como tal, el arreglo es un puntero a la primera posición del mismo. Por tanto, podemos acceder a los elementos del arreglo de la siguiente manera:

```c++
nombre_arreglo[indice];
// Lo que es equivalente a acceder al dato que se encuentra en la dirección de memoria
// del "puntero" nombre_arreglo, sumado al indice (como posiciones consecutivas de ese espacio en memoria)
*(nombre_arreglo + indice);
```

También podríamos crear nuestro porpio puntero a un arreglo de la siguiente manera:

```c++
tipo_de_dato *nombre_puntero = nombre_arreglo;
```

E incluso, crear nuestra propia versión de un arreglo:

```c++
tipo_de_dato *nombre_arreglo = new tipo_de_dato[tamaño_arreglo];
// Equivalente a
tipo_de_dato *nombre_arreglo = (tipo_de_dato *)malloc(tamaño_arreglo * sizeof(tipo_de_dato));
```

En el segundo escenario, creamos un puntero de un tipo de dato. Y a partir de el, reservamos un espacio en memoria del tamaño del arreglo, multiplicado por el tamaño del tipo de dato. Esto nos devuelve un puntero a la primera posición del arreglo, como si lo hubiéramos creado con la sintaxis de arriba. El cast es necesario para que el compilador sepa que el tipo de dato que estamos reservando es un puntero.

Podemos acceder a los elementos del arreglo de la siguiente manera de las maneras en que lo hicimos antes `nombre_arreglo[indice]` o `*(nombre_arreglo + indice)`.

En el segundo escenario, es necesario liberar la memoria reservada para el arreglo, de lo contrario, tendremos un memory leak. Para liberar la memoria, usamos la función `free`:

```c++
free(nombre_arreglo);
```

### Acceso a arreglos

Como lo mencionamos antes, podemos acceder a los elementos del arreglo de las siguientes maneras:

```c
nombre_arreglo[indice];
// Lo que es equivalente a acceder al dato que se encuentra en la dirección de memoria
*(nombre_arreglo + indice);

```

### Modificación de arreglos

En este caso, la modificación de los elementos del arreglo se hace accediendo a ellos, y reasignando el valor

```c
nombre_arreglo[indice] = valor;
// Lo que es equivalente a acceder al dato que se encuentra en la dirección de memoria
*(nombre_arreglo + indice) = valor;
```

Recordemos que como es una estructura de tamaño fijo. No podemos como tal "agregar" o "eliminar" elementos. Pero podemos simularlo, creando un nuevo arreglo con el tamaño que necesitemos, y copiando los elementos del arreglo original en el nuevo. Esto hace que el tiempo de ejecución sea $O(n)$, donde $n$ es el tamaño del arreglo. Y la implementación se lograría de manera sencilla iterando sobre los indices con un ciclo for.

Por ejemplo, si deseamos reducir el tamaño del arreglo en m unidades, podemos hacer lo siguiente:

```c++
int *nuevo_arreglo = new int[tamaño_arreglo - m];
for (int i = 0; i < tamaño_arreglo - m; i++) {
  nuevo_arreglo[i] = arreglo[i];
}
```

Y si deseamos aumentar el tamaño del arreglo en m unidades, podemos hacer lo siguiente:

```c++
int *nuevo_arreglo = new int[tamaño_arreglo + m];
for (int i = 0; i < tamaño_arreglo; i++) {
  nuevo_arreglo[i] = arreglo[i];
}
```

### Pros y contras de arreglos

- Contras:
  - Tamaño fijo
  - No se pueden agregar o eliminar elementos
  - Habríá que conocer cuantos datos se van a almacenar
- Pros:
  - Acceso constante
  - La memoria se reserva de forma contigua
  - Los datos se guardan como los indicamos

### Ejercicios

- [Hackerrank](https://www.hackerrank.com/domains/data-structures?filters%5Bsubdomains%5D%5B%5D=arrays)
- [CSES](https://cses.fi/problemset/task/1094)

## Listas

A diferencia de los arreglos, el tamaño de las listas no es fijo, por tanto, cada vez que se necesite almacenar un nuevo elemento, se debe crear un nuevo nodo unicamente para ese elemento, y agregarlo a la lista. Por tanto, el tiempo de ejecución de agregar un elemento a la lista es $O(1)$ si se agrega a la cabecera, o $O(i)$ si lo agregamos en la iesima posición de la lista.

Otra diferencia notable, es que no existen posiciones consecutivas de memoria  para los elementos de la lista, y por lo mismo, decimos que no es indexado. Por tanto, el acceso a los elementos de la lista es lineal, es decir, el tiempo de acceso es $O(n)$, donde $n$ es el tamaño de la lista.

### Visualización de listas

Podríamos visualizar una lista de la siguiente manera:

![Lista](https://upload.wikimedia.org/wikipedia/commons/thumb/6/6d/Singly-linked-list.svg/1200px-Singly-linked-list.svg.png)
[Imagen tomada de Wikipedia](https://upload.wikimedia.org/wikipedia/commons/thumb/6/6d/Singly-linked-list.svg/1200px-Singly-linked-list.svg.png)

Donde cada cajita representa un nodo, y cada flecha representa la dirección de memoria del siguiente nodo. En este caso, la lista tiene 4 nodos, y el último nodo apunta a `NULL`, que es un puntero que apunta a ninguna dirección de memoria.

Cada nodo es compuesto por dos elementos: un dato almacenado, y un puntero al siguiente nodo. Por tanto, el tamaño de cada nodo es el tamaño del dato almacenado, más el tamaño del puntero al siguiente nodo.

En principio, al no tener ningún elemento, la lista se encuentra vacía, y por lo tanto, el puntero a la cabeza de la lista apunta a `NULL`. Por tanto, la lista se encuentra vacía.

De hecho, la cabeza de la lista que sería la forma de referirnos a la propia lista, es un puntero a un nodo, y al ser propiamente un apuntador, puede simplemente apuntar a `NULL`, indicando que la lista está vacía.

### Declaración de listas (Definición de los nodos)

Empezamos declarando un nodo, que es la estructura que usaremos para crear la lista. El nodo es una estructura que contiene un dato, y un puntero al siguiente nodo. Por tanto, la estructura se vería de la siguiente manera:

```c
typedef struct nodo {
  tipo_de_dato dato;
  struct nodo *siguiente;
}nodo;
```

Utilizando tipos de dato genéricos, podemos crear una lista de cualquier tipo de dato. La forma en que se haría es la siguiente:

```c
typedef struct nodo {
  void *dato;
  struct nodo *siguiente;

}nodo;
```

o en C++ con templates:

```c++
template <typename T>
struct nodo {
  T dato;
  nodo<T> *siguiente;
};
```

Para crear nuestra lista, simplemente creamos un puntero a un nodo, y lo inicializamos en `NULL`, indicando que la lista está vacía.

```c
nodo *head = NULL;
```

### Inserción de elementos en una lista

Para insertar un elemento en una lista, debemos crear un nuevo nodo, y asignarle el dato que queremos almacenar. Luego, debemos asignarle el puntero al siguiente nodo, que en este caso, será el nodo que actualmente es la cabeza de la lista. Por último, debemos asignarle el nuevo nodo como la nueva cabeza de la lista.

```c
nodo *nuevo_nodo = new nodo;
nuevo_nodo->dato = dato;
nuevo_nodo->siguiente = head;
head = nuevo_nodo;
```

Observemos que el tiempo de ejecución de esta operación es $O(1)$, ya que no depende del tamaño de la lista, y que los datos se guardan con el orden en que fueron ingresados.

Usando menos variables, podemos escribir la inserción de la siguiente manera:

```c
head -> siguiente = new nodo(head -> siguiente, dato);
```
