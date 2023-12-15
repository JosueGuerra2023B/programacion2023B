Algoritmo Bono_a_recibir
	
	Definir tim, sul Como Real
	
	Escribir " ---Sistema de consultas--- "
	Escribir " ---Puedes consultar tu bono navideño aqui--- "
	Escribir " Cuantos años llevas trabajando en la empresa: "
	Leer tim
	Escribir " Inserta el salario que ganas "
	Leer  sul
	Escribir " Recuerda que tu sueldo está colocado en pesos "
	
	Segun tim Hacer
		1: 
			si tim = tim y sul = sul Entonces
			FinSi
		De Otro Modo:
			Escribir "Tu bono navideño es de: "
			si sul < 2000 y tim > 4 Entonces
				bono = sul * 0.25 
				sueldo = bono + sul
				Escribir bono
				Escribir "Y tu sueldo con el bono navideño es de: "
				Escribir sueldo
			FinSi
		2:
			Escribir "Tu bono navideño es de: "
			si sul > 2000 y tim < 4 Entonces
				bono = sul * 0.20 
				sueldo = bono + sul
				Escribir bono
				Escribir "Y tu sueldo con el bono navideño es de: "
				Escribir sueldo
			FinSi
			
	Fin Segun
	Escribir "//////////-----//////////"
	Escribir " Gracias por entrar al sistema "
	
FinAlgoritmo