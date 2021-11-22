/*Ejercicio 2
Se desea implementar una aplicación que permita realizar el balanceo de carga de varios
servidores web. Para ello se cuenta con N nodos, todos iguales, que atienden los pedidos
que le deriva el balanceador de carga.
Cuando llega un pedido el balanceador deberá asignar el mismo al nodo que posea menos
pedidos en espera.
Cada nodo tiene una capacidad M para encolar pedidos. Si al momento de asignar un
pedido, todos los nodos se encuentran al máximo de su capacidad, deberá generase un
nuevo nodo.
En caso de encontrar varios nodos con la misma cantidad de pedidos, aplicar una política
aleatoria para seleccionar uno de los nodos.
Los nodos utilizan una política FIFO para procesar los pedidos.Cada pedido posee:
● Id
● Cantidad de ciclos de procesador a utilizar.
● Tipo: CPU | E/S
Se pide:
● Definir estrategia y estructuras para soportar las definiciones anteriores
● Desarrollar el procedimiento para agregar un nuevo proceso
● Desarrollar el procedimiento que permita “procesar” uno de los procesos que se
encuentran en el balanceador de carga. El procedimiento debe recibir la cantidad de
ciclos que pudo aplicar
●Desarrollar un procedimiento que de un reporte de status informando:
○ % de procesos CPU y E/S de cada nodo
○ El nodo que más procesos de tipo CPU procesó
○ El nodo que procesó el proceso de E/S más largo
*/

/*
lista de colas
nodo{
    queue
    nodo
}
queue{
    nodo frente
    nodo fin
}
nodo{
    
}
*/