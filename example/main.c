#include <stdio.h>
#include <stdint.h>

#define STATIC_SITE_IMPLEMENTATION
#include "../simple-static-site.h"

int main()
{
    StaticSiteInstance* instance = sss_instance();
    sss_add_template(instance, "templates/base.html", 20, "base");
    sss_add_template(instance, "templates/post.html", 20, "post");

    {
        size_t mark_down_size = 0;
        char* mark_down_data = sss_read_file("content/home.md", &mark_down_size);

        char* html = sss_render_file(instance, mark_down_data, mark_down_size);
        printf("HTML %s\n", html);
        sss_write_to_file("build/home.html", html);
    }
}
