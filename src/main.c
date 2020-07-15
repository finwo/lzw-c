#ifdef __cplusplus
extern "C" {
#endif

#include <stdio.h>

#include "argparse.h"

#define LZW_MODE_ENC (1<<0)
#define LZW_MODE_DEC (1<<1)

static const char *const usage[] = {
  "lzw [options]",
  NULL,
};

int main(int argc, const char **argv) {
  int mode = 0;

  // Configure arguments
  struct argparse_option options[] = {
    OPT_HELP(),
    OPT_BIT('e', "encode", &mode, "encode data", NULL, LZW_MODE_ENC),
    OPT_BIT('d', "decode", &mode, "decode data", NULL, LZW_MODE_DEC),
    OPT_END(),
  };

  // Parse arguments
  struct argparse argparse;
  argparse_init(&argparse, options, usage, 0);
  argparse_describe(&argparse, "\nA brief description of what the program does and how it works.", "\nAdditional description of the program after the description of the arguments.");
  argc = argparse_parse(&argparse, argc, argv);

  printf("MODE: %d\n", mode);
  printf("ARGC: %d\n", argc);

  if (argc) {
    int i;
    for (i = 0; i < argc; i++) {
      printf("argv[%d]: %s\n", i, *(argv + i));
    }
  }

  return 0;
}

#ifdef __cplusplus
} // extern "C"
#endif
