#FINAL Juan Cruz Vidiri - Teoria de Lenguajes

Instalar gcc, flex y bison con apt-get

## Compilar

Compilar los archivos fuente del compilador, usando los instrucciones del makefile

    $ make

El comando MAKE genera un archivo ejecutable de nombre tiny.exe. Este archivo permite compilar un programa (codigo fuente) con el nuevo compilador (tiny).

    $ ./tiny sample.tny.

El compilador tiny genera un archivo con extensión tm (sample.tm), el cual contiene las instrucciones que el programa que compiló va a llevar a cabo. Para poder ejecutar el programa que se compiló, es necesario contar con un programa que traduzca las instrucciones del lenguaje ensamblador, para ello está el programa TM.

    $ gcc tm.c –o tm.

El archivo resultante (tm) nos permitira traducir las instrucciones en lenguaje ensamblador.

    $ ./tm sample.tm.

TM ejecutará las instrucciones del programa (sample.tny) que tiny compilo.
Modo de uso:
            - Para poder introducir el número a calcular, poner el comando “go” y después el número.
            - Para ingresar otro numero, poner el comando "clear" y luego "go".
            - Finalmente enecesario teclear el comando “quit + enter” para poder salir del programa.
