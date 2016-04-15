#!/usr/bin/python

import cgi, cgitb

def head():
	print "Content-Type:text/html\n\n"
	print """
		<!DOCTYPE html>
		<html>
			<a href="./dashboard.py">Return to Dashboard</a>
		</html>
		"""

def addFriend():

def hasFriend(user, friend): #checks if user already has friend
	FILE = open('../friends.txt', 'r')
	f = FILE.getline()
	for user in f
try:
	head()
except:
	cgi.print_exception()
