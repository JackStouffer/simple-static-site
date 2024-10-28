#include <stdio.h>
#include <stdint.h>

#define STATIC_SITE_IMPLEMENTATION
#include "../simple-static-site.h"

uint8_t* read_file(const char* filename, size_t* out_size)
{
    FILE* file = fopen(filename, "rb");
    if (!file)
    {
        perror("Failed to open file");
        return NULL;
    }

    if (fseek(file, 0, SEEK_END) != 0)
    {
        fclose(file);
        return NULL;
    }

    long file_size = ftell(file);
    if (file_size < 0)
    {
        fclose(file);
        return NULL;
    }
    rewind(file);

    uint8_t* buffer = malloc(file_size + 1);
    size_t bytes_read = fread(buffer, 1, file_size, file);
    if (bytes_read != file_size)
    {
        fclose(file);
        return NULL;
    }

    buffer[file_size] = '\0';
    fclose(file);

    if (out_size != NULL)
    {
        *out_size = file_size;
    }

    return buffer;
}

int write_buffer_to_file(const char *filename, uint8_t* buffer, size_t length)
{
    // Open the file for writing in binary mode
    FILE *file = fopen(filename, "wb");
    if (!file) {
        perror("Failed to open file");
        return -1;
    }

    // Write the buffer to the file
    size_t written = fwrite(buffer, 1, length, file);
    if (written != length) {
        perror("Failed to write the entire buffer to the file");
        fclose(file);
        return -1;
    }

    // Close the file
    if (fclose(file) != 0) {
        perror("Failed to close the file");
        return -1;
    }

    return 0; // Success
}

int main()
{
    StaticSiteInstance* instance = static_site_instance();
    static_site_add_template(instance, (uint8_t*) "templates/base.html", 20, "base");
    static_site_add_template(instance, (uint8_t*) "templates/post.html", 20, "post");

    {
        size_t mark_down_size = 0;
        uint8_t* mark_down_data = read_file("content/home.md", &mark_down_size);

        uint8_t* html = static_site_render_file(instance, mark_down_data, mark_down_size);

        if (html != NULL)
            write_buffer_to_file("build/home.html", html, 0);
    }
}
