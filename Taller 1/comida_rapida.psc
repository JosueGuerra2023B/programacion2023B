Algoritmo comida_rapida
	Escribir "Bienvenido a no engordaras"
	Definir ci,ti, n  Como Entero
	Definir venta Como Real
	ti=0
	n=0
	
	Repetir
		Escribir  " Inserte en cuantas ciudades existen sucursales del local " 
		leer ci
		Para ciud <- 1 Hasta ci Hacer
			totciud <- 0
			
			Escribir "Inserte cuantas tiendas existen en la ciudad ", ciud, ": "
			Leer ti
			
			Para tiend <- 1 Hasta ti Hacer
				tottiend <- 0
				
				Escribir " Cuantos empleados hay en tienda ", tiend 
				leer n
				
				Para emp <- 1 Hasta  n Hacer
					Escribir " Inserte el valor de la venta personal del empleado"
					Escribir " de la tienda ", ti, " de la ciudad ", ci, ": "
					leer totemp 
					tottiend <- tottiend + totemp
				FinPara
				
				Escribir "La venta en la tienda ", ti,  "de la ciudad " , ci, ": ", tottiend
				totciud <- totciud + tottiend
			FinPara
			
			Escribir "Las ventas totales de la Ciudad ", ciud, ": " ,totciud
			totca <- totca + totciud
		FinPara
		Escribir "Las ventas totales de la Cadena en un día: ", totca
		
		Escribir " Desea Continuar nuevamente: (Si(y) | No(x)) "
		Leer cont
		
	Hasta Que cont = "x"
	Escribir  " --Gracias por usar nuestro sistema-- "
	Escribir " Creado Por Guerra JOsué "
FinAlgoritmo

