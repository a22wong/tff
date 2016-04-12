#!/usr/bin/python

import cgi, cgitb, os

cgitb.enable()

form=cgi.FieldStorage()

name=form.getvalue('fullname')
username=form.getvalue('username')
job=form.getvalue('job')

def head():

	print"""
	Content-Type:text/html\n\n
	<html>

	<head>
		<title> tff Dashboard </title> 
	</head>

	<body bgcolor="ECFAFF">
	<font face="Arial Rounded MT Bold" color="2340FA" size="3">
                <p align="left">
	"""
	print "
	%s <br> %s <br>
	", name, job

	print """
	<font face="Arial Rounded MT Bold" color="2340FA" size="3">
		<p align="right">
		<a href="../tff/makefriend.py">
                        Make a Friend
                </a>
		&emsp;
		<a href="../tff/seefriend.py">
                        See a Friend
                </a>
		&emsp;
		<a href="../tff/index.html">
                        Logout
                </a>
		</p>
	"""
def form():
	print """ <center><form name="status" action="status.py" method="get">

		<font face="Arial Rounded MT Bold" color="FF846A" size="4"><b>
			Update status: 
		</b></font>
		<input type="text" name="status">
		<input type="submit" value="Post">
	</form></center>
	
	<br><br>
	


	</body>
	</html>"""

def statuses():
	
	s=open("status.txt")
	f=open("friends.txt")
			
	statuses=s.read().splitlines()
	friends=f.read().splitlines()
	#open files. display only statuses of friends of USERNAME. do this by parsing by line with splitlines(). add friends(tokenize w/ space) to variables. for all lines in statuses, print only if username is one of friends variables(includeing themself) 

	for i, elem in enumerate(friends):
		if friends[i].split(" ")[0]=username:
			fr=friends[i]
			break
	
	while i<20 or elem in enumerate statuses:
		if statuses[i].split(" ")[0] in fr.split():
			un=statuses[i].split(" ").pop
			stat=statuses[i].split(" ")
			print """
				<font face="Arial Rounded MT Bold" color="2340FA" size="3">
				<p>"""
			print "%s: %s </p> ", un, join(map(str, stat))
			i+=1	


#main method
if __name__="__main__":
	try:
		head()
		form()
		statuses()
	except: 
		cgi.print_exception()	
