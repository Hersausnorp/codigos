from conexion import conectar


def crear_cliente(nombre):
    db = conectar()
    cursor = db.cursor()
    cursor.execute("INSERT INTO clientes (nombre) VALUES (%s)", (nombre,))
    db.commit()
    db.close()


def listar_clientes():
    db = conectar()
    cursor = db.cursor()
    cursor.execute("SELECT * FROM clientes")
    datos = cursor.fetchall()
    db.close()
    return datos


def abrir_cuenta(cliente_id, productos, total):
    db = conectar()
    cursor = db.cursor()

    # 1 Buscamos si el cliente ya tiene una cuenta abierta
    cursor.execute("SELECT id, productos, total FROM cuentas WHERE cliente_id = %s", (cliente_id,))
    cuenta_existente = cursor.fetchone()

    if cuenta_existente:
        # 2 Si ya existe, extraemos los datos y los actualizamos
        id_cuenta = cuenta_existente[0]
        productos_actuales = cuenta_existente[1]
        total_actual = float(cuenta_existente[2])

        # Concatenamos los productos y sumamos el total
        nuevos_productos = f"{productos_actuales}, {productos}"
        nuevo_total = total_actual + float(total)

        # Actualizamos el registro
        cursor.execute(
            "UPDATE cuentas SET productos = %s, total = %s WHERE id = %s",
            (nuevos_productos, nuevo_total, id_cuenta)
        )
    else:
        # 3 Si no tiene cuenta, creamos una nueva normalmente
        cursor.execute(
            "INSERT INTO cuentas (cliente_id, productos, total) VALUES (%s,%s,%s)",
            (cliente_id, productos, total)
        )

    db.commit()
    db.close()


def listar_cuentas():
    db = conectar()
    cursor = db.cursor()
    cursor.execute("""
                   SELECT c.id, cl.nombre, c.productos, c.total
                   FROM cuentas c
                            JOIN clientes cl ON c.cliente_id = cl.id
                   """)
    datos = cursor.fetchall()
    db.close()
    return datos


def pagar_cuenta(id_cuenta):
    db = conectar()
    cursor = db.cursor()
    cursor.execute("DELETE FROM cuentas WHERE id=%s", (id_cuenta,))
    db.commit()
    db.close()