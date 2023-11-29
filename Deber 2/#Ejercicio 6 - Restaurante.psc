Algoritmo Restaurante
	
	Definir a, b, c, tot Como Real
	
	Escribir "Bienvenidos al Naufrago satisfecho"
	Escribir "Te ofrecemos 3 tipos de hamburguesas"
	Escribir "/////***/////***/////***/////***/////"
	Escribir "|1. (S), Sencillas $20|"
	Escribir "|2. (D), Dobles $25|"
	Escribir "|3. (T), Triples $28|"
	Escribir "Escoge la opción que vas a comprar"
	Leer a
	Escribir "Ingrese el número de hamburguesas que desea"
	Leer b
	Escribir "Pago en efectivo (1) o tarjeta (2)"
	Leer c
	
	Segun a Hacer
		1:
			Segun c Hacer
				1:
					tot = b * 20
				2:
					tot = b * 20 + (b * 20 * 0.05)
				De Otro Modo:
					Escribir "Intente de nuevo por favor"
			FinSegun
		2:
			Segun c Hacer
				1:
					tot = b * 25
				2:
					tot = b * 25 + (b * 25 * 0.05)
				De Otro Modo:
					Escribir "Intente de nuevo por favor"
			FinSegun
		3:
			Segun c Hacer
				1:
					tot = b * 28
				2:
					tot = b * 28 + (b * 28 * 0.05)
				De Otro Modo:
					Escribir "Intente de nuevo por favor"
			FinSegun
	FinSegun
	Escribir "El total a pagar es: ", tot
	Escribir " Si desea seguir pidiendo presione 1, si desea salir presione 2 "
	leer op
	Si op = 1 Entonces
		Escribir "Escoge la opción que vas a comprar"
		Leer a
		Escribir "Ingrese el número de hamburguesas que desea"
		Leer b
		Escribir "Pago en efectivo (1) o tarjeta (2)"
		Leer c
		
		Segun a Hacer
			1:
				Segun c Hacer
					1:
						tot = b * 20
					2:
						tot = b * 20 + (b * 20 * 0.05)
					De Otro Modo:
						Escribir "Intente de nuevo por favor"
				FinSegun
			2:
				Segun c Hacer
					1:
						tot = b * 25
					2:
						tot = b * 25 + (b * 25 * 0.05)
					De Otro Modo:
						Escribir "Intente de nuevo por favor"
				FinSegun
			3:
				Segun c Hacer
					1:
						tot = b * 28
					2:
						tot = b * 28 + (b * 28 * 0.05)
					De Otro Modo:
						Escribir "Intente de nuevo por favor"
				FinSegun
		FinSegun
		tot1 = tot +tot
		Escribir "El total a pagar es: ", tot1
	SiNo
		si op = 2 Entonces
			Escribir " Gracias por su compra"
		FinSi
	Fin Si
FinAlgoritmo
