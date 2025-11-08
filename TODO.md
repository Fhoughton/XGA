# TODO
- Enforce C99 and add to README
- Write a tool to convert a PNG sprite into a surface or sprite object
- Also write a tool to somehow convert audio into hardcoded executable data to remove need for filesystem access
- Add filesystem access APIs, with query for if platform provides them so game can detect it and use alternative system such as passwords
- Add a builtin pixel spritefont, I expect https://github.com/gheja/tom-thumb-ttf as it's CC0 and fits the screen space well
- Support screen sizes and optional feature sets as want to expand renderer to support advanced features such as 3d optionally

# PLATFORMS
- Console UI (cross-platform so not curses unless can find windows compatability layer)
- Xbox 360
- Wii (test via dolphin)
- Emacs window
- Web
