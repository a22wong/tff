#!/usr/bin/python

import cgi, cgitb

cgitb.enable()

form=cgi.FieldStorage()

username=form.getvalue("username")

def head():

	print "Content-Type:text/html\n\n"
	print """
		<html>

		<head>
			<title> tff Dashboard </title> 
		</head>

		<body bgcolor="ECFAFF">
		<font face="Arial Rounded MT Bold" color="2340FA" size="3">
        	"""
	print """ <p align="right">
                        <a href="../index.html">
                                Logout
                      </a>
                      </p>

		<p align="left">
		"""
	print "%s's dashboard" % username
	print "<br>"

	print """
		<font face="Arial Rounded MT Bold" color="2340FA" size="3">
			<p>
			<form name="makefriends" action="makefriends.py" method="post">
			<input type="submit" value="Make Friends">
			<input type="hidden" name="username" value=
		"""
	print "\"%s\">" % username
	print "</form>"
	print """
		<p>
		<form name="seefriends" action="seefriends.cgi" method="post">
                        <input type="submit" value="See Friends">
                        <input type="hidden" name="username" value=
                """
        print "\"%s\">" % username
        print "</form>"

def form():
	print """ <form name="status" action="status.py" method="post">

		<font face="Arial Rounded MT Bold" color="FF846A" size="4"><b>
			Update status: 
		</b></font>
		<input type="text" name="status" width="48" height="30">
	
		<input type="submit" value="Post">
		<input type="hidden" name="username" value=
		"""
	print "\"%s\">" % username
	print """</form>
	
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
