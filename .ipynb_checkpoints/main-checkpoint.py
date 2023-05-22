import os


from PIL import Image
from extract_keywords import extract_cpp_keywords
from myTurtle import Turtle

# cpp_keywords = ['while', 'break', 'else' ,'if', 'for', 'int', 'double', 'char', 'new', 'void']

codeList = os.listdir("code")

for file in codeList:
    if file.split('.')[-1] != 'cpp': continue
    code = open("{}".format("code/" + file), "r").read()

    code_keywords = extract_cpp_keywords(code)

    T = Turtle()
    # True : 키워드 표시
    # False : 키워드 미표시
    T.setKeywordsPosition(False)

    for i in range(0, len(code_keywords) - 1):
        T.drawLine(code_keywords[i], code_keywords[i+1])

    T.done(file)

def crop_image(image_path, file_name, keep_ratio):
    # 이미지 로드
    file_path = image_path + '/' + file_name
    image = Image.open(file_path)

    # 이미지의 너비와 높이 가져오기
    width, height = image.size
    
    # 자르기를 원하는 비율 계산
    crop_ratio = 1 - keep_ratio
    
    # 자를 영역 계산
    left = int(width * crop_ratio / 2)
    upper = int(height * crop_ratio / 2)
    right = int(width * (1 - crop_ratio / 2))
    lower = int(height * (1 - crop_ratio / 2))
    
    # 이미지 자르기
    cropped_image = image.crop((left, upper, right, lower))

    # 자른 이미지 저장
    cropped_image.save("./crop_image/cp_" + file_name)
    
    
imageList = os.listdir("image")
# i = 0
for file in imageList:
    if len(file.split('.')) == 3:
        # print(i, file)
        # i+=1
        filename = file.split('.')[2]
        if(filename == "svg"):
            os.remove("image/{}".format(file))

# codeList = os.listdir("image")
imagePath = os.getcwd() + '/image'
imageList = os.listdir(imagePath)

for fileName in imageList:
    if len(fileName.split('.')) == 3:
        # image파일 경로, image파일 이름, 이미지 사이즈 퍼센트
        # 이미지퍼센트는 60%를 남긴다는 뜻
        crop_image(imagePath, fileName, 0.6) 
    

