
#include "editor_controller.h"

editor_controller::editor_controller(editor_model *model, editor_view *view) : model(model), view(view) {}

editor_image editor_controller::createNewImage(int width, int height, const std::string name, const std::string path)
{
    editor_image newImage(name, path);

    newImage.setWidth(width);
    newImage.setHeight(height);

    model->setImage(&newImage);

    return newImage;

}

editor_image editor_controller::importImage(const std::string path) {

    editor_image *img;

    return *img;
}

void editor_controller::removeImage(int index) {

}

editor_controller::~editor_controller() {


}
