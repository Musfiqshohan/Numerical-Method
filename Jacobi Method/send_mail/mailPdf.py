# Import smtplib for the actual sending function
import smtplib

# Import the email modules we'll need
from email.mime.multipart import MIMEMultipart
from email.mime.text import MIMEText

# Open a plain text file for reading.  For this example, assume that
# the text file contains only ASCII characters.
# textfile='textfile.txt'
# fp = open(textfile, 'rb')
# # Create a text/plain message
# msg = MIMEText(fp.read())
# fp.close()

msg = MIMEMultipart()
msg.attach(MIMEText(file("mypdf.pdf").read()))


EMAIL_ADDRESS = "online14classroom@gmail.com"
PASSWORD = "online.14.classroom"
# server = smtplib.SMTP('smtp.gmail.com:587')
# server.ehlo()
# server.starttls()
# server.login(EMAIL_ADDRESS, PASSWORD)

# me ='online14classroom@gmail.com'
# you ='musfuq14shohan@gmail.com'
# msg['Subject'] = 'The contents of %s' % textfile
# msg['From'] = me
# msg['To'] = you

# # Send the message via our own SMTP server, but don't include the
# # envelope header.
# s = smtplib.SMTP('smtp.gmail.com:587')
# s.sendmail(me, [you], msg.as_string())
# s.quit()

try:
    server = smtplib.SMTP('smtp.gmail.com:587')
    server.ehlo()
    server.starttls()
    server.login(EMAIL_ADDRESS, PASSWORD)
    # message = 'Subject: {}\n\n{}'.format(subject, msg)

    receiver = "musfuq14shohan@gmail.com"
    server.sendmail(EMAIL_ADDRESS, receiver, msg.as_string())
    server.quit()
    print("Success: Email sent!")
except:
    print("Email failed to send.")
