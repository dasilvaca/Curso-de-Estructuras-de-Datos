# Curso de Estructuras de datos

## Tabla de contenido

- Qué son estructuras de datos
- Notación asintótica
- Breve vistazo al uso y manipulación de memoria
  - Clases de funciones para notación asintótica
- Clases de estructuras de datos

## Qué son estructuras de datos

Son formas de organizar los datos para que puedan ser utilizados de manera eficiente.
Son colecciones de datos que se organizan de una manera particular para que puedan ser utilizados de manera eficiente.
Clasifican los datos de acuerdo a las características de los datos que se almacena y su forma de acceso.

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
2. Creamos un puntero a punto, y le asignamos la dirección de memoria de un objeto de tipo punto. La palabra reservada ```new```, nos permite crear un objeto en el *heap*, y nos devuelve la dirección de memoria de ese objeto.
3. Asignamos valores a los miembros x e y del objeto al que apunta el puntero p, utilizando la notación de flecha.

Es importante destacar, que el objeto al que apunta el puntero p, no es el mismo objeto que creamos con la palabra reservada ```new```. El objeto al que apunta el puntero p, es un objeto que se encuentra en el *heap*, y que tiene los mismos miembros que el objeto que creamos con la palabra reservada ```new```.

Por tanto, podemos resumir que la notación de flecha es utilizada para acceder a los miembros de un objeto al que apunta un puntero, y la de punto es utilizada para acceder a los miembros de un objeto como tal (sin utilizar punteros, y de manera directa o explícita).

## Clases de estructuras de datos

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

## Arreglos

Son estructuras de datos que almacenan un conjunto de datos del mismo tipo.
Tienen un tamaño fijo, es decir, una vez que se crea el arreglo no se puede modificar su tamaño.
Se accede a los elementos del arreglo de forma constante, es decir, el tiempo de acceso es constante mediante un índice que va desde 0 hasta el tamaño del arreglo menos 1. (Estan indexados desde 0). El tiempo de acceso es $O(1)$.

### Declaración de arreglos

```c
tipe_de_dato nombre_arreglo[tamaño_arreglo];
```

### Acceso a arreglos

```c
nombre_arreglo[indice];
```

### Modificación de arreglos

```c
nombre_arreglo[indice] = valor;
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

Son estructuras de datos que almacenan un conjunto de datos del mismo tipo. Se diferencian de los arreglos en que no tienen un tamaño fijo, es decir, se pueden agregar o eliminar elementos. Se accede a los elementos de la lista de forma lineal, es decir, el tiempo de acceso es lineal. El tiempo de acceso es $O(n)$.

### Declaración de listas

```c
struct nodo {
  type_de_dato dato;
  struct nodo *siguiente;
};
```
