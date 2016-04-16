#!/usr/bin/python

import cgi, cgitb
form = cgi.FieldStorage()
newFriends = form.getlist("newfriends")
currUser = form.getvalue("username")
#currUser = "wongy"

def head():
	print "Content-Type:text/html\n\n"
	print """
		<!DOCTYPE html>
		<html>
			<body>
			<form name="return" action="dashboard.py" method="post">
			<input type="submit" value="Return to Dashboard">
			<input type="hidden" name="username" value=
		"""
	print "\"%s\">" % currUser

		
	for friend in form.getlist("newfriend"):
		print "Adding: ", friend, "<br>"
		addFriend(currUser, friend)
	print """
		</html>
		"""

def addFriend(user, friend):
	if hasFriend(user, friend) == 0:
		FILE = open('../friends.txt', 'r+')
		for line in FILE:
			if user == line.split(" ")[0]:
				print "Appending: ", friend, "<br>"
				newLine = ' '.join([line.strip('^M'), friend])
				print "Writing: ", newLine, "<br>"
				FILE.write(newLine)
		FILE.close()
	else: return


def hasFriend(user, friend):
	FILE = open('../friends.txt', 'r')
	for line in FILE:
		if user == line.split(" ")[0]:
			for tok in line.split():
				if friend == tok: return 1
	FILE.close()
	return 0
try:
	#for toAdd in newFriends:
	#	addFriend(currUser, toAdd)
	head()
except:
	cgi.print_exception()
