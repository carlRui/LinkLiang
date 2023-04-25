
import xlrd
import xlwt
import copy
from xlutils.copy import copy

rb=xlrd.open_workbook("C:/Users/ASUS/Desktop/dynamic/copy.xlsx")

SPECIFICATION_INDEX =16 #表的规格位置

rs =rb.sheet_by_name("单款明细表")
b2 = rs.col_values(SPECIFICATION_INDEX) #读取对应列的数据
value = rs.cell_value(1,16); #读取对应行列数据
nrows = rs.nrows #读取行数

print(nrows)

print(b2)
print(len(b2))
result = []

for y in range(len(b2)):
        result.append([])
        result[y]=str(b2[y])

rb.release_resources()

def fun3_2_2():
        workbook = xlrd.open_workbook("C:/Users/ASUS/Desktop/dynamic/23秋冬商品资料建立2.xlsx")

        new_workbook = copy(workbook)

        sheet = workbook.sheet_by_index(0)
        col2 = sheet.col_values(1)
        cel_value = sheet.cell_value(1,1)
        print(col2)
        print(cel_value)

        #write data info
        write_save = new_workbook.get_sheet(1)
        #write_save.write(0,0,"liangluqing")
        #print(type(rs.cell_value(2, 6)))
        #print(type(rs.cell_value(2, 9)))
        get_year = rs.cell_value(2,15)
        #print(type(rs.cell_value(2, 11)))
        print(get_year[0:4])
        for i in range(rs.nrows-2):
                for j in range(7):
                        write_save.write(i*7+j+1,0,rs.cell_value(i+2,6))
                        commodity_code = rs.cell_value(i+2,6)+rs.cell_value(i+2,9)+str(int(rs.cell_value(1,16+j)))
                        write_save.write(i*7+j+1,1,commodity_code)
                        write_save.write(i * 7 + j + 1, 2, rs.cell_value(i+2,7))
                        write_save.write(i * 7 + j + 1, 5, 'Alphabet')
                        boyOrGirl = rs.cell_value(i+2, 11);
                        write_save.write(i * 7 + j + 1, 6,boyOrGirl[0])
                        write_save.write(i * 7 + j + 1, 10, '否')
                        write_save.write(i * 7 + j + 1, 14, '是')
                        write_save.write(i * 7 + j + 1, 15, int(rs.cell_value(i+2,9)))
                        write_save.write(i * 7 + j + 1, 16, rs.cell_value(i + 2, 10))
                        write_save.write(i * 7 + j + 1, 18, '是')
                        write_save.write(i * 7 + j + 1, 19, '常规尺码')
                        specification_serial_number = '0'+str(j+1);
                        write_save.write(i * 7 + j + 1, 21, specification_serial_number)
                        write_save.write(i * 7 + j + 1, 22, rs.cell_value(1, 16+j))
                        get_year = rs.cell_value(i+2, 15)
                        write_save.write(i * 7 + j + 1, 31,get_year[0:4])
                        write_save.write(i * 7 + j + 1, 32, rs.cell_value(i+2, 12))
                        write_save.write(i * 7 + j + 1, 41, rs.cell_value(i+2, 13))
                        write_save.write(i * 7 + j + 1, 99, rs.cell_value(i + 2, 13))


        #save new book
        new_workbook.save("C:/Users/ASUS/Desktop/dynamic/new_test.xlsx")


fun3_2_2()


''''
        #create new book
        workbook = xlwt.Workbook(encoding='ascii')

        #create sheet table
        worksheet = workbook.add_sheet("My new Sheet")

        #write content
        worksheet.write(0,0,"content1")
        worksheet.write(2,1,"content2")

        #save
        workbook.save("C:/Users/ASUS/Desktop/dynamic/123.xlsx")

 
#fun3_2_2()


#index = result.index(469)
#print(index)


import socket

client = socket.socket(socket.AF_INET,socket.SOCK_DGRAM)
client.connect(('47.106.179.135',9988))

msg="quit"
client.send(msg.encode('utf-8'));

client.close()
'''''
