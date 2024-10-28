Not ready yet

# Simple Static Site Generator

A simple, cross platform, static site generator for markdown based content.

I need something that is

* Stable. 
    * I can't STAND coming back to a project and having to redo all of the node dependencies. I just need it TO WORK. This is just a project that MAKES HTML.
* Takes Markdown and generates static HTML from given HTML templates
* Cross platform
* UTF-8 first
* Easy to use across projects

### Caveats

This library just `malloc`s every time it needs a string. If for some reason you're generating a site of many gigabytes than this will be an issue for you

## Include

```c
#include "simple-static-site.h"
```

In one, and only one file do

```c
#define STATIC_SITE_IMPLEMENTATION
#include "simple-static-site.h"
```

## Usage



