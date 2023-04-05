# Curso de Estructuras de datos

## Tabla de contenido

- Qué son estructuras de datos
- Notación asintótica
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
  Nos brinda una noción de la cantidad de instrucciones que se ejecutan en el peor de los casos. Una función $f(n)$ es $O(g(n))$ si y solo si existe un número $c > 0$ y un número $n_0 > 0$ tal que para todo $n > n_0$, $f(n) <= c * g(n)$. En otras palabras, si al multiplicar $g(n)$ por un número $c$, se obtiene un número mayor o igual a $f(n)$ desde un punto hasta el infinito. O sea, la acota superiormente. (O es una función que acota superiormente a $f(n)$).
- Notación Omega := $\Omega$(f(n))
  Nos brinda una noción de la cantidad de instrucciones que se ejecutan en el mejor de los casos. Una función $f(n)$ es $\Omega(g(n))$ si y solo si existe un número $c > 0$ y un número $n_0 > 0$ tal que para todo $n > n_0$, $f(n) >= c * g(n)$. En otras palabras, si al multiplicar $g(n)$ por un número $c$, se obtiene un número menor o igual a $f(n)$ desde un punto hasta el infinito. O sea, la acota inferiormente. ($\Omega$ es una función que acota inferiormente a $f(n)$).
- Notación Theta := $\Theta$(f(n))
  Es la intersección de las funciones $O$ y $\Omega$. Es decir, es la función que acota superior e inferiormente a $f(n)$.

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

### Ejercicios:
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


