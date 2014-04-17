void kmain(void) {
  typedef enum {
    Black = 0,
    Blue = 1,
    Green = 2,
    Cyan = 3,
    Red = 4,
    Magenta = 5,
    Brown = 6,
    LightGrey = 7,
    DarkGrey = 8,
    LightBlue = 9,
    LightGreen = 10,
    LightCyan = 11,
    LightRed = 12,
    LightMagenta = 13,
    LightBrown = 14,
    White = 15
  } ConsoleColor;
  char *message = "my first kernel", *protected_video_memory = (char *)0xb8000;
  ConsoleColor text_color = Blue;
  unsigned int i, j;
  for (j = 0; j < 80 * 25 * 2; j += 2)
    protected_video_memory[j] = ' ', protected_video_memory[j + 1] = text_color;
  for (i = j = 0; message[j] != '\0'; i += 2, j++)
    protected_video_memory[i] = message[j],
    protected_video_memory[i + 1] = text_color;
}
