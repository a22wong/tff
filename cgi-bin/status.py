#!/usr/bin/python

import cgi, cgitb
cgitb.enable()
form=cgi.FieldStorage()

def write():

	#username="nasty"
	#status="milky milky milk"
	f=open("../status.txt", "a")

	if form.has_key('status') and form.getvalue('status')!="":
		f.write(form.getvalue('username'));
		f.write(" ");
		f.write(form.getvalue('status'));
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
		<head> 
		"""
	#<meta http-equiv="refresh" content="0;url=./dashboard.py">
	print """
		</head>
		<body>
		<form name="info" action="dashboard.py" method="post">
		<input type="submit" name="back" value="Back to Dashboard">
		<input type="hidden" name="username" value=
		"""
	print	"\"%s\">" % form.getvalue('username')
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
