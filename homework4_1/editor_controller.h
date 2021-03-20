#ifndef OTUS_HOMEWORK4_EDITOR_CONTROLLER_H
#define OTUS_HOMEWORK4_EDITOR_CONTROLLER_H

#include "editor_model.h"
#include "editor_view.h"

#include "editor_image.h"

#include <string>

class editor_controller {

    editor_model * model;
    editor_view *view;

public:
    editor_controller(editor_model *model, editor_view *view);
    editor_image createNewImage(int width, int height, std::string name, const std::string path);
    editor_image importImage(const std::string path);
    void exportImage(const std::string path, editor_image);
    void removeImage(editor_image *image);
    void removeImage(int index);

    virtual ~editor_controller();

};


#endif //OTUS_HOMEWORK4_EDITOR_CONTROLLER_H
