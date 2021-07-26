import sys

def periodic_table():
    html_text = """\
<!DOCTYPE html>
<html lang="en">
<head>
    <meta charset="UTF-8">
    <title>Periodic Table</title>
    <style>
        .text-center {
            text-align: center;
        }
        
        .box {
            width: 150px;
        }
    </style>
</head>
<body>
    <div>
        <table>
            <tr>
"""

    r = open('periodic_table.txt', 'r')
    data = list(filter(None, r.read().split('\n')))
    with open('periodic_table.html', 'w') as file:
        file.write(html_text)
        for i in data:
            file.write('                <td style="border: 1px solid black; padding:10px">\n')
            val = ""
            idx = 0
            for j in i:
                if j == ' ':
                    break
                val += j
                idx += 1
            idx += 3
            file.write('                    <h4 class="text-center">' + val + '</h4>\n')
            file.write('                    <ul class="box">\n')
            flist = i[idx:].split(',')
            for j in range(0, len(flist)):
                flist[j] = flist[j].lstrip()
            val = ""
            for j in range(7, len(flist[1])):
                val += flist[1][j]
            file.write('                        <li>No ' + val + '</li>\n')
            val = ""
            for j in range(7, len(flist[2])):
                val += flist[2][j]
            file.write('                        <li>' + val + '</li>\n')
            val = ""
            for j in range(6, len(flist[3])):
                val += flist[3][j]
            file.write('                        <li>' + val + '</li>\n')
            val = ""
            for j in range(9, len(flist[4])):
                val += flist[4][j]
            file.write('                        <li>' + val + ' electron</li>\n')
            file.write('                    </ul>\n                </td>\n')

        file.write("            </tr>\n        </table>\n    </div>\n</body>\n</html>")
    r.close()

if __name__ == '__main__':
    periodic_table()