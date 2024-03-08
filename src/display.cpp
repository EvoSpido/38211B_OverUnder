#include "display/lv_core/lv_obj.h"
#include "display/lv_objx/lv_img.h"
#include "main.h"

void display() {
    lv_obj_t* scrCougears;

    LV_IMG_DECLARE(cougears);
    
    scrCougears = lv_obj_create(NULL, NULL);
    lv_obj_t* imgCougears = lv_img_create(scrCougears, NULL);
    lv_img_set_src(imgCougears, &cougears);
    //lv_obj_align(imgCougears, NULL, LV_ALIGN_IN_TOP_LEFT, 0, 0);

    lv_scr_load(scrCougears);
    delay(20);
}