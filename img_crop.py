import os
from PIL import Image

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
    cropped_image = image.crop((left, top, right, bottom))

    # 자른 이미지 저장
    cropped_image.save("./crop_image/cp_" + file_name)
    

codeList = os.listdir("image")
imagePath = os.getcwd() + '/image'
imageList = os.listdir(imagePath)
print(imageList)

for fileName in imageList:
    if len(fileName.split('.')) == 3:
        crop_image(imagePath, fileName)
    

    
    
    