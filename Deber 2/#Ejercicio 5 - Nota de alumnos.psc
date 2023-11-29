Algoritmo Notas_de_alumnos
	Definir N, est, aprob, reprob Como Real
	
	aprob = 0
	reprob =0
	
	Escribir " ///Ingrese la cantidad de alumnos/// "
	leer est
	Para i <- 1 Hasta est Hacer
		Escribir " **Ingrese la nota**"
		Leer N
		Si N > 6.99 y N <= 10 Entonces
			reprob = reprob + 1
		Sino 
			aprob = aprob + 1
		FinSi
	FinPara
	Escribir " Los estudiantes reprobados son: ", reprob
	Escribir  " Los estudiantes Aprobados son: ", aprob
	
FinAlgoritmo
