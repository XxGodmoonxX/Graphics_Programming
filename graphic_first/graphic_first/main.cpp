//
//  main.cpp
//  graphic_first
//
//  Created by 渡辺　基暉 on 2017/04/13.
//  Copyright (c) 2017年 渡辺　基暉. All rights reserved.
//

#include <iostream>

int main(int argc, const char * argv[]) {
    // insert code here...
    
//    std::cout << "私の名字は渡辺です。\n";
//    std::cout << "私の名前は基暉です。\n";
//    std::cout << "環境情報学部3年生です。\n";
//    for (int i = 0; i < 10; i++) {
//        std::cout << "こんにちは\n";
//    }
    
    //ピラミッド
    
    for (int i = 0; i < 5; i++) {
//        if (i == 0) {
//            std::cout << "hello";
//        }
//        if (i == 1) {
//            for (int j = 0; j < i + 1; j++) {
//                std::cout << "hello";
//            }
//        }
//        if (i == 2) {
//            for (int j = 0; j < i + 1; j++) {
//                std::cout << "hello";
//            }
//        }
//        if (i == 3) {
//            for (int j = 0; j < i + 1; j++) {
//                std::cout << "hello";
//            }
//        }
//        if (i == 4) {
//            for (int j = 0; j < i + 1; j++) {
//                std::cout << "hello";
//            }
//        }
        for (int j = 0; j < i + 1; j++) {
            std::cout << "hello";
        }
        std::cout << "\n";
    }
    
    // SFCを5列を3行

    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 5; j++) {
            std::cout << "SFC ";
        }
        std::cout << "\n";
    }
    
    return 0;
}
