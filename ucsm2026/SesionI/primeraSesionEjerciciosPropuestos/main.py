import pandas as pd
import os
from inventory import Inventory
from order import enviar_correo

inv = Inventory()

def main():
    while True:
        print("\n--- SISTEMA TIENDA UCSM ---")
        print("1. Admin (Inventario) | 2. Cliente (Compra) | 3. Salir")
        op = input("Seleccione: ")
        try:
            df = inv.get_df()
            if op == "1":
                print("\nInventario Actual:\n", df)
                sub = input("1.Añadir/Editar | 2.Borrar: ")
                if sub == "1":
                    id_p = input("ID: ")
                    df = df[df["ID"].astype(str) != str(id_p)]
                    nuevo = pd.DataFrame([{"ID": str(id_p), "Nombre": input("Nombre: "), 
                                          "Precio": float(input("Precio: ")), "Stock": int(input("Stock: "))}])
                    df = pd.concat([df, nuevo], ignore_index=True)
                elif sub == "2": df = df[df["ID"].astype(str) != input("ID a borrar: ")]
                inv.save(df)
            elif op == "2":
                print(df[["ID", "Nombre", "Precio", "Stock"]])
                id_p = input("ID a comprar: ")
                idx = df[df["ID"].astype(str) == str(id_p)].index[0]
                cant = int(input("Cantidad: "))
                if df.at[idx, "Stock"] >= cant:
                    df.at[idx, "Stock"] -= cant
                    inv.save(df)
                    if enviar_correo(input("Correo cliente: "), df.at[idx, "Nombre"]):
                        print("Compra exitosa y correo enviado.")
                else: print("Stock insuficiente.")
            elif op == "3": break
        except Exception as e: print(f"Error: {e}")

if __name__ == "__main__": main()