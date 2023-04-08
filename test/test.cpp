#include <ios>
#include <zip.h>
#include <iostream>
#include <memory>
#include <vector>

int main() {
    const char* zipfile = "/home/strike/workspace/mini-jvm/testzip.zip";
    struct zip* za = zip_open(zipfile, ZIP_RDONLY, nullptr);
    if (!za) {
        std::cerr << "Error opening zip file " << zipfile << std::endl;
        return 1;
    }

    int num_files = zip_get_num_entries(za, ZIP_FL_UNCHANGED);
    for (int i = 0; i < num_files; ++i) {
        struct zip_file* zf = zip_fopen_index(za, i, 0);
        if (!zf) {
            std::cerr << "Error opening file #" << i << " in zip file" << std::endl;
            continue;
        }
        std::cout << "Reading file #" << i << " in zip file: " << zip_get_name(za, i, 0) << std::endl;

        char buf[1024];
        zip_int64_t count = 0;
        while ((count = zip_fread(zf, buf, sizeof(buf))) > 0) {
            // do something with the file data
        }

        zip_fclose(zf);
    }

    zip_close(za);

    std::shared_ptr<int[]> arr = std::make_shared<int[]>(100);
    std::cout << "Size of array: " << std::extent<decltype(arr)>::value << std::endl;

    std::vector<std::string> vec(5);
    vec.push_back("hello");
    std::cout << vec.size() << vec.at(0);
    return 0;
}
