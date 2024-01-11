print("Amazon")
print("--// LOGIN AMAZON //--")
print(" ")

print("Credenciales")
usuario = "tosh@gmail.com"
contraseña = "Secret*"

us = input("Inserte su usuario: \n")
contra = input(" Inserte su contraseña: \n")

while us != usuario or contra != contraseña:
    print(" ----- Error -----")
    print("Por favor, inserte correctamente sus credenciales ")
    us = input("Inserte su usuario: \n")
    contra = input(" Inserte su contraseña: \n")

opcion = 0
total = 0
prod = 0
totprecio = 0
codes = "enero"
descuento_aplicado = False

while True:
    print("\n-----// Bienvenido a AMAZON //-----")
    print(" Menu de opciones ")
    print(" 1. Ingresar productos al carrito de compras ")
    print(" 2. Facturar ")
#Ejercicio echo por Josué Guerra
    print(" 3. Salir ")

    opcion = int(input("Inserte la opcion que desea realizar: "))

    while opcion not in [1, 2, 3]:
        print(" Opción no encontrada\nSeleccione una de las opciones indicadas ")
        opcion = int(input(" Inserte la opcion que desea realizar: "))

    if opcion == 1:
        producto = int(input(" Ingrese la cantidad de productos a registrar: "))

        for _ in range(producto):
            nombre = input("Ingrese el nombre del producto: ")
            print(" ¿El producto tiene cupón de descuento?: ")
            print(" Si (1) | No (2) ")
            descuento = int(input(" Ingrese si o no: "))

            if descuento == 1:
                while True:
                    print(" El códgio aplica un 10% ")
                    codigo = input(" Ingrese el código del producto: ")

                    if codigo == codes:
                        descuento_aplicado = True
                        break
                    else:
                        print(" No aplica descuento, inserte correctamente (Debe ser 'enero') ")

                precio = float(input(" Ingrese el precio del producto: "))
#Ejercicio echo por Josué Guerra
                precio -= precio * 0.1  

                if precio <= 0:
                    print(" Inserte valores mayores que 0 ")
                    precio = float(input(" Ingrese el precio del producto: "))
            else:
                precio = float(input(" Ingrese el precio del producto: "))

                if precio <= 0:
                    print(" Inserte valores mayores que 0 ")
                    precio = float(input(" Ingrese el precio del producto: "))

            totprecio += precio
            prod += 1  

    elif opcion == 2:
        print(" ---//---// Factura Electrónica //---//--- ")
        print(" Su factura será enviada a su correo\n ")

        if descuento_aplicado:
            print(" /-/-/-- DESCUENTO --/-/-/ ")
            print(" * Detalle del descuento * ")
            print(" * Nombre del cupón de descuento: enero ")
            print(" * Número de productos con descuento:  ", prod)
            print(" * Número total de productos: ", prod)
            print(" * Precio FINAL de la compra:  ", totprecio)
        else:
            print(" * Número de productos comprados:  ", prod)
            print(" * Precio FINAL de la compra:  ", totprecio)
#Ejercicio echo por Josue Guerra
    elif opcion == 3:
        print(" Gracias por usar nuestro sistema ")
        print(" Vuelva pronto ")
        break
