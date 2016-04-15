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
		<form name="info" action="dashboard.py" method="post">
		<input type="hidden" name="username" value=
		"""
	print	"\"%s\">" % username
	print """If not redirected, 
		<a href="./dashboard.py"> click here</a>
		</form>
		</body>
		</html>
		"""
#main method
if __name__=="__main__":
	try:
		write()
		redirect()
	except:
		cgi.print_exception()
