// Copyright 2022 NNTU-CS
#include <iostream>
#include <fstream>
#include <cstdlib>
#include <ctime>
#include "train.h"

int main() {
    srand(time(NULL)); 
    
    std::ofstream file("result/data.csv");
    
    file << "Length,AllOff,AllOn,Random\n";

    for (int n = 10; n <= 500; n += 10) {
        file << n << ",";

        Train t1;
        for (int i = 0; i < n; i++) t1.addCar(false);
        t1.getLength();
        file << t1.getOpCount() << ",";

        Train t2;
        for (int i = 0; i < n; i++) t2.addCar(true);
        t2.getLength();
        file << t2.getOpCount() << ",";

        Train t3;
        for (int i = 0; i < n; i++) {
            bool randomLight = rand() % 2; 
            t3.addCar(randomLight);
        }
        t3.getLength();
        file << t3.getOpCount() << "\n";
    }
    
    file.close();
    std::cout << "Данные собраны и записаны в result/data.csv" << std::endl;
    
    return 0;
}
