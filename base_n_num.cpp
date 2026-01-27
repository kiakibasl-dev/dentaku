#include <iostream>
#include <string>
#include <algorithm>
#include <limits>
using namespace std;

//ｎ進数変換する関数
string fnc(int dec, int base){
    if(dec == 0) return "0";

    string baseNnum;
    while(dec > 0){ 
        //余りを計算
        int rem = dec % base;
        char s;
        if(base > 10 && rem > 9) s = 'a' + (rem - 10);
        else s = '0' + rem;
        //10進数をbaseで割る
        dec /= base;

        baseNnum += s;
    }
    reverse(baseNnum.begin(), baseNnum.end());
    return baseNnum;
}

int main(){
    //UTF-8のロケールを設定
    setlocale(LC_ALL, "ja_JP.UTF-8");
    //プログラム起動時のメッセージ
    cout << "10進数を2以上16以下のｎ進数に変換します。" << endl;

    while(1){
        cout << "10進数の正の整数を入力してください。終了するときは数字以外の文字を入力をしてください" << endl;
        int decimal; cin >> decimal;
        if(cin.fail()){
            cout << "数字以外の文字が入力されました。" << endl;
            break;
        }

        cout <<"2以上16以下の整数を入力してください。終了するときは数字以外の文字を入力をしてください" << endl;
        int base; cin >> base;
        if(cin.fail()){
            cout << "数字以外の文字が入力されました。" << endl;
            break;
        }else if(base < 2 || 16 < base){
            cout << "2未満または16より大きい数が入力されました。" << endl;
            break;
        }

        cout << decimal << "を" << base << "進数に直した値は:" << fnc(decimal, base) << endl;
    }

    cout << "ｎ進数変換を終了します。" << endl;
}