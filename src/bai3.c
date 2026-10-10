#include <stdio.h>

// --- INTERFACE BẮT BUỘC - KHÔNG ĐỔI CHỮ KÝ HÀM ---
int phanPhoiATM(int soTien, int *to500, int *to200, int *to100, int *to50);

#ifndef UNIT_TEST
int main() {
    int soTien;
    int to500 = 0, to200 = 0, to100 = 0, to50 = 0;

    printf("Nhap so tien can rut (Boi so 50.000): ");
    scanf("%d", &soTien);

    if (soTien <= 0 || soTien % 50000 != 0) {
        printf("So tien khong hop le! He thong tu choi giao dich.\n");
        return 0;
    }

    int tongTo = phanPhoiATM(soTien, &to500, &to200, &to100, &to50);

    printf("\n--- KET QUA RUT TIEN ---");
    printf("\nTo 500k: %d", to500);
    printf("\nTo 200k: %d", to200);
    printf("\nTo 100k: %d", to100);
    printf("\nTo  50k: %d", to50);
    printf("\nTong so to tien nhan: %d to\n", tongTo);

    return 0;
}
#endif

// --- SINH VIÊN VIẾT CODE CỦA HÀM DƯỚI ĐÂY ---
int phanPhoiATM(int soTien, int *to500, int *to200, int *to100, int *to50) {

    // Khởi Tạo Số Tờ Của Mỗi Mệnh Giá

    *to500 = 0;

    *to200 = 0;

    *to100 = 0;

    *to50 = 0;

    // Số Tiền Âm Phải Chia Hết Cho 50 Thì Không Thể Phân Phối Chính Xác
    if (soTien < 0 || soTien % 50 !=0 ){
        return 0;
    }
    // Lấy Số Tờ 500, Rồi Giữ Lại Phần Tiền Phân Phối

    *to500 = soTien / 500;
    soTien = soTien % 500;

    //Tiếp Tục Với Mệnh Giá 200

    *to200 = soTien / 200;
    soTien = soTien % 500;

    //Tiếp Tục Với Mệnh Giá 100

    *to100 = soTien / 100;
    soTien = soTien % 100;

    // Với Các Phần Tiền Còn Lại Quy Đổi Thành Tờ 50

    *to50 = soTien / 50;
    soTien = soTien % 50;
    // Cộng Trừ Số Tờ Của Cách Mệnh Giá 

    return *to500 + *to200 + *to100 + *to50;
    // T0ODO: Viết code phân phối số tờ tiền và trả về tổng số tờ
    // Yeu cau: Tuyet doi khong dung lenh in ra man hinh ben trong ham nay
    
    return 0;
}
