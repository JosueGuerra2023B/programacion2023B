Algoritmo Poliza
	
	Definir op1, op2, op3, op4, resultado, plan Como Real 
	
	Escribir "Bienvenido al sistema digital de la póliza Internacional";
	Escribir "Plan (A) cobertura amplia $1200 "
	Escribir "Plan (B) daños y terceros $950 "
	Escribir "Escoja el plan que desea adquirir (A) o (B) "
	Leer op
	plan = 1200
	plan = 950
	
	Segun op Hacer
		"A":
			Si op = "A" Entonces
				plan = 1200
			SiNo
				plan = 950
			FinSi
			
De Otro Modo:
	Escribir "Escoja correctamente cualquiera de las dos OPCIONES"
	Leer op
	Escribir "Consume bebidas alcohólicas - 1 si | 2 no"
	Leer a
	Escribir "Usa lentes - 1 si | 2 no"
	Leer b
	Escribir "Padece alguna enfermedad (Deficiencia cardíaca, diabetes) - 1 si | 2 no"
	Leer c
	Escribir "Tiene más de 40 años - 1 si | 2 no"
	Leer d
	Escribir "¿Qué edad tiene?"
	Leer e
	si a = 1 Entonces
		op1 = plan * 0.10
		si a = 2 Entonces
			op1 = plan * 0.10
		FinSi
	FinSi
	si b = 1 Entonces
		op2 = plan * 0.05 * 0.10
		si b = 2 Entonces
			op1 = plan * 0.10
		FinSi
	FinSi
	si c = 1 Entonces
		op3 = plan * 0.05 * 0.10
		si c = 2 Entonces
			op1 = plan * 0.10
		FinSi
	FinSi
	si d = 1 Entonces
		op4 = plan * 0.20 * 0.10
		si d = 2 Entonces
			op1 = plan * 0.10
		FinSi
	FinSi
	si a = 1 y b = 1 y c = 1 y d = 1 Entonces
		resultado = op1 + op2 + op3 + op4 + plan
		Escribir "El costo de su plan es de: ", resultado
	SiNo
		resultado = op1 + op2 + op3 + op4 + plan
		Escribir "El costo de su plan es de: ", resultado 
	FinSi
	Escribir "Gracias por usar nuestro sistema"
	
Fin Segun
	
	
FinAlgoritmo
