import smtplib, json, os
from email.message import EmailMessage

def enviar_correo(dest, prod):
    try:
        # Busca el JSON en la misma carpeta que este archivo
        base_path = os.path.dirname(os.path.abspath(__file__))
        json_path = os.path.join(base_path, "config_mail.json")
        
        with open(json_path, "r") as f: conf = json.load(f)
        
        msg = EmailMessage()
        msg.set_content(f"Hola, tu pedido de {prod} ya esta listo para recoger.")
        msg['Subject'] = 'Pedido Listo - Tienda UCSM'
        msg['From'] = conf['email']
        msg['To'] = dest

        with smtplib.SMTP_SSL('smtp.gmail.com', 465) as s:
            s.login(conf['email'], conf['password'])
            s.send_message(msg)
        return True
    except Exception as e: 
        print(f"Error de envío: {e}")
        return False