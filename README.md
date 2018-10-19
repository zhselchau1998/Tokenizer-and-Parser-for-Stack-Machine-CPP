prog2_1.hpp: Sets up the skeleton for a tokenizer.
prog2_1.cpp: Implements prog2_1.hpp and checks if the tokens are valid tokens.Throws an error if a token is not valid. Also stores tokens and returns them as a vector with the function GetTokens();

prog2_2.cpp: Reads a text file and tokenizes it with prog2_1.cpp. If a token is invalid it catches an error.

prog2_3.hpp: Sets up the skeleton for a parser.
prog2_3.cpp: Implements prog2_3.hpp. This checks a string vector for correct syntax.

prog2_4.cpp: Reads a text file, tokenizes with prog2_1.cpp, then parses with prog2_3.cpp. If a token is invalid it catches an error and if there is incorrect syntax it prints an error message.