# C++-based Bottle Recycle Service

C++ console application that implements bottle recycling system

![bottlerecyclemachine](https://github.com/user-attachments/assets/791d1050-fdce-40e8-8bf9-8da7b13345db)

## How It Works

1. When the application starts, it displays a main menu. The user can choose:
   - 1 to start recycling.
   - 0 to exit the application.

2. If the user chooses 1 (Aloita palautus):
   - A new menu appears with different bottle and can options.
   - Each option adds a specific deposit refund amount to the total.
   - The loop continues until the user selects option 6 (Lopeta ja tulosta kuitti).

3. When option 6 is selected, the program:
   - Generates a receipt with a breakdown of bottles/cans and the total refund amount.
   - Returns to the main menu, allowing another session.

4. If the user selects 0 in the main menu, the application exits with a farewell message.

The code can be compiled and ran using a C++ compiler like g++ with the following command:

```
g++ -o bottle_recycle bottlerecyclingmachine.cpp
./bottle_recycle
```

## Inquiries

In case of inquiries, feel free to send message via email to nidalaburaed94@gmail.com

