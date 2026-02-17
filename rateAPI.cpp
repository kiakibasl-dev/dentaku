#include "httplib.h"
#include "json.hpp"
#include <iostream>
#include <string>
#include <algorithm>

using json = nlohmann::json;
using namespace std;

int rateAPI() {
    //UTF-8のロケールを設定
    setlocale(LC_ALL, "ja_JP.UTF-8");

    // HTTPSが使えないため、HTTPで提供されているAPIを利用
    httplib::Client cli("http://www.floatrates.com");
    json j;
    //通信しレスポンスを取得
    if (auto res = cli.Get("/daily/usd.json")) {
        if (res->status == 200) {
            j = json::parse(res->body);
        }else{
            cerr << "サーバーエラーが発生しました。ステータスコード: " << res->status << endl;
            return 1;
        }
    } else {
        //通信エラー
        cerr << "通信失敗。HTTPのまま試してください。" << endl;
        return 1;
    }

    //オープニング
    cout << "2つの通貨の為替レートを計算します。対応通貨を出力しますか？ y/n" << endl;
    char yn; cin >> yn;
    if(yn == 'y'){
        cout << "--- 対応通貨一覧 ---" << endl;
        int count = 0;
        for (auto& item : j.items()) {          //auto&を用いて容量を節約、itemsはjson固有のメソッド
            cout << item.key() << " ";
            if (++count % 10 == 0) cout << endl; // 10個ごとに改行して見やすく
        }
        cout << "\n--------------------" << endl;
    }

    //通貨のペアを入力する
    cout << "基準通貨の通貨コードを入力してください。" << endl;
    string baseCurrency; cin >> baseCurrency;
    cout << "決済通貨の通貨コードを入力してください。" << endl;
    string quoteCurrency; cin >> quoteCurrency;
    cout << "金額を入力してください" << endl;
    float amount; cin >> amount;

    //入力のエラーハンドリング
    transform(baseCurrency.begin(), baseCurrency.end(), baseCurrency.begin(), ::tolower); //ラムダ式で書く方法もある
    transform(quoteCurrency.begin(), quoteCurrency.end(), quoteCurrency.begin(), ::tolower); //ラムダ式で書く方法もある
    if(!j.contains(baseCurrency) || !j.contains(quoteCurrency)){
        cerr << "通貨コードが間違っています。" <<endl;
        return 1;
    };

    // 入力した通貨のレートを取得
    float baseInvRate = j[baseCurrency]["inverseRate"];
    float quoteRate = j[quoteCurrency]["rate"];

    std::cout << "===== 現在の為替レート =====" << std::endl;
    std::cout << amount << baseCurrency << " = " << amount * baseInvRate * quoteRate << quoteCurrency << std::endl;
    std::cout << "============================" << std::endl;

    return 0;
}