#!/usr/bin/python

import cgi, cgitb
cgitb.enable()

form=cgi.FieldStorage()

def head():

	print "Content-Type:text/html\n\n"
	#print headers
	print """
		<html>
			<head>
				<title>Make a Friend!</title>
			</head>
			<body><center>
				<h1>Make a friend by choosing from the list below</h1>
		"""
	#read users.txt
	FILE=open('../users.txt', 'r')
	
	#loop through users.txt
	i=4
	for line in FILE:
		
		if (i%4) == 0:
			print """
				<form action='newfriends.py'>
					<input type="checkbox" name="newfriend" value="
				"""
			
			#print each username
			print line, """ "> """, line, "<br>"
			
			#close form
			print """
				</form>
				"""
		i+=1
	#print bottom of html	
	print """
			</center></body>
		</html>
		"""

#main
try:
	head()
except:
	cgi.print_exception()
