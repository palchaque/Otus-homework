
#include "editor_controller.h"

editor_controller::editor_controller(editor_model *model, editor_view *view) : model(model), view(view) {}

editor_image editor_controller::createNewImage(int width, int height, std::string name, std::filesystem::path path)
{
    editor_image newImage(name, path);

    newImage.setWidth(width);
    newImage.setHeight(height);

    model->setImage(&newImage);

    return newImage;

}



editor_controller::~editor_controller() {


}
