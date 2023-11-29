Algoritmo Paquete_a_comprar
	
	Escribir " ---Consulta de paquetes que recibiras--- "
	Escribir " Inserte el valor del bono que recibio: "
	Leer bono
	Segun bono Hacer
		1: 
			si bono = bono Entonces
			FinSi
		De Otro Modo:
			Escribir "Puede acceder a los diferentes paquetes "
			si bono >= 50000 Entonces
				Escribir " Segun su bono accedio al paquete A "
				Escribir " Una televisión, un modular, tres pares de zapatos" 
				Escribir " Cinco camisas y cinco pantalones."
			FinSi
			si bono >= 20000 y bono < 50000 Entonces
				Escribir " Segun su bono accedio al paquete B "
				Escribir " Una grabadora, tres pares de zapatos, " 
				Escribir " Cinco camisas y cinco pantalones. "
			FinSi
			si bono >= 10000 y bono < 20000 Entonces
				Escribir " Segun su bono accedio al paquete C "
				Escribir " Una grabadora, Dos pares de zapatos, " 
				Escribir " Tres camisas y Tres pantalones. "
			FinSi
			si bono < 10000 
				Escribir " Segun su bono accedio al paquete D "
				Escribir " Un pare de zapatos" 
				Escribir " Dos camisas y Dos pantalones."
			FinSi
	Fin Segun
	Escribir "//////////-----//////////"
	Escribir " Gracias por entrar al sistema "
	
FinAlgoritmo
