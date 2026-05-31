// Copyright 2021 NNTU-CS
#include "train.h"

Train::Train() {
    countOp = 0;
    first = nullptr;
}

void Train::addCar(bool light) {
    Car* newCar = new Car;
    newCar->light = light;

    if (first == nullptr) {
        first = newCar;
        first->next = first;
        first->prev = first;
    } else {
        Car* last = first->prev;

        last->next = newCar;
        newCar->prev = last;

        newCar->next = first;
        first->prev = newCar;
    }
}

int Train::getLength() {
    if (first == nullptr) return 0;

    first->light = true;
    Car* current = first;
    int distance = 0;

    while (true) {
        current = current->next;
        distance++;
        countOp++;

        if (current->light == true) {
            current->light = false;

            for (int i = 0; i < distance; i++) {
                current = current->prev;
                countOp++;
            }

            if (current->light == false) {
                return distance;
            }

            for (int i = 0; i < distance; i++) {
                current = current->next;
                countOp++;
            }
        }
    }
}

int Train::getOpCount() {
    return countOp;
}
