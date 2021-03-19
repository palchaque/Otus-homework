
#ifndef OTUS_HOMEWORK4_EDITOR_VIEW_H
#define OTUS_HOMEWORK4_EDITOR_VIEW_H

#include "editor_image.h"

class editor_view {
    std::shared_ptr<editor_image> image;

public:
    void showImage(editor_image *img);
    void draw(int x, int y);
    void draw(int r);
    void erase(int x, int y);

};


#endif //OTUS_HOMEWORK4_EDITOR_VIEW_H
