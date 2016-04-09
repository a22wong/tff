#!/usr/bin/python

import cgi

form=cgi.FieldStorage()

if(form.has_key("status"):
  with open("status", "a") as myfile:
    myfile.write("username "+"status")
