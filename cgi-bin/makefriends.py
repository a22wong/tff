#!/usr/bin/python

import cgi, cgitb
cgitb.enable()

form=cgi.FieldStorage()
def head():

	print "Content-Type:text/html\n\n"
	#print headers
	print """
		<!DOCTYPE html>
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
	i=0
	j=2
	print """<form action="newfriends.py" method="post">"""
	for line in FILE:
		#store username and full name
		if (i%4) == 0:
                        uName=line
                if (j%4) == 0:
                        fName=line
			#print form
			print """
					<input type="checkbox" name="newfriend" value="
				"""
			print uName, """ "> """, fName, ":", uName, "<br>"
			
		i+=1
		j+=1
	print """<input type="submit" value="Submit">"""
	print """<input type="hidden" name="username" value="username">"""
	print "</form>"
	#print bottom of html	
	print """
			</center></body>
		</html>
		"""
	FILE.close()
#main
try:
	head()
except:
	cgi.print_exception()
