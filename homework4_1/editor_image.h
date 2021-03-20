
#ifndef OTUS_HOMEWORK4_EDITOR_IMAGE_H
#define OTUS_HOMEWORK4_EDITOR_IMAGE_H

#include <iostream>

class editor_image {

    int width;
public:
    editor_image(const std::string &name, const std::string &path);

    int getWidth() const;

    void setWidth(int width);

    int getHeight() const;

    void setHeight(int height);

    const std::string &getName() const;

    void setName(const std::string &name);

private:
    int height;
    std::string name;
    std::string path;


};


#endif //OTUS_HOMEWORK4_EDITOR_IMAGE_H
