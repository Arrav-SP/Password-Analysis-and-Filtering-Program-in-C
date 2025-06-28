## Password Analysis and Filtering Program

### Overview

This C program analyzes and processes user-entered passwords based on specific criteria. It performs the following tasks:

- Validates password length (must be between 16 and 20 characters, no spaces).
- Counts vowels and consonants in the password.
- Identifies the most frequent vowel.
- Removes vowels from the password and sorts the remaining characters.
- Displays the results and tracks the number of processed passwords.

### Features

- **Password Validation:** Ensures the password is 16–20 characters long.
- **Vowel and Consonant Analysis:** Counts each vowel and consonant in the password.
- **Most Frequent Vowel:** Determines which vowel appears most frequently.
- **Filtering and Sorting:** Removes vowels and sorts the remaining characters in ascending order.
- **Processing Count:** Displays the total number of passwords processed in the session.

### How to Use

1. **Compile the Program:**
   ```bash
   gcc password_analysis.c -o password_analysis
   ```

2. **Run the Program:**
   ```bash
   ./password_analysis
   ```

3. **Follow the Prompt:**
   - Enter a password when prompted.
   - The password must be 16–20 characters long and should not contain spaces.

4. **View Results:**
   - The program will display the total number of vowels and consonants.
   - It will show the most frequent vowel.
   - It will print the password with vowels removed and the remaining characters sorted.
   - It will display the total number of passwords processed.

### Example Output

```
Enter a password (16-20 characters, no spaces): mysecurepassword123
Total vowels: 6, total consonants: 10
Most Frequent Vowel: o
Filtered password (no vowels): 123cdmprrssw
Total passwords processed: 1
```

### Notes

- The program does not currently check for spaces in the password input. Ensure you do not enter spaces.
- If the password length is invalid, the program will display an error and terminate.
- The vowel count persists across multiple password entries due to the use of a static array.

### Files

- `password_analysis.c` — Main source code file.

### Author

Handwritten and digitized by Arav Singh Patel
