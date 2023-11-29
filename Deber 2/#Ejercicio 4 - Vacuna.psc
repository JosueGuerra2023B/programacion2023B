Algoritmo vacunas
	
	//Definir que tipo de vacuna se le asignara al paciente
	Escribir " ---Sistema de consultas--- "
	Escribir "Inserte su edad"
	Leer a
	Escribir " Inserte su sexo "
	Escribir " Masculino (M) | Femenino (F)" 
	Leer b
	
	Segun b Hacer
		"M":
			//Verificar si es masculino
		"F":
			//Verificar si es Femenino
		De Otro Modo:
			Escribir "Inserta tu genero Con las letras indicadas: "
			leer b
	Fin Segun
	Si a >= 70 Entonces
		Escribir " La vacuna a aplicarse es la tipo C "
	SiNo
		si a >= 16 y a <= 69 Entonces
			Si b = "F" Entonces
				Escribir " La vacuna a aplicarse es la tipo B "
			FinSi
		SiNo
				Escribir " La vacuna a aplicarse es la tipo A "
			FinSi
		FinSi
		si a <= 16 Entonces
			Escribir " La vacuna a aplicarse es la tipo A "
		FinSi
	
	Escribir "//////////-----//////////"
	Escribir " Gracias por entrar al sistema "
	
FinAlgoritmo