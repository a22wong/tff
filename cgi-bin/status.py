#!/usr/bin/python

import cgi, cgitb
cgitb.enable()

def write():
	form=cgi.FieldStorage()

	f=open(status.txt, 'r+')

	if form.has_key("status") and form["status"].value!="":
		f.write(form["username"].value +"form["status"].value\n")

	f.close()
def redirect():
	print "Content-Type:text/html\n\n"
	print """
		<html>
		<head> <meta http-equiv="refresh" content="0; url=./dashboard.py />
		</head>
		</html>
		"""

