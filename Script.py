#!/usr/bin/python
# -*- coding: iso-8859-1 -*-
import serial  #biblioteca para ler a porta serial do arduino
import mysql.connector    #biblioteca para conectar no mysql
import time				#biblioteca para manipulação de data e tempo(Só para o time.sleep

comport = serial.Serial('COM7', 9600) 
print ('Serial Iniciada...\n')

cnx = mysql.connector.connect(user='root', password='', host='127.0.0.1', database='frota')   #Aqui esta criando uma conexão chamado cnx
cursor = cnx.cursor()    #iniciando a comunicação com o BD
add_onibus1 = ("INSERT INTO onibus1 (peso, sentido) VALUES (%s, %s)")	#comando para preencher o BD

 
while (True):			#Entra em um loop pra ficar sempre lendo a porta serial
  serialValue = comport.readline()		#lendo a porta serial
  values = str(serialValue)					#transformando o que está vindo na porta em string, porque vem em bytes
  peso = values.split(':')[1].replace(" kg\\r\\n'", "")      #to pegando o peso da balança que estava em string neste values e depois deu um split que é separar  e depois eu substituo os caracteres indesejados por nada // o 1
  sentido = values.split(':')[0].replace("b'", "")
  peso = float(peso)   #transforma o peso em float pra mandar pro banco que é o formato certo
  print(peso, sentido)  
  time.sleep(.1)      #Só pra evitar que manda duas informações ao mesmo tempo
  
  insert = [peso, sentido]     #È uma lista do que eu quero mandar pro banco
  cursor.execute(add_onibus1, insert)   #É aqui que ele escrevendo pro BD executando  o add_onibus1 que está em cima, e o insert 
  cnx.commit()   #Registra no BD(Apertando o Enter pra mandar)
 
cursor.close()
cnx.close()
comport.close()

