
def Binarry(value, T):#图像二值化函数
    if value > T:
        value = 255
    else:
        value = 0
    return value
    

DataThree = bytearray(520*520)#图像数据
f = open('Map.bmp', 'rb+')
imghead = f.read(54)

imgdata = f.read()
f.close()
imgdata = bytearray(imgdata)
m = 0
for i in range(520):
    for j in range(520):
        k = 3*j
        #temp = (imgdata[520*3*i+k]+imgdata[520*3*i+k+1]+imgdata[520*3*i+k+2])
        temp = (imgdata[520*3*i+k]+imgdata[520*3*i+k+1])/2      
        #temp = imgdata[520*3*i+k+1]
        #temp = imgdata[520*3*i+k+2]
        temp = Binarry(temp, 125)
        DataThree[m] = temp
        m+=1        
        imgdata[520*3*i+k]=temp
        imgdata[520*3*i+k+1]=temp
        imgdata[520*3*i+k+2]=temp
f = open('2.bmp', 'wb+')
f.write(imghead)
f.write(imgdata)
f.close()
Map = bytearray(28*28)
for i in range(28*28):
    Map[i]=2
Map1 = [[2 for i in range(28)] for j in range(28)]
for i in range(26):
    for j in range(26):
        imgde_block_sum = 0
        for block_y in range(20):
            for block_x in range(20):
                #print(DataThree[20*520*i+block_y*520+j*20+block_x])
                imgde_block_sum += DataThree[20*520*i+block_y*520+j*20+block_x]
        imgde_block_sum//=20*20
        Map1[i+1][j+1]=imgde_block_sum
        if imgde_block_sum>200:
            Map[(26-i)*28+j+1]=1
            Map1[i+1][j+1]=1
                    
        else:
            Map[(26-i)*28+j+1]=0
            Map1[i+1][j+1]=0

for i in range(28):
    print(Map1[i])


Map[28+j+13]=0
Map[28+j+14]=0
Map[56+j+13]=0
Map[56+j+14]=0

f = open('1pass', 'wb+')
f.write(Map)
f.close()
for i in range(28*28):
    if i%28==0:
        print('\n')
    print(Map[i], end=" ")
print('finish')
