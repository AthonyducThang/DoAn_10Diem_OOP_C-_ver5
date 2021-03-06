
#include <iostream>

#include"DoiBong.h"
#include "San.h"

using namespace std;


int main()
{
    int flag = 1;
    DoiBong* a = new DoiBong();
    a->Nhap();
    San* san = new San();
    int co = 1, co2 = 1, co3 = 0, co4 = 0;
    while (flag == 1)
    {
        cout << "\t\t\t************************MENU************************\t\t\t" << endl;
        cout << "\t\t\t***            1. Quan Ly Cau Thu                ***\t\t\t" << endl;
        cout << "\t\t\t***            2. Xuat danh sach Cau thu         ***\t\t\t" << endl;
        cout << "\t\t\t***            3. Quan Ly Nhan Vien              ***\t\t\t" << endl;
        cout << "\t\t\t***            4. Xuat danh sach Nhan vien       ***\t\t\t" << endl;
        cout << "\t\t\t***            5. Quan Ly San                    ***\t\t\t" << endl;
        cout << "\t\t\t***            6. Hoat Dong                      ***\t\t\t" << endl;
        cout << "\t\t\t***            7. Thoat                          ***\t\t\t" << endl;
        cout << "\t\t\t****************************************************\t\t\t" << endl;
        cout << "Moi nhap lua chon cua ba => Your choice: ";
        int choice; cin >> choice;
        switch (choice)
        {
        case 1:
        {
            a->MenuQLCT();
            co3 = 1;
            break;
        }
        case 2:
        {
            int i = 0;
            if (a->getQuanLyCauThu()->getvectorCauThu()->size() != 0)
            {
                for (auto item : *a->getQuanLyCauThu()->getvectorCauThu())
                {
                    cout << "STT: " << i++ << " Ho ten: " << item->sHoTen << " Chuc vu: " << item->sNghe << endl;
                }
            }
            else
            {
                cout << "chua nhap thong tin cau thu nao !!" << endl;
            }
            break;
        }
        case 3:
        {
            a->MenuQLNV();
            co4 = 1;
            break;
        }
        case 4:
        {
            int i = 0;
            if (a->getQuanLyNhanVien()->getlCaNhan()->size() != 0)
            {
                for (auto item : *a->getQuanLyNhanVien()->getlCaNhan())
                {
                    cout << "STT: " << i++ << " Ho ten: " << item->sHoTen << " Chuc vu: " << item->sNghe << endl;
                }
            }
            else
            {
                cout << "chua nhap thong tin nhan vien nao !!" << endl;
            }
            break;
        }
        case 5:
        {
            if (co == 1)
            {
                cout << "Doi Bong co san co khong? 1_Co || 2_Khong : ";
                int temp; cin >> temp;
                if (temp == 1)
                {
                    san->Nhap();
                    cout << "//////////////////////////////////////////////////////////////////////" << endl;
                    san->Xuat();
                }
                else
                {
                    co2 = 0;
                    san = nullptr;
                    cout << "Doi bong khong co San!! " << endl;
                }
                co = 0;
            }
            else
            {
                if (co2 == 1)
                    san->Xuat();
                else
                    cout << "Doi bong khong co San!! " << endl;
            }
            co3 = 1;
            break;
        }
        case 6:
        {
            if (co3 == 1)
                a->MenuHoatDong(san);
            else
            {
                cout << "ung dung nay su dung thong tin san vui long nhap thong tin san" << endl;
            }
            break;
        }
        case 7:
        {
            //a->~DoiBong();
            flag = 0;
            break;
        }
        default:
        {
            cout << "Nhap sai, moi nhap lai!!  " << endl;
            break;
        }
        }
    }
}
