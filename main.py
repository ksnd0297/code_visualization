import os

from extract_keywords import extract_cpp_keywords
from myTurtle import Turtle

# cpp_keywords = ['while', 'break', 'else' ,'if', 'for', 'int', 'double', 'char', 'new', 'void']

codeList = os.listdir("code")

for file in codeList:
    code = open("{}".format("code/" + file), "r").read()

    code_keywords = extract_cpp_keywords(code)

    T = Turtle()
    # True : 키워드 표시
    # False : 키워드 미표시
    T.setKeywordsPosition(False)

    for i in range(0, len(code_keywords) - 1):
        T.drawLine(code_keywords[i], code_keywords[i+1])

    T.done(file)

imageList = os.listdir("image")
# print(imageList)
for file in imageList:
    if len(file.split('.')) == 3:
        filename = file.split('.')[2]
    
    if(filename == "svg"):
        os.remove("image/{}".format(file))