import pandas as pd
import os

class Inventory:
    def __init__(self, file="data.xlsx"):
        self.file = file
        if not os.path.exists(file):
            pd.DataFrame(columns=["ID", "Nombre", "Precio", "Stock"]).to_excel(file, index=False)

    def get_df(self): return pd.read_excel(self.file)
    def save(self, df): df.to_excel(self.file, index=False)