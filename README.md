**Not ready yet**

# Simple Static Site Generator

A simple, cross platform, code driven, static site generator for markdown based content.

Most of this code wasn't written by me, it's mostly base off of MD4C: http://github.com/mity/md4c

## Project Goals

I need something that is

* Stable. 
    * I can't STAND coming back to a project and having to redo all of the node dependencies anymore. I just need it TO WORK. This is just a project that WRITES HTML FILES.
* Takes Markdown and generates static HTML from given HTML templates
* No comlicated domain specific language. The site's structure should be driven from real code
* Cross platform
* UTF-8
* Easy to use across projects
   * No make, cmake, et. al.

A single-header-file, C99 compliant library is by far the easiest thing to make fit these requirements.

### Caveats

As this is meant to be a batch tool, this library just `malloc`s every time it needs a string and never calls `free`. If for some reason you're generating a site of many gigabytes than this will be an issue for you

## Include

```c
#include "simple-static-site.h"
```

In one, and only one, file do

```c
#define STATIC_SITE_IMPLEMENTATION
#include "simple-static-site.h"
```

## Usage

`main.c`

```c
#define STATIC_SITE_IMPLEMENTATION
#include "../simple-static-site.h"


int main()
{
    char* title = "Home";
    char* base_template = sss_read_file("templates/base.html", NULL);
    char* markdown_data = sss_read_file("content/home.md", NULL);

    char* html = sss_render_file(
        base_template,
        title,
        markdown_data
    );
    sss_write_to_file("build/home.html", html);
}
```

`base.html`

```html
<!doctype html>
<html>
    <head>
        <title>{{ title }}</title>
    </head>
    <body>
        {{ markdown }}
    </body>
</html>
```

`base.md`

```markdown
# This Is A Body Header

This is body content
```

There's a larger example in the `example` folder.

