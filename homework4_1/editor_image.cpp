//
// Created by palch on 01.03.2021.
//

#include "editor_image.h"

int editor_image::getWidth() const {
    return width;
}

void editor_image::setWidth(int width) {
    editor_image::width = width;
}

int editor_image::getHeight() const {
    return height;
}

void editor_image::setHeight(int height) {
    editor_image::height = height;
}

const std::string &editor_image::getName() const {
    return name;
}

void editor_image::setName(const std::string &name) {
    editor_image::name = name;
}

editor_image::editor_image(const std::string &name, const std::string &path) : name(name), path(path) {}
