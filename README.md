#Sccbs - Skyline Cyber Cafe Billing System
## - Project
This project is for billing system designed for Skyline Cyber Cafe. This system helps user to manage the billing system as it prints and scans the document, It is developed using C++..
## 🚀 Features Implemented
- **Admin Pricing Update:** Allows the admin to change pricing per hour.
- **User Sessions Management:** Tracks login/logout times to calculate charges.
- **Billing Output:** Automatically generates billing details.
- **Modular User Stories:** Each major feature is implemented as a separate user story:
  - User Story 1: Registering the Users
  - User Story 2: Session tracking
  - User Story 3: Dynamic pricing
  - User Story 4: Output formatting
 
  ###Who has done it:
  -**Shishir005400** and **masrafe321** has done the code. masrafe 321 has done the code "for Admin" and corrected the code if there is any mistakes. Shishir has done the code of User registration, password rules, and printing and scanning with session based billing.
  Both the contributors have divided the 6 user story into half and done 3/3 user stories..

  ## Follow these steps
  1. **User Story 1**
  Implements User registration with:
 - Email Validation using regular expression.
 - strong password validation (min 8 chars, 1 uppercase, 1 digit)
 - stores user details in a list

 2. **User Story 2**
 Refines registration with:
- Enhanced password rule enforcement (requires at least one digit and uppercase letter)
- Email input and basic storage

3. **User Story 3**
Introducing a billing system for printing and scanning:
- Menu to choose scan or print
- Calculates and displays total cost
- Uses "unordered_map" to store and access pricing

4. **User Story 4**
Creates a secure login system:
- Accepts email and password
- Validates admin login
- Displays admin dashboard if credentials are valid

5. **For Admin**
Admin specific features
- Lists all active users
- Allows admin to deactive (inactive) a user by email

6. **Admin Pricing Update**
Features
- View Current scan/print prices
- update prices dynamically by entering a new rates

7. **Final Code**
- "Correct Code.cpp" : Updated and fixed the final output code..
- "Final Output.cpp" : Final complete system with all functionalities integrated.

###How to run it
-To run this project, you need to :
1. A c++ compiler
2. Access to terminal/command prompt

   --Then you can clone it using the command like
   git clone https://github.com/Shishir005400/Sccbs.git
   cd Sccbs


   ......The final code to run and know how the code works is you can click on "Correct code.cpp" that is the final code for this project....
