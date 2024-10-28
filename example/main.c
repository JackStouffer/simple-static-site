#include <stdio.h>

#include "../simple-static-site.h"

#define STATIC_SITE_IMPLEMENTATION

int main()
{
    StaticSiteInstance* instance = static_site_instance();
    static_site_add_template(instance, "templates/base.html", "base");
    static_site_add_template(instance, "templates/post.html", "post");

    {
        char* html = static_site_render_file(instance, "content/home.md");
        FILE* file = fopen("build/home.html", "w");
        fwrite(html, sizeof(char), strlen(html), file);
        fclose(file);
    }

    {
        char* html = static_site_render_file(instance, "content/about.md");
        FILE* file = fopen("build/about.html", "w");
        fwrite(html, sizeof(char), strlen(html), file);
        fclose(file);
    }

    {
        char* html = static_site_render_file(instance, "content/post_one.md");
        FILE* file = fopen("build/post_one.html", "w");
        fwrite(html, sizeof(char), strlen(html), file);
        fclose(file);
    }
}
