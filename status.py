#!/usr/bin/python

import cgi, cgitb
cgitb.enable()

form=cgi.FieldStorage()

f=open(status.txt, 'a')

if(form["status"]:
	f.write("username "+"status")
	

