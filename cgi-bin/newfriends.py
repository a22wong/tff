#!/usr/bin/python

import cgi, cgitb

def head():
	print "Content-Type:text/html\n\n"
	print """
		<!DOCTYPE html>
		<html>
			<a href="./dashboard.py">Return to Dashboard</a><br>
		"""
	print hasFriend("nasty", "cohny")
	print """
		</html>
		"""
def addFriend():
	return 0

def hasFriend(user, friend):
	FILE = open('../friends.txt', 'r')
	for f in FILE:
		tokens = f.split()
		if user == tokens[0]:
			for tok in tokens:
				if friend == tok: return 1
	return 0
try:
	head()
except:
	cgi.print_exception()
