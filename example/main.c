#include <stdio.h>
#include <stdint.h>

#define STATIC_SITE_IMPLEMENTATION
#include "../simple-static-site.h"

int main()
{
    char* base_template = sss_read_file("templates/base.html", NULL);

    // size_t post_template_length = 0;
    // char* post_template = sss_read_file("templates/post.html", &post_template_length);

    {
        char* title = "Home";
        char* mark_down_data = sss_read_file("content/home.md", NULL);

        char* html = sss_render_file(
            base_template,
            title,
            mark_down_data
        );
        printf("HTML %s\n", html);
        sss_write_to_file("build/home.html", html);
    }
}
