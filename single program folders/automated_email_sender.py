from email.message import EmailMessage
import ssl
import smtplib

email_sender = "shreejalbhattarai13@gmail.com"
email_password = "ysmwuhxmzpepqkor"
email_receiver = input("Email?")

subject = "Regarding Application Fee waiver"
your_college = input("College name?")
Body = f'''
Hetauda,Nepal
Respected Sir,

I hope all is well with you. I am writing this email in the hope of getting my application fee waived for {your_college}.
My name is Shreejal Bhattarai, and I have completed my schooling from Makawanpur Multiple Campus, and since then wanted to enrol myself for my further education in {your_college}. Education in this college would inculcate in me the required skills and knowledge which are necessary to stand out in the competitive world and to achieve my goal of becoming a successful and reputed computer engineer.
Due to my financial conditions and present circumstances, I am not able to pay much in application fees.I belong to a rural city in Nepal,and have a hard time accessing the banks for the payments.Also there is a limit for which a person can use their card for international transactions.On the same time,the bank charge huge sums of money on their own.So I request to waive the application fee or defer it till I get admitted So I can pay it late and help me to submit my application to be put into review.
Thank you so much for taking the time to read this. I request that you kindly inform me of your decision on the same.
 
Sincerely,
Shreejal Bhattarai 

'''

em = EmailMessage()
em["From"] = email_sender
em["To"] = email_receiver
em["Subject"] = subject
em.set_content(Body) 

context = ssl.create_default_context()

with smtplib.SMTP_SSL("smtp.gmail.com", 465, context = context) as smtp:
    smtp.login(email_sender, email_password)
    smtp.sendmail(email_sender, email_receiver, em.as_string())





