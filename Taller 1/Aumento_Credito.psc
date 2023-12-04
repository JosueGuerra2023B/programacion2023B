Algoritmo Aumento_Credito
	
	Definir tipT Como Caracter
	Definir porcen Como Real
	
	// Solicitar el tipo de tarjeta al cliente
	Repetir
		Escribir " Ingrese el tipo de tarjeta (A, B, C u otro): "
		Escribir " Tarjeta Tipo (A) "
		Escribir " Tarjeta Tipo (B) "
		Escribir " Tarjeta Tipo (C) "
		Escribir " Otro tipo de Tarjeta (Otro) "
		Leer tipoT
		
		Segun tipoT Hacer
				Caso "A":
				porcen <- 0.28
				Caso "B":
				porcen <- 0.38
				Caso "C":
				porcen <- 0.45
				Otro:
				aporcen <- 0.55
		FinSegun
		
		Escribir " Segun la tarjeta que escogio, el aumento sera diferente "
		Escribir "El aumento porcentual para el tipo de tarjeta ", tipoTarjeta
		Escribir " es del ", porcen * 100, "%."
		Escribir " /////**/////--/////**/////--/////"
		
		Escribir " Desea Continuar: (Si(y) | No(x))"
		Leer cont
	Hasta Que cont = "x"
	Escribir " --Gracias po usar nuestro sistema-- "
	Escribir " Creado Por Guerra JOsué "
	
FinAlgoritmo
