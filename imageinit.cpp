#include <iostream>
#include <openslide/openslide.h>

using namespace std;

int main() {
    const char* filename = "file1.svs";

    openslide_t* slide = openslide_open(filename);
    if (!slide) {
        cerr << "Error opening slide: " << openslide_get_error(slide) << endl;
        return 1;
    }

    int64_t width, height;
    openslide_get_level_dimensions(slide, 0, &width, &height);
    cout << "Level 0 Dimensions: " << width << " x " << height << endl;

    openslide_get_level_dimensions(slide, 1, &width, &height);
    cout << "Level 0 Dimensions: " << width << " x " << height << endl;

    openslide_get_level_dimensions(slide, 2, &width, &height);
    cout << "Level 0 Dimensions: " << width << " x " << height << endl;

    openslide_get_level_dimensions(slide, 3, &width, &height);
    cout << "Level 0 Dimensions: " << width << " x " << height << endl;

    int32_t num_levels = openslide_get_level_count(slide);
    cout << "Number of levels: " << num_levels << endl;

    openslide_close(slide);
    return 0;
}
