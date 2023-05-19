import os
from PIL import Image

def crop_image(image_path, file_name):
    # 이미지 로드
    file_path = image_path + '/' + file_name
    image = Image.open(file_path)

    # 이미지 크기 가져오기
    width, height = image.size

    # 자를 영역 계산
    crop_width = width * 0.4
    crop_height = crop_width

    left = (width - crop_width) / 2
    top = (height - crop_height) / 2
    right = (width + crop_width) / 2
    bottom = (height + crop_height) / 2

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
    

    
    
    