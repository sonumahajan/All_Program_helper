import smtplib

import config


def send_email(subject, msg):
    try:
        rec_email = ['techysushrut@gmail.com','sukritji@gmail.com']
        server = smtplib.SMTP('smtp.gmail.com:587')
        server.ehlo()
        server.starttls()
        server.login(config.EMAIL_ADDRESS, config.PASSWORD)
        message = 'Subject: {}\n\n{}'.format(subject, msg)
        server.sendmail(config.EMAIL_ADDRESS, rec_email, message)
        server.quit()
        print("Success: Email sent!")
    except:
        print("Email failed to send.")


subject = "Hey!"
msg = "Hello there, how are you today?"

send_email(subject, msg)
