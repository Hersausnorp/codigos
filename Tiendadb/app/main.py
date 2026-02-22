from crud import *
import os


def limpiar_pantalla():
    # Limpia la consola según el sistema operativo
    os.system('cls' if os.name == 'nt' else 'clear')


def menu_principal():
    limpiar_pantalla()
    print("=" * 30)
    print("   SISTEMA DE GESTIÓN POS")
    print("=" * 30)
    print("1. 👤 Crear cliente")
    print("2. 📋 Ver clientes")
    print("3. 🛒 Abrir cuenta")
    print("4. 💰 Ver cuentas")
    print("5. ✅ Pagar cuenta")
    print("6. ❌ Salir")
    print("-" * 30)


while True:
    menu_principal()
    op = input("Seleccione una opción: ")

    if op == "1":
        print("\n--- NUEVO CLIENTE ---")
        nombre = input("Nombre del cliente: ")
        crear_cliente(nombre)
        print(f"\n✔️ Cliente '{nombre}' creado con éxito.")
        input("\nPresione Enter para continuar...")

    elif op == "2":
        print("\n--- LISTADO DE CLIENTES ---")
        clientes = listar_clientes()
        if not clientes:
            print("No hay clientes registrados.")
        else:
            # Encabezado simple
            print(f"{'ID':<5} | {'Nombre'}")
            print("-" * 20)
            for c in clientes:
                # Asumiendo que 'c' es una tupla o tiene atributos
                print(f"{c[0]:<5} | {c[1]}")
        input("\nPresione Enter para continuar...")

    elif op == "3":
        print("\n--- NUEVA CUENTA ---")
        try:
            id_c = int(input("ID del cliente: "))
            prod = input("Productos (separados por coma): ")
            total = float(input("Monto total: $"))
            abrir_cuenta(id_c, prod, total)
            print("\n✔️ Cuenta abierta exitosamente.")
        except ValueError:
            print("\n❌ Error: Ingrese valores numéricos válidos.")
        input("\nPresione Enter para continuar...")

    elif op == "4":
        print("\n--- CUENTAS PENDIENTES ---")
        cuentas = listar_cuentas()
        if not cuentas:
            print("No hay cuentas activas.")
        else:
            print(f"{'ID':<4} | {'Cliente':<10} | {'Total':<10}")
            print("-" * 30)
            for c in cuentas:
                # Suponiendo que el total es la cuarta columna (índice 3)
                # Y que el índice 2 son los productos que no queremos mostrar en esta tabla resumida
                print(f"{c[0]:<4} | {c[1]:<10} | ${float(c[3]):>8.2f}")
        input("\nPresione Enter para continuar...")

    elif op == "5":
        print("\n--- PROCESAR PAGO ---")
        try:
            id_cuenta = int(input("Ingrese el ID de la cuenta a pagar: "))
            pagar_cuenta(id_cuenta)
            print(f"\n✅ Cuenta #{id_cuenta} marcada como PAGADA.")
        except ValueError:
            print("\n❌ Error: El ID debe ser un número.")
        input("\nPresione Enter para continuar...")

    elif op == "6":
        print("\nGracias por usar el sistema. ¡Adiós!")
        break

    else:
        print("\n⚠️ Opción no válida, intente de nuevo.")
        input("Presione Enter para continuar...")