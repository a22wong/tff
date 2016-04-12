#!/user/bin/python

import cgi
import cgitb;
cgitb.enable()

from = cgi.FieldStorage()

print """
	<!DOCTYPE html>
	<html>
		<title>Make a Friend!</title>
		<body bgcolor="ECFAFF"><center>
			<h2>Make a Friend by choosing from the list below</h2>
	"""
f = open('users.txt', 'r')
for line in f:
        i=0
        if i%4:
                print """<input type="checkbox" name="new_friend" value="""line""">"""line"""<br>"""
			</form>
	</center></body>
	</html>
	"""

def addFriend():
