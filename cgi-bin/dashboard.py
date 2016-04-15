#!/usr/bin/python

import cgi, cgitb

cgitb.enable()

form=cgi.FieldStorage()

name=form.getvalue('fullname')
username=form.getvalue('username')
job=form.getvalue('job')

def head():

	print "Content-Type:text/html\n\n"
	print """
		<html>

		<head>
			<title> tff Dashboard </title> 
		</head>

		<body bgcolor="ECFAFF">
		<font face="Arial Rounded MT Bold" color="2340FA" size="3">
        	        <p align="left">
		"""
	print "", name
	print "<br>"
	print "", job

	print """
		<font face="Arial Rounded MT Bold" color="2340FA" size="3">
			<p align="right">
			<a href="./makefriends.py">
                	        Make Friends
              		 </a>
			&emsp;
			<a href="./seefriends.cgi">
                	        See Friends
               		 </a>
			&emsp;
			<a href="../index.html">
                	        Logout
          	      </a>
			</p>
		"""
def form():
	print """ <form name="status" action="status.py" method="post">

		<font face="Arial Rounded MT Bold" color="FF846A" size="4"><b>
			Update status: 
		</b></font>
		<input type="text" name="status" width="48" height="30">
	
		<input type="submit" value="Post">
		<input type="hidden" name="username" value="username"
		</form>
	
		<br><br>
	
		"""

def statuses():
	
	s=open("../status.txt","r")
	f=open("../friends.txt","r")
			
	statuses=s.readlines()
	friends=f.readlines()
	#for i, elem in enumerate(friends):
	#	print friends[i]
	#for i, elem in enumerate(statuses):
	#	print statuses[i]

	"""open files. display only statuses of friends of USERNAME. do this by parsing by line with splitlines(). add friends(tokenize w/ space) to variables. for all lines in statuses, print only if username is one of friends variables(includeing themself)""" 
	
	for i, elem in enumerate(friends):
		if friends[i].split(" ")[0]==username:
			fr=friends[i]
			break
	
	if len(statuses)>20:
		for i in range (0, 20):
			if statuses[i].split(" ")[0] in fr.split():
				line=statuses[i].split(" ")
                                un=line[0]
                                line.remove(line[0])
                                stat=line
                                print """
                                        <font face="Arial Rounded MT Bold" color="2340FA" size="3">
                                        <p>"""
                                print "", un
                                print ' '.join(stat)

	else:
		for i, elem in enumerate(statuses):	
			if statuses[i].split(" ")[0] in fr.split():
				line=statuses[i].split(" ")
                                un=line[0]
				line.remove(line[0])
                                stat=line
                                print """
                                        <font face="Arial Rounded MT Bold" color="2340FA" size="3">
                                        <p>"""
                                print "", un
				print ' '.join(stat)
	print """</body>
		</html>
		"""

	s.close()
	f.close()
#main method
if __name__=="__main__":
	try:
		head()
		form()
		statuses()
	except: 
		cgi.print_exception()	
