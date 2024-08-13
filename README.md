# Library-Management-App

This Library Management Program is developed using C++ and the Qt framework. It provides a user-friendly GUI for managing library operations, including book management, user authentication, and more.
Features

    User Authentication: Secure login for both users and admins.
    Book Management: Add, search, filter, and remove books.
    User Roles: Different functionalities for users and admins.
    Persistent Storage: Data is saved between sessions using txt files. (Should be improve in future)

<br />
![LibraryManagementApp_Fx63SBNYos](https://github.com/user-attachments/assets/e217de12-ad57-4d0d-b35f-971834ac7878)
<br />The login screen allows users to log in as either a user or an admin. It includes fields for entering login credentials and options to create a new account if one does not exist.

<br />
![LibraryManagementApp_RK2X0PMqWs](https://github.com/user-attachments/assets/40f5c9d6-6b2f-4d70-b8e8-7277dbd8da13)
<br />The admin page allows administrators to manage the library’s book inventory. On the left side, there is a form to add new books to the library, including fields for the book title, author’s name, ISBN, and quantity. Administrators can add books to the library or view all books with the respective buttons. On the right side, there is a list of saved books, displaying the title, author, and availability of each book. Additional options include viewing the activity list and clearing data.

<br />
![LibraryManagementApp_aNW0bQLnaZ](https://github.com/user-attachments/assets/e37bf9e9-673f-4943-8441-125bbb1fcdaa)
<br />The activity log lists all actions performed by the admin, including logging in, adding books, and updating book quantities. Each entry includes a timestamp for tracking purposes.

<br />
![LibraryManagementApp_FVFpxcEzvI](https://github.com/user-attachments/assets/d86298c3-efc4-4410-9ed4-7fe9e75de71e)
<br />User Page The user page allows users to view available books and manage their borrowed books. The “Available books” section includes a search bar and buttons to find specific books or show all available books. Below the search bar, a list of available books is displayed with their titles, authors, and availability. The “Your books” section shows the books currently borrowed by the user, along with their availability.
<br />
![LibraryManagementApp_VqJhcX5FwM](https://github.com/user-attachments/assets/b881e217-0880-4b83-8cdb-d11f324eb1fa)
<br />You can also check the main attributes of the books, such as title, ISBN etc.

