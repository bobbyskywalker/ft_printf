# **42 ft_printf**  
A simplistic version of a standard C function *printf*, built as part of the 42 curriculum at 42 Warsaw.

---

## **📖 About the project**  
The ***ft_printf*** project involves creating a simplified version of the standard C printf function. This project is designed to deepen understanding of variadic functions. 

---

## ✅ **Features**
The ***ft_printf*** function does not fully replicate the entire functionality of the standard ***printf***.
Supported conversions using format specifiers:
| **Format Specifier** | **Description**                              |
|---------------------|----------------------------------------------|
| `%d`                 | Prints a signed decimal integer             |
| `%i`                 | Prints a signed integer (same as `%d`)      |
| `%x`                 | Prints an unsigned hexadecimal (lowercase)  |
| `%X`                 | Prints an unsigned hexadecimal (uppercase)  |
| `%p`                 | Prints a pointer address in hexadecimal     |
| `%u`                 | Prints an unsigned decimal integer          |
| `%c`                 | Prints a single character                   |
| `%s`                 | Prints a string of characters               |
| `%%`                 | Prints a literal percent sign `%`           |




## **⚙️ Compilation**

To compile the "libftprintf.a" library, run the following commands in your terminal:

```bash
# Clone the repository:
git clone https://github.com/bobbyskywalker/ft_printf.git
cd ft_printf

# Compile the library:
make 
```

---

## **🛠 Usage**
1. Include the header file in your project:
   ```c
    #include "ft_printf.h"
    ```
2. Compile your code and link with 'libftprintf.a' library
    ```bash
    gcc -Wall -Wextra -Werror your_program.c path_to_libftprintf.a/libftprintf.a -o your_program
    ```
---
## 💬 Notes

👀**Feel free to submit a pull request if you want to contribute to this project!**  
📢 **If you're a 42 student, use this as a guide at most. Don't cheat, learn! <3**  
### 📅 Created in December 2024 as part of 42's Common Core at 42 Warsaw

