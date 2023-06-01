#include "Animation.h"

void Animation::advance() {
    counter = (counter + 1) % length;
    setPixmap(*sprites[counter]);
}

void Animation::setSprites(std::string path, int len) {
    for (int i = 0; i < len; i++) {
        sprites.push_back(new QPixmap(QString::fromStdString(path + std::to_string(i) + ".png")));
    }
    length = len;
}

Animation::~Animation() {
    for (auto& thing : sprites) {
        delete thing;
    }
}
