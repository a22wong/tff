#!/usr/bin/env python
import cgi, cgitb
cgitb.enable()

form = cgi.FieldStorage()

def htmlTop():
	print("""
	Content-Type:text/html\n\n
	<!DOCTYPE html>
	    <html lang="en">
	        <head> 
		    <meta name="author" content="Annastasia Stathakos"?
		    <meta name="description" content="success page for registration">
		    <meta charset="UTF-8">
		    <title> Registration Page </title>

		    <!-- will make a style sheet that matches whatever ethan designs -->
		    <link rel="stylesheet" type="text/css" href="style.css">
		</head>
		<body>""") 

def htmlTail():
	print("""
		</body>
	</html>""")

def getName():
	fname = form.getvalue('fullname')
	return fname

def getJob():
	if form.getvalue('job'):
		job_desc = form.getvalue('job')
	else:
		job_desc = "No Description"
	return job_desc

def getUsername():
	username = form.getvalue('user')
	#not sure how to do this but i want to call my register.c program to validate username here
	return username
	
def getPass():
	password = form.getvalue('pass')
	return password

#main program
if __name__ == "__main__":
	try:
		htmlTop()
		fullName = getName()
		jobDesc = getJob()
		user = getUsername()
		password = getPass()
		print("<center><h3>Welcome to Tinder For Friends, {0}!</h3></center>".format(fullName))
		print(jobDesc)
		print("<p>Your Username is {0}".format(user))
		print("<p>Your password is {0}".format(password))
		htmlTail()
	except:
		cgi.print_exception()




