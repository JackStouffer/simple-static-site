#include <stdio.h>
#include <stdint.h>

#define STATIC_SITE_IMPLEMENTATION
#include "../simple-static-site.h"

int main()
{
    char* base_template = sss_read_file("templates/base.html", NULL);
    char* post_template = sss_read_file("templates/post.html", NULL);

    {
        char* title = "Home";
        char* mark_down_data = sss_read_file("content/home.md", NULL);

        char* html = sss_render_file(
            base_template,
            title,
            mark_down_data
        );
        sss_write_to_file("build/home.html", html);
    }

    // Loop through all of the posts and render their HTML
    {
        unsigned number_of_posts = 0;
        const char** posts = sss_get_files_in_folder("content/posts", &number_of_posts);

        char content_path_buffer[256];
        char build_path_buffer[256];

        for (size_t i = 0; i < number_of_posts; ++i)
        {
            snprintf(content_path_buffer, sizeof(content_path_buffer), "content/posts/%s", posts[i]);
            snprintf(build_path_buffer, sizeof(build_path_buffer), "build/posts/%s.html", posts[i]);

            char* mark_down_data = sss_read_file(content_path_buffer, NULL);
            char* html = sss_render_file(
                post_template,
                posts[i],
                mark_down_data
            );
            sss_write_to_file(build_path_buffer, html);
        }
    }
}
