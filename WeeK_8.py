class SinhVien:                                                                #Khai báo lớp sinh viên với các thuộc tính đề bài đã cho
    def __init__(self, maSV, hoTen, gioiTinh, ngaySinh, diaChi, lop, khoa):    #Khởi tạo các thuộc tính của đối tượng sinh viên
        self.maSV = maSV                                                       
        self.hoTen = hoTen                                                     
        self.gioiTinh = gioiTinh                                               
        self.ngaySinh = ngaySinh                                                    
        self.diaChi = diaChi                                                   
        self.lop = lop                                                          
        self.khoa = khoa                                                       
        self.next = None                                                       #Con trỏ trỏ đến sinh viên tiếp theo trong danh sách

class DanhSachSV:                                                              
    def __init__(self):                                                        
        self.first = None                                                      #Khởi tạo thuộc tính first để lưu địa chỉ của sinh viên đầu tiên trong danh sách, nếu danh sách rỗng thì địa chỉ là None

    def isEmpty(self):                                                         #Kiểm tra xem danh sách có rỗng không
        return self.first == None                                              #Trả về True -> danh sách rỗng và false ngược lại

    def nhapSV(self):
        maSV = input("Nhập mã số sinh viên: ")
        hoTen = input("Nhập họ và tên sinh viên: ")
        gioiTinh = input("Nhập giới tính: ")
        ngaySinh = input("Nhập ngày tháng năm sinh: ")
        diaChi = input("Nhập nơi ở hiện tại: ")
        lop = input("Nhập lớp sinh viên: ")
        khoa = input("Nhập ngành học của sinh viên: ")
        newSV = SinhVien(maSV, hoTen, gioiTinh, ngaySinh, diaChi, lop, khoa)   #Tạo một đối tượng sinh viên mới với thông tin người dùng nhập
        newSV.next = self.first                                                #Đặt con trỏ của sinh viên mới trỏ đến sinh viên hiện tại
        self.first = newSV

    def Bubble_sort(self):                                                     #Dùng thuật toán sắp xếp nổi bọt để sắp xếp mssv từ bé đến lớn
        current = self.first
        while current:
            next_node = current.next
            while next_node:
                if current.maSV > next_node.maSV:
                    current.maSV, next_node.maSV = next_node.maSV, current.maSV
                next_node = next_node.next
            current = current.next

    def themSV(self, svMoi):
        # Tìm vị trí thích hợp để chèn
        current = self.head
        prev = None
        while current and current.maSV < svMoi.maSV:
            prev = current
            current = current.next
        
        # Chèn sinh viên mới
        svMoi.next = current
        if prev:
            prev.next = svMoi
        else:
            self.head = svMoi

    def timSVTheoNgaySinh(self, ngaySinh):
        current = self.head
        while current:
            if current.ngaySinh == ngaySinh:
                print(f"Mã SV: {current.maSV}, Họ tên: {current.hoTen}")
            current = current.next
        if current == None:
            print("Không tìm thấy sinh viên cùng ngày sinh")

    def xoaSVTheoNgaySinh(self, ngaySinh):
        current = self.head
        prev = None
        while current:
            if current.ngaySinh == ngaySinh:
                if prev:
                    prev.next = current.next
                else:
                    self.head = current.next
            else:
                prev = current
            current = current.next

    def inDanhSach(self):
        current = self.head
        while current:
            print(f"Mã SV: {current.maSV}, Họ tên: {current.hoTen}, ...")
            current = current.next

if __name__ == "__main__":
    ds = DanhSachSV()

    # Nhập một số sinh viên
    for _ in range(3):
        ds.nhapSV()

    # Sắp xếp danh sách
    ds.sapXepTangDan()

    # In danh sách sau khi sắp xếp
    ds.inDanhSach()

    # Tìm sinh viên theo ngày sinh
    ngaySinh = input("Nhập ngày sinh cần tìm: ")
    ds.timSVTheoNgaySinh(ngaySinh)

    # Xóa sinh viên theo ngày sinh
    ds.xoaSVTheoNgaySinh(ngaySinh)

    # In danh sách sau khi xóa
    ds.inDanhSach()