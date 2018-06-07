Problem: Given two numbers i and j, print the tokens on the columns that between the ith column and jth column (inclusive)

Input: Two command line arguments, integers i and j, with i >= 1, and j >= i
       Whitespace seperated tokens are fed to stdin, the last token in a line has a semicolon at the end

Output: Print to stdout, tokens seperated by exactly one space (no trailing whitespace after the last token excluding newline) that are the tokens within the specified column numbers i and j
		After processing the last token in a line, print a newline (i.e. there should be same amount of lines in the input and the output)	
        If a line does not have any tokens within i and j, then no token is printed (though following the above rule, a newline should still be printed)

See tests folder of sample input, test5 has sample output as well
