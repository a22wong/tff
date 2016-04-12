#!/usr/bin/python

import cgi, cgitb

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
		<a href="../tff/makefriend.html">
                        Make a Friend
                </a>
		&emsp;
		<a href="../tff/seefriend.html">
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




#main method
if __name__="__main__":
	try:
		head()
		form()
		
