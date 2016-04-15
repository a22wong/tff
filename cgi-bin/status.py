#!/usr/bin/python

import cgi, cgitb
cgitb.enable()


def write():
	form=cgi.FieldStorage()
	#username="nasty"
	#status="milky milky milk"
	f=open("../status.txt", "r+")

	if form.has_key("status") and form["status"].value!="":
		f.write(form["username"].value);
		f.write(" ");
		f.write(form["status"].value);
		f.write("\n");
	
	#f.write(username);
	#f.write(" ");
	#f.write(status);
	#f.write("\n");
	#str=f.read(2000)
	#print str
	f.close()
def redirect():
	print "Content-Type:text/html\n\n"
	print """
		<html>
		<head> <meta http-equiv="refresh" content="0;url=./dashboard.py">
		</head>
		<body>
		If not redirected, 
		<a href="./dashboard.py"> click here</a>
		</body>
		</html>
		"""
write()
redirect()
