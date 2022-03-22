#include <iostream>
#include <string.h>
#include <cstdlib>
using namespace std;
#define NUMS_SIZE 10

int nums[NUMS_SIZE];

void showMainPage();
void showP1Page();
 void showNums();
 void showInputDataPage();
 void showSearchPage();
void showP2Page();

int main()
{
    showMainPage();
    return 0;
}

void ascend_sort()
{
    for (int i = 0; i < NUMS_SIZE; ++i)
    {
        for (int j = i + 1; j < NUMS_SIZE; ++j)
        {
            if (nums[i] > nums[j])
            {
                int temp = nums[i];
                nums[i] = nums[j];
                nums[j] = temp;
            }
        }
    }
}

void descend_sort()
{
    for (int i = 0; i < NUMS_SIZE; ++i)
    {
        for (int j = i + 1; j < NUMS_SIZE; ++j)
        {
            if (nums[i] < nums[j])
            {
                int temp = nums[i];
                nums[i] = nums[j];
                nums[j] = temp;
            }
        }
    }
}

int search(int n)
{
    for (int i = 0; i < NUMS_SIZE; ++i)
    {
        if (nums[i] == n)
        {
            return i;
        }
    }
    return -1;
}

void drawLine(int lenght)
{
    cout << "\n";
    for (int i = 0; i < lenght; ++i)
    {
        cout << "-";
    }
}

void drawLine()
{
    cout << "\n";
    for (int i = 0; i < 44; ++i)
    {
        cout << "-";
    }
}

void drawRow(const char * phrase)
{
    cout << "\n";
    printf("| %-40s |", phrase);
}

void clrscr()
{
    // //clear screen dan mengembalikan kursor ke awal, tidak bekerja untuk DevC++
    // cout<<"\33[2J";
    // cout<<"\33[0;0H";

    //hanya bekerja untuk compiler tertentu pada windows
    system("cls");
}

void showMainPage()
{
    clrscr();
    drawLine();
    drawRow("Menu Utama");
    drawLine();
    drawRow("1. Program Sorting & Searching");
    drawRow("2. Program Menghitung Nilai");
    drawLine();

    cout<<"\nPilihan Anda: ";
    int inp;
    cin >> inp;

    switch (inp)
    {
    case 1:
        showP1Page();
        break;
    case 2:
        showP2Page();
        break;
    default:
        showMainPage();
    }
}

void showP1Page()
{
    clrscr();
    drawLine();
    drawRow("Program Sorting & Searching");
    drawLine();
    drawRow("1. Input Data");
    drawRow("2. Urutkan dari Terkecil");
    drawRow("3. Urutkan dari Terbesar");
    drawRow("4. Search");
    drawRow("5. Kembali ke Menu Utama");
    drawLine();

    cout<<"\nPilihan Anda: ";
    int inp;
    cin >> inp;

    switch (inp)
    {
    case 1:
        showInputDataPage();
        getchar();
        getchar();
        showP1Page();
        break;
    case 2:
        ascend_sort();
        clrscr();
        drawLine();
        drawRow("Data diurutkan dari terkecil");
        drawLine();
        showNums();
        getchar();
        getchar();
        showP1Page();
        break;
    case 3:
        descend_sort();
        clrscr();
        drawLine();
        drawRow("Data diurutkan dari terbesar");
        drawLine();
        showNums();
        getchar();
        getchar();
        showP1Page();
        break;
    case 4:
        showSearchPage();
        getchar();
        getchar();
        showP1Page();
        break;
    case 5:
        showMainPage();
        break;
    default:
        showP1Page();
    }
}

void showP2Page()
{
    string nama;
    int n_tugas, n_uts, n_uas;

    // meminta input
    clrscr();
    drawLine();
    drawRow("Program Menghitung Nilai");
    drawLine();
    cout << "\nMasukan Nama Anda : ";
    getchar();
    getline(cin,nama);
    cout << "\nMasukan nilai-nilai anda !"
         << "\n\tNilai Tugas : ";
    cin >> n_tugas;
    cout << "\tNilai UTS : ";
    cin >> n_uts;
    cout << "\tNilai UAS : ";
    cin >> n_uas;

    double n_akhir = (3 * n_tugas / 10) + (35 * n_uts / 100) + (35 * n_uas / 100);
    string predicate;

    if (n_akhir >= 93)
    {
        predicate = "A (Sangat Baik)";
    }
    else if (n_akhir >= 84 && n_akhir <= 92)
    {
        predicate = "B (Baik)";
    }
    else if (n_akhir >= 75 && n_akhir <= 83)
    {
        predicate = "C (Cukup)";
    }
    else if (n_akhir < 75)
    {
        predicate = "D (Kurang)";
    }

    // menampilkan output
    drawLine();
    drawRow(string("Nilai dari " + nama).c_str());
    drawLine();
    char n_akhirShowPhrase[100];
    sprintf(n_akhirShowPhrase, "Nilai Akhir = %f", n_akhir);
    drawRow(n_akhirShowPhrase); 
    drawRow(string("Predikat    = " + predicate).c_str());
    drawLine();

    getchar();
    getchar();
    showMainPage();
}

void showNums(){
    cout<<endl;
    for(int i=0; i<NUMS_SIZE; ++i){
        printf("%-5d", nums[i]);
    }
}

void showInputDataPage(){
    clrscr();
    drawLine();
    drawRow("Masukan data");
    drawLine();

    cout<<"\n";
    for(int i=0; i<NUMS_SIZE; ++i){
        cout<<"Data-"<<i+1<<" : ";
        cin>>nums[i];
    }
}

void showSearchPage(){
    clrscr();
    drawLine();
    drawRow("Mencari data");
    drawLine();

    int n;
    cout<<"\nCari : ";
    cin>>n;
    
    int res = search(n);
    if(res != -1){
        cout<<"Data ditemukan pad index ke-"<<res;
    }else{
        cout<<"Data tidak ditemukan";
    }
}