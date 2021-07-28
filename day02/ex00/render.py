import sys
import os
import re

import settings

def render():
    if len(sys.argv) != 2:
        return
    arg = sys.argv[1]
    regex = re.compile(".*\.template")
    if not regex.match(arg):
        return
    if not os.path.isfile(arg):
        return
    html_text = """\
<!DOCTYPE html>
<html lang="en">
<head>
    <meta charset="UTF-8">
    <title>Render</title>
</head>
<body>
    <p>name : seonkim</p>
    <p>age : 42</p>
    <p>job : student</p>
"""
    r = open(arg, 'r')
    template = "".join(r.readlines())
    r.close()
    file = template.format(name=settings.name)
    with open('myCV.html', 'w') as f:
        f.write(html_text)
        f.write('   ' + file + '\n')
        f.write('</body>\n</html>')


if __name__ == '__main__':
    render()