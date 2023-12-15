Algoritmo Arca_de_Noe
    Definir P, Pm, Pr, Pa Como Real
    Definir M, R, A Como Entero
	
    P <- 0
    Pm <- 0
    Pr <- 0
    Pa <- 0
    M <- 0
    R <- 0
    A <- 0
	
    Escribir 'Ingrese el peso m�ximo que soportar� el arca'
    Leer P
	
    Repetir
        Escribir ''
        Escribir 'Escoja la clasificaci�n (con los n�meros):'
        Escribir '1. Mam�feros'
        Escribir '2. Reptiles'
        Escribir '3. Aves'
        Escribir '4. Finalizar'
        Leer C
		
        Segun C Hacer
            1:
                Repetir
                    Escribir ''
                    Escribir 'Escoja el animal (con las letras):'
                    Escribir 'a. Elefante (4000kg)'
                    Escribir 'b. Jirafa (1200kg)'
                    Escribir 'c. Caballo (800kg)'
                    Escribir 'd. Volver al men� de clasificaci�n'
                    Leer Cm
					
                    Segun Cm Hacer
                        'a':
                            Pm <- Pm + 4000 * 2
                            M <- M + 2
                        'b':
                            Pm <- Pm + 1200 * 2
                            M <- M + 2
                        'c':
                            Pm <- Pm + 800 * 2
                            M <- M + 2
                    FinSegun
					
                    Si Pm + Pr + Pa > P Entonces
                        Escribir 'No soporta el peso m�ximo'
                        M <- M - 2
                        Si Cm = 'a' Entonces
                            Pm <- Pm - 4000 * 2
                        FinSi
                        Si Cm = 'b' Entonces
                            Pm <- Pm - 1200 * 2
                        FinSi
                        Si Cm = 'c' Entonces
                            Pm <- Pm - 800 * 2
                        FinSi
                    FinSi
                Hasta Que Cm = 'd'
            2:
                Repetir
                    Escribir ''
                    Escribir 'Escoja el animal (con las letras):'
                    Escribir 'a. Lagarto (200kg)'
                    Escribir 'b. Serpiente (10kg)'
                    Escribir 'c. Cocodrilo (250kg)'
                    Escribir 'd. Volver al men� de clasificaci�n'
                    Leer Cr
					
                    Segun Cr Hacer
                        'a':
                            Pr <- Pr + 200 * 2
                            R <- R + 2
                        'b':
                            Pr <- Pr + 10 * 2
                            R <- R + 2
                        'c':
                            Pr <- Pr + 250 * 2
                            R <- R + 2
                    FinSegun
					
                    Si Pm + Pr + Pa > P Entonces
                        Escribir 'No soporta el peso m�ximo'
                        R <- R - 2
                        Si Cr = 'a' Entonces
                            Pr <- Pr - 200 * 2
                        FinSi
                        Si Cr = 'b' Entonces
                            Pr <- Pr - 10 * 2
                        FinSi
                        Si Cr = 'c' Entonces
                            Pr <- Pr - 250 * 2
                        FinSi
                    FinSi
                Hasta Que Cr = 'd'
            3:
                Repetir
                    Escribir ''
                    Escribir 'Escoja el animal (con las letras):'
                    Escribir 'a. �guila (5kg)'
                    Escribir 'b. Pinz�n (0.05kg)'
                    Escribir 'c. Pel�cano (10kg)'
                    Escribir 'd. Volver al men� de clasificaci�n'
                    Leer Ca
					
                    Segun Ca Hacer
                        'a':
                            Pa <- Pa + 5 * 2
                            A <- A + 2
                        'b':
                            Pa <- Pa + 0.05 * 2
                            A <- A + 2
                        'c':
                            Pa <- Pa + 10 * 2
                            A <- A + 2
                    FinSegun
					
                    Si Pm + Pa + Pr > P Entonces
                        Escribir 'No soporta el peso m�ximo'
                        A <- A - 2
                        Si Ca = 'a' Entonces
                            Pr <- Pr - 5 * 2
                        FinSi
                        Si Ca = 'b' Entonces
                            Pr <- Pr - 0.05 * 2
                        FinSi
                        Si Ca = 'c' Entonces
                            Pr <- Pr - 10 * 2
                        FinSi
                    FinSi
                Hasta Que Ca = 'd'
        FinSegun
	Hasta Que c = 4
	Si Pm+Pr+Pa>0 Entonces
		Escribir ''
		Escribir '--------------------- RESUMEN ---------------------'
		Escribir 'Hay ',M,' mamiferos en el arca'
		Escribir 'Hay ',R,' reptiles en el arca'
		Escribir 'Hay ',A,' aves en el arca'
		Escribir 'Hay ',M+R+A,' animales en total en el arca'
		Escribir ''
		Escribir 'Hay ',(M+R+A)/2,' animales macho en el arca'
		Escribir 'Hay ',(M+R+A)/2,' animales hembra en el arca'
		Escribir ''
		Escribir 'El peso total de todos los mam�feros es de: ',Pm
		Escribir 'El peso total de todos los reptiles es de: ',Pr
		Escribir 'El peso total de todas las aves es de: ',Pa
		Escribir 'El peso total de todos los animales es de: ',Pm+Pr+Pa
		Escribir '---------------------------------------------------'
	SiNo
		Escribir 'No se ha a�adido ning�n animal al arca'
	FinSi
	Si Pm+Pr+Pa>0.9*P Entonces
		Escribir 'El arca naveg� con �xito'
	SiNo
		Escribir 'El arca todavia tiene capacidad, por lo tanto no zarpar�'
	FinSi
	
FinAlgoritmo

