import sys

from extract_keywords import extract_cpp_keywords
from myTurtle import Turtle

if len(sys.argv) != 3:
    print("python3 main.py [cpp 파일 1 경로] [cpp 파일 2 경로]")
    sys.exit()


code1_path = sys.argv[1]
code2_path = sys.argv[2]

# cpp_keywords = ['while', 'break', 'else' ,'if', 'for', 'int', 'double', 'char', 'new', 'void']

code1 = open("{}.cpp".format(code1_path), "r").read()
code2 = open("{}.cpp".format(code1_path), "r").read()

code1_keywords = extract_cpp_keywords(code1)
code2_keywords = extract_cpp_keywords(code2)
print(code1_keywords)

T = Turtle()
T.setKeywordsPosition(True)

for i in range(0, len(code1_keywords) - 1):
    T.drawLine(code1_keywords[i], code1_keywords[i+1])

T.done()