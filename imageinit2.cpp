#include <iostream>
#include <vector>
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

    int32_t target_level = 0; 
    int64_t x_start = 0;
    int64_t y_start = 0;
    int64_t tile_w = 512;
    int64_t tile_h = 512;

    vector<uint32_t> pixel_buffer(tile_w * tile_h);

    openslide_read_region(slide, pixel_buffer.data(), x_start, y_start, target_level, tile_w, tile_h);

    const char* error_msg = openslide_get_error(slide);
    if (error_msg != nullptr) 
    {
        cerr << "Error reading region: " << error_msg << endl;
    }
    else 
    {
        cout << "Successfully read region!" << endl;
    }
    openslide_close(slide);
    return 0;
}


// g++ imageinit2.cpp -IC:/openslide-bin-4.0.1.2-windows-x64/openslide-bin-4.0.1.2-windows-x64/include -LC:/openslide-bin-4.0.1.2-windows-x64/openslide-bin-4.0.1.2-windows-x64/lib -lopenslide -o test.exe
