

**Negoescu Iulian Andrei – 321-AB**
**Operating System:** macOS
**IDE:** Visual Studio Code

---

### **– Class: `Produs` (Product)**

The `Produs` class is used to represent a product in stock. Each product has a unique ID, a name, a price, and a quantity.

**Data Members:**

* `static int nextId`: A static counter used to generate unique product IDs.
* `const int id`: The unique ID of the product, constant after initialization.
* `char denumire[50]`: A character array for the product name, limited to 50 characters.
* `float pret`: The price of the product.
* `int cantitate`: The available quantity in stock.

**Constructors:**

* `Produs()`: Default constructor that initializes a product with default values. The ID is generated using `nextId`.
* `Produs(const int id, const char denumire[50], const float pret, const int cantitate)`: Parameterized constructor that sets all product details.

**Methods:**

* `scadeCantitate(int cantitateScazuta)`: Decreases the stock by a certain quantity, without allowing it to go negative.
* `getId()`, `getDenumire()`, `getPret()`, `getCantitate()`: Getter methods for product information.

**Overloaded Operators:**

* `operator<<`: For printing a product to the output stream.
* `operator>>`: For reading product details from the input stream.

---

### **– Class: `Comanda` (Order)**

The `Comanda` class represents an order placed by a client and includes a list of products and the date of the order.

**Data Members:**

* `int id`: The order ID.
* `int zi, luna, an`: The day, month, and year the order was placed.
* `int nrProduse`: Number of products in the order.
* `Produs* produse`: Dynamic array of products in the order.

**Constructors:**

* `Comanda()`: Default constructor initializing with default values.
* `Comanda(...)`: Parameterized constructor that sets all order details and copies the products into a dynamic array.

**Destructor:**

* `~Comanda()`: Frees the memory allocated for the product array.

**Overloaded Operators:**

* `operator<<`: For displaying order details.
* `operator>>`: For reading order input.

---

### **– Class: `Client`**

The `Client` class represents a customer who has placed an order.

**Data Members:**

* `char nume[60]`: Client's name, up to 60 characters.
* `Comanda comanda`: The order associated with the client.

**Constructors:**

* `Client()`: Default constructor that initializes the name as an empty string.
* `Client(const char* numeClient, const Comanda& comandaClient)`: Initializes the client name and associated order.

**Overloaded Operators:**

* `operator<<`: For displaying client information.
* `operator>>`: For reading client input.

---

### **– Relationships Between Classes**

* The `Produs` class stores product data.
* The `Comanda` class manages a list of products and represents an order made by a client.
* The `Client` class links a client with a specific order.

Essentially, a **Client** places a **Comanda** (Order) that contains multiple **Produs** (Products).

---

### **– Main Program Flow**

The program starts by checking for required input files containing product and client data. If any files are missing, it prints an error message and exits.

Once the files are opened, it reads the data and creates two output files:

1. One for processed orders.
2. One for the remaining stock.

The program first reads the number of products and dynamically allocates memory for storing them. It then loads each product into memory.

Next, it reads client information. It allocates a dynamic array for clients and reads each client and their order. All this information is saved to the output file with proper formatting.

**Main logic:**
For each client, the program checks if there is enough stock to fulfill the order. If not, it displays a warning and skips to the next product. If stock is sufficient, it decreases the quantity accordingly.

At the end, it writes the updated stock to the output file with detailed product information, then safely closes the files and frees memory.


