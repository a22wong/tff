#!/user/bin/python

import cgi, cgitb
cgitb.enable()

from = cgi.FieldStorage()

def head():
	print """
		<!DOCTYPE html>
		<html>
			<title>Make a Friend!</title>
			<body bgcolor="ECFAFF"><center>
				<h2>Make a Friend by choosing from the list below</h2>
		"""
	print """
			<input type="checkbox" name="new_friend" value="""line""">"""line"""<br>"""
			</form>
			</center></body>
		</html>
		"""

def addFriend():
