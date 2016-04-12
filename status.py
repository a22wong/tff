#!/usr/bin/python

import cgi, cgitb
cgitb.enable()

form=cgi.FieldStorage()

f=open(status.txt, 'a')

if(form.has_key("status"):
	f.write("username "+"status")
	

