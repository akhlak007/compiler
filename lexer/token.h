#ifndef __TOKEN_H__
#define __TOKEN_H__

// The lexer returns tokens [0-255] if it's an unknown / single-character ASCII token
// otherwise it returns one of these negative enumeration values for known tokens/keywords
enum Token {
  // End Of File
  tok_eof = -1,

  // Commands / Function Definitions
  tok_def = -2,
  tok_extern = -3,

  // Primary Entities
  tok_identifier = -4,
  tok_number = -5,

  // Control Flow (Conditionals & Loops)
  tok_if = -6,
  tok_then = -7,
  tok_else = -8,
  tok_for = -9,
  tok_in = -10,

  // User-Defined Operators
  tok_binary = -11,
  tok_unary = -12,

  // Mutable Local Variables
  tok_var = -13
};

#endif
