#include <iostream>
#include <string>

using namespace std;

class SinhVien {   // Định nghĩa lớp SinhVien
public:            // Khởi tạo các thuộc tính của lớp sinh viên
    string maSV;
    string hoTen;
    string gioiTinh;
    string ngaySinh;
    string diaChi;
    string lop;
    string khoa;
    SinhVien* next; // Con trỏ trỏ đến sinh viên tiếp theo
    SinhVien(string ma, string hoTen, string gioiTinh, string ngaySinh, string diaChi, string lop, string khoa)                   //Khởi tạo các thuộc tính của một đối tượng sinh viên mới
        : maSV(ma), hoTen(hoTen), gioiTinh(gioiTinh), ngaySinh(ngaySinh), diaChi(diaChi), lop(lop), khoa(khoa), next(nullptr) {}
};

class DanhSachSV {  // Định nghĩa lớp DanhSachSV
private:
    SinhVien* first; // Con trỏ trỏ đến sinh viên đầu tiên trong danh sách

public:
    DanhSachSV() : first(nullptr) {}   //Cho danh sách ban đầu rỗng

    bool isEmpty() {      // Kiểm tra xem danh sách có rỗng không, first trỏ đến nullptr -> true
        return first == nullptr;
    }

    void nhapSV() {  //Khởi tạo hàm nhập để điền thông tin của sinh viên
        string maSV, hoTen, gioiTinh, ngaySinh, diaChi, lop, khoa;
        cout << "Nhập mã số sinh viên: ";
        getline(cin, maSV);
        cout << "Nhập họ và tên sinh viên: ";
        getline(cin, hoTen);
        cout << "Nhập giới tính: ";
        getline(cin, gioiTinh);
        cout << "Nhập ngày tháng năm sinh: ";
        getline(cin, ngaySinh);
        cout << "Nhập nơi ở hiện tại: ";
        getline(cin, diaChi);
        cout << "Nhập lớp sinh viên: ";
        getline(cin, lop);
        cout << "Nhập ngành học của sinh viên: ";
        getline(cin, khoa);

        SinhVien* newSV = new SinhVien(maSV, hoTen, gioiTinh, ngaySinh, diaChi, lop, khoa);         // Tạo một đối tượng sinh viên mới với thông tin vừa nhập
        newSV->next = first;
        first = newSV;  //thêm sinh viên mới vào đầu danh sách
    }

    void Bubble_Sort() {      //Sắp xếp mssv tăng dần bằng thuật toán nổi bọt
        if (isEmpty()) return;
        SinhVien* current = first;
        while (current) {
            SinhVien* next_node = current->next;
            while (next_node) {
                if (current->maSV > next_node->maSV) {   //nếu mssv của sv hiện tại lớn hơn sv tiếp theo thì hoán đổi các thuộc tính
                    swap(current->maSV, next_node->maSV);
                    swap(current->hoTen, next_node->hoTen);
                    swap(current->gioiTinh, next_node->gioiTinh);
                    swap(current->ngaySinh, next_node->ngaySinh);
                    swap(current->diaChi, next_node->diaChi);
                    swap(current->lop, next_node->lop);
                    swap(current->khoa, next_node->khoa);
                }
                next_node = next_node->next;
            }
            current = current->next;
        }
    }

    void timSV(const string& ngaySinh) {   //tìm sv theo ngày sinh
        SinhVien* current = first;
        bool found = false;
        while (current) {
            if (current->ngaySinh == ngaySinh) {
                cout << "Mã SV: " << current->maSV << ", Họ tên: " << current->hoTen << endl;
                found = true;
            }
            current = current->next;
        }
        if (!found) {
            cout << "Không tìm thấy sinh viên cùng ngày sinh" << endl;
        }
    }

    void xoaSV(const string& ngaySinh) {   //xóa sv theo ngày sinh
        SinhVien* current = first;
        SinhVien* prev = nullptr;
        while (current) {
            if (current->ngaySinh == ngaySinh) {
                if (prev) {
                    prev->next = current->next;
                } else {
                    first = current->next;
                }
                delete current; // Giải phóng bộ nhớ
                current = (prev) ? prev->next : first;
            } else {
                prev = current;
                current = current->next;
            }
        }
    }

    void inDanhSach() {    //in danh sách sinh viên
        SinhVien* current = first;
        while (current) {
            cout << "Mã SV: " << current->maSV << ", Họ tên: " << current->hoTen << ", Giới tính: " << current->gioiTinh
                 << ", Ngày sinh: " << current->ngaySinh << ", Địa chỉ: " << current->diaChi
                 << ", Lớp: " << current->lop << ", Khoa: " << current->khoa << endl;
            current = current->next;
        }
    }

    // Hàm hủy để giải phóng bộ nhớ
    ~DanhSachSV() {
        while (first) {
            SinhVien* temp = first;
            first = first->next;
            delete temp;
        }
    }
};

int main() {
    DanhSachSV ds;
    for (int i = 0; i < 5; ++i) {      // Nhập một số sinh viên
        ds.nhapSV();
    }
    ds.Bubble_Sort();
    cout << "Danh sách sinh viên sau khi sắp xếp:" << endl;
    ds.inDanhSach();
    string ngaySinh;
    cout << "Nhập ngày sinh cần tìm: ";
    getline(cin, ngaySinh);
    ds.timSV(ngaySinh);  //tìm sv theo ngày sinh

    ds.xoaSV(ngaySinh);  //xóa sv theo ngày sinh

    cout << "Danh sách sinh viên sau khi xóa:" << endl;   //in danh sách sau khi xóa
    ds.inDanhSach();
    return 0;
}
