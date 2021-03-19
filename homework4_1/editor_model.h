#ifndef OTUS_HOMEWORK4_EDITOR_MODEL_H
#define OTUS_HOMEWORK4_EDITOR_MODEL_H

#include "editor_image.h"
#include <list>

class editor_model {

    std::list<editor_image> images;

public:
    editor_image getImage(int index);
    void setImage(editor_image *image);


};


#endif //OTUS_HOMEWORK4_EDITOR_MODEL_H
