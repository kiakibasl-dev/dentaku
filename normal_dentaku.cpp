#include <iostream>
using namespace std;

//四則演算を行うクラス
class Calculator{
    public : 
        double Calc(double x, char op, double y);
};
//四則演算を行うクラスのメンバ関数
double Calculator::Calc(double x, char op, double y){
    switch(op){
        case '+': return x + y;
        case '-': return x - y;
        case '*': return x * y;
        case '/': 
            if (y == 0){
                //cout << "ゼロ除算です。計算前の数値を保存しています。" << endl;
                return x;
            }
            else return x / y;
        default: 
            cout << "不適切な演算子です。計算前の数値を保存しています。" << endl;
            return x;
    }
}

int main(){
    //UTF-8のロケールを設定
    setlocale(LC_ALL, "ja_JP.UTF-8");
    //プログラム起動時のメッセージ
    cout << "標準の電卓です。" << endl;

    double num1 = 0, num2 = 0;
    char op = '+';    
    Calculator c;

    //左オペランドの入力
    do{
        cout << "左オペランド(数値)を入力してください" << endl;
        cin >> num1;
        //エラー処理
        if(cin.fail()){
            cout << "入力が数値ではありません。" << endl;
            cin.clear(); cin.ignore();
        }else break;
    }while(1);
    
    //ループ処理
    do{
        //演算子の入力
        do{
            cout << "演算子を入力してください（終了するには'q'）" << endl;
            cin >> op;
            //プログラム終了処理
            if(op == 'q'){
                cout << "電卓アプリを終了します。" << endl;
                return 0;
            }
            //エラー処理
            if(op != '+' && op != '-' && op != '*' && op != '/'){
                cout << "演算子が不適切です。" << endl;
                cin.clear(); cin.ignore();
            }
            else break;
        }while(1);
        //右オペランドの入力
        do{
            cout << "右オペランド(数値)を入力してください" << endl;
            cin >> num2;
            //エラー処理
            if(cin.fail()){
                cout << "入力が数値ではありません。" << endl;
                cin.clear(); cin.ignore();
            }else break;
        }while(1);

        //計算
        if(op == '/' && num2 == 0){
            cout << "ゼロ除算です。計算前の数値を保存しています。" << endl;
            cout << "現在の数値は：" << num1 << endl;
        }else{
            cout << num1 << " " << op << " " << num2 << " = ";
            num1 = c.Calc(num1, op, num2);
            cout << num1 << endl;
        }
    }while(1);
}