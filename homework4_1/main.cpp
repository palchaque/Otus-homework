
#include "editor_model.h"
#include "editor_view.h"
#include "editor_controller.h"

int main() {

    editor_model model;
    editor_view view;
    editor_controller controller(&model, &view);

    controller.createNewImage(1920, 1080, "image1", "/home/user/image");
    controller.importImage("/home/user/image/img1.png");
    controller.removeImage(0);

    return 0;
}
