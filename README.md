#FINAL Juan Cruz Vidiri - Teoria de Lenguajes

Instalar gcc, flex y bison con apt-get

## Compilar

Compilar los archivos fuente del compilador, usando los instrucciones del makefile

```{r, engine='bash', count_lines}
    $ make
```


El comando MAKE genera un archivo ejecutable de nombre tiny.exe. Este archivo permite compilar un programa (codigo fuente) con el nuevo compilador (tiny)

```{r, engine='bash', count_lines}
    $ ./tiny sample.tny
```

El compilador tiny genera un archivo con extensión tm (sample.tm), el cual contiene las instrucciones que el programa que compiló va a llevar a cabo. Para poder ejecutar el programa que se compiló, es necesario contar con un programa que traduzca las instrucciones del lenguaje ensamblador, para ello está el programa TM

```{r, engine='bash', count_lines}
    $ gcc tm.c –o tm
```

El archivo resultante (tm) nos permitira traducir las instrucciones en lenguaje ensamblador

```{r, engine='bash', count_lines}
    $ ./tm sample.tm
```

TM ejecutará las instrucciones del programa (sample.tny) que tiny compilo
Modo de uso:
            - Para poder introducir el número a calcular, poner el comando “go” y después el número.
            - Para ingresar otro numero, poner el comando "clear" y luego "go".
            - Usar el comando “quit” para poder salir del programa.
